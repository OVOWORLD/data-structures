#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
  # include <wx/wx.h>
  # include <wx/spinctrl.h>
  # include <wx/textctrl.h>		// Automatically included
  # include <wx/combobox.h>		// in versions 2.8 and 2.9
  # include <wx/listbox.h>		//     of wx.h
#endif

#include <fstream> 
#include <string> 

#include "sstream"
using namespace std;

//=================================================================
string to_string ( int number )
{
	string number_string = "";
	char charValue = '\0';
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
			    
			default: charValue = ' '; break;
		}
		number -= intValue;
		number_string = charValue + number_string;
		if ( number == 0 )
		{
			break;          // Break out of the while loop
		}
		number = number/10;
	}
	return number_string;
}
     
    
string makeRecord(int rankNo, string player, string team, int totRuns,
                  string oppTeam, int yr)
{
    string record;
    
    record = to_string(rankNo);
    record.append(" \t\t");
    record.append(player);
    record.append(" \t\t");
    record.append(team);
    record.append(" \t\t");
    record.append(to_string(totRuns));
    record.append("  \t\t");
    record.append(oppTeam);
    record.append(" \t\t");
    record.append(to_string(yr));
    
    return record;
}


string strip(string str)
{
	// Remove preceding blanks and tabs from the string
	while (!isalpha(str[0]))
	{
		for (int x = 0; x < str.length()-1; x++)
		{
			str[x] = str[x+1];
		}
		str[str.length()-1] = ' ';
	}
	
	// Reset the string width to 20 characters and pad it with blanks
	str.resize(20, ' ');
	
	return str;
}
//=================================================================

//ADTs header files
#include "Queue.h"
#include "Deque.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "BSTree.h"
#include "AVLTree.h"
#include "BinaryHeap.h"
#include "RBTree.h"
#include "SplayTree.h"
#include "Set.h"

//Dialog Box header files
#include "DialogBox.h"
#include "DelDialog.h"


// ADT Containers
Queue* queue = new Queue();
Deque* deque = new Deque();
PriorityQueue* pQueue = new PriorityQueue();
Stack* stack = new Stack();
BSTree* bst = new BSTree();
AVLTree* avl = new AVLTree();
BinaryHeap* heap = new BinaryHeap();
RBTree* rbTree = new RBTree();
SplayTree* splay = new SplayTree();
Set* setA = new Set();
Set* setB = new Set();
Set* setC = new Set();



/************************************************************************************
 *  Step 2: Name an inherited application class from wxApp and declare it with 
 *	  the function to execute the program				    
 *************************************************************************************/
class MyApp: public wxApp
    {
        virtual bool OnInit();
    };


/************************************************************************************
 *   Step 3: Declare the inherited main frame class from wxFrame. In this class 
 *	   also will ALL the events handlers be declared    
 *************************************************************************************/
class MyFrame: public wxFrame
{
    private:
        DECLARE_EVENT_TABLE() //To declare events items
    
    public:
        MyFrame(const wxString& title, const wxPoint& pos, 
                const wxSize& size);
        
		//Functions for File Menu Items
		void OnOpenFile(wxCommandEvent& event);
		void OnDisplay(wxCommandEvent& event);

		void OnSave(wxCommandEvent& event);	//handle for Save function
		void OnSaveAs(wxCommandEvent& event);	//handle for Save As function
		void OnExit(wxCommandEvent& event); 	//handle for Quit function		
		void OnAbout(wxCommandEvent& event);	//handle for About function
		
		
		// Functions for the Queue
		void OnCreateQueue(wxCommandEvent& event);	
		void OnEnqueueQue(wxCommandEvent& event);	
		void OnDequeueQue(wxCommandEvent& event);	
		void OnDisplayQueue(wxCommandEvent& event);	
		void OnShowHeadQueue(wxCommandEvent& event);	
		void OnShowTailQueue(wxCommandEvent& event);	
		
		
		// Functions for the Deque
		void OnCreateDeque(wxCommandEvent& event);	
		void OnAddHead(wxCommandEvent& event);	
		void OnAddTail(wxCommandEvent& event);	
		void OnDisplayDeque(wxCommandEvent& event);	
		void OnShowHeadDeque(wxCommandEvent& event);	
		void OnShowTailDeque(wxCommandEvent& event);	
		void OnDequeueHead(wxCommandEvent& event);	
		void OnDequeueTail(wxCommandEvent& event);
		
		
		// Functions for the Priority Queue
		void OnCreatePQueue(wxCommandEvent& event);	
		void OnEnqueuePQueue(wxCommandEvent& event);	
		void OnDequeuePQueue(wxCommandEvent& event);	
		void OnDisplayPQueue(wxCommandEvent& event);	
		void OnShowHeadPQueue(wxCommandEvent& event);	
		void OnShowTailPQueue(wxCommandEvent& event);	
		
		
		// Functions for the stack
		void OnCreateStack(wxCommandEvent& event);	
		void OnPopStack(wxCommandEvent& event);	
		void OnPushStack(wxCommandEvent& event);	
		void OnDisplayStack(wxCommandEvent& event);	
		void OnShowHeadStack(wxCommandEvent& event);	
		void OnShowTailStack(wxCommandEvent& event);	
		
		//Functions for the BSTree
		void OnCreateBST(wxCommandEvent& event);	
		void OnAddBST(wxCommandEvent& event);	
		void OnDeleteBST(wxCommandEvent& event);	
		void OnInorderBST(wxCommandEvent& event);	
		void OnPreorderBST(wxCommandEvent& event);	
		void OnPostorderBST(wxCommandEvent& event);	

		//Functions for the AVL Tree
		void OnCreateAVL(wxCommandEvent& event);	
		void OnAddAVL(wxCommandEvent& event);	
		void OnDeleteAVL(wxCommandEvent& event);	
		void OnInorderAVL(wxCommandEvent& event);	
		void OnPreorderAVL(wxCommandEvent& event);	
		void OnPostorderAVL(wxCommandEvent& event);	

		
		//Functions for the Heap Tree
		void OnCreateHeap(wxCommandEvent& event);	
		void OnAddHeap(wxCommandEvent& event);	
		void OnDeleteHeap(wxCommandEvent& event);	
		void OnDisplayHeap(wxCommandEvent& event);	
		void OnSortHeap(wxCommandEvent& event);	
		
		
		//Functions for the RB Tree
		void OnCreateRBTree(wxCommandEvent& event);	
		void OnAddRBTree(wxCommandEvent& event);	
		void OnDeleteRBTree(wxCommandEvent& event);	
		void OnInorderRBTree(wxCommandEvent& event);	
		void OnPreorderRBTree(wxCommandEvent& event);	
		void OnPostorderRBTree(wxCommandEvent& event);	
		

