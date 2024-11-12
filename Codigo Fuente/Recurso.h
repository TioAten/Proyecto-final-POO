#include <string>
#include <fstream>
#include "Persona.h"

using namespace std;

#ifndef RECURSO_H
#define RECURSO_H

class Recurso {
protected:
	/// @brief Protecte para que puedan ser usadas por las hijas.
	string m_titulo, m_autor;
	Persona* m_persona;
	
public:
	/*
	Se declara 'Persona* persona' para guerdar la dirección de memoria de un objeto tipo Perosna.
	Se inicializa m_persona como nulltpr porque no se le asigna una persona al crear un nuevo Recurso.
	Se inicializa m_titulo y m-autor con paso por referencia para evitar la creación de copias innecesarias y se agrega const para que no sean modificadas.
	*/
	Recurso(const string& titulo, const string& autor) : m_titulo(titulo), m_autor(autor), m_persona(nullptr) {}
	Recurso() {}
	
	/// @brief Asigna a 'm_persona' la dirección de apuntada por p.
	void Prestar_A(Persona* p) { m_persona = p; }
	
	/// @brief Asigna a 'm_persona' un puntero tipo nulo.
	void Devolver() { m_persona = nullptr; }
	
	/// @brief Retorna si el un recurso está prestado o no.
	bool Esta_Prestado () const { return m_persona != nullptr; }
	
	string Get_Autor() { return m_autor; }
	
	string Get_Titulo() { return m_titulo; }
	
	/// @brief Retorna los datos de m_persona para comparación. 
	Persona* get_persona() { return m_persona; }
		
	/// @brief Pregunta si m_persona NO es nulltpr. En caso positivo retorna su número de socio. En caso negativo retorna -1 como señal de error. 
	int Get_NroSocio_Prestamo () const;
	
	/// @brief Método usado para saber si un recurso esta pretado a alguien o no.
	/// @return Si m_persona no es nulltpr retorna el nombre completo sino retorna "No prestado".
	string Get_Info_Persona () const { return (m_persona != nullptr) ? m_persona->get_nom_completo() : "No prestado"; }
	
	/// @brief Tendrá una implementació por defecto por puedo o no ser reescripa por las hijas.
	virtual string Get_Info() const =0;
	
	/// @brief  Tendrá una implementació por defecto por puedo o no ser reescripa por las hijas.
	virtual string Get_Info_Pres() const =0;
	
	/// @brief Método enteramente virtual que será definida por las hijas.
	virtual void serializar(ofstream& archivo) const = 0;
	
	/// @brief Método enteramente virtual puro que será definida por las hijas.
	virtual void deserializar(ifstream& archivo) = 0;
	
	
};

#endif
