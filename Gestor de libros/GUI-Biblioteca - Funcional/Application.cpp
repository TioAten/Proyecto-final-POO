#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	m_gestor = new Gestor("biblioteca.bin");
	m_gestor->Load_Recurso();
	HijaPrincipal *win = new HijaPrincipal(m_gestor); // Crea una nueva ventana tipo WinExample.
	win->Show(); // hace se muestre la ventana.
	return true;
}

