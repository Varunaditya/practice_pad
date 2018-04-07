/*
An implementation of singly-linked-list
*/

#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class linkedList{
private:
	node *head, *tail;

public:
	linkedList(){
		head = NULL;
		tail = NULL;
	}

	void createNode(int value){
		node *temp = new node();
		temp->data = value;
		temp->next = NULL;
		head = temp;
		tail = temp;
		temp = NULL;
	}

	void display(){
		node *temp = new node();
		temp = head;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	
	void push_front(int value){
		if(head == NULL) createNode(value);
		else{
		node *temp = new node();
		temp->data = value;
		temp->next = head;
		head = temp;
		}
	}

	void push_back(int value){
		if(head == NULL) createNode(value);
		else{
		node *temp = new node();
		temp->data = value;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		}
	}

	void pop_front(){
		node *temp = new node();
		temp = head;
		head = head->next;
		delete temp;
	}

	void pop_back(){
		node *current = new node();
		node *previous = new node();
		node *temp = new node();
		current = head;
		while(current != NULL){
			previous = current;
			current = current->next;
		}
		temp = tail;
		tail = previous;
		delete temp;
	}
};

int main(){
	linkedList obj;
	obj.push_back(2);
	obj.push_front(1);
	obj.display();
	obj.push_back(3);
	obj.display();
	obj.pop_front();
	obj.display();
	obj.pop_front();
	obj.display();
	return 0;
}