		//Functions for the Splay Tree
		void OnCreateSplay(wxCommandEvent& event);	
		void OnAddSplay(wxCommandEvent& event);	
		void OnDeleteSplay(wxCommandEvent& event);	
		void OnInorderSplay(wxCommandEvent& event);	
		void OnPreorderSplay(wxCommandEvent& event);	
		void OnPostorderSplay(wxCommandEvent& event);	

		
		// Functions for the Set
		void OnCreateSet(wxCommandEvent& event);	
		void OnAddSet(wxCommandEvent& event);	
		void OnDisplaySetA(wxCommandEvent& event);	
		void OnDisplaySetB(wxCommandEvent& event);
		void OnDisplayIntersection(wxCommandEvent& event);
		void OnDisplayUnion(wxCommandEvent& event);
		void OnDeleteSetA(wxCommandEvent& event);
		void OnDeleteSetB(wxCommandEvent& event);


		//Public attributes
		wxTextCtrl* MainEditBox;
		wxTextCtrl* filenameTextBox;
		wxString CurrentDocPath;		// The Path to the file we have open

    };


/************************************************************************************
 *  Step 4. Declare the compiler directives				    
 *************************************************************************************/
DECLARE_APP(MyApp)		// Declare Application class
IMPLEMENT_APP(MyApp)		// Create Application class object


enum
        {
		ID_OpenFile	= wxID_HIGHEST + 1,		//File menu item
		ID_Display,
		ID_Save,
		ID_SaveAs,
		ID_Exit,
		ID_About,
		
		ID_CreateQueue,
		ID_Enqueue,
		ID_Dequeue,
		ID_DislayQueue,
		ID_ShowHeadQueue,
		ID_ShowTailQueue,
		
		ID_CreateDeque,
		ID_Insertfirst,
		ID_InsertLast,
		ID_DislayDeque,
		ID_ShowHeadDeque,
		ID_ShowTailDeque,
		ID_RemoveFirst,
		ID_RemoveLast,
		
		ID_CreatePQ,
		ID_PQEnqueue,
		ID_PQDequeue,
		ID_DislayPQ,
		ID_ShowHeadPQ,
		ID_ShowTailPQ,
		
		ID_CreateStack,
		ID_PushStack,
		ID_PopStack,
		ID_DislayStack,
		ID_ShowHeadStack,
		ID_ShowTailStack,
 		  
		ID_CreateBST,
		ID_AddBST,
		ID_DeleteBST,
		ID_InorderBST,
		ID_PreorderBST,
		ID_PostorderBST,
		
		ID_CreateAVL,
		ID_AddAVL,
		ID_DeleteAVL,
		ID_InorderAVL,
		ID_PreorderAVL,
		ID_PostorderAVL,
		
		ID_CreateHeap,
		ID_AddHeap,
		ID_DeleteHeap,
		ID_DisplayHeap,
		ID_SortHeap,
		
		ID_CreateRBT,
		ID_AddRBT,
		ID_DeleteRBT,
		ID_InorderRBT,
		ID_PreorderRBT,
		ID_PostorderRBT,
		
		ID_CreateSplay,
		ID_AddSplay,
		ID_DeleteSplay,
		ID_InorderSplay,
		ID_PreorderSplay,
		ID_PostorderSplay,
		
		ID_CreateSet,
		ID_AddSet,
		ID_DislaySetA,
		ID_DislaySetB,
		ID_DislayIntersection,
		ID_DislayUnion,
		ID_DeleteSetA,
		ID_DeleteSetB,
        };

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
	// File Main Menu item's sub-menu items
	EVT_MENU ( ID_OpenFile, MyFrame::OnOpenFile )
	EVT_MENU ( ID_Display, 	MyFrame::OnDisplay )
	EVT_MENU ( ID_Save, 	MyFrame::OnSave )
	EVT_MENU ( ID_SaveAs, 	MyFrame::OnSaveAs )
	EVT_MENU ( ID_Exit, 	MyFrame::OnExit )
	EVT_MENU ( ID_About, 	MyFrame::OnAbout )

	
	// Queue Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateQueue, MyFrame::OnCreateQueue )
	EVT_MENU ( ID_Enqueue,   MyFrame::OnEnqueueQue )
	EVT_MENU ( ID_Dequeue,    MyFrame::OnDequeueQue )
	EVT_MENU ( ID_DislayQueue, MyFrame::OnDisplayQueue )
	EVT_MENU ( ID_ShowHeadQueue, MyFrame::OnShowHeadQueue )
	EVT_MENU ( ID_ShowTailQueue, MyFrame::OnShowTailQueue )


	// Deque Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateDeque, MyFrame::OnCreateDeque )
	EVT_MENU ( ID_Insertfirst,   MyFrame::OnAddHead )
	EVT_MENU ( ID_InsertLast,    MyFrame::OnAddTail )
	EVT_MENU ( ID_DislayDeque, MyFrame::OnDisplayDeque )
	EVT_MENU ( ID_ShowHeadDeque, MyFrame::OnShowHeadDeque )
	EVT_MENU ( ID_ShowTailDeque, MyFrame::OnShowTailDeque )
	EVT_MENU ( ID_RemoveFirst, MyFrame::OnDequeueHead )
	EVT_MENU ( ID_RemoveLast, MyFrame::OnDequeueTail )
	
	
	// Priority Main Menu item's sub-menu items
	EVT_MENU ( ID_CreatePQ, MyFrame::OnCreatePQueue )
	EVT_MENU ( ID_PQEnqueue,   MyFrame::OnEnqueuePQueue )
	EVT_MENU ( ID_PQDequeue,    MyFrame::OnDequeuePQueue )
	EVT_MENU ( ID_DislayPQ, MyFrame::OnDisplayPQueue )
	EVT_MENU ( ID_ShowHeadPQ, MyFrame::OnShowHeadPQueue )
	EVT_MENU ( ID_ShowTailPQ, MyFrame::OnShowTailPQueue )

	
	// Stack Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateStack, MyFrame::OnCreateStack )
	EVT_MENU ( ID_PushStack,   MyFrame::OnPushStack )
	EVT_MENU ( ID_PopStack,    MyFrame::OnPopStack )
	EVT_MENU ( ID_DislayStack, MyFrame::OnDisplayStack )
	EVT_MENU ( ID_ShowHeadStack, MyFrame::OnShowHeadStack )
	EVT_MENU ( ID_ShowTailStack, MyFrame::OnShowTailStack )
	
	
	// BS Tree Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateBST, MyFrame::OnCreateBST )
	EVT_MENU ( ID_AddBST,   MyFrame::OnAddBST )
	EVT_MENU ( ID_DeleteBST,    MyFrame::OnDeleteBST )
	EVT_MENU ( ID_InorderBST, MyFrame::OnInorderBST )
	EVT_MENU ( ID_PreorderBST, MyFrame::OnPreorderBST )
	EVT_MENU ( ID_PostorderBST, MyFrame::OnPostorderBST )
	
	
	// AVL Tree Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateAVL, MyFrame::OnCreateAVL )
	EVT_MENU ( ID_AddAVL,   MyFrame::OnAddAVL )
	EVT_MENU ( ID_DeleteAVL,    MyFrame::OnDeleteAVL )
	EVT_MENU ( ID_InorderAVL, MyFrame::OnInorderAVL )
	EVT_MENU ( ID_PreorderAVL, MyFrame::OnPreorderAVL )
	EVT_MENU ( ID_PostorderAVL, MyFrame::OnPostorderAVL )
	
	
	// Heap Tree Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateHeap, MyFrame::OnCreateHeap )
	EVT_MENU ( ID_AddHeap,   MyFrame::OnAddHeap )
	EVT_MENU ( ID_DeleteHeap,    MyFrame::OnDeleteHeap )
	EVT_MENU ( ID_DisplayHeap, MyFrame::OnDisplayHeap )
	EVT_MENU ( ID_SortHeap, MyFrame::OnSortHeap )
	
	
	// RB Tree Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateRBT, MyFrame::OnCreateRBTree )
	EVT_MENU ( ID_AddRBT,   MyFrame::OnAddRBTree )
	EVT_MENU ( ID_DeleteRBT,    MyFrame::OnDeleteRBTree )
	EVT_MENU ( ID_InorderRBT, MyFrame::OnInorderRBTree )
	EVT_MENU ( ID_PreorderRBT, MyFrame::OnPreorderRBTree )
	EVT_MENU ( ID_PostorderRBT, MyFrame::OnPostorderRBTree )
	
	
	// Splay Tree Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateSplay, MyFrame::OnCreateSplay )
	EVT_MENU ( ID_AddSplay,   MyFrame::OnAddSplay )
	EVT_MENU ( ID_DeleteSplay,    MyFrame::OnDeleteSplay )
	EVT_MENU ( ID_InorderSplay, MyFrame::OnInorderSplay )
	EVT_MENU ( ID_PreorderSplay, MyFrame::OnPreorderSplay )
	EVT_MENU ( ID_PostorderSplay, MyFrame::OnPostorderSplay )
	
	
	// Sets Main Menu item's sub-menu items
	EVT_MENU ( ID_CreateSet, MyFrame::OnCreateSet )
	EVT_MENU ( ID_AddSet, MyFrame::OnAddSet )
	EVT_MENU ( ID_DislaySetA, MyFrame::OnDisplaySetA )
	EVT_MENU ( ID_DislaySetB, MyFrame::OnDisplaySetB )
	EVT_MENU ( ID_DislayIntersection, MyFrame::OnDisplayIntersection )
	EVT_MENU ( ID_DislayUnion, MyFrame::OnDisplayUnion )
	EVT_MENU ( ID_DeleteSetA, MyFrame::OnDeleteSetA )
	EVT_MENU ( ID_DeleteSetB, MyFrame::OnDeleteSetB )
	
