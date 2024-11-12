#include <string>
#include <fstream>
#include "Recurso.h"

using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

class Libro : public Recurso {
	string  m_ISBN;
	
public:
	/// @brief Constructor y uso de herencia.
	/// @param titulo Parametro heredado de 'Recurso'.
	/// @param autor Parametro heredado de 'Recurso'.
	/// @param ISBN Siglas de 'Número estándar internacional de libro' pero en inglés
	Libro(const string& titulo, const string& autor, const string& ISBN) : Recurso(titulo, autor), m_ISBN(ISBN) {}
	Libro() : Recurso("", ""), m_ISBN("") {}
	
	string Get_isbn() { return m_ISBN; }
	
	/// @brief Obtiene información del libro.
	/// @return Retorna información detallada del libro y de haberlo de la persona.
	string Get_Info() const override;
	
	/// @brief Retorna información detallada del libro sin información de la persona.
	string Get_Info_Pres() const override;
	
	/// @brief Serializa la información del libro para guardar.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n del libro.
	void serializar(ofstream& archivo) const override;
	
	/// @brief Deserializa la información del recurso desde un archivo de entrada.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n del libro.
	void deserializar(ifstream& archivo) override;
};


#endif
