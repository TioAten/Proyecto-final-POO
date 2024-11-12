#include <vector>
#include <string>
#include "Recurso.h"
#include "Persona.h"

using namespace std;

#ifndef GESTORBIBLIOTECA_H
#define GESTORBIBLIOTECA_H

/// @brief Clase diseÃ±ada para gestiÃ³n de recursos desde la GUI.
class Gestor {
	
	/// @brief Vector de tipo puntero de 'Recurso' para almacenar objetos de las clases hijas en un mismo vector.
	vector<Recurso*> recursos;
	vector<int> indices;
	string m_filename;
	int cnt;
	
public:
	
	Gestor (string filename) : m_filename(filename) {}
	
	/// @brief Agrega un recurso al vector de recursos.
	/// @param recurso Toma un puntuero a un recurso para agregar objetos de sus clases hijas.
	void Add_Recurso(Recurso* recurso);
	
	/// @brief Retorna el recurso almacenado en la posición 'i' del vector 'recursos'. 
	Recurso* Indice_Recurso(int i);
	
	/// @brief Obtiene un recurso. 'const' para que el mÃ©todo no modifique el recurso.
	void Get_Recurso() const;
	
	/// @brief Retorna el valor almacenado en la posición 'i'.
	int Get_Indices(int i) { return indices[i]; }
	
	/// @brief Limpia el vector 'indices'.
	void Clear_Indices();
	
	/// @brief Limpia el vector 'recursos'.
	void Clear_Vector();
	
	/// @brief Presta un recurso a una persona y modifica su estado.
	/// @param recurso Puntero de 'Recurso' para poder pasar instancias de sus clases hijas.
	/// @param persona Puntero de 'Persona' para representar la persona a la que se le presta el recurso.
	void Prestar_Recurso(Recurso* recurso, Persona* persona);
	
	/// @brief Devuelve un recurso que estaba prestado.
	/// @param recurso Toma el recurso que se estÃ¡ devolviento. Es puntero para pasar instancias de las clases hijas.
	void Devolver_Recurso(Recurso* recurso);
	
	/// @brief Guarda informaciÃ³n sobre los recursos en un archivo binario.
	/// @param filename Nombre del archivo. Referencia para evitar copias innecesarias. Â´constÂ´ para evitar modificar la refenrencia.
	void Save_Recurso() const;
	
	/// @brief Carga la informaciÃ³n del archivo y crear un objeto en funciÃ³n del tipo de recurso
	/// @param filename Nombre del archivo. Referencia para evitar copias innecesarias. Â´constÂ´ para evitar modificar la refenrencia.
	void Load_Recurso();
	
	/// @brief Busca recursos asociados a una persona en el vector 'recursos'. 'const' para que el mÃ©todo no medifique miembros de la clase.
	/// @param persona Puntero de 'Persona' porque 'recursos' es un vector de punteros de tipo 'Recursos'.
	int Find_Recurso(const string& parametro);
	
	/// @brief Retorna 'cnt'.
	int Get_cnt_of_Find() { return cnt; }
	
	/// @brief Retorna el tama�o del vector 'recursos'.
	int Cant_Datos() { return recursos.size(); }
};

#endif
