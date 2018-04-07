/*
Alice is taking a cryptography class and finding anagrams to be very useful. We consider two 
strings to be anagrams of each other if the first string's letters can be rearranged to form 
the second string. In other words, both strings must contain the same exact letters in the 
same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.
Alice decides on an encryption scheme involving two large strings where encryption is 
dependent on the minimum number of character deletions required to make the two strings 
anagrams. Can you help her find this number?
Given two strings, a and b, that may or may not be of the same length, determine the minimum 
number of character deletions required to make and anagrams. Any characters can be deleted 
from either of the strings. 

Link: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

*/

#include <map>
#include <string>
#include <iostream>
using namespace std;

int number_needed(string a, string b) {
    int requiredNumber = 0; //this number would be returned
    int i,temp; //for iterations
    map<char,int> string_A,string_B; //mapping the characters of a and b
    map<char,int>::iterator it; //variable of class iterator for iterating through the maps
    for(i = 0; i < a.length(); i++){
        string_A[a[i]] = string_A[a[i]] + 1; //counting the number of occurences of letters in string_A
    }
    for(i = 0; i < b.length(); i++){
        string_B[b[i]] = string_B[b[i]] + 1;  //counting the number of occurences of letters in string_B
    }
    for(it = string_A.begin(); it != string_A.end(); it++){
        if(string_B[it->first]){ //it->first is the key n the mapped data while it->second is the value
            temp = (string_B[it->first] - it->second);
            if(temp < 0) temp *= (-1);
            requiredNumber += temp;
            }
        else{
            requiredNumber += it->second;
            }
        }
    for(it = string_B.begin(); it != string_B.end(); it++){
        if(!string_A[it->first]){ //looking for characters that are not present in string A.
            requiredNumber += it->second;
            }
        }
    return requiredNumber;
    }

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}