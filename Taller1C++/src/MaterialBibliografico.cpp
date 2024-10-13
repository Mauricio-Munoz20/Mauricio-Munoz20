/*
 * MaterialBibliografico.cpp
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#include "MaterialBibliografico.h"

MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor) {
	this -> nombre = nombre;
	this -> isbn = isbn;
	this -> autor = autor;
	this -> prestado = false;
}
bool MaterialBibliografico::isPrestado(){
	return prestado;
}
void MaterialBibliografico::devolver(){
	this -> prestado = false;
}
void MaterialBibliografico::prestar(){
	this -> prestado = true;
}
MaterialBibliografico::~MaterialBibliografico() {}

