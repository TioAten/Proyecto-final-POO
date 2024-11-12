#include "Libro.h"
#include <string>
#include <fstream>

using namespace std;

string Libro::Get_Info() const {
	string info = "Titulo: " + m_titulo + ", Autor: " + m_autor + ", ISBN: " + m_ISBN;
	
	if (m_persona != nullptr) {
		info += ", Prestado a: " + m_persona->get_nom_completo();
	}
	
	return info;
}

string Libro::Get_Info_Pres() const {
	string info = "Titulo: " + m_titulo + ", Autor: " + m_autor + ", ISBN: " + m_ISBN;
	
	return info;
}

void Libro::serializar(ofstream& archivo) const {
	// Establece que tipo de recurso es.
	int tipoRecurso = 1;
	archivo.write(reinterpret_cast<const char*>(&tipoRecurso), sizeof(tipoRecurso));
	
	archivo << m_titulo << '|' << m_autor << '|' << m_ISBN << '|';
	
	if (m_persona != nullptr) {
		archivo << m_persona->get_nom() << '|' << m_persona->get_ape() << '|' << m_persona->get_Nsocio() << '|';
	}
	else
		archivo << "" << '|' << "" << '|' << -1 << '|'; //Formato nulo para momento en los que el recurso no esta prestado.
}

void Libro::deserializar(ifstream& archivo) {
	getline(archivo, m_titulo, '|');
	getline(archivo, m_autor, '|');
	getline(archivo, m_ISBN, '|');
	
	string nombre, apellido;
	int nr_soc;
	getline(archivo, nombre, '|');
	getline(archivo, apellido, '|');
	archivo >> nr_soc;
	archivo.ignore();
	
	if (nombre != "" && apellido != "") {
		m_persona = new Persona(nombre, apellido, nr_soc);
	}
	else {
		m_persona = nullptr;
	}
}
