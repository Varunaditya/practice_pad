/*
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
Some examples of balanced brackets are []{}(), [({})]{}() and ({(){}[]})[].
By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
    1. It contains no unmatched brackets.
    2. The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.
*/

#include <stack>
#include <iostream>
using namespace std;

bool is_balanced(string expression){
    stack <char> chars;
    char c;
    for(char c : expression){
        if (c == '{') chars.push('}');
        else if (c == '(') chars.push(')');
        else if (c == '[') chars.push(']');
        else{
            if (chars.empty() or c != chars.top()) return false;
            chars.pop();
        }
    }
    return chars.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
