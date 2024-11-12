///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

BasePrincipal::BasePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_ST_Buscar = new wxStaticText( this, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ST_Buscar->Wrap( -1 );
	bSizer2->Add( m_ST_Buscar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BarraBusqueda = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_BarraBusqueda->ShowSearchButton( true );
	#endif
	m_BarraBusqueda->ShowCancelButton( false );
	bSizer2->Add( m_BarraBusqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_b_Buscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_b_Buscar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grilla->CreateGrid( 0, 5 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );
	
	// Columns
	m_grilla->SetColSize( 0, 125 );
	m_grilla->SetColSize( 1, 125 );
	m_grilla->SetColSize( 2, 125 );
	m_grilla->SetColSize( 3, 125 );
	m_grilla->SetColSize( 4, 125 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelSize( 30 );
	m_grilla->SetColLabelValue( 0, wxT("Titúlo") );
	m_grilla->SetColLabelValue( 1, wxT("Autor") );
	m_grilla->SetColLabelValue( 2, wxT("ISBN/Nro/Duración") );
	m_grilla->SetColLabelValue( 3, wxT("Propietario") );
	m_grilla->SetColLabelValue( 4, wxT("Nro. Socio") );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grilla->AutoSizeRows();
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer1->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_b_prestar = new wxButton( this, wxID_ANY, wxT("Prestar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_b_prestar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_b_devolver = new wxButton( this, wxID_ANY, wxT("Devolver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_b_devolver, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_b_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_b_agregar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_b_Buscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonBuscar ), NULL, this );
	m_b_prestar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonPrestar ), NULL, this );
	m_b_devolver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonDevolver ), NULL, this );
	m_b_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAgregar ), NULL, this );
}

BasePrincipal::~BasePrincipal()
{
	// Disconnect Events
	m_b_Buscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonBuscar ), NULL, this );
	m_b_prestar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonPrestar ), NULL, this );
	m_b_devolver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonDevolver ), NULL, this );
	m_b_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAgregar ), NULL, this );
	
}

BaseAgregar::BaseAgregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_r_Libro = new wxRadioButton( this, wxID_ANY, wxT("Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_r_Libro, 0, wxALL, 5 );
	
	m_r_Revista = new wxRadioButton( this, wxID_ANY, wxT("Revista"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_r_Revista, 0, wxALL, 5 );
	
	m_r_Video = new wxRadioButton( this, wxID_ANY, wxT("Video"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_r_Video, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer9, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Titulo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer5->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_titulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_t_titulo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Autor:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer51->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_autor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( m_t_autor, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("ISBN/Nro/Duración:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer52->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_ind = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( m_t_ind, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer52, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button5 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer6, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickAceptar ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickCancelar ), NULL, this );
}

BaseAgregar::~BaseAgregar()
{
	// Disconnect Events
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickAceptar ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickCancelar ), NULL, this );
	
}

BasePrestar::BasePrestar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	m_comboRecurso = new wxComboBox( this, wxID_ANY, wxT("Recurso"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer13->Add( m_comboRecurso, 0, wxALL, 5 );
	
	
	bSizer16->Add( bSizer13, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Nombre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer11->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_t_Nombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Apellido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer12->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_Apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_t_Apellido, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Nro. Socio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer15->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_t_nSocio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_t_nSocio, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );
	
	
	bSizer16->Add( bSizer14, 1, wxEXPAND, 5 );
	
	
	bSizer10->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button8, 0, wxALL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button7, 0, wxALL, 5 );
	
	
	bSizer10->Add( bSizer17, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestar::ClickAceptar ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestar::ClickCancelar ), NULL, this );
}

BasePrestar::~BasePrestar()
{
	// Disconnect Events
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestar::ClickAceptar ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestar::ClickCancelar ), NULL, this );
	
}
