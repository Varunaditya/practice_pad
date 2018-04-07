/*
A kidnapper wrote a ransom note but is worried it will be traced back 
to him. He found a magazine and wants to know if he can cut out whole 
words from it and use them to create an untraceable replica of his 
ransom note. The words in his note are case-sensitive and he must use
whole words available in the magazine, meaning he cannot use substrings 
or concatenation to create the words he needs.
Given the words in the magazine and the words in the ransom note, print 
Yes if he can replicate his ransom note exactly using whole words from 
the magazine; otherwise, print No.

Link: https://www.hackerrank.com/challenges/ctci-ransom-note/problem

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool ransomeNote(vector <string> magazine, vector <string> ransome){
	if (magazine.size() < ransome.size()) return false;
	int i, flag = 0;
	map <string, int> magazineMap;
	map <string, int> :: iterator it;
	for(i = 0; i < magazine.size(); i++){
		magazineMap[magazine[i]] += 1;
	}
	for(i = 0; i < ransome.size(); i++){
		if(magazineMap[ransome[i]]){
			magazineMap[ransome[i]] = magazineMap[ransome[i]] - 1;
		}
		else{
            flag = 1;
            break;
        }
	}
	if (flag) return false;
	else return true;
}


int main(){
	int m; cin >> m;
    int n; cin >> n;
	string temp;
    vector <string> magWords, ransomeWords; 
	for(int i = 0; i < m; i++){
		cin >> temp;
        magWords.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		cin >> temp;
        ransomeWords.push_back(temp);
    }
	if (ransomeNote(magWords, ransomeWords)) cout << "Yes\n";
	else cout << "No\n";
	return 0;
    }
