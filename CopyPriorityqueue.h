#ifndef PriorityQueue_H
#define PriorityQueue_H

#include "Node.h"
#include <cstddef>
#include<iostream>
using namespace std;

class PriorityQueue{
	private:
		Node* head;
	
	public:
		//con
		PriorityQueue(){head = NULL;}
		
		void purge() {head = NULL;}
		
		//Mutator Function
		void enqueue(int, string, string, int, string, int);
		string dequeue();
		
		//Accessor Function
		bool isEmpty(){return (head == NULL)?true:false;}
		string displayAll();
		string getHead();
		string getTail();
		int size();
};


void PriorityQueue::enqueue(int rank, string name, string nationality, int score, string opponent, int year)
{
	Node* temp = new Node(rank, name, nationality, score, opponent, year);
	Node* cur = head;
	Node* prev = cur;

	if(head == NULL)
	{			//Priority Queue is empty
		head = temp;
		return;
	}
	
	if(cur->getRank() > rank)
	{
		temp->setNext(head);
		head = temp;
	}
	else
	{
		//walk down to where value is less than rank 
		while(cur->getNext() != NULL && cur->getRank() <= rank)
		{
			prev = cur;
			cur = cur->getNext();
			
		}
		
		if(cur->getNext() == NULL && cur->getRank() < rank)
			cur->setNext(temp);
		else
		{
			temp->setNext(prev->getNext());
			prev->setNext(temp);
		}	
	}
}


string PriorityQueue::dequeue()
{
	string str = "";

	if(head == NULL)		//Queue is empty
		return ("\n\tPriority Queue is empty...\n");
		
	str.append(head->getRecord());
	Node* temp = head;
	head = head->getNext();
	
	delete temp;
	return str;
	
}


string PriorityQueue::getHead()
{
	string str = "";

	if(head == NULL)
		return ("\n\tPriority Queue is empty...\n");
	else
		return str.append(head->getRecord());
}


string PriorityQueue::getTail()
{
	string str = "";
	//str.append( head->getRecord());
	
	if (head == NULL)
		return ("\nThe queue is empty...");
	else
	{
		Node* cur = head;
		while (cur->getNext() != NULL)
			cur = cur->getNext();
	    
		return str.append(cur->getRecord());
	}
}


int PriorityQueue::size()
{
	Node* cur = head;
	int count = 0;
	while(cur != NULL)
	{
		cur = cur->getNext();
		count++;
	}
	return count;
}


string PriorityQueue::displayAll()
{
	Node* cur = head;
	string str = "";
	
	while(cur != NULL)
	{
		str.append(cur->getRecord());
		str.append("\n");
		cur = cur->getNext();
	}
	str.append("\n\n");
	
	return str;
}

#endif
