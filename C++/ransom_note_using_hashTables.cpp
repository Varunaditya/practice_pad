#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define TABLE_SIZE 256

int hashTable[TABLE_SIZE] = {0};

int hashFunction(string key){
	int hashKey = 0, intChar;
	for(int i = 0; i < key.length(); i++){
		intChar = key[i];
		hashKey += intChar;
	}
	return hashKey%TABLE_SIZE;
}

void insertKey(vector <string> magazine){
	int i, hashKey;
	for(i = 0; i < magazine.size(); i++){
		hashKey = hashFunction(magazine[i]);
		hashTable[hashKey] += 1;
	}
}


bool ransomNote(vector <string> magazine, vector <string> ransom){
	int i, flag = 0, ransomHashKey;
	insertKey(magazine);
	for(i = 0; i < ransom.size(); i++){
		ransomHashKey = hashFunction(ransom[i]);
		if(hashTable[ransomHashKey]){
			hashTable[ransomHashKey] -= 1;
		}
		else{
			flag = 1;
			break;
		}
	}
	return flag == 1 ? false : true;
}

int main(){
	int m; cin >> m;
    int n; cin >> n;
	string temp;
    vector <string> magWords, ransomWords; 
	for(int i = 0; i < m; i++){
		cin >> temp;
        magWords.push_back(temp);
	}
	for(int i = 0; i < n; i++){
		cin >> temp;
        ransomWords.push_back(temp);
    }
    if (ransomNote(magWords, ransomWords)) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}