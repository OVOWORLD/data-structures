/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif

#include <fstream> 
#include <string> 

using namespace std;

// Other miscellaneous functions' protypes
//string to_string(int);
string strip(string);
string makeRecord(int, string, string, int, string, int);
string to_string(int x);
  /*{
    ostringstream convert;
    convert << x;
    return convert.str();
  }*/


#include "queue.h"
#include "deque.h"
#include "PriorityQueue.h"
#include "stack.h"
#include "RBTree.h"  
#include "BSTree.h"
#include "AVLTree.h"
#include "BinHeap.h"
#include "RBTree.h" 
#include "SplayTree.h"
#include "Set.h"



//Global pointers for the ADT containers
Queue* qList = new Queue();
Stack* sList = new Stack();
PriorityQueue* pqList = new PriorityQueue();
Deque* dList = new Deque();
BSTree* BSTList = new BSTree();
AVL* AVLList = new AVL();
RBT* RBTList = new RBT();
SplayTree* STList = new SplayTree();
BinHeap* BHList = new BinHeap();
Set* AList = new Set();
Set* BList = new Set();
Set* CList = new Set();


/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with 
      the function to execute the program                    
*************************************************************************************
*************************************************************************************/
class MyApp: public wxApp
  {
     virtual bool OnInit();
  };

  
  
  
  
/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class 
       also will ALL the events handlers be declared    
*************************************************************************************
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
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);    
        void OnExit(wxCommandEvent& event);     //handle for Quit function
        
        //Functions for Queue Menu Items
        void OnCreateQueue(wxCommandEvent& event);
        void OnDisplayQueue(wxCommandEvent& event);
        void OnShowHeadQueue(wxCommandEvent& event);
        void OnShowTailQueue(wxCommandEvent& event);
        void OnDequeueQueue(wxCommandEvent& event);
        
	
	//Functions for Priority Queue Menu Items
	void OnCreatePQ(wxCommandEvent& event);
	void OnDisplayPQ(wxCommandEvent& event);
        void OnShowHeadPQ(wxCommandEvent& event);
	void OnShowTailPQ(wxCommandEvent& event);
	void OnDequeuePQ(wxCommandEvent& event);
	
	//Functions for Deque Menu Items
	void OnCreateDeque(wxCommandEvent& event);
	void OnDisplayDeque(wxCommandEvent& event);
	void OnShowHeadDeque(wxCommandEvent& event);
	void OnShowTailDeque(wxCommandEvent& event);
	void OnDequeueHeadDeque(wxCommandEvent& event);
	void OnDequeueTailDeque(wxCommandEvent& event);
	void OnEnqueueHeadDeque(wxCommandEvent& event);
	void OnEnqueueTailDeque(wxCommandEvent& event);
	
	//Functions for Stack Menu Items
	void OnCreateStack(wxCommandEvent& event);
	void OnPushStack(wxCommandEvent& event);
	void OnPopStack(wxCommandEvent& event);
	void OnDisplayStack(wxCommandEvent& event);
	void OnShowHeadStack(wxCommandEvent& event);
	void OnShowTailStack(wxCommandEvent& event);
	
	//Function for the Help About Menu Item
	void OnAbout(wxCommandEvent& event);
	
        //Functions for Binary search Tree Menu Items
	void OnCreateBST(wxCommandEvent& event);
	void OnAddDataBST(wxCommandEvent& event);
	void OnDeleteDataBST(wxCommandEvent& event);
	void OnPreOrderBST(wxCommandEvent& event);
	void OnPostOrderBST(wxCommandEvent& event);
	void OnInOrderBST(wxCommandEvent& event);
	
        //Functions for AVL Tree Menu Items
	void OnCreateAVL(wxCommandEvent& event);
	void OnAddDataAVL(wxCommandEvent& event);
	void OnDeleteDataAVL(wxCommandEvent& event);
	void OnPreOrderAVL(wxCommandEvent& event);
	void OnPostOrderAVL(wxCommandEvent& event);
	void OnInOrderAVL(wxCommandEvent& event);
	
	//Functions for Heap Menu Items
	void OnCreateHeap(wxCommandEvent& event);
	void OnAddDataHeap(wxCommandEvent& event);
	void OnDeleteDataHeap(wxCommandEvent& event);
	void OnDisplayAll(wxCommandEvent& event);
	void OnHeapSort(wxCommandEvent& event);
	
	
	//Functions for Red-Black Tree Menu Items
	void OnCreateRBT(wxCommandEvent& event);
	void OnAddDataRBT(wxCommandEvent& event);
	void OnDeleteDataRBT(wxCommandEvent& event);
	void OnPreOrderRBT(wxCommandEvent& event);
	void OnPostOrderRBT(wxCommandEvent& event);
	void OnInOrderRBT(wxCommandEvent& event);
	
	//Funtions for Splay Tree Menu Items
	void OnCreateSplay(wxCommandEvent& event);
	void OnAddDataSplay(wxCommandEvent& event);
	void OnDeleteDataSplay(wxCommandEvent& event);
	void OnPreOrderSplay(wxCommandEvent& event);
	void OnPostOrderSplay(wxCommandEvent& event);
	void OnInOrderSplay(wxCommandEvent& event);
	
	//Functions for Set Menu Items
        void OnCreateSet(wxCommandEvent& event);
	void OnAddDataSet(wxCommandEvent& event);
	void OnDisplaySetA(wxCommandEvent& event);
	void OnDisplaySetB(wxCommandEvent& event);
	void OnDisplayIntersection(wxCommandEvent& event);
	void OnDisplayUnion(wxCommandEvent& event);
	void OnDeleteSetA(wxCommandEvent& event);
	void OnDeleteSetB(wxCommandEvent& event);
	
        //Public attributes
        wxTextCtrl* MainEditBox;
        wxTextCtrl* filenameTextBox;
        wxString CurrentDocPath;    // The Path to the file we have open
        
  };

 
  