END_EVENT_TABLE () 



/************************************************************************************
 *  Step 5.  Define the Application class function to initialize the application
 *************************************************************************************/
bool MyApp::OnInit()
{
	// Create the main application window
	MyFrame *frame = new MyFrame( wxT("COMP2115 – Pelican Travels Database"), 
							    wxPoint(50,50), wxSize(500,400) );
      
	// Display the window
	frame->Show(TRUE);
      
	SetTopWindow(frame);
      
	return TRUE;
}


/************************************************************************************
 *  Step 6:   Define the Constructor functions for the Frame class
 *************************************************************************************/
MyFrame::MyFrame ( const wxString& title, const wxPoint& pos, const wxSize& size) : 
                    wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	// Set the frame icon - optional
	SetIcon(wxIcon(wxT("uwiIcon.xpm")));
    
	// Create a "File" main-menu item
	wxMenu *menuFile = new wxMenu;
	wxMenu *menuDisplay = new wxMenu;
	wxMenu *menuQueue = new wxMenu;
	wxMenu *menuDeque = new wxMenu;
	wxMenu *menuPrQueue = new wxMenu;
        wxMenu *menuStack = new wxMenu;
	wxMenu *menuBST = new wxMenu;
	wxMenu *menuAVLT = new wxMenu;
	wxMenu *menuHeap = new wxMenu;
	wxMenu *menuRBTree = new wxMenu;
	wxMenu *menuSplay = new wxMenu;
	wxMenu *menuSet = new wxMenu;
        wxMenu *menuHelp = new wxMenu;
	
	
    
        //Append menu items to the "File" menu item
		menuFile->Append( ID_OpenFile, wxT("&Open File"), wxT("Open an existing file") );
		menuFile->AppendSeparator();
		menuFile->Append( ID_Display, wxT("&Display File"), wxT("Display opened file") );
		menuFile->Append( ID_Save, wxT("&Save File"), wxT("Save to opened file") );
		menuFile->Append( ID_SaveAs, wxT("Save &As"), wxT("Save to new file") );
		menuFile->Append( ID_About, wxT("A&bout Program"), wxT("About the program") );
		menuFile->AppendSeparator();	   
	
		// Queue Main menu items
		menuQueue->Append( ID_CreateQueue, wxT("Create Queue"), wxT("Create the queue") );
		menuQueue->Append( ID_Enqueue, wxT("Add Data"), wxT("Add new data to the Queue") );
		menuQueue->Append( ID_DislayQueue, wxT("Display All"), wxT("Display contents of Queue") );
		menuQueue->Append( ID_ShowHeadQueue, wxT("Show Head"), wxT("Display head of Queue") );
		menuQueue->Append( ID_ShowTailQueue, wxT("Show Tail"), wxT("Display tail of Queue") );
		menuQueue->Append( ID_Dequeue, wxT("Dequeue"), wxT("Remove data from the Queue") );

		
		// Deque Main menu items
		menuDeque->Append( ID_CreateDeque, wxT("Create Deque"), wxT("Create the queue") );
		menuDeque->Append( ID_Insertfirst, wxT("Add Head"), wxT("Add new data to the head of Deque") );
		menuDeque->Append( ID_InsertLast, wxT("Add Tail"), wxT("Add new data to the tail of Deque") );
		menuDeque->Append( ID_DislayDeque, wxT("Display All"), wxT("Display contents of Deque") );
		menuDeque->Append( ID_ShowHeadDeque, wxT("Show Head"), wxT("Display head of Deque") );
		menuDeque->Append( ID_ShowTailDeque, wxT("Show Tail"), wxT("Display tail of Deque") );
		menuDeque->Append( ID_RemoveFirst, wxT("Dequeue Head"), wxT("Remove data from the Head of Deque") );
		menuDeque->Append( ID_RemoveLast, wxT("Dequeue Tail"), wxT("Remove data from the tail of Deque") );

		
		// Priority Queue Main menu items
		menuPrQueue->Append( ID_CreatePQ, wxT("Create Priority Queue"), wxT("Create the Priority Queue") );
		menuPrQueue->Append( ID_PQEnqueue, wxT("Add Data"), wxT("Add new data to the Priority Queue") );
		menuPrQueue->Append( ID_DislayPQ, wxT("Display All"), wxT("Display contents of Priority Queue") );
		menuPrQueue->Append( ID_ShowHeadPQ, wxT("Show Head"), wxT("Display head of Priority Queue") );
		menuPrQueue->Append( ID_ShowTailPQ, wxT("Show Tail"), wxT("Display tail of Priority Queue") );
		menuPrQueue->Append( ID_PQDequeue, wxT("Dequeue"), wxT("Remove data from the Priority Queue") );


		// Stack Main menu items
		menuStack->Append( ID_CreateStack, wxT("Create Stack"), wxT("Create the stack") );
		menuStack->Append( ID_PopStack, wxT("Pop Stack"), wxT("Remove data from the stack") );
		menuStack->Append( ID_PushStack, wxT("Push Stack"), wxT("Add new data to the stack") );
		menuStack->Append( ID_DislayStack, wxT("Display Stack"), wxT("Display contents of Stack") );
		menuStack->Append( ID_ShowHeadStack, wxT("Show Head"), wxT("Display head of Stack") );
		menuStack->Append( ID_ShowTailStack, wxT("Show Tail"), wxT("Display tail of Stack") );

		
		// BST Main menu items
		menuBST->Append( ID_CreateBST, wxT("Create BST"), wxT("Create BST") );
		menuBST->Append( ID_AddBST, wxT("Add Data"), wxT("Add new data to BST") );
		menuBST->Append( ID_DeleteBST, wxT("Delete Data"), wxT("Remove data from BST") );
		menuBST->Append( ID_InorderBST, wxT("Inorder"), wxT("Display BST inorder") );
		menuBST->Append( ID_PreorderBST, wxT("Preorder"), wxT("Display BST preorder") );
		menuBST->Append( ID_PostorderBST, wxT("Postorder"), wxT("Display BST postorder") );
		
		
		// AVL Tree Main menu items
		menuAVLT->Append( ID_CreateAVL, wxT("Create AVL"), wxT("Create AVL Tree	") );
		menuAVLT->Append( ID_AddAVL, wxT("Add Data"), wxT("Add new data to AVL Tree") );
		menuAVLT->Append( ID_DeleteAVL, wxT("Delete Data"), wxT("Remove data from AVL Tree") );
		menuAVLT->Append( ID_InorderAVL, wxT("Inorder"), wxT("Display AVL Tree inorder") );
		menuAVLT->Append( ID_PreorderAVL, wxT("Preorder"), wxT("Display AVL Tree preorder") );
		menuAVLT->Append( ID_PostorderAVL, wxT("Postorder"), wxT("Display AVL Tree postorder") );
		
		
		// Heap Tree Main menu items
		menuHeap->Append( ID_CreateHeap, wxT("Create Heap"), wxT("Create Heap Tree") );
		menuHeap->Append( ID_AddHeap, wxT("Add Data"), wxT("Add new data to Heap Tree") );
		menuHeap->Append( ID_DeleteHeap, wxT("Delete Data"), wxT("Remove data from Heap Tree") );
		menuHeap->Append( ID_DisplayHeap, wxT("Display Heap"), wxT("Display contents of Heap") );
		menuHeap->Append( ID_SortHeap, wxT("Sort Heap"), wxT("Sort contents of Heap") );

		
		// RBTree Main menu items
		menuRBTree->Append( ID_CreateRBT, wxT("Create RBTree"), wxT("Create RB Tree") );
		menuRBTree->Append( ID_AddRBT, wxT("Add Data"), wxT("Add new data to RB Tree") );
		menuRBTree->Append( ID_DeleteRBT, wxT("Delete Data"), wxT("Remove data from RB Tree") );
		menuRBTree->Append( ID_InorderRBT, wxT("Inorder"), wxT("Display RB Tree inorder") );
		menuRBTree->Append( ID_PreorderRBT, wxT("Preorder"), wxT("Display RB Tree preorder") );
		menuRBTree->Append( ID_PostorderRBT, wxT("Postorder"), wxT("Display RB Tree postorder") );
		
		
		// Splay Tree Main menu items
		menuSplay->Append( ID_CreateSplay, wxT("Create Splay"), wxT("Create Splay Tree") );
		menuSplay->Append( ID_AddSplay, wxT("Add Data"), wxT("Add new data to Splay Tree") );
		menuSplay->Append( ID_DeleteSplay, wxT("Delete Data"), wxT("Remove data from Splay Tree") );
		menuSplay->Append( ID_InorderSplay, wxT("Inorder"), wxT("Display Splay Tree inorder") );
		menuSplay->Append( ID_PreorderSplay, wxT("Preorder"), wxT("Display Splay Tree preorder") );
		menuSplay->Append( ID_PostorderSplay, wxT("Postorder"), wxT("Display Splay Tree postorder") );
		
		// Set Main menu items
		menuSet->Append( ID_CreateSet, wxT("Create Set"), wxT("Create Set") );
		menuSet->Append( ID_AddSet, wxT("Add Data"), wxT("Add new data to Set") );
		menuSet->Append( ID_DislaySetA, wxT("Display SetA "), wxT("Display contents in SetA") );
		menuSet->Append( ID_DislaySetB, wxT("Display SetB"), wxT("Display contents in SetB") );
		menuSet->Append( ID_DislayIntersection, wxT("Display Intersection "), wxT("Display Intersection") );
		menuSet->Append( ID_DislayUnion, wxT("Display Union "), wxT("Display Union") );
		menuSet->Append( ID_DeleteSetA, wxT("Delete SetA"), wxT("Remove data from SetA") );
		menuSet->Append( ID_DeleteSetB, wxT("Delete SetB"), wxT("Remove data from SetB") );


		//Append "Help" sub-menu item to it 
		menuHelp->Append(ID_About, wxT("A&bout..."), wxT("About the program"));
		menuHelp->Append( ID_Exit, wxT("E&xit"), wxT("Exit program") );


	//Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;
    
	//Append the main menu items ("File" and "Help") to it
        menuBar->Append( menuFile, wxT("&File") );
	menuBar->Append( menuQueue, wxT("&Queue") );
	menuBar->Append( menuDeque, wxT("&Deque") );
	menuBar->Append( menuPrQueue, wxT("&Priority Queue") );
        menuBar->Append( menuStack, wxT("&Stack") );
	menuBar->Append( menuBST, wxT("&BST") );
	menuBar->Append( menuAVLT, wxT("&AVL Tree") );
	menuBar->Append( menuHeap, wxT("&Heap") );
	menuBar->Append( menuRBTree, wxT("&RB Tree") );
	menuBar->Append( menuSplay, wxT("&Splay") );
	menuBar->Append( menuSet, wxT("S&et") );
        menuBar->Append( menuHelp, wxT("He&lp") );
    
        //Attach this main menu bar to the frame
	SetMenuBar( menuBar );
    
	// Create a status bar just for fun
	CreateStatusBar(3);
    
	//Put something in the first section of the status bar
	SetStatusText( wxT("Ready") );
    
	//Put something in the second section of the status bar
	SetStatusText( wxT("Jade Medford"), 1 );
	
	//Put something in the third section of the status bar
	SetStatusText( wxT("412002700"), 2 );
    
	   
	   
	   	//Set up the panel for data display
