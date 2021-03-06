#include <wx/wx.h>

/**
   A frame that contains a text control.
*/
class TextFrame : public wxFrame
{
public:
   /**
      Constructs the text control.
   */
   TextFrame();
private:
   wxTextCtrl* text;
};

/**
   An application that shows a frame with a text control.
*/
class TextApp : public wxApp
{
public:
   /**
      Constructs and shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   TextFrame* frame;
};

DECLARE_APP(TextApp)

IMPLEMENT_APP(TextApp)

TextFrame::TextFrame() 
   : wxFrame(NULL, -1, "TextFrame")
{
   text = new wxTextCtrl(this, -1, "Type some text here!",
      wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
}

bool TextApp::OnInit()
{
   frame = new TextFrame();
   frame->Show(true);
   return true;
}
