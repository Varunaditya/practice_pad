/*
We're going to make our own Contacts application! The application must perform two types of operations:
1. add name, where name is a string denoting a contact name. This must store name as a new contact in the 
   application.
2. find partial, where partial is a string denoting a partial name to search the application for. It must count the 
   number of contacts starting with partial and print the count on a new line.
Given n sequential add and find operations, perform each operation in order.

Link: https://www.hackerrank.com/challenges/ctci-contacts/problem

*/

#include <iostream>
#include <string>
#define ALPHA_SIZE 26
using namespace std;

struct trieNode{
	bool isEndOfWord;
	struct trieNode *child[ALPHA_SIZE];
};

struct trieNode *createNode(){
	struct trieNode *node = new trieNode;
	node->isEndOfWord = false;
	for(int i = 0; i < ALPHA_SIZE; i++){
		node->child[i] = NULL;
	}
	return node;
}

void insert(struct trieNode *root, string key){
	struct trieNode *traverse = root;
	for(int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if(!traverse->child[index]){
			traverse->child[index] = createNode();
		}
		traverse = traverse->child[index];
	}
	traverse->isEndOfWord = true;
}

bool search(struct trieNode *root, string key){
	struct trieNode *traverse = root;
	for(int i = 0; i < key.length(); i++){
		int index = key[i] - 'a';
		if(!traverse->child[index]){
			return false;
		}
		traverse = traverse->child[index];
	}
    while()
	return (traverse != NULL);
}

int main(){
	int N; cin >> N;
	string temp;
	struct trieNode *root = createNode();
	for(int i = 0; i < N; i++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add"){
            insert(root, contact);
        }
        else if(op == "find"){
            cout << search(root, contact) << endl;
        }
    }
	return 0;
}