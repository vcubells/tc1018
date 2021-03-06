//
//  main.cpp
//  EP2_E3
//
//  Created by Vicente Cubells Nonell on 13/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <utility>
#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include <stdlib.h>


const int LEFT_ASSOC  = 0;
const int RIGHT_ASSOC = 1;

// Map the different operators: +, -, *, / etc
typedef std::map< std::string, std::pair< int,int > > OpMap;
typedef std::vector<std::string>::const_iterator cv_iter;
typedef std::string::iterator s_iter;

const OpMap::value_type assocs[] =
{  OpMap::value_type( "+", std::make_pair( 0, LEFT_ASSOC ) ),
    OpMap::value_type( "-", std::make_pair( 0, LEFT_ASSOC ) ),
    OpMap::value_type( "*", std::make_pair( 5, LEFT_ASSOC ) ) };

const OpMap opmap( assocs, assocs + sizeof( assocs ) / sizeof( assocs[ 0 ] ) );

bool isParenthesis( const std::string& token);
bool isOperator( const std::string& token);
bool isAssociative( const std::string& token, const int& type);
int cmpPrecedence( const std::string& token1, const std::string& token2 );
bool infixToRPN( const std::vector<std::string>& inputTokens,
                const int& size,
                std::vector<std::string>& strArray );
std::string evaluateRPN( std::vector<std::string> tokens );
std::vector<std::string> getExpressionTokens( const std::string& expression );


template<typename T, typename InputIterator>
void Print( const std::string& message,
           const InputIterator& itbegin,
           const InputIterator& itend,
           const std::string& delimiter);

std::string addition(std::string first, std::string second);
std::string multiplication(std::string first, std::string second);

int main(int argc, const char * argv[]) {
    
    //std::string s = "{7,1,193}+{55,1}";
    //std::string s = "{7,1,193,1}*{55,1}";
    //std::string s = "{1,3,9,77}*({7,1,193}+{55})";
    //std::string s = "{1,3,9,77}*{7,1,193}+{55}";
    
    std::string s = "(({3}+({1,4,2}))*({1,2,3,4,5}*{4,3,2,5}*{2,3,4,5,6}+{}))+{}";
    
    Print<char, s_iter>( "Input expression:", s.begin(), s.end(), "" );
    
    // Tokenize input expression
    std::vector<std::string> tokens = getExpressionTokens( s );
    
    Print<std::string, cv_iter>( "Tokens:", tokens.begin(), tokens.end(), ":" );
    
    // Evaluate feasible expressions
    std::vector<std::string> rpn;
    if ( infixToRPN( tokens, (int) tokens.size(), rpn ) )
    {
        std::string d = evaluateRPN( rpn );
        Print<std::string, cv_iter>( "RPN tokens:  ", rpn.begin(), rpn.end(), " " );
        
        std::cout << "Result = " << d << std::endl;
    }
    else
    {
        std::cout << "Mis-match in parentheses" << std::endl;
    }
    
    return 0;

}


// Test if token is an pathensesis
bool isParenthesis( const std::string& token)
{
    return token == "(" || token == ")";
}

// Test if token is an operator
bool isOperator( const std::string& token)
{
    return token == "+" || token == "-"
     || token == "*" || token == "/";
}

// Test associativity of operator token
bool isAssociative( const std::string& token, const int& type)
{
    const std::pair<int,int> p = opmap.find( token )->second;
    return p.second == type;
}

// Compare precedence of operators.
int cmpPrecedence( const std::string& token1, const std::string& token2 )
{
    const std::pair<int,int> p1 = opmap.find( token1 )->second;
    const std::pair<int,int> p2 = opmap.find( token2 )->second;
    
    return p1.first - p2.first;
}

// Convert infix expression format into reverse Polish notation
bool infixToRPN( const std::vector<std::string>& inputTokens,
                const int& size,
                std::vector<std::string>& strArray )
{
    bool success = true;
    
    std::list<std::string> out;
    std::stack<std::string> stack;
    
    // While there are tokens to be read
    for ( int i = 0; i < size; i++ )
    {
        // Read the token
        const std::string token = inputTokens[ i ];
        
        // If token is an operator
        if ( isOperator( token ) )
        {
            // While there is an operator token, o2, at the top of the stack AND
            // either o1 is left-associative AND its precedence is equal to that of o2,
            // OR o1 has precedence less than that of o2,
            const std::string o1 = token;
            
            if ( !stack.empty() )
            {
                std::string o2 = stack.top();
                
                while ( isOperator( o2 ) &&
                       ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||
                        ( cmpPrecedence( o1, o2 ) < 0 ) ) )
                {
                    // pop o2 off the stack, onto the output queue;
                    stack.pop();
                    out.push_back( o2 );
                    
                    if ( !stack.empty() )
                        o2 = stack.top();
                    else
                        break;
                }
            }
            
            // push o1 onto the stack.
            stack.push( o1 );
        }
        // If the token is a left parenthesis, then push it onto the stack.
        else if ( token == "(" )
        {
            // Push token to top of the stack
            stack.push( token );
        }
        // If token is a right bracket ')'
        else if ( token == ")" )
        {
            // Until the token at the top of the stack is a left parenthesis,
            // pop operators off the stack onto the output queue.
            std::string topToken  = stack.top();
            
            while ( topToken != "(" )
            {
                out.push_back(topToken );
                stack.pop();
                
                if ( stack.empty() ) break;
                topToken = stack.top();
            }
            
            // Pop the left parenthesis from the stack, but not onto the output queue.
            if ( !stack.empty() ) stack.pop();
            
            // If the stack runs out without finding a left parenthesis,
            // then there are mismatched parentheses.
            if ( topToken != "(" )
            {
                return false;
            }
        }
        // If the token is a number, then add it to the output queue.
        else
        {
            out.push_back( token );
        }
    }
    
    // While there are still operator tokens in the stack:
    while ( !stack.empty() )
    {
        const std::string stackToken = stack.top();
        
        // If the operator token on the top of the stack is a parenthesis,
        // then there are mismatched parentheses.
        if ( isParenthesis( stackToken )   )
        {
            return false;
        }
        
        // Pop the operator onto the output queue./
        out.push_back( stackToken );
        stack.pop();
    }          
    
    strArray.assign( out.begin(), out.end() );    
    
    return success;      
}

