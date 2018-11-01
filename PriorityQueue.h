#include <iostream>
#include <string> 


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
    
/*string Node::to_string(int x)
  {
    ostringstream convert;
    convert << x;
    return convert.str();
  }*/

string Node::to_string ( int number )
    {
        string number_string = "";
        char charValue;
        int intValue = 0;
        while ( true )
            {
                intValue = number % 10;
                switch ( intValue )
                    {
                        case 0: charValue = '0'; break;
                        case 1: charValue = '1'; break;
                        case 2: charValue = '2'; break;
                        case 3: charValue = '3'; break;
                        case 4: charValue = '4'; break;
                        case 5: charValue = '5'; break;
                        case 6: charValue = '6'; break;
                        case 7: charValue = '7'; break;
                        case 8: charValue = '8'; break;
                        case 9: charValue = '9'; break;
                    }
                number -= intValue;
                number_string = charValue + number_string;
                if ( number == 0 )
                    {
                        break;
                    }
                number = number/10;
            }
        return number_string;
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
   
    
class PriorityQueue
    {
        private:
            Node* head;
            Node* tail;
    
        public:
            PriorityQueue(){head = NULL;}
            
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
    
    
void PriorityQueue::enqueue( int placement, string player, string country,
             int runs, string adversary, int yr)
    {
        Node* theNode = new Node(placement, player, country, runs, 
                                 adversary, yr);
	Node* cur;
        // is the queue empty?
       if (head == NULL || placement < head-> getRank())
       {
	 theNode -> setNext(head);
	 head = theNode;
       }
       else
       {
	 cur = head;
	 while(cur -> getNext()!= NULL && cur -> getNext()-> getRank()<= placement)
	 {
	  cur = cur -> getNext();
	 }
	 
	 theNode-> setNext(cur->getNext());
	 cur-> setNext(theNode);
       }
        return;
    }
   
   
string PriorityQueue::dequeue()
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
   
   
string PriorityQueue::displayAll()
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
        bool PriorityQueue::isEmpty()
                {
                    if (head == NULL)
                        return true;
                    else 
                        return false;
                }
                
                
            int PriorityQueue::getSize(){return 0;}
            string PriorityQueue::showHead(){return "";}
            string PriorityQueue::showTail(){return "";} 
