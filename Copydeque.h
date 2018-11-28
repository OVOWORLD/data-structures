#ifndef Deque_H
#define Deque_H
#include <cstddef>
#include "Node.h"
using namespace std;


class Deque{
	private:
		Node* head;
	
	 public:
		//con
		Deque(){head = NULL;}
		
		void purge() {head = NULL;}
		
		//Mutator Function
		void insertFirst(int, string, string, int, string, int);
		void insertLast(int, string, string, int, string, int);
		string removeFirst();
		string removeLast();
		
		//Accessor Function
		string first();
		string last();
		bool isEmpty(){return (head == NULL)?true:false;}
		int size();
		string displayAll();
		
};

void Deque::insertFirst(int rank, string name, string nationality, int score, string opponent, int year)
{
	Node* temp = new Node(rank, name, nationality, score, opponent, year);
	
	if (head == NULL)			//The list is empty
		head = temp;
	else						//The list is not empty
	{
		temp->setNext(head);
		head = temp;
	}
}
	
void Deque::insertLast(int rank, string name, string nationality, int score, string opponent, int year)
{
	Node* temp = new Node(rank, name, nationality, score, opponent, year);
	
	if(head == NULL)	//List is empty
	{			
		head = temp;
		return;
	}
	
	Node* cur = head;
	
	//walk down to the last node in the list
	while(cur->getNext() != NULL)
		cur = cur ->getNext();
	
	//Last node
	cur->setNext(temp);
}

string Deque::removeFirst(){
  
	string str = "";
	
	if(head == NULL)		//Deque is empty
		return ("\n\tDeque is empty...\n");;
		
	
	str.append(head->getRecord());
	Node* temp = head;
	head = head ->getNext();
	delete temp;
	
	return str;
}
		
string Deque::removeLast(){
	
	string str = "";

	if(head ==NULL)
		return ("\n\tDeque is empty...\n");
	
	if(head-> getNext() == NULL){	//List has only one node 
		str.append(head->getRecord());
		delete head;
	}
	else{
		Node* prev = head;
		Node* cur = head->getNext();
		
		while(cur->getNext() != NULL){
			prev = cur;
			cur = cur->getNext();
		}
		str.append(cur->getRecord());
		prev->setNext(NULL);
		delete cur;
	}
	return str;
}
		
string Deque::first(){
 	string str = "";

	if(head == NULL)
		return ("\n\tDeque is empty...\n");
	else
		return str.append(head->getRecord());
}

string Deque::last(){
  
	string str = "";

	if(head == NULL)
		return ("\n\tDeque is empty...\n");
	else 
	{
		Node* cur = head;
		while(cur->getNext() != NULL)
			cur = cur ->getNext();
		
		return str.append(cur->getRecord());
	}
}

int Deque::size(){
	if(head == NULL)
		return 0;
	else{
		Node* cur = head;
		int count = 1;
		while(cur->getNext() != NULL){
			cur = cur->getNext();
			count++;
		}
		return count;
	}
	
			
		//or
			
	Node* cur = head;
	int count = 0;
	while(cur != NULL){
		cur = cur->getNext();
		count++;
	}
	return count;	
}
		
string Deque::displayAll(){
	string str = "";

	if(head == NULL)
		return ("\n\tDeque is empty...\n");
  
	Node* cur = head;
	while(cur != NULL){
		str.append(cur->getRecord());
		str.append("\n");
		cur = cur->getNext();
	}
	str.append("\n\n");
	return str;
}

#endif
