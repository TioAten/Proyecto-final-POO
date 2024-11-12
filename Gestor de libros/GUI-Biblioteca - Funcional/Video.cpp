#include "Video.h"
#include <string>
#include <fstream>

using namespace std;

string Video::Get_Info() const {
	string info = "Titulo: " + m_titulo + ", Autor: " + m_autor + ", Duracion: " + to_string(m_duracion);
	
	if (m_persona != nullptr) {
		info += ", Prestado a: " + m_persona->get_nom_completo();
	}
	
	return info;
}
string Video::Get_Info_Pres() const {
	string info = "Titulo: " + m_titulo + ", Autor: " + m_autor + ", Duracion: " + to_string(m_duracion);

	return info;
}
void Video::serializar(ofstream& archivo) const {
	// Establece que tipo de recurso es.
	int tipoRecurso = 3;
	archivo.write(reinterpret_cast<const char*>(&tipoRecurso), sizeof(tipoRecurso));
	
	archivo << m_titulo << '|' << m_autor << '|' << m_duracion << '|';
	
	if (m_persona != nullptr) {
		archivo << m_persona->get_nom() << '|' << m_persona->get_ape() << '|' << m_persona->get_Nsocio() << '|';
	}
	else
		archivo << "" << '|' << "" << '|' << -1 << '|';
}

void Video::deserializar(ifstream& archivo) {
	getline(archivo, m_titulo, '|');
	getline(archivo, m_autor, '|');
	archivo >> m_duracion;
	archivo.ignore(); // Ignorar el '|' después del entero.
	
	string nombre, apellido;
	int nr_soc;
	getline(archivo, nombre, '|');
	getline(archivo, apellido, '|');
	archivo >> nr_soc;
	archivo.ignore();
	
	if (nombre != "" && apellido != "") {
		m_persona = new Persona(nombre, apellido, nr_soc);
	} else {
		m_persona = nullptr;
	}
}
