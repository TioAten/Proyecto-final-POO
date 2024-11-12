///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFB_PROJECT_H__
#define __WXFB_PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/srchctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/dialog.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePrincipal
///////////////////////////////////////////////////////////////////////////////
class BasePrincipal : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_ST_Buscar;
		wxSearchCtrl* m_BarraBusqueda;
		wxButton* m_b_Buscar;
		wxGrid* m_grilla;
		wxButton* m_b_prestar;
		wxButton* m_b_devolver;
		wxButton* m_b_agregar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonPrestar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonDevolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BasePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 653,697 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~BasePrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregar
///////////////////////////////////////////////////////////////////////////////
class BaseAgregar : public wxDialog 
{
	private:
	
	protected:
		wxRadioButton* m_r_Libro;
		wxRadioButton* m_r_Revista;
		wxRadioButton* m_r_Video;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_t_titulo;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_t_autor;
		wxStaticText* m_staticText32;
		wxTextCtrl* m_t_ind;
		wxButton* m_button5;
		wxButton* m_button6;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BaseAgregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 538,223 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~BaseAgregar();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class BasePrestar
///////////////////////////////////////////////////////////////////////////////
class BasePrestar : public wxDialog 
{
	private:
	
	protected:
		wxComboBox* m_comboRecurso;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_t_Nombre;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_t_Apellido;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_t_nSocio;
		wxButton* m_button8;
		wxButton* m_button7;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BasePrestar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 644,331 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~BasePrestar();
	
};

#endif //__WXFB_PROJECT_H__
