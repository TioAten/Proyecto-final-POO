#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "GestorBiblioteca.h"

class Application : public wxApp {
	Gestor *m_gestor;
	
	public:
		virtual bool OnInit();
};

#endif
