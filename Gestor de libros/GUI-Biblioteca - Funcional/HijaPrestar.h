#ifndef HIJAPRESTAR_H
#define HIJAPRESTAR_H
#include "wxfb_project.h"
#include "GestorBiblioteca.h"
#include "Recurso.h"

class HijaPrestar : public BasePrestar {
	
private:
	Gestor *m_gestor;
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
	
public:
	HijaPrestar(wxWindow *parent, Gestor *gestor);
	
	Recurso* Buscar(const string& titulo);
};

#endif