//=========================================================================================
//=========================== DO NOT CHANGE THE CODE IN THIS SECTION ======================	
//=========================================================================================

	wxPanel 	 *panel = new wxPanel(this, -1);
	wxBoxSizer *vbox  = new wxBoxSizer(wxVERTICAL);		//Vertical sizer for main window
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);	//Horizontal sizer for main window

	//Add two textboxes to the panel for data display
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);	//Horizontal sizer for filename window
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);	//Horizontal sizer for display window
	
	wxStaticText *fileLabel 	  = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
	wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

	//Initialize the filename textbox window
	filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));
	
	//Initialize the display window
	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), 
				      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);
				      

	//Position the labels and textboxes in the panel
	hbox1->Add(fileLabel, 0, wxRIGHT, 8);
	hbox1->Add(filenameTextBox, 1);
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

	vbox->Add(-1, 10);
	hbox2->Add(displayLabel, 0);
	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
	vbox->Add(-1, 10);

	hbox3->Add(MainEditBox, 1, wxEXPAND);
	vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

	vbox->Add(-1, 25);
	panel->SetSizer(vbox);
}


/************************************************************************************
 *  Step 7:  Define member functions for the Frame class
 *************************************************************************************/


//===================================================================================
//=========== Definition for the File Functions =====================================
//===================================================================================