/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives                    
*************************************************************************************
*************************************************************************************/
DECLARE_APP(MyApp)        // Declare Application class
IMPLEMENT_APP(MyApp)      // Create Application class object
  

enum
    {
          // File menu items
    ID_OpenFile  = wxID_HIGHEST + 1,        //File menu item
    ID_Display,
    ID_Save,
    ID_SaveAs,
    ID_Exit,
      
    
    // Queue menu items
    ID_CreateQueue,
    ID_DisplayQueue,
    ID_ShowHeadQueue,
    ID_ShowTailQueue,
    ID_DequeueQueue,

    // Priority Queue menu items
    ID_CreatePQ,
    ID_DisplayPQ,
    ID_ShowHeadPQ,
    ID_ShowTailPQ,
    ID_DequeuePQ,
    
    // Deque menu items
    ID_CreateDeque,
    ID_DisplayDeque,
    ID_ShowHeadDeque,
    ID_ShowTailDeque,
    ID_DequeueHeadDeque,
    ID_DequeueTailDeque,
    ID_EnqueueHeadDeque,
    ID_EnqueueTailDeque,
    
    //Stack menu items
    ID_CreateStack,
    ID_PushStack,
    ID_PopStack,
    ID_DisplayStack,
    ID_ShowHeadStack,
    ID_ShowTailStack,
    
    //BST menu items
    ID_CreateBST,
    ID_AddDataBST,
    ID_DeleteDataBST,
    ID_PreOrderBST,
    ID_PostOrderBST,
    ID_InOrderBST,
    
    //AVL menu items
    ID_CreateAVL,
    ID_AddDataAVL,
    ID_DeleteDataAVL,
    ID_PreOrderAVL,
    ID_PostOrderAVL,
    ID_InOrderAVL,
    
    //Heap menu
    ID_CreateHeap,
    ID_AddDataHeap,
    ID_DeleteDataHeap,
    ID_DisplayAll,
    ID_HeapSort,
    
    //RBT menu items
    ID_CreateRBT,
    ID_AddDataRBT,
    ID_DeleteDataRBT,
    ID_PreOrderRBT,
    ID_PostOrderRBT,
    ID_InOrderRBT,
    
    //Splay Tree menu items
    ID_CreateSplay,
    ID_AddDataSplay,
    ID_DeleteDataSplay,
    ID_PreOrderSplay,
    ID_PostOrderSplay,
    ID_InOrderSplay,
    
    // Set menu items
    ID_CreateSet,
    ID_AddDataSet,
    ID_DisplaySetA,
    ID_DisplaySetB,
    ID_DisplayIntersection,
    ID_DisplayUnion,
    ID_DeleteSetA,
    ID_DeleteSetB,
    
    ID_About,
    
    };

    
    
BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile,   MyFrame::OnOpenFile )   //File Menu 
      EVT_MENU ( ID_Display,    MyFrame::OnDisplay )
      EVT_MENU ( ID_Save,       MyFrame::OnSave )
      EVT_MENU ( ID_SaveAs,     MyFrame::OnSaveAs )
      EVT_MENU ( ID_Exit,       MyFrame::OnExit )
    
        
      // Events for the "Queue" menu items
      EVT_MENU ( ID_CreateQueue,    MyFrame::OnCreateQueue)
      EVT_MENU ( ID_DisplayQueue,   MyFrame::OnDisplayQueue)
      EVT_MENU ( ID_ShowHeadQueue,  MyFrame::OnShowHeadQueue)
      EVT_MENU ( ID_ShowTailQueue,  MyFrame::OnShowTailQueue)
      EVT_MENU ( ID_DequeueQueue,   MyFrame::OnDequeueQueue)
      
      //Events for the "Priority Queue" menu items
      EVT_MENU ( ID_CreatePQ,    MyFrame::OnCreatePQ)
      EVT_MENU ( ID_DisplayPQ,   MyFrame::OnDisplayPQ)
      EVT_MENU ( ID_ShowHeadPQ,  MyFrame::OnShowHeadPQ)
      EVT_MENU ( ID_ShowTailPQ,  MyFrame::OnShowTailPQ)
      EVT_MENU ( ID_DequeuePQ,   MyFrame::OnDequeuePQ)

      //Events for the "Deque" menu items
     EVT_MENU ( ID_CreateDeque,    MyFrame::OnCreateDeque)
     EVT_MENU ( ID_DisplayDeque,    MyFrame::OnDisplayDeque)
     EVT_MENU ( ID_ShowHeadDeque,    MyFrame::OnShowHeadDeque)
     EVT_MENU ( ID_ShowTailDeque,    MyFrame::OnShowTailDeque)
     EVT_MENU ( ID_DequeueHeadDeque,    MyFrame::OnDequeueHeadDeque)
     EVT_MENU ( ID_DequeueTailDeque,    MyFrame::OnDequeueTailDeque)
     EVT_MENU ( ID_EnqueueHeadDeque,    MyFrame::OnEnqueueHeadDeque)
     EVT_MENU ( ID_EnqueueTailDeque,    MyFrame::OnEnqueueTailDeque)
     
     //Events for the "Stack" menu items
     EVT_MENU ( ID_CreateStack,    MyFrame::OnCreateStack)
     EVT_MENU ( ID_PushStack,    MyFrame::OnPushStack)
     EVT_MENU ( ID_PopStack,    MyFrame::OnPopStack)
     EVT_MENU ( ID_DisplayStack,    MyFrame::OnDisplayStack)
     EVT_MENU ( ID_ShowHeadStack,    MyFrame::OnShowHeadStack)
     EVT_MENU ( ID_ShowTailStack,    MyFrame::OnShowTailStack)
     
     //Events for the "BST Tree" menu items
     EVT_MENU ( ID_CreateBST,    MyFrame::OnCreateBST)
     EVT_MENU ( ID_AddDataBST,    MyFrame::OnAddDataBST)
     EVT_MENU ( ID_DeleteDataBST,    MyFrame::OnDeleteDataBST)
     EVT_MENU ( ID_PreOrderBST,    MyFrame::OnPreOrderBST)
     EVT_MENU ( ID_PostOrderBST,    MyFrame::OnPostOrderBST)
     EVT_MENU ( ID_InOrderBST,    MyFrame::OnInOrderBST)
     
     //Events for the "AVL Tree" menu items
     EVT_MENU ( ID_CreateAVL,    MyFrame::OnCreateAVL)
     EVT_MENU ( ID_AddDataAVL,    MyFrame::OnAddDataAVL)
     EVT_MENU ( ID_DeleteDataAVL,    MyFrame::OnDeleteDataAVL)
     EVT_MENU ( ID_PreOrderAVL,    MyFrame::OnPreOrderAVL)
     EVT_MENU ( ID_PostOrderAVL,    MyFrame::OnPostOrderAVL)
     EVT_MENU ( ID_InOrderAVL,    MyFrame::OnInOrderAVL)
     
     //Events for the "Heap" menu items
     EVT_MENU(ID_CreateHeap, MyFrame::OnCreateHeap)
     EVT_MENU(ID_AddDataHeap, MyFrame::OnAddDataHeap)
     EVT_MENU(ID_DeleteDataHeap, MyFrame::OnDeleteDataHeap)
     EVT_MENU(ID_DisplayAll, MyFrame::OnDisplayAll)
     EVT_MENU( ID_HeapSort, MyFrame::OnHeapSort)
     
    
     //Events for the "Red-Black Tree" menu items
     EVT_MENU ( ID_CreateRBT,    MyFrame::OnCreateRBT)
     EVT_MENU ( ID_AddDataRBT,    MyFrame::OnAddDataRBT)
     EVT_MENU ( ID_DeleteDataRBT,    MyFrame::OnDeleteDataRBT)
     EVT_MENU ( ID_PreOrderRBT,    MyFrame::OnPreOrderRBT)
     EVT_MENU ( ID_PostOrderRBT,    MyFrame::OnPostOrderRBT)
     EVT_MENU ( ID_InOrderRBT,    MyFrame::OnInOrderRBT)
     
     //Events for the "Splay Tree" menu items
     EVT_MENU ( ID_CreateSplay,    MyFrame::OnCreateSplay)
     EVT_MENU ( ID_AddDataSplay,    MyFrame::OnAddDataSplay)
     EVT_MENU ( ID_DeleteDataSplay,    MyFrame::OnDeleteDataSplay)
     EVT_MENU ( ID_PreOrderSplay,    MyFrame::OnPreOrderSplay)
     EVT_MENU ( ID_PostOrderSplay,    MyFrame::OnPostOrderSplay)
     EVT_MENU ( ID_InOrderSplay,    MyFrame::OnInOrderSplay)
     
     //Events for the "Set" menu items
     EVT_MENU ( ID_CreateSet,    MyFrame::OnCreateSet)
     EVT_MENU ( ID_AddDataSet,    MyFrame::OnAddDataSet)
     EVT_MENU ( ID_DisplaySetA,    MyFrame::OnDisplaySetA)
     EVT_MENU ( ID_DisplaySetB,    MyFrame::OnDisplaySetB)
     EVT_MENU ( ID_DisplayIntersection,    MyFrame::OnDisplayIntersection)
     EVT_MENU ( ID_DisplayUnion,    MyFrame::OnDisplayUnion)
     EVT_MENU ( ID_DeleteSetA,    MyFrame::OnDeleteSetA)
     EVT_MENU ( ID_DeleteSetB,    MyFrame::OnDeleteSetB)
     
     //Events for the about help menu items
     EVT_MENU (ID_About, MyFrame::OnAbout)
     