std::string evaluateRPN( std::vector<std::string> tokens )
{
    std::stack<std::string> st;
    
    // For each token
    for ( int i = 0; i < (int) tokens.size(); ++i )
    {
        const std::string token = tokens[ i ];
        
        // If the token is a value push it onto the stack
        if ( !isOperator(token) )
        {
            st.push(token);
        }
        else
        {
            std::string result =  "";
            
            // Token is an operator: pop top two entries
            const std::string val2 = st.top();
            st.pop();
            
            if ( !st.empty() )
            {
                const std::string val1 = st.top();
                st.pop();
                
                //Get the result
                result = token == "+" ? addition(val1, val2) :
                token == "*" ? multiplication(val1, val2) : " ";
            }
            
            // Push result onto stack
            std::ostringstream s;
            s << result;
            st.push( s.str() );
        }
    }
    
    return st.top();
}

std::vector<std::string> getExpressionTokens( const std::string& expression )
{
    std::vector<std::string> tokens;
    std::string str = "";
    
    int len = (int) expression.length();
    
    for ( int i = 0; i < len ; ++i )
    {
        const std::string token( 1, expression[ i ] );
        
        if ( isOperator( token ) || isParenthesis( token ) )
        {
            if ( !str.empty() )
            {
                tokens.push_back( str ) ;
            }
            str = "";
            tokens.push_back( token );
        }
        else
        {
            // Append the numbers
            if ( !token.empty() && token != " " )
            {
                str.append( token );
            }
            else
            {
                if ( str != "" )
                {
                    tokens.push_back( str );
                    str = "";
                }
            }
        }
    }
    
    /* La expresión termina con un número */
    if ( str != "" )
    {
        tokens.push_back( str );
    }

    return tokens;
}

// Print iterators in a generic way
template<typename T, typename InputIterator>
void Print( const std::string& message,
           const InputIterator& itbegin,
           const InputIterator& itend,
           const std::string& delimiter)
{
    std::cout << message << std::endl;
    
    std::copy(itbegin,
              itend,
              std::ostream_iterator<T>(std::cout, delimiter.c_str()));
    
    std::cout << std::endl;
}

/************************************************************/
/*** Funciones para operaciones de conjuntos              ***/
/************************************************************/

bool isSeparator( const std::string & token)
{
    return token == "{" || token == "}" || token == ",";
}

std::vector<std::string> split(const std::string & expression )
{
    std::vector<std::string> tokens;
    std::string str = "";
    
    int len = (int) expression.length();
    
    for ( int i = 0; i < len ; ++i )
    {
        const std::string token( 1, expression[ i ] );
        
        if ( isSeparator( token ) )
        {
            if ( !str.empty() )
            {
                tokens.push_back( str ) ;
            }
            str = "";
        }
        else
        {
            // Append the numbers
            if ( !token.empty() )
            {
                str.append( token );
            }
            else
            {
                if ( str != "" )
                {
                    tokens.push_back( str );
                    str = "";
                }
            }
        }
    }
    
    /* La expresión termina con un número */
    if ( str != "" )
    {
        tokens.push_back( str );
    }
    
    return tokens;

}

std::string merge(const std::vector<std::string> & tokens )
{
    std::string out = "{";
    
    for (auto item : tokens) {
        if (!isSeparator( std::string( 1, out.back() ) ) ) {
            out.append(",");
        }
        out.append(item);
    }
    
    out.append("}");
    
    return out;
}

std::string addition(std::string first, std::string second)
{
    std::vector<std::string> setOne = split(first);
    
    std::vector<std::string> setTwo = split(second);
    
    std::vector<std::string> out(setOne.size());
    
    copy(setOne.begin(), setOne.end(), out.begin());
    
    for (auto item : setTwo) {
        auto exist = find(out.begin(), out.end(), item );
        
        if ( exist == out.end() )
        {
            out.push_back(item);
        }
    }
    
    return merge(out);
}

std::string multiplication(std::string first, std::string second)
{
    std::vector<std::string> setOne = split(first);
    
    std::vector<std::string> setTwo = split(second);
    
    std::vector<std::string> out;
    
    for (auto item : setOne) {
        
        auto exist = find(setTwo.begin(), setTwo.end(), item );
        
        if ( exist != setTwo.end()   )
        {
            exist = find(out.begin(), out.end(), item );
            
            if ( exist == out.end() )
            {
                out.push_back(item);
            }
        }
    }
    
    return merge(out);
    
}
