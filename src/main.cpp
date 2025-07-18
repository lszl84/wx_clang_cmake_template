#include <wx/settings.h>
#include <wx/wx.h>

class MyApp : public wxApp {
public:
    MyApp() { }
    bool OnInit() wxOVERRIDE;
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    MyFrame* frame = new MyFrame("Hello wxWidgets!");
    frame->Show(true);

    return true;
}


MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
  
}