END_EVENT_TABLE () 
  




/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool MyApp::OnInit()
  {
      // Create the main application window
      MyFrame *frame = new MyFrame( wxT("COMP2611 - Data Structures"), 
                    wxPoint(50,50), 
                    wxSize(840,600) );

      // Display the window
      frame->Show(TRUE);
    
      SetTopWindow(frame);

      return TRUE;

  }
  
  
  

/************************************************************************************
*************************************************************************************
  Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
MyFrame::MyFrame ( const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame((wxFrame *)NULL, -1, title, pos, size)
  {
    // Set the frame icon - optional
    SetIcon(wxIcon(wxT("cricket.xpm")));

    
    
    // Create the main-menu items
    wxMenu *menuFile  =   new wxMenu;
    wxMenu *menuQueue =   new wxMenu;
    wxMenu *menuPQ    =   new wxMenu;
    wxMenu *menuDeque =   new wxMenu;
    wxMenu *menuStack =   new wxMenu;
    wxMenu *menuBST   =   new wxMenu;
    wxMenu *menuAVL   =   new wxMenu;
    wxMenu *menuHeap  =   new wxMenu;
    wxMenu *menuRBT   =   new wxMenu;
    wxMenu *menuSplay =   new wxMenu;
    wxMenu *menuSet   =   new wxMenu;
    wxMenu *menuHelp  =   new wxMenu;
    
    //Create a Main menu bar
    wxMenuBar *menuBar = new wxMenuBar;
        
    
    //Append the main menu items to the Menu Bar
    menuBar->Append( menuFile,   wxT("File") );
    menuBar->Append( menuQueue,  wxT("Queue") );
    menuBar->Append( menuPQ,     wxT("Priority Queue") );
    menuBar->Append( menuDeque,  wxT("Deque") );
    menuBar->Append( menuStack,  wxT("Stack") );    
    menuBar->Append( menuBST,    wxT("BST") );
    menuBar->Append( menuAVL,    wxT("AVL Tree") );
    menuBar->Append( menuHeap,   wxT("Heap") );
    menuBar->Append( menuRBT,    wxT("Red-Black Tree") );
    menuBar->Append( menuSplay,  wxT("Splay Tree") );
    menuBar->Append( menuSet,    wxT("Set") );
    menuBar->Append( menuHelp,   wxT("Help") );
    
    
    //Append the sub-menu items to the File Main Menu item
    menuFile->Append( ID_OpenFile,  wxT("&Open File..."),   wxT("Open an Existing file") );
    menuFile->Append( ID_Display,   wxT("&Display File..."),wxT("Display contents of opened file") );
    menuFile->Append( ID_Save,      wxT("&Save"),           wxT("Save opened file") );
    menuFile->Append( ID_SaveAs,    wxT("Save &As..."),     wxT("Save display as a new file") );
    menuFile->Append( ID_Exit,      wxT("E&xit"),           wxT("Close and EXIT Program") );
    
    
    
    //Append the sub-menu items to the Queue Main Menu item
    menuQueue->Append( ID_CreateQueue,   wxT("Create Queue"), wxT("Create the Queue") );
    menuQueue->Append( ID_DisplayQueue,  wxT("Display All"),  wxT("Display ALL records") );
    menuQueue->Append( ID_ShowHeadQueue, wxT("Show Head"),    wxT("Show record at head") );
    menuQueue->Append( ID_ShowTailQueue, wxT("Show Tail"),    wxT("Show record at tail") );
    menuQueue->Append( ID_DequeueQueue,  wxT("Dequeue"),      wxT("Remove record from head") );
    
    //Append the sub-menu items to the Priority Queue Main Menu item
    menuPQ->Append( ID_CreatePQ,   wxT("Create PQ"), wxT("Create the  Priority Queue") );
    menuPQ->Append( ID_DisplayPQ,  wxT("Display All"),  wxT("Display ALL records") );
    menuPQ->Append( ID_ShowHeadPQ, wxT("Show Head"),    wxT("Show record at head") );
    menuPQ->Append( ID_ShowTailPQ, wxT("Show Tail"),    wxT("Show record at tail") );
    menuPQ->Append( ID_DequeuePQ,  wxT("Dequeue"),      wxT("Remove record from head") );
    
    //Append the sub-menu items to the Deque Main Menu item
    menuDeque->Append( ID_CreateDeque,   wxT("Create Deque"), wxT("Create the Deque") );
    menuDeque->Append( ID_DisplayDeque,  wxT("Display All"),  wxT("Display ALL records") );
    menuDeque->Append( ID_ShowHeadDeque, wxT("Show Head"),    wxT("Show record at head") );
    menuDeque->Append( ID_ShowTailDeque, wxT("Show Tail"),    wxT("Show record at tail") );
    menuDeque->Append( ID_DequeueHeadDeque,  wxT("Dequeue Head"),      wxT("Remove record from head") );
    menuDeque->Append( ID_DequeueTailDeque,  wxT("Dequeue Tail"),      wxT("Remove record from tail") );
    menuDeque->Append( ID_EnqueueHeadDeque,  wxT("Enqueue Head"),      wxT("Add record to head") );
    menuDeque->Append( ID_EnqueueTailDeque,  wxT("Enqueue Tail"),      wxT("Add record to tail") );
    
    //Append the sub-menu items to the Stack Main Menu item
    menuStack->Append( ID_CreateStack,   wxT("Create Stack"), wxT("Create the Stack") );
    menuStack->Append( ID_PushStack,     wxT("Push"),       wxT("Add record to the tail") );
    menuStack->Append( ID_PopStack,      wxT("Pop"),        wxT("Remove record from head") );
    menuStack->Append( ID_DisplayStack,  wxT("Display All"),    wxT("Display All records") );
    menuStack->Append( ID_ShowHeadStack, wxT("Show Head"),    wxT("Show record at Head") );
    menuStack->Append( ID_ShowTailStack, wxT("Show Tail"),      wxT("Show record at Tail") );
    
    //Append the sub-menu items to the BST Tree Main Menu item
     menuBST->Append( ID_CreateBST,   wxT("Create BST"), wxT("Create the BST Tree") );
     menuBST->Append( ID_AddDataBST,   wxT("Add Data"), wxT("Add to the BST Tree") );
     menuBST->Append( ID_DeleteDataBST,   wxT("Delete Data"), wxT("Delete from the BST Tree") );
     menuBST->Append( ID_PreOrderBST,   wxT("PreOrder BST Tree"), wxT("PreOrder Traversal") );
     menuBST->Append( ID_PostOrderBST,   wxT("PostOrder BST Tree"), wxT("PostOrder Traversal") );
     menuBST->Append( ID_InOrderBST,   wxT("InOrder BST Tree"), wxT("InOrder Traversal") );
     
      //Append the sub-menu items to the AVL Tree Main Menu item
     menuAVL->Append( ID_CreateAVL,   wxT("Create AVL"), wxT("Create the AVL Tree") );
     menuAVL->Append( ID_AddDataAVL,   wxT("Add Data"), wxT("Add to the AVL Tree") );
     menuAVL->Append( ID_DeleteDataAVL,   wxT("Delete Data"), wxT("Delete from the AVL Tree") );
     menuAVL->Append( ID_PreOrderAVL,   wxT("PreOrder AVL Tree"), wxT("PreOrder Traversal") );
     menuAVL->Append( ID_PostOrderAVL,   wxT("PostOrder AVL Tree"), wxT("PostOrder Traversal") );
     menuAVL->Append( ID_InOrderAVL,   wxT("InOrder AVL Tree"), wxT("InOrder Traversal") );
     
     //Append the sub-menu items to the Heap Main Menu item
     menuHeap->Append( ID_CreateHeap,   wxT("Create Heap"), wxT("Create the Binary heap") );
     menuHeap->Append( ID_AddDataHeap,   wxT("Add Data"), wxT("Add to the Binary heap") );
     menuHeap->Append( ID_DeleteDataHeap,   wxT("Delete Data"), wxT("Delete from the Binary Heap") );
     menuHeap->Append( ID_DisplayAll,   wxT("display All"), wxT("display All from the Heap") );
     menuHeap->Append( ID_HeapSort,   wxT("Binary Heap sort"), wxT("Binary Heap") );
     
     //Append the sub-menu items to the RBT Tree Main Menu item
     menuRBT->Append( ID_CreateRBT,   wxT("Create RBT"), wxT("Create the RBT Tree") );
     menuRBT->Append( ID_AddDataRBT,   wxT("Add Data"), wxT("Add to the RBT Tree") );
     menuRBT->Append( ID_DeleteDataRBT,   wxT("Delete Data"), wxT("Delete from the RBT Tree") );
     menuRBT->Append( ID_PreOrderRBT,   wxT("PreOrder"), wxT("PreOrder Traversal") );
     menuRBT->Append( ID_PostOrderRBT,   wxT("PostOrder"), wxT("PostOrder Traversal") );
     menuRBT->Append( ID_InOrderRBT,   wxT("InOrder"), wxT("InOrder Traversal") );
     
     //Append the sub-menu items to the Splay Tree Main Menu item
     menuSplay->Append( ID_CreateSplay,   wxT("Create Splay"), wxT("Create the Splay Tree") );
     menuSplay->Append( ID_AddDataSplay,   wxT("Add Data"), wxT("Add to the Splay Tree") );
     menuSplay->Append( ID_DeleteDataSplay,   wxT("Delete Data"), wxT("Delete from the Splay Tree") );
     menuSplay->Append( ID_PreOrderSplay,   wxT("PreOrder"), wxT("PreOrder Traversal") );
     menuSplay->Append( ID_PostOrderSplay,   wxT("PostOrder"), wxT("PostOrder Traversal") );
     menuSplay->Append( ID_InOrderSplay,   wxT("InOrder"), wxT("InOrder Traversal") );
     
     //Append the sub-menu items to the Splay Tree Main Menu item
     menuSet ->Append( ID_CreateSet, wxT("Create Set"), wxT("Create the Set") );
     menuSet ->Append( ID_AddDataSet, wxT("Add Data"), wxT("Add to the Set") );
     menuSet ->Append( ID_DisplaySetA, wxT("Display SetA"), wxT("Display SetA") );
     menuSet ->Append( ID_DisplaySetB, wxT("Display SetB"), wxT("Display Set B") );
     menuSet ->Append( ID_DisplayIntersection, wxT("Display Intersection"), wxT("Display the Intersection") );
     menuSet ->Append( ID_DisplayUnion, wxT("Display Union"), wxT("Display the Union ") );
     menuSet ->Append( ID_DeleteSetA, wxT("Delete SetA"), wxT("Delete SetA") );
     menuSet ->Append( ID_DeleteSetB, wxT("Delete SetB"), wxT("Delete SetB") );
     
    //Append the sub-menu items to the Help Main Menu item
    menuHelp->Append( ID_About, wxT("About"),      wxT("About Help") );
    
    // ... and now... attach this main menu bar to the frame
    SetMenuBar( menuBar );
        
    // Create a status bar just for fun
    CreateStatusBar(3);
        
    //Put something in the first section of the status bar
    SetStatusText( wxT("Ready...") );
    
    //Put something in the Second section of the status bar
    SetStatusText( wxT("Nirisi Marshall"), 1 );
    
    //Put something in the Third section of the status bar
    SetStatusText( wxT("417002395"), 2 );
    
    
    
    
    //Set up the panel for data display
//===============================================================================
//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================    
//===============================================================================

    wxPanel     *panel     = new wxPanel(this, -1);
    wxBoxSizer  *vbox      = new wxBoxSizer(wxVERTICAL);        //Vertical sizer for main window
    wxBoxSizer  *hbox1     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for main window

    //Add two textboxes to the panel for data display
    wxBoxSizer  *hbox2     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for filename window
    wxBoxSizer  *hbox3     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for display window
    
    wxStaticText *fileLabel     = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
    wxStaticText *displayLabel     = new wxStaticText(panel, wxID_ANY, wxT("Display"));

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

    Centre();
    
  }


//============+++======================================================
//=========== Other Support Functions =================================
//=====================================================================
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

    
  
string makeRecord(int rankNo, string player, string team, int totRuns, 
                  string oppTeam, int yr)
                                
    {
        string record;
        
        record.append(to_string(rankNo));
        record.append(" \t\t");
        record.append(player);
        record.append(" \t");
        record.append(team);
        record.append(" \t");
        record.append(to_string(totRuns));
        record.append("  \t\t");
        record.append(oppTeam);
        record.append(" \t");
        record.append(to_string(yr));
        
        return record;
    }
  
  
  
string to_string ( int number )
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
  
 
  
/**************************************************************************
***************************************************************************
  Step 7:  Define member functions for the Frame class
***************************************************************************
***************************************************************************/

