#include "HijaPrincipal.h"
#include "GestorBiblioteca.h"
#include "Libro.h"
#include "Revista.h"
#include "Video.h"
#include "Persona.h"
#include "HijaAgregar.h"
#include <wx/msgdlg.h>
#include <string>

#include <sstream>
#include "HijaPrestar.h"
using namespace std;

HijaPrincipal::HijaPrincipal(Gestor *gestor) : BasePrincipal(nullptr), m_gestor (gestor)
{
	Refrescar_Grilla();
}

void HijaPrincipal::Refrescar_Grilla() {
	
	if ( m_grilla->GetNumberRows() != 0 )
		m_grilla->DeleteRows( 0,m_grilla->GetNumberRows() );
	for ( int i = 0; i < m_gestor->Cant_Datos(); i++ ) {
		Recurso *r = m_gestor->Indice_Recurso(i);
		
		m_grilla->AppendRows();
		
		m_grilla->SetCellValue(i, 0, r->Get_Titulo());
		m_grilla->SetCellValue(i, 1, r->Get_Autor());
		
		/* 'dynamic_cast< >( )' Es una operación de casting dinámico que intenta convertir el puntero 'r'
		al tipo 'Libro*'. Si 'r' es un puntero 'Libro' devolvera un puntero tipo 'Libro*'. Si no un puntero 'nullptr'.*/

		if ( dynamic_cast<Libro *>(r) != nullptr )
			m_grilla->SetCellValue(i, 2, dynamic_cast<Libro *>(r)->Get_isbn());
		else if (dynamic_cast<Revista *>(r) != nullptr)
			m_grilla->SetCellValue(i, 2, dynamic_cast<Revista *>(r)->Get_numero());
		else if (dynamic_cast<Video *>(r) != nullptr)
			m_grilla->SetCellValue(i, 2, dynamic_cast<Video *>(r)->Get_Duracion());
		
		if (r->Esta_Prestado()) {
			Persona *propietario = r->get_persona();
			string aux = propietario->get_nom() + " " + propietario->get_ape();
			cout << aux << endl; // Variable auxiliar usada para pruebas cuando ocurrió un error ya solucionado.
			m_grilla->SetCellValue(i, 3, aux);
			m_grilla->SetCellValue(i, 4, propietario->get_NsocioS());
		}
		else {
			m_grilla->SetCellValue(i, 3, "");
			m_grilla->SetCellValue(i, 4, "");
		}
	}
}

/// @brief Botón devolver de la ventana principal.
/// @param event Toma la pocisión de la casilla selecionada y convierte el atributo 'm_persona' a 'nullptr'.
void HijaPrincipal::ClickBotonDevolver( wxCommandEvent& event )  {
	int f = m_grilla->GetGridCursorRow();
	
	int YES_NO = wxMessageBox("�Esta seguro?", "Advertencia", wxYES_NO | wxICON_QUESTION);
	
	
	if (YES_NO == wxYES) {
		Recurso* recurso = m_gestor->Indice_Recurso(f);
		m_gestor->Devolver_Recurso(recurso);
		m_gestor->Save_Recurso();
		Refrescar_Grilla();
	}
}

/// @brief Botón 'Buscar' de la pantalla principal.
/// @param event Realiza una buscqueda en base al parametro ingresado en la barra de búsqueda..
void HijaPrincipal::ClickBotonBuscar(wxCommandEvent& event) {
	
	// Obtener el texto ingresado por el usuario.
	string parametro = m_BarraBusqueda->GetValue().ToStdString();

	// Limpiar grilla antes de realizar la b�squeda.
	m_grilla->ClearGrid();

	if ( parametro.empty() )
		Refrescar_Grilla();
	else {
		if (m_grilla->GetNumberRows() != 0)
			m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
		
		m_gestor->Find_Recurso(parametro);
		for ( int i = 0; i < m_gestor->Get_cnt_of_Find(); i++ ) {
			// Realizar la b�squeda y actualizar la grilla
			index = m_gestor->Find_Recurso( parametro );
			if ( index != -1 ) {
				Recurso* r = m_gestor->Indice_Recurso(m_gestor->Get_Indices( i ));
				// Agregar una nueva fila a la grilla
				m_grilla->AppendRows();
				// Configurar las celdas de la grilla con los datos del recurso
				m_grilla->SetCellValue(i, 0, r->Get_Titulo());
				m_grilla->SetCellValue(i, 1, r->Get_Autor());

				if (dynamic_cast<Libro*>(r) != nullptr)
					m_grilla->SetCellValue(i, 2, dynamic_cast<Libro*>(r)->Get_isbn());
				else if (dynamic_cast<Revista*>(r) != nullptr)
					m_grilla->SetCellValue(i, 2, dynamic_cast<Revista*>(r)->Get_numero());
				else if (dynamic_cast<Video*>(r) != nullptr)
					m_grilla->SetCellValue(i, 2, dynamic_cast<Video*>(r)->Get_Duracion());

				if (r->Esta_Prestado()) {
					Persona* propietario = r->get_persona();
					m_grilla->SetCellValue(i, 3, propietario->get_nom_completo());
					m_grilla->SetCellValue(i, 4, propietario->get_NsocioS());
				} else {
					m_grilla->SetCellValue(i, 3, "");
					m_grilla->SetCellValue(i, 4, "");
				}
			}
		}
		m_gestor->Clear_Indices();
	}
}


/// @brief Botón 'Prestar' de la pantalla principal. Se debe limpiar el vector y volverlo a cargar debido que había un error con la memoría al momento de hacer click en aceptar.
/// @param event Abre la ventana Dialog para prestar un recurso en base a los datos ingresado en la misma.
void HijaPrincipal::ClickBotonPrestar( wxCommandEvent& event )  {
	HijaPrestar *win = new HijaPrestar(this, m_gestor);
	
	if (win->ShowModal() == 1){
		m_gestor->Clear_Vector(); // Limpia el vector 'recursos'.
		m_gestor->Load_Recurso(); // Carga el vector 'recursos' con los datos guardados en el archivo '.bin'.
		Refrescar_Grilla();
	}
}

/// @brief Botón 'Agregar' de la pantalla principal.
/// @param event Abre la ventana de dialogo para agregar un nuevo recurso.
void HijaPrincipal::ClickBotonAgregar( wxCommandEvent& event )  {
	HijaAgregar *win = new HijaAgregar(this, m_gestor);
	
	if (win->ShowModal() == 1){
		m_gestor->Save_Recurso();
		Refrescar_Grilla();
	}
}

