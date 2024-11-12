#include "Recurso.h"

using namespace std;

int Recurso::Get_NroSocio_Prestamo() const {
    // Se lee como "Es m_persona distinto de nulltpr ? Sí: retorna su numero de socio. No: -1".
    return (m_persona != nullptr) ? m_persona->get_Nsocio() : -1;
}
