#include "HijaAgregar.h"
#include "Persona.h"
#include <string>
#include <wx/string.h>
#include "Recurso.h"
#include "Libro.h"
#include "Revista.h"
#include "Video.h"
#include "GestorBiblioteca.h"
#include <regex>
#include <wx/msgdlg.h>

using namespace std;


// Utiliza la biblioteca de expresiones 'regex' para definir un patr�n que representa el formato 'ISBN'.
bool Validar_Formato(const string& isbn) {
	// Expresi�n rgular para verificar el formato del ISBN.
	regex formatoISBN("^\\d{3}-\\d{10}$");
	
	/*
		'^': Coincide con el inicio de la cadena.
		'\\d{3}': Coincide con tres d�gitos num�ricos.
		'-': Coincide con el guion.
		'\\d{10}': Coincide con diez d�gitos num�ricos.
		'$': Coincide con el final de la cadena.
	*/
	
	// Devuelve true si el formato es v�lido, false en caso constraio.
	return regex_match(isbn, formatoISBN);
}

auto esNumero = [](const string& str) {
	try {
		stoi(str);
		return true;
	} catch (const std::invalid_argument& e) {
		return false;
	}
};

HijaAgregar::HijaAgregar(wxWindow *parent, Gestor *gestor) : BaseAgregar(parent), m_gestor(gestor) {
	
}

void HijaAgregar::ClickAceptar( wxCommandEvent& event )  {
	Recurso* n_recurso = nullptr;
	
	string titulo = m_t_titulo->GetValue().ToStdString();
	string autor = m_t_autor->GetValue().ToStdString();
	string dato_extra = m_t_ind->GetValue().ToStdString();
	
	/* 'try-catch' para manejar excepciones.
		'try': Se coloca el cogico que puede tirar un excepci�n.
		'catch': Bloque que se ejecutacuando se produce una excepci�n en 'try'.
		'(const invalid_argumentn&/exception& e)': Expecifica el tipo de excepci�n.
	*/
	
	try {
		
		if (titulo.empty() || autor.empty() || dato_extra.empty()) {
			wxMessageBox("Por favor, complete todos los campos", "Error", wxICON_ERROR | wxOK);
			return;
		}
		
		if (m_r_Libro->GetValue() && Validar_Formato(dato_extra)) {
			n_recurso = new Libro(titulo, autor, dato_extra);
		} else if (m_r_Revista->GetValue() && esNumero(dato_extra)) {
			n_recurso = new Revista(titulo, autor, dato_extra);
		} else if (m_r_Video->GetValue() && esNumero(dato_extra)) {
			n_recurso = new Video(titulo, autor, stoi(dato_extra));
		} else {
			wxMessageBox("Formato de recurso no v�lido.", "Error", wxICON_ERROR | wxOK);
			return;
		}
		
		m_gestor->Add_Recurso(n_recurso);

	}catch(const exception& e) {
		// Maneja cualquier excepci�n no especificada anteriormente
		wxMessageBox("Ocurri� un error al procesar la informaci�n.", "Error", wxICON_ERROR | wxOK);
		return;
	};
	
	EndModal(1);
}

void HijaAgregar::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

