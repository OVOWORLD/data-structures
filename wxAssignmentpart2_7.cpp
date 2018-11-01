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
#include "stack.h"
#include "PriorityQueue.h"


//Global pointers for the ADT containers
Queue* qList = new Queue();
Stack* sList = new Stack();
PriorityQueue* pqList = new PriorityQueue();





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
        void OnEnqueueQueue(wxCommandEvent& event);
	
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
  
}

void MyFrame::OnDisplayDeque(wxCommandEvent& event)
{
  
}

void MyFrame::OnShowHeadDeque(wxCommandEvent& event)
{
  
}

void MyFrame::OnShowTailDeque(wxCommandEvent& event)
{
  
}

void MyFrame::OnDequeueHeadDeque(wxCommandEvent& event)
{
  
}

void MyFrame::OnDequeueTailDeque(wxCommandEvent& event)
{
  
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
                                
                                record.append("\t\t...Enqueued\n");
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

void MyFrame::OnAbout(wxCommandEvent& event)
{
  
}