void MyFrame::OnOpenFile(wxCommandEvent& event )
{
	// Creates a "open file" dialog with 3 file types
	wxFileDialog *OpenDialog = new wxFileDialog( this, 
		(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
		(wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
               	 wxFD_OPEN, wxDefaultPosition);
 
	if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
	{
		  // Sets our current document to the file the user selected
		  CurrentDocPath = OpenDialog->GetPath();

		//Clean up filename textbox and Display file name in filename textbox 
		filenameTextBox->Clear();
		filenameTextBox->AppendText(CurrentDocPath);

		MainEditBox->LoadFile(CurrentDocPath);   //Opens that file in the MainEditBox

		// Set the Title
		SetTitle(wxString(wxT("COMP2115 - Pelican Travels Database")));
	}

}
 

void MyFrame::OnSave(wxCommandEvent& event )
{
	// Save to the already-set path for the document
	MainEditBox->SaveFile(CurrentDocPath);
}
   
void MyFrame::OnSaveAs(wxCommandEvent& event)
{
	wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), 
						    wxEmptyString, wxEmptyString,
						    (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
						    wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) 	// If the user clicked "OK"
	    {
		CurrentDocPath = SaveDialog->GetPath();

		// set the path of our current document to the file the user chose to save under
		MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

		// Set the Title to reflect the file open
		SetTitle(wxString(wxT("COMP2115 - Information Structures : 412002700")));
	    }
	    
} 
 
 
void MyFrame::OnDisplay(wxCommandEvent& event )
{
	// Creates a "open file" dialog with 4 file types
	wxFileDialog *OpenDialog = new wxFileDialog( this, (wxT("Choose a file to open")), 
				wxEmptyString, wxEmptyString,
				(wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
				wxFD_OPEN, wxDefaultPosition);

	MainEditBox->Clear();

	MainEditBox->LoadFile(CurrentDocPath); 
}
  
  
void MyFrame::OnExit(wxCommandEvent& event)
{
	wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE); // Close the window
}

    
void MyFrame::OnAbout(wxCommandEvent& event )
{
	wxMessageBox(wxT("Information Structures\n    Project"), wxT("About..."), wxOK | wxICON_INFORMATION, this);
}

    
//===================================================================================
//=========== Definition for the Queue Functions ====================================
//===================================================================================

void MyFrame::OnCreateQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the Queue
	queue->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}

	
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		//trim(nationality);
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"New Zealand"))
			{
			    queue->enqueue(rankNo,player,nationality,score,opponent,year);
			
			    record = makeRecord(rankNo, player, nationality, score, opponent, year);
			    record.append("\n");
			    
			    // Convert record into a wxString to display in the MainEditBox
			    wxString wxRecord(record.c_str(), wxConvUTF8);
			    MainEditBox->AppendText(wxRecord);
		      
			    record = "";
			    //MainEditBox->AppendText(wxT("\n\t"));         
			}
		}
        }  // End while
}

