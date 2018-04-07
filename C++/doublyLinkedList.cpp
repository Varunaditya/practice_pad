/*
An implementation of Doubly Linked List.
*/
#include <iostream>
using namespace std;

class node{
	int data;
	node *next;
	node *previous;
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
		temp->previous = NULL;
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
		temp->previous = NULL;
		head->previous = temp;
		head = temp;
		}
	}

	void push_back(int value){
		if(head == NULL) createNode(value);
		else{
		node *temp = new node();
		temp->data = value;
		temp->next = NULL;
		temp->previous = tail;
		tail->next = temp;
		tail = temp;
		}
	}

	void pop_front(){
		node *temp = new node();
		temp = head;
		head = head->next;
		head->previous = NULL;
		delete temp;
	}

	void pop_back(){
		node *temp = new node();
		temp = tail;
		tail = tail->previous;
		tail->next = NULL;
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