//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================

void MyFrame::OnOpenFile(wxCommandEvent& event )
    {
           // Creates a "open file" dialog with 3 file types
        wxFileDialog *OpenDialog = new wxFileDialog( this, 
            (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
             (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);
 
        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
        {
            // Sets our current document to the file the user selected
            CurrentDocPath = OpenDialog->GetPath();

            //Clean up filename textbox and Display file name in filename textbox 
            filenameTextBox->Clear();
            filenameTextBox->AppendText(CurrentDocPath);

            MainEditBox->LoadFile(CurrentDocPath);   //Opens that file in the MainEditBox

            // Set the Title
            SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
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
        if (SaveDialog->ShowModal() == wxID_OK)     // If the user clicked "OK"
            {
                CurrentDocPath = SaveDialog->GetPath();

                // set the path of our current document to the file the user chose to save under
                MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

                // Set the Title to reflect the file open
                SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
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



    
  
  
//=============================================================================
//============== Definition for the Queue Functions ===========================
//=============================================================================

void MyFrame::OnCreateQueue(wxCommandEvent& event)
  {
        int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();

    //Empty the Deque
    // dq->purgeQueue();   // Write that function!
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "New Zealand"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Enqueued\n");
                                qList->enqueue(rankNo, player, team, totRuns, oppTeam, yr);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
    }



void MyFrame::OnDisplayQueue(wxCommandEvent& event)
  {
      // Clear the edit box
      MainEditBox->Clear();     

      string records = qList->displayAll();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
  
  }


void MyFrame::OnShowHeadQueue(wxCommandEvent& event)
{
        // Clear the edit box
      MainEditBox->Clear();     

      string record = qList->showHead();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}


void MyFrame::OnShowTailQueue(wxCommandEvent& event)
{
      // Clear the edit box
      MainEditBox->Clear();     

      string record = qList->showTail();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
      MainEditBox->AppendText(wxRecord);
}


void MyFrame::OnDequeueQueue(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();  

      string record = qList->dequeue();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the Priority Functions ===========================
//=============================================================================

void MyFrame::OnCreatePQ(wxCommandEvent& event)
{
        int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        /*if(strstr(team.c_str(), "New Zealand"))
                            {*/
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Enqueued\n");
                                pqList->enqueue(rankNo, player, team, totRuns, oppTeam, yr);
                            //}
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnDisplayPQ(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = pqList->displayAll();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Priority Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
      
      MainEditBox->ShowPosition(0);
      MainEditBox->SetSelection(0,0);
}

void MyFrame::OnShowHeadPQ(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string record = pqList->showHead();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnShowTailPQ(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string record = pqList->showTail();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnDequeuePQ(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();  

      string record = pqList->dequeue();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the Deque Functions ===========================
//=============================================================================

void MyFrame::OnCreateDeque(wxCommandEvent& event)
{
   int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();

    //Empty the Deque
    // dq->purgeQueue();   // Write that function!
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "West Indies"))
                            {
                               //Enter at the head
			      record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Enqueued\n");
                                dList->enqueueHead(rankNo, player, team, totRuns, oppTeam, yr);
                            }
                            
                        if(strstr(oppTeam.c_str(), "West Indies"))
                            {
                               //Enter at the tail
			      record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Enqueued\n");
                                dList->enqueueTail(rankNo, player, team, totRuns, oppTeam, yr);
			    }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnDisplayDeque(wxCommandEvent& event)
{
  MainEditBox->Clear();     

      string records = dList->displayAll();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnShowHeadDeque(wxCommandEvent& event)
{
   MainEditBox->Clear();     

      string record = dList->showHead();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnShowTailDeque(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string record = dList->showTail();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnDequeueHeadDeque(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();  

      string record = dList->dequeueHead();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnDequeueTailDeque(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();  

      string record = dList->dequeueTail();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnEnqueueHeadDeque(wxCommandEvent& event)
{
  
}

void MyFrame::OnEnqueueTailDeque(wxCommandEvent& event)
{
  
}

//=============================================================================
//============== Definition for the Stack Functions ===========================
//=============================================================================

void MyFrame::OnCreateStack(wxCommandEvent& event)
{
        int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();

      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "Zimbabwe") || strstr(team.c_str(), "Sri Lanka"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Pushed\n");
                                sList->push(rankNo, player, team, totRuns, oppTeam, yr);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnPushStack(wxCommandEvent& event)
{
  
}

void MyFrame::OnPopStack(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();  

      string record = sList->pop();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord removed from Head:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

void MyFrame::OnDisplayStack(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string records = sList->displayAll();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Stack:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnShowHeadStack(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string record = sList->showHead();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Head:\n\n"));
      MainEditBox->AppendText(wxRecord);

}

void MyFrame::OnShowTailStack(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string record = sList->showTail();
        
      //Convert to a wxString
      wxString wxRecord(record.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecord in Tail:\n\n"));
      MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the BST Tree Functions ===========================
//=============================================================================

void MyFrame::OnCreateBST(wxCommandEvent& event)
{
  int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                        
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                record.append("\t\t...Inserted\n");
				
                                BSTList->insert(rankNo, player, team, totRuns, oppTeam, yr);
                            
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    
            }  // End while
}

void MyFrame::OnAddDataBST(wxCommandEvent& event)
{
  BSTList->insert( 2, "Chris Gayle", "West Indies", 376, "Pakistan", 2003);
  
}


void MyFrame::OnDeleteDataBST(wxCommandEvent& event)
{
  BSTList->remove(1);
}

void MyFrame::OnPreOrderBST(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string records = BSTList->preOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnPostOrderBST(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = BSTList->postOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);

}

void MyFrame::OnInOrderBST(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = BSTList->inOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

//=============================================================================
//============== Definition for the AVL Tree Functions ===========================
//=============================================================================

void MyFrame::OnCreateAVL(wxCommandEvent& event)
{
  int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "Australia"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                AVLList->insert(rankNo);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnAddDataAVL(wxCommandEvent& event)
{
  AVLList->insert(120);
}


void MyFrame::OnDeleteDataAVL(wxCommandEvent& event)
{
  AVLList->remove(100);
}


void MyFrame::OnPreOrderAVL(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string records = AVLList->preOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnPostOrderAVL(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = AVLList->postOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);

}

void MyFrame::OnInOrderAVL(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = AVLList->inOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

//=============================================================================
//============== Definition for the Binary Heap Functions ===========================
//=============================================================================
void MyFrame::OnCreateHeap(wxCommandEvent& event)
{
 int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "South Africa"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                BHList->addMinHeap(rankNo);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnAddDataHeap(wxCommandEvent& event)
{
  BHList-> addMinHeap(30);
}


void MyFrame::OnDeleteDataHeap(wxCommandEvent& event)
{
  BHList-> deleteMinHeapVal(30);
}


void MyFrame::OnDisplayAll(wxCommandEvent& event)
{
   // Clear the edit box
	MainEditBox->Clear();
      
	string strVal = BHList->displayHeap();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Heap:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnHeapSort(wxCommandEvent& event)
{
  // Clear the edit box
	MainEditBox->Clear();
      
	string strVal = BHList->sortMinHeap();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Sorted Heap:\n\n"));
	MainEditBox->AppendText(wxVal);

}





//=============================================================================
//============== Definition for the RBT Tree Functions ===========================
//=============================================================================
void MyFrame::OnCreateRBT(wxCommandEvent& event)
{
  int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "England"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                RBTList->insert(rankNo);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnAddDataRBT(wxCommandEvent& event)
{
  RBTList->insert(25);
}


void MyFrame::OnDeleteDataRBT(wxCommandEvent& event)
{
  RBTList->remove(98);
}


void MyFrame::OnPreOrderRBT(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string records = RBTList->preOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnPostOrderRBT(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = RBTList->postOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);

}

void MyFrame::OnInOrderRBT(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = RBTList->inOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

//=============================================================================
//============== Definition for the Splay Tree Functions ===========================
//=============================================================================
void MyFrame::OnCreateSplay(wxCommandEvent& event)
{
  int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "India") || strstr(team.c_str(), "Pakistan"))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                STList->Insert(rankNo);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
            }  // End while
}

void MyFrame::OnAddDataSplay(wxCommandEvent& event)
{
  STList->Insert(54);
}


void MyFrame::OnDeleteDataSplay(wxCommandEvent& event)
{
  //STList->remove(54);
}


void MyFrame::OnPreOrderSplay(wxCommandEvent& event)
{
   // Clear the edit box
      MainEditBox->Clear();     

      string records = STList->PreOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

void MyFrame::OnPostOrderSplay(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = STList->PostOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);

}

void MyFrame::OnInOrderSplay(wxCommandEvent& event)
{
  // Clear the edit box
      MainEditBox->Clear();     

      string records = STList->InOrder();
        
      //Convert to a wxString
      wxString wxRecords(records.c_str(), wxConvUTF8);

      //display the words in the MainEditBox
      MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Queue:\n\n"));
      MainEditBox->AppendText(wxRecords);
}

//=============================================================================
//============== Definition for the Set Functions ===========================
//=============================================================================
void MyFrame::OnCreateSet(wxCommandEvent& event)
{
  int     rankNo;
        string  player;
        string  team;
        int     totRuns;
        string  oppTeam;
        int     yr;
        string  line;
        char    comma;

        string record, heading;
        
    // Clear the edit box
    MainEditBox->Clear();
      
    //open the file
    ifstream infile(CurrentDocPath.mb_str(), ios::in);

    // Check to see if a valid file was opened.
    if (!infile)
      {
          MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
      }
    
        // Read off the heading line
        getline(infile, heading, '\n');
  
        // Create a label for the displayed records
        heading = "Rank \tName \t\t\tNationality \t\tScore \t\tOpponent \t\tYear\n";
        heading.append("=====================================================\n");

        
        // Convert "heading" into a wxString and display it in the MainEditBox
        wxString headingLine(heading.c_str(), wxConvUTF8);
        MainEditBox->AppendText(headingLine);


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
                    
                        // Test to see if the substring "West Indies" is in the team variable
                        if(strstr(team.c_str(), "West Indies") && (yr < 1981))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                AList->add(rankNo);
                            }
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
                    }
                    else if (strstr(team.c_str(), "West Indies") && (yr > 1980))
                            {
                                record = makeRecord(rankNo, player,team, totRuns, oppTeam, yr);
                                
                                record.append("\t\t...Inserted\n");
                                BList->add(rankNo);
                            
                                                
                        wxString wxRecord(record.c_str(), wxConvUTF8);
                        MainEditBox->AppendText(wxRecord);
                        
                        //Reset record variable
                        record = "";
	    }
            }  // End while

}

void MyFrame::OnAddDataSet(wxCommandEvent& event)
{
 
AList->add(15);
BList->add(20);
}

void MyFrame::OnDisplaySetA(wxCommandEvent& event)
{
  // Clear the edit box
	MainEditBox->Clear();
      
	string strVal = AList->displaySet();

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
      
	string strVal = BList->displaySet();

	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in SetA:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDisplayIntersection(wxCommandEvent& event)
{
  // Clear the edit box
	MainEditBox->Clear();
      
	CList->intersectionSet(AList, BList);
	string strVal = CList->displaySet();
	
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
      
	CList->intersectionSet(AList, BList);
	string strVal = CList->displaySet();
	
	//Convert to a wxString
	wxString wxVal(strVal.c_str(), wxConvUTF8);

	//display the words in the MainEditBox
	MainEditBox->AppendText(wxT("\t\t\t\t\nRecords in Intersection:\n\n"));
	MainEditBox->AppendText(wxVal);
}

void MyFrame::OnDeleteSetA(wxCommandEvent& event)
{
  
}

void MyFrame::OnDeleteSetB(wxCommandEvent& event)
{
  
}




void MyFrame::OnAbout(wxCommandEvent& event)
{
  
}