void MyFrame::OnEnqueueQue(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Queue Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			if(strstr(nationality.c_str(),"New Zealand"))
				queue->enqueue(rankNo,player,nationality,score,opponent,year);
			else
				wxMessageBox(wxT("Invalid Record in Queue"), wxT("Record..."), wxOK | wxICON_INFORMATION, this);
		      
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}	

void MyFrame::OnDequeueQue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = queue->dequeue();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from the Queue:\n\n"));
	MainEditBox->AppendText(wxVal);
}	

void MyFrame::OnDisplayQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = queue->displayAll();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnShowHeadQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = queue->getHead();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nFirst Record in Queue:\n\n"));
	MainEditBox->AppendText(wxVal);	  
}

void MyFrame::OnShowTailQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = queue->getTail();
		
      //Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nLast Record in Queue:\n\n"));
	MainEditBox->AppendText(wxVal);	  
}


//===================================================================================
//=========== Definition for the Deque Functions ====================================
//===================================================================================

void MyFrame::OnCreateDeque(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the Deque
	deque->purge(); 
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"West Indies"))
			{
				deque->insertFirst(rankNo,player,nationality,score,opponent,year);
			    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);
			  
				record = "";
			//MainEditBox->AppendText(wxT("\n\t"));
			}
			else if(strstr(opponent.c_str(),"West Indies"))
			{
				deque->insertLast(rankNo,player,nationality,score,opponent,year);
			    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);
			  
				record = "";
			//MainEditBox->AppendText(wxT("\n\t"));
			}
		}
        }  // End while
}	

void MyFrame::OnAddHead(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Deque Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			// ... Now send the data to the ADT. e.g
			// pq->enqueuePQ(idNo, firstname, lastname, period, yr, totNights, etc...);
			if(strstr(nationality.c_str(),"West Indies"))
				deque->insertFirst(rankNo,player,nationality,score,opponent,year);

		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}

void MyFrame::OnAddTail(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Deque Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			
			if(strstr(opponent.c_str(),"West Indies"))
    				deque->insertLast(rankNo,player,nationality,score,opponent,year);
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}

void MyFrame::OnDisplayDeque(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = deque->displayAll();
	
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Deque:\n\n"));
	MainEditBox->AppendText(wxVal);
}	

void MyFrame::OnShowHeadDeque(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = deque->first();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nFirst Record in Deque:\n\n"));
	MainEditBox->AppendText(wxVal);
}	

void MyFrame::OnShowTailDeque(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = deque->last();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nLast Records in Deque:\n\n"));
	MainEditBox->AppendText(wxVal);
}	

void MyFrame::OnDequeueHead(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = deque->removeFirst();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from the Deque:\n\n"));
	MainEditBox->AppendText(wxVal);

}	

void MyFrame::OnDequeueTail(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = deque->removeLast();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from the Deque:\n\n"));
	MainEditBox->AppendText(wxVal);
}


//===================================================================================
//=========== Definition for the Priority Queue Functions ===========================
//===================================================================================

void MyFrame::OnCreatePQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
	
	//Empty the Priority Queue
	pQueue->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);
	
	
	  
	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	
	
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			pQueue->enqueue(rankNo,player,nationality,score,opponent,year);
                    
			record = makeRecord(rankNo, player, nationality, score, opponent, year);
			record.append("\n");
			
			// Convert record into a wxString to display in the MainEditBox
			wxString wxRecord(record.c_str(), wxConvUTF8);
			MainEditBox->AppendText(wxRecord);
                  
			record = "";
			//MainEditBox->AppendText(wxT("\n\t"));
		}
        }  // End while

}

void MyFrame::OnEnqueuePQueue(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Priority Queue Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			// ... Now send the data to the ADT. e.g
			// pq->enqueuePQ(idNo, firstname, lastname, period, yr, totNights, etc...);
			pQueue->enqueue(rankNo,player,nationality,score,opponent,year);
			
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}	

void MyFrame::OnDequeuePQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = pQueue->dequeue();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from the Priority Queue:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDisplayPQueue(wxCommandEvent& event)
{
// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = pQueue->displayAll();
		
      //Convert to a wxString
      wxString wxVal(strVal.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Priority Queue:\n\n"));
      MainEditBox->AppendText(wxVal);
}	

void MyFrame::OnShowHeadPQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = pQueue->getHead();
		
      //Convert to a wxString
      wxString wxVal(strVal.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Priority Queue:\n\n"));
      MainEditBox->AppendText(wxVal);
  
}

void MyFrame::OnShowTailPQueue(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = pQueue->getTail();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Priority Queue:\n\n"));
	MainEditBox->AppendText(wxVal);
}


//===================================================================================
//=========== Definition for the Stack Functions ====================================
//===================================================================================

void MyFrame::OnCreateStack(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
	
	//Empty the stack
	stack->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"Sri Lanka") || strstr(nationality.c_str(),"Zimbabwe"))
			{
				stack->push(rankNo,player,nationality,score,opponent,year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
		}
        }  // End while
}

void MyFrame::OnDisplayStack(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = stack->displayAll();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Stack:\n\n"));
	MainEditBox->AppendText(wxVal);
}
  
void MyFrame::OnPushStack(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Stack Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			if(strstr(nationality.c_str(),"Sri Lanka") || strstr(nationality.c_str(),"Zimbabwe"))
				stack->push(rankNo,player,nationality,score,opponent,year);
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}
  
void MyFrame::OnPopStack(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = stack->pop();
		
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecord poped from the Stack:\n\n"));
	MainEditBox->AppendText(wxVal);
}
  
