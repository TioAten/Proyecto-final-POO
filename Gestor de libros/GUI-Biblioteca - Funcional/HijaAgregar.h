#ifndef HIJAAGREGAR_H
#define HIJAAGREGAR_H
#include "wxfb_project.h"
#include "GestorBiblioteca.h"

class HijaAgregar : public BaseAgregar {
	
private:
	Gestor *m_gestor;
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
	
public:
	HijaAgregar(wxWindow *parent, Gestor *gestor);
};

#endif

