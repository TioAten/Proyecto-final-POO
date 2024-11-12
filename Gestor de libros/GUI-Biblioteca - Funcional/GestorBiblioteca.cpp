#include <vector>
#include <string>
#include "GestorBiblioteca.h"
#include "Recurso.h"
#include "Libro.h"
#include "Revista.h"
#include "Video.h"
#include "Persona.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <typeinfo>

using namespace std;


void Gestor::Add_Recurso(Recurso* recurso) {
	recursos.push_back(recurso);
}

void Gestor::Get_Recurso() const{
	for (auto& recurso : recursos)
		cout << recurso->Get_Info() << endl;
}

void Gestor::Prestar_Recurso(Recurso* recurso, Persona* persona) {
	recurso->Prestar_A(persona);
}

void Gestor::Devolver_Recurso(Recurso* recurso) {
	recurso->Devolver();
}

void Gestor::Save_Recurso() const {
	ofstream archivo(m_filename, ios::binary);
	if (archivo.is_open()) {
		for (const auto& recurso : recursos) {
			recurso->serializar(archivo);
		}
		archivo.close();
	} else {
		cout << "No se pudo abrir el archivo para escritura." << endl;
	}
}

void Gestor::Load_Recurso() {
	ifstream archivo(m_filename, ios::binary);
	if (archivo.is_open()) {
		recursos.clear();
		while (archivo.peek() != EOF) {
			int tipoRecurso;
			archivo.read(reinterpret_cast<char*>(&tipoRecurso), sizeof(tipoRecurso));
			
			Recurso* nuevoRecurso = nullptr;
			switch (tipoRecurso) {
			case 1: // Libro
				nuevoRecurso = new Libro();
				break;
			case 2: // Revista
				nuevoRecurso = new Revista();
				break;
			case 3: // Video
				nuevoRecurso = new Video();
				break;
			default:
				cout << "Tipo de recurso no válido." << endl;
				break;
			}
			
			if (nuevoRecurso != nullptr) {
				nuevoRecurso->deserializar(archivo);
				recursos.push_back(nuevoRecurso);
			}
		}
		archivo.close();
	} else {
		cout << "No se pudo abrir el archivo para lectura." << endl;
	}
}

int Gestor::Find_Recurso(const string& parametro) {
	cnt = 0;
	bool recursosEncontrados = false;
	// Verificar si el par?metro es un n?mero (socio) o un t?tulo/autor
	bool buscarPorSocio = all_of(parametro.begin(), parametro.end(), ::isdigit);
	cout << "Resultados de la b?squeda para: " << parametro << endl;
	
	for (int i = 0; i < recursos.size(); i++) {
		// Verificar si el recurso est? prestado y si coincide con el par?metro de b?squeda
		if ((buscarPorSocio && recursos[i]->Esta_Prestado() && recursos[i]->Get_NroSocio_Prestamo() == stoi(parametro)) ||
			(!buscarPorSocio && (recursos[i]->Get_Info().find(parametro) != string::npos))) {
			
			if (buscarPorSocio) {
				// Si se busca por socio, mostrar solo los libros prestados a esa persona
				if (typeid(*recursos[i]) == typeid(Libro) || typeid(*recursos[i]) == typeid(Revista) || typeid(*recursos[i]) == typeid(Video)) {
					cout << recursos[i]->Get_Info_Persona() << endl;
					indices.push_back(i);
				}
			} else {
				// Si no se busca por socio, mostrar informaci?n del recurso
				cout << recursos[i]->Get_Info();
				indices.push_back(i);
				if (recursos[i]->Esta_Prestado()) {
					// Mostrar informaci?n de la persona a la que est? prestado
					cout << recursos[i]->Get_Info_Persona();
					indices[i] = i;
				}
				cnt++;
				cout << endl;
			}
			recursosEncontrados = true;
		}
	}
	
	if (!recursosEncontrados) {
		cout << "No se encontraron resultados para la b?squeda." << endl;
		return -1; // Retorna un valor por defecto si no se encuentran recursos
	}
}

Recurso* Gestor::Indice_Recurso(int i) {
	if (i >= 0 && i < recursos.size())
		return recursos[i];
	else
		return nullptr;
}

void Gestor::Clear_Indices() {
	indices.clear();
}

void Gestor::Clear_Vector() {
	for (auto& recurso : recursos)
		delete recurso; // Libera memoria del objeto apuntado por el puntero.
	recursos.clear(); // Limpia el vector.
}
