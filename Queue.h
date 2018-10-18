#include <iostream>
#include <string>
#include <sstream>


class Node
	{
   		private:
            int rank;
            string name;
            string nationality;
            int score;
            string opponent;
            int year;
            Node*  Next;   //This contains the address of the next node

		public:
  			Node ( void )   { Next = NULL; }
  			Node ( int, string, string, int, string, int);
            
			  //Define the accessor member functions...
  			int getRank ( void )    { return rank; }
  			Node*  getNext ( void )    { return Next;  }
  			string getData();

			  //Define the mutators...
			 void setData ( int, string, string, int, string, int );
                   void setNext ( Node* Nx )    { Next  = Nx; }
             
                    string to_string(int);
                      
	     
 	};

 
Node::Node ( int place, string player, string country, int runs, 
             string adversary, int yr)
    {
            rank       = place;
            name        = player;
            nationality = country;
            score       = runs;
            opponent    = adversary;
            year        = yr;
            Next        = NULL;
    }
    
 string Node::to_string(int x)
  {
    ostringstream convert;
    convert << x;
    return convert.str();
  }
    
string Node::getData()
    {
        string str = "";
        str.append(to_string(rank));
        str.append("\t");
        str.append(name);
        str.append("\t");
        str.append(nationality);
        str.append("\t");
        str.append(to_string(score));
        str.append("\t");
        str.append(opponent);
        str.append("\t");
        str.append(to_string(year));
        str.append("\n");

        return str;
    }
   
 void Node::setData( int place, string player, string country,
             int runs, string adversary, int yr)
    {
            rank        = place;
            name        = player;
            nationality = country;
            score       = runs;
            opponent    = adversary;
            year        = yr;
    }
   
    
class Queue
    {
        private:
            Node* head;
            Node* tail;
    
        public:
            Queue(){head = NULL;}
            
            // Mutator functions
            void enqueue(int, string, string, int, string, int);
            string dequeue();
            
            // Accessor functions
            bool isEmpty();//{return (head == NULL) ? true: false; };
            int getSize();
            string displayAll();
            string showHead();
            string showTail();
    };
    
    
void Queue::enqueue( int placement, string player, string country,
             int runs, string adversary, int yr)
    {
        Node* theNode = new Node(placement, player, country, runs, 
                                 adversary, yr);
        // is the queue empty?
        if (isEmpty())
            {
                head = theNode;
                tail = theNode;
                return;
            }
            
        tail->setNext(theNode);
        tail = theNode;
        return;
    }
   
   
string Queue::dequeue()
    {
        // Test to see if queue is empty
        if (isEmpty())
            {
                return "Queue is empty";
            }
        
        // There is only one node in the queue
        if (head == tail)
            {
                Node* temp = head;
                string str = head->getData();
                head = tail = NULL;
                delete temp;
                return str;
            }
            
        // Normal case
        Node* cur = head;
        string str = head->getData();
        head = head->getNext();
        delete cur;
        return str;
    }
   
   
string Queue::displayAll()
    {
        string str;
        
        if (isEmpty()) return "The queue is empty!\n";
        
        Node* cur = head;
        
        while (cur != NULL)
        {
            str.append(cur->getData());
            cur = cur->getNext();
        }
        return str;
    }
            
            
            // Accessor functions
        bool Queue::isEmpty()
                {
                    if (head == NULL)
                        return true;
                    else 
                        return false;
                }
                
                
            int Queue::getSize(){return 0;}
            string Queue::showHead(){return "";}
            string Queue::showTail(){return "";} 
    
