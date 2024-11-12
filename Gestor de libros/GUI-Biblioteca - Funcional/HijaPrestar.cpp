#include "HijaPrestar.h"
#include "Recurso.h"
#include "Libro.h"
#include "Revista.h"
#include "Video.h"
#include "Persona.h"
#include <wx/msgdlg.h>
#include <string>

using namespace std;

HijaPrestar::HijaPrestar(wxWindow *parent, Gestor *gestor) : BasePrestar(parent), m_gestor(gestor) {
	for ( int i = 0; i < m_gestor->Cant_Datos(); i++ ) {
		Recurso* r = m_gestor->Indice_Recurso(i);
		// Rellena al comboBox con con los nombres de los recursos.
		m_comboRecurso->Append( r->Get_Titulo() );
	}
}

void HijaPrestar::ClickAceptar(wxCommandEvent& event) {
	
	string valorOfBusqueda = string(m_comboRecurso->GetStringSelection().mb_str());
	string nombre = string(m_t_Nombre->GetValue().mb_str());
	string apellido = string(m_t_Apellido->GetValue().mb_str());
	string aux = string(m_t_nSocio->GetValue().mb_str());
	int nSocio = stoi(aux);
	
	if ( nombre.empty() || apellido.empty() || !(nSocio != 0) || valorOfBusqueda.empty() ) {
		wxMessageBox("Por favor, complete todos los campos correctamente.", "Error", wxOK | wxICON_ERROR);
		return;
	}
	
	Persona p( nombre, apellido, nSocio );

	Recurso* r = Buscar(valorOfBusqueda);
	
	m_gestor->Prestar_Recurso(r, &p);
	
	m_gestor->Save_Recurso();
	
	EndModal( 1 );
}


void HijaPrestar::ClickCancelar( wxCommandEvent& event )  {
	EndModal( 0 );
}

Recurso* HijaPrestar::Buscar (const string& titulo) {
	Recurso* recursoBuscado = nullptr;
	
	/* Toma el parametro string y lo compara con el nombre del recurso en la pocisión 'i' del vector.
	Luego retorna la pocisión en memoria. */
	for ( int i = 0; i < m_gestor->Cant_Datos() ; i++ ) {
		recursoBuscado = m_gestor->Indice_Recurso(i);
		
		if ( recursoBuscado->Get_Titulo() == titulo)
			return recursoBuscado;
	}
	
	return nullptr;
}
