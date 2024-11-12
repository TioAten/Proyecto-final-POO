#include <string>

using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

/// @brief Clase que representa una persona.

class Persona {
	string m_nombre, m_apellido, m_email;
	int m_nro_socio;
	
public:
	/// @brief Constructor de Persona.
	/// @param name Nombre.
	/// @param ape Apellido.
	/// @param email E-mail.
	/// @param nro_socio Numero de socio.
	Persona(string name, string ape, string email, int nro_socio) : m_nombre(name), m_apellido(ape), m_email(email), m_nro_socio(nro_socio) {}

	/// @brief Constructor de persona sin el parametor de 'email' usado para purebas cortas. Probablemente me olvide de que de cambiar el main para agregar el mail a los datos de la persona. 
	Persona(string name, string ape, int nro_socio) : m_nombre(name), m_apellido(ape), m_nro_socio(nro_socio) {}
	
	string get_nom() { return m_nombre; }
	string get_ape() { return m_apellido; }
	string get_email() { return m_email; }
	string get_nom_completo() { return m_nombre + " " + m_apellido; }
	int get_Nsocio() { return m_nro_socio; }
	string get_NsocioS() { return to_string(m_nro_socio); }
};

#endif
