#include <string>
#include <fstream>
#include "Recurso.h"

using namespace std;

#ifndef VIDEO_H
#define VIDEO_H

class Video : public Recurso {
	int m_duracion;
	
public:
	
	/// @brief Constructor y uso de herencia.
	/// @param titulo Parametro heredado de 'Recurso'.
	/// @param autor Parametro heredado de 'Recurso'.
	/// @param duracion Duracion del video.
	Video(const string& titulo, const string& autor, const int& duracion) : Recurso(titulo, autor), m_duracion(duracion) {}
	Video() : Recurso("", ""), m_duracion(0) {}
	
	string Get_Duracion() { return to_string(m_duracion); }
	
	/// @brief Obtiene informaciÃ³n del video.
	/// @return Retorna informaciÃ³n detallada del video.
	string Get_Info() const override;
	
	string Get_Info_Pres() const override;
	
	/// @brief Serializa la informaciÃ³n del video.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n del video.
	void serializar(ofstream& archivo) const override;
	
	/// @brief Deserializa la informaciÃ³n del recurso desde un archivo de entrada.
	/// @param archivo Pasa un archivo por referencia para guardar la informaciÃ³n del video.
	void deserializar(ifstream& archivo) override;
	
};

#endif
