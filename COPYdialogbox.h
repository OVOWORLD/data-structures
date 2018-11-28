#ifndef MYDIALOG_H
#define MYDIALOG_H

 
struct record
{
	int    rank;
	wxString name;
	wxString nationality;
	int    score;
	wxString opponent;
	int    year;
};
typedef struct record Record;

   
  
//Define a dialog box class with 5 data fields (Attributes) - inheriting from wxDialog, of course 
class DialogBox: public wxDialog
{
	public:
		DialogBox(const wxString& title, const wxPoint& pos, const wxSize& size);
		
		wxTextCtrl* NameEditBox;
		
		wxSpinCtrl* RankEditBox;
		wxSpinCtrl* ScoreEditBox;
		wxSpinCtrl* YearEditBox;
		
		wxComboBox* NationalityCombo;		//For a drop-down list
		wxComboBox* OpponentCombo;
		
};

  
DialogBox::DialogBox ( const wxString& title, const wxPoint& pos, 
		   const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
{
		//Set up the panel
		wxPanel    *panel = new wxPanel(this, -1);
 
		//Define and position the StaticTexts - ie the labels
		wxStaticText 	*rankLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Rank"), wxPoint(15, 35) );
		wxStaticText 	*nameLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Name"), wxPoint(15, 70) );
		wxStaticText 	*nationalityLabel 	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Nationality"), wxPoint(15, 105) );
		wxStaticText 	*scoreLabel = new wxStaticText(panel, wxID_ANY, 
						  wxT("Score"), wxPoint(325, 35) );
		
		wxStaticText 	*opponentLabel	= new wxStaticText(panel, wxID_ANY, 
						  wxT("Opponent"), wxPoint(325, 70) );
		wxStaticText 	*yearLabel = new wxStaticText(panel, wxID_ANY, 
						  wxT("Year"), wxPoint(325, 105) );			
		//Define and position the Data Boxes
		RankEditBox = new wxSpinCtrl(panel, -1, wxT("1"), wxPoint(100, 35), 
					     wxSize(100, -1), wxSP_ARROW_KEYS, 1, 
					     999, 1);		
		
		NameEditBox 	=  new wxTextCtrl ( panel, wxID_ANY, wxT("Name"), 
						    wxPoint(100, 70), wxSize(170, -1) );
		
		ScoreEditBox	= new wxSpinCtrl(panel, -1, wxT("1"), wxPoint(400, 35), 
						wxSize(100, -1), wxSP_ARROW_KEYS, 0, 
						1000, 1);	
			
		YearEditBox	=  new wxSpinCtrl(panel, -1, wxT("2017"), wxPoint(400, 105), 
						  wxSize(80, -1), wxSP_ARROW_KEYS, 1990, 
						  2020, 1);	
			
		
		//Define and position a drop-down list for trip purpose
		wxArrayString nationality;
		nationality.Add(wxT("Australia"));
		nationality.Add(wxT("England"));
		nationality.Add(wxT("India"));
		nationality.Add(wxT("New Zealand"));		
		nationality.Add(wxT("Pakistan"));
		nationality.Add(wxT("South Africa"));
		nationality.Add(wxT("Sri Lanka"));
		nationality.Add(wxT("West Indies"));
		nationality.Add(wxT("Zimbabwe"));
		nationality.Add(wxT("Other"));
		NationalityCombo = new wxComboBox(panel, -1, wxT("Australia"), wxPoint(100, 105), 
					      wxSize(120, -1), nationality, wxCB_READONLY);	
		
		//Define and position a drop-down list for Season
		wxArrayString opponent;
		opponent.Add(wxT("Australia"));
		opponent.Add(wxT("England"));
		opponent.Add(wxT("India"));
		opponent.Add(wxT("New Zealand"));		
		opponent.Add(wxT("Pakistan"));
		opponent.Add(wxT("South Africa"));
		opponent.Add(wxT("Sri Lanka"));
		opponent.Add(wxT("West Indies"));
		opponent.Add(wxT("Zimbabwe"));
		opponent.Add(wxT("Other"));
		OpponentCombo = new wxComboBox(panel, -1, wxT("Australia"), wxPoint(400, 70), 
					      wxSize(120, -1), opponent, wxCB_READONLY);	
		
		
		// Define and position the Response buttons (OK and CANCEL)
		
		// The OK button
		wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), 
					    wxPoint(200, 150), wxDefaultSize, 0);

		// The CANCEL button
		wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
						  wxPoint(330, 150), wxDefaultSize, 0 );
		
		// Centre the dialog on the parent's window
		Centre();

        	Maximize(); // Maximize the window
}


wxString getDataString(Record dataRec)
{
	wxString str = wxT("\n\n");
    
	wxString rankNo, yr, Score;
	rankNo << dataRec.rank;
	str.Append(rankNo);
	str.Append(wxT("\t"));
	str.Append(dataRec.name);
	str.Append(wxT("\t"));
	str.Append(dataRec.nationality);
	str.Append(wxT("\t"));
	Score << dataRec.score;
	str.Append(Score);
	str.Append(wxT("\t"));
	str.Append(dataRec.opponent);
	str.Append(wxT("\t"));
	yr << dataRec.year;
	str.Append(yr);
	str.Append(wxT("\n"));
	
	return str;
}
#endif
