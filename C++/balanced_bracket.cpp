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

#include <iostream>
#include <string>
#include <stack>
#include <map>


void setBracketMapping(std::map<char, char>& mapping){
    mapping.insert(std::pair<char, char> ('(', ')'));
    mapping.insert(std::pair<char, char> ('{', '}'));
    mapping.insert(std::pair<char, char> ('[', ']'));
}


char getMappedBracket(std::map<char, char> mapping, char target){
    for(auto itr = mapping.begin(); itr != mapping.end(); itr++){
        if(itr->first == target){
            return itr->second;    
        }
    }
    return 'X';
}


bool isValid(std::string s){
    std::stack <char> brackets;
    std::map <char, char> bracketMapping;
    setBracketMapping(bracketMapping);
    char lastBracket, currentBracket, expectedBracket;
    brackets.push(s[0]);
    for(unsigned int i = 1; i < s.length(); i++){
        lastBracket = brackets.top();
        expectedBracket = getMappedBracket(bracketMapping, lastBracket);
        currentBracket = s[i];
        if(currentBracket == expectedBracket){
            brackets.pop();
        }
        else{
            brackets.push(s[i]);
        }
    }
    if(brackets.empty()){
        return true;
    }
    else{
        return false;
    }
}    
    
    
int main()
{
    std::string brackets = "((){})";
    if (isValid(brackets)){
        std::cout << "Balanced.\n";
    }
    else{
        std::cout << "Not Balanced.\n";
    }
}
