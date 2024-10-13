/*
 * Usuario.cpp
 *
 *  Created on: 14-09-2024
 *      Author: Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#include "Usuario.h"
#include <iostream>

Usuario::Usuario(string nombre, string id) {
	this -> nombre = nombre;
	this -> id = id;
	this -> contadorMaterialesPrestados = 0;
	for (int i = 0; i < 5; ++i) {
		materialesPrestados[i] = nullptr;
	}
}
bool Usuario::prestarMaterial(MaterialBibliografico* material){
	if(contadorMaterialesPrestados < 5 && !material -> isPrestado()){
		materialesPrestados[contadorMaterialesPrestados ++] = material;
		material -> prestar();
		return true;
	}
	return false;
}
bool Usuario::devolverMaterial(MaterialBibliografico* material){
	for (int i = 0; i < contadorMaterialesPrestados; ++i) {
		if(materialesPrestados[i] == material) {
			material -> devolver();
			materialesPrestados[i] = nullptr;
			for (int j = 0; j < contadorMaterialesPrestados; j++) {
				materialesPrestados[j] = materialesPrestados[j + 1];
			}
			materialesPrestados[--contadorMaterialesPrestados] = nullptr;
			return true;
		}
	}
	return false;
}
void Usuario::mostrarMaterialesPrestados() const {
	cout<<"Listados de materiales prestados al nombre de "<<nombre<<" (ID: "<<id<<"):"<<endl;
	for (int i = 0; i < contadorMaterialesPrestados; ++i) {
		materialesPrestados[i] -> mostrarInformación();
	}
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

