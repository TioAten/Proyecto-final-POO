#include <string>
#include <fstream>
#include "Recurso.h"

using namespace std;

#ifndef REVISTA_H
#define REVISTA_H

class Revista : public Recurso {
	string m_numero;
	
public:
	
	/// @brief Constructor y uso de herencia.
	/// @param titulo Parametro heredado de 'Recurso'.
	/// @param autor Parametro heredado de 'Recurso'.
	/// @param numero Numero de la revista.
	Revista(const string& titulo, const string& autor, const string& numero) : Recurso(titulo, autor), m_numero(numero) {}
	Revista() : Recurso("", ""), m_numero("") {}
	
	string Get_numero() { return m_numero; }
	
	/// @brief Obtiene informaciÃ³n de la revista.
	/// @return Retorna informaciÃ³n detallada de la revista.
	string Get_Info() const override;
	
	string Get_Info_Pres() const override;
	
	/// @brief Serializa la informaciÃ³n de la revista.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n de la revista.
	void serializar(ofstream& archivo) const override;
	
	/// @brief Deserializa la informaciÃ³n del recurso desde un archivo de entrada.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n de la revista.
	void deserializar(ifstream& archivo) override;
};
#endif
