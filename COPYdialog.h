#ifndef MYDELDIALOG_H
#define MYDELDIALOG_H
//#include "DialogBox.h"

struct rec
{
	int    rank;
};
typedef struct rec Rec;

  
//Define a dialog box class with 5 data fields (Attributes) - inheriting from wxDialog, of course 
class DelDialog: public wxDialog
{
	public:
		DelDialog(const wxString& title, const wxPoint& pos, const wxSize& size);		
		
		wxSpinCtrl* RankEditBox;
};


DelDialog::DelDialog ( const wxString& title, const wxPoint& pos, 
		   const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
		//Set up the panel
		wxPanel    *panel = new wxPanel(this, -1);
 
		//Define and position the StaticTexts - ie the labels
		wxStaticText 	*rankLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Rank"), wxPoint(15, 35) );
		  
		//Define and position the Data Boxes
		RankEditBox = new wxSpinCtrl(panel, -1, wxT("1"), wxPoint(80, 30), 
					     wxSize(100, -1), wxSP_ARROW_KEYS, 1,
					     999, 1);
		
		
		// The OK button
		wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), 
					    wxPoint(15, 80), wxDefaultSize, 0);

		// The CANCEL button
		wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
						  wxPoint(110, 80), wxDefaultSize, 0 );
		
		// Centre the dialog on the parent's window
		Centre();

        	Maximize(); // Maximize the window	
}


wxString getDataString(Rec dataRec)
{
	wxString str = wxT("\n\n");
    
	wxString rankNo;
	rankNo << dataRec.rank;
	str.Append(rankNo);
	str.Append(wxT("\n"));
	
	return str;
}
#endif