void MyFrame::OnShowHeadStack(wxCommandEvent& event)
{
// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = stack->getHead();
		
      //Convert to a wxString
      wxString wxVal(strVal.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nDisplay Record at Head of Stack:\n\n"));
      MainEditBox->AppendText(wxVal);
}
  
void MyFrame::OnShowTailStack(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
  
	string strVal = stack->getTail();
		
      //Convert to a wxString
      wxString wxVal(strVal.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nDisplay Record at Tail of Stack:\n\n"));
      MainEditBox->AppendText(wxVal);

}


//===================================================================================
//=========== Definition for the BS Tree Functions ==================================
//===================================================================================

void MyFrame::OnCreateBST(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  team;
	int     totRuns;
	string  oppTeam;
	int     yr;
	string  line;
	char    comma;
	
	string record, heading;
	
	//Empty the BST
	bst->purge();
      
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
          
	// Read off the heading line and discard it
	getline(infile, heading, '\n');
	
	
	while (!infile.eof())
	{
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, team, ',');
		infile >> totRuns >> comma;
		getline(infile, oppTeam, ',');
		infile >> yr;
		
		if (!infile.eof())
		{
			player  = strip(player);
			team    = strip(team);
			oppTeam = strip(oppTeam);
		}
		    
		      // Concatenate all the data into a string
		record = makeRecord(rankNo, player, team, totRuns, oppTeam, yr);
		record.append("\n");
            
		  // Insert the data into the BST
		bst->insert(rankNo, player, team, totRuns, oppTeam, yr);
         
		  // Convert record into a wxString to display in the MainEditBox
		wxString wxRecord(record.c_str(), wxConvUTF8);
		MainEditBox->AppendText(wxRecord);
                        
		  //Reset record variable
		record = "";
		   
	}  // End while

}

void MyFrame::OnAddBST(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("BS Tree Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			// ... Now send the data to the ADT. e.g
			// pq->enqueuePQ(idNo, firstname, lastname, period, yr, totNights, etc...);
			bst->insert(rankNo,player,nationality,score,opponent,year);
			
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();			//Destroy the dialog box
}

void MyFrame::OnDeleteBST(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete BS Tree Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			

			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			bst->remove(rankNo);
		}
		else
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnInorderBST(wxCommandEvent& event)
{
	string record;

	// Clear the edit box
	MainEditBox->Clear();
	
	MainEditBox->AppendText(wxT("\n\nInorder Traversal:\n\n"));

	// Get the Inorder data from the bST
	record = bst->inOrder();
	//record.append("\n");
            
        
	// Convert record into a wxString to display in the MainEditBox
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPreorderBST(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
//	string record = bst->Preorder();

	string record;
	record = bst->preOrder();
	
	MainEditBox->AppendText(wxT("\n\nPreorder Traversal:\n\n"));
	
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPostorderBST(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
	string record = bst->postOrder();
	MainEditBox->AppendText(wxT("\n\nPreorder Traversal:\n\n"));
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}


//===================================================================================
//=========== Definition for the AVL Tree Functions =================================
//===================================================================================

void MyFrame::OnCreateAVL(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the stack
	avl->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"Australia"))
			{
				avl->insert(rankNo,player,nationality,score,opponent,year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
		}
        }  // End while
}

void MyFrame::OnAddAVL(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("AVL Tree Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			
			if(strstr(nationality.c_str(),"Australia"))
				avl->insert(rankNo,player,nationality,score,opponent,year);
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box
}

void MyFrame::OnDeleteAVL(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete AVL Tree Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			avl->remove(rankNo);
		}
		else 
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnInorderAVL(wxCommandEvent& event)
{
	string record;

	// Clear the edit box
	MainEditBox->Clear();
	
	MainEditBox->AppendText(wxT("\n\nInorder Traversal:\n\n"));

	// Get the Inorder data from the bST
	record = avl->inOrder();
	//record.append("\n");
            
        
	// Convert record into a wxString to display in the MainEditBox
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPreorderAVL(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
//	string record = bst->Preorder();

	string record;
	record = avl->preOrder();
	
	MainEditBox->AppendText(wxT("\n\nPreorder Traversal:\n\n"));
	
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPostorderAVL(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
	string record = avl->postOrder();
	MainEditBox->AppendText(wxT("\n\nPostorder Traversal:\n\n"));
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}


//===================================================================================
//=========== Definition for the Heap Tree Functions ================================
//===================================================================================

void MyFrame::OnCreateHeap(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the Heap
	heap->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"South Africa"))
			{
				heap->addMinHeap(rankNo,player, nationality, score, opponent, year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
		}
        }  // End while 
}

void MyFrame::OnAddHeap(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Heap Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
			
			if(strstr(nationality.c_str(),"South Africa"))
				heap->addMinHeap(rankNo,player,nationality,score,opponent,year);
		    }

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();
}

void MyFrame::OnDeleteHeap(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete Heap Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			heap->deleteMinHeapVal(rankNo);
		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnDisplayHeap(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = heap->displayHeap();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Heap:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnSortHeap(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = heap->sortMinHeap();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Sorted Heap:\n\n"));
	MainEditBox->AppendText(wxVal);
}


//===================================================================================
//=========== Definition for the RB Tree Functions ==================================
//===================================================================================

void MyFrame::OnCreateRBTree(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the RB Tree
	rbTree->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"England"))
			{
				rbTree->insert(rankNo,player,nationality,score,opponent,year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
		}
        }  // End while
}

void MyFrame::OnAddRBTree(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("RB Tree Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
		
			if(strstr(nationality.c_str(),"England"))
				rbTree->insert(rankNo,player,nationality,score,opponent,year);
			
		}

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box

}

void MyFrame::OnDeleteRBTree(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete RB Tree Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			rbTree->remove(rankNo);
		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnInorderRBTree(wxCommandEvent& event)
{
	string record;

	// Clear the edit box
	MainEditBox->Clear();
	
	MainEditBox->AppendText(wxT("\n\nInorder Traversal:\n\n"));

	// Get the Inorder data from the bST
	record = rbTree->inOrder();
	//record.append("\n");
            
        
	// Convert record into a wxString to display in the MainEditBox
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPreorderRBTree(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
	string record;
	record = rbTree->preOrder();
	
	MainEditBox->AppendText(wxT("\n\nPreorder Traversal:\n\n"));
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPostorderRBTree(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
	string record = rbTree->postOrder();
	
	MainEditBox->AppendText(wxT("\n\nPostorder Traversal:\n\n"));
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}


//===================================================================================
//=========== Definition for the Splay Tree Functions ===============================
//===================================================================================

void MyFrame::OnCreateSplay(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the splay
	splay->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"India") || strstr(nationality.c_str(),"Pakistan"))
			{
				splay->insert(rankNo,player,nationality,score,opponent,year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
		}
        }  // End while
}

void MyFrame::OnAddSplay(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("AVL Tree Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
		
			if(strstr(nationality.c_str(),"India") || strstr(nationality.c_str(),"Pakistan"))
				splay->insert(rankNo,player,nationality,score,opponent,year);
    
		}

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();			//Destroy the dialog box

}

void MyFrame::OnDeleteSplay(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete RB Tree Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			splay->remove(rankNo);
		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnInorderSplay(wxCommandEvent& event)
{
	string record;

	// Clear the edit box
	MainEditBox->Clear();
	
	MainEditBox->AppendText(wxT("\n\nInorder Traversal:\n\n"));

	// Get the Inorder data from the bST
	record = splay->inOrder();
	//record.append("\n");
            
        
	// Convert record into a wxString to display in the MainEditBox
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPreorderSplay(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
//	string record = bst->Preorder();

	string record;
	record = splay->preOrder();
	
	MainEditBox->AppendText(wxT("\n\nPreorder Traversal:\n\n"));
	
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnPostorderSplay(wxCommandEvent& event)
{
	MainEditBox->Clear();
	
	string record = splay->postOrder();
	MainEditBox->AppendText(wxT("\n\nPostorder Traversal:\n\n"));
	wxString wxRecord(record.c_str(), wxConvUTF8);
	MainEditBox->AppendText(wxRecord);
}


//===================================================================================
//=========== Definition for the Set Functions ======================================
//===================================================================================

void MyFrame::OnCreateSet(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
	
	int     rankNo;
	string  player;
	string  nationality;
	int     score;
	string  opponent;
	int     year;
	string  line;
	char    comma;
	
	string record, heading;
      
	//Empty the sets
	setA->purge();
	setB->purge();
	
	//open the file
	ifstream infile(CurrentDocPath.mb_str(), ios::in);

	// Check to see if a valid file was opened.
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
		return;
	}
	  
        while (!infile.eof())
        {
		infile  >> rankNo >> comma;
		getline(infile, player, ',');
		getline(infile, nationality, ',');
		infile >> score >> comma;
		getline(infile, opponent, ',');
		infile >> year;
	
		if (!infile.eof())
		{
			if(strstr(nationality.c_str(),"West Indies") && (year < 1981))
			{
				setA->add(rankNo,player, nationality, score, opponent, year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}
			else if(strstr(nationality.c_str(),"West Indies") && (year > 1980))
			{
				setB->add(rankNo,player, nationality, score, opponent, year);
    
				record = makeRecord(rankNo, player, nationality, score, opponent, year);
				record.append("\n");
				
				// Convert record into a wxString to display in the MainEditBox
				wxString wxRecord(record.c_str(), wxConvUTF8);
				MainEditBox->AppendText(wxRecord);

				record = ""; 
			}  
		}
        }  // End while 
}

void MyFrame::OnAddSet(wxCommandEvent& event)
{
	Record dataRec;
		
		DialogBox *dialogBox = new DialogBox( wxT("Set Record Entry"), 
						      wxPoint(200,200), wxSize(600,200) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		    {
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
		
			//Grab value from the NameBox.
			dataRec.name = dialogBox->NameEditBox->GetValue();
			
			
			//Grab value from the IDNoBox
			dataRec.score = dialogBox->ScoreEditBox->GetValue();
			
			// Grab the year
			dataRec.year = dialogBox->YearEditBox->GetValue();
			

			//Grab the list item selected
			dataRec.nationality 	= dialogBox->NationalityCombo->GetValue();
			dataRec.opponent 	= dialogBox->OpponentCombo->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			//   You need to disaggregate the data from dataRec to
			//   send them to your ADTs. e.g.:
			int    rankNo 	 	= dataRec.rank;
			string player 	 	= string(dataRec.name.mb_str());
			string nationality	= string(dataRec.nationality.mb_str());;
			int    score		= dataRec.score;
			string opponent		= string(dataRec.opponent.mb_str());;			
			int    year		= dataRec.year;
			
		
			if(strstr(nationality.c_str(),"West Indies") && (year < 1981))
				setA->add(rankNo,player, nationality, score, opponent, year);			
			else
			  if(strstr(nationality.c_str(),"West Indies") && (year > 1980))
				setB->add(rankNo,player, nationality, score, opponent, year);
    
		}

		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
 
		dialogBox->Destroy();	
}

void MyFrame::OnDisplaySetA(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = setA->displaySet();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in SetA:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDisplaySetB(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	string strVal = setB->displaySet();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in SetB:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDisplayIntersection(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	setC->intersectionSet(setA, setB);
	string strVal = setC->displaySet();
	
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Intersection:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDisplayUnion(wxCommandEvent& event)
{
	// Clear the edit box
	MainEditBox->Clear();
      
	setC->unionSet(setA, setB);
	string strVal = setC->displaySet();
	
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Union:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDeleteSetA(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete SetA Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			setA->remove(rankNo);
		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}

void MyFrame::OnDeleteSetB(wxCommandEvent& event)
{
	Rec dataRec;
		
		DelDialog *dialogBox = new DelDialog( wxT("Delete SetB Record"), 
						      wxPoint(200,200), wxSize(200,120) );

		// If the OK button is clicked...
		if (dialogBox->ShowModal() == wxID_OK )
		{
			//Grab value from the RankBox
			dataRec.rank = dialogBox->RankEditBox->GetValue();
			
			
			//Clear the main edit box and display the record just grabbed
			MainEditBox->Clear();
			
			MainEditBox->AppendText(getDataString(dataRec));

			int    rankNo 	 = dataRec.rank;
			
			setB->remove(rankNo);
		}
		else 			 //if (dialogBox->ShowModal() == wxID_CANCEL)
			 dialogBox->Close();
			    
		dialogBox->Destroy();
}
