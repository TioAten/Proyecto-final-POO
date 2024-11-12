#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H

#include "wxfb_project.h"
#include "GestorBiblioteca.h"

class HijaPrincipal : public BasePrincipal {
	private:
		int index;
	protected:
		void ClickBotonBuscar( wxCommandEvent& event )  override;
		void ClickBotonPrestar( wxCommandEvent& event )  override;
		void ClickBotonAgregar( wxCommandEvent& event )  override;
		void ClickBotonDevolver( wxCommandEvent& event )  override;
		Gestor* m_gestor;
	
	public:
		HijaPrincipal(Gestor *gestor);
		
		void Refrescar_Grilla();
};

#endif

