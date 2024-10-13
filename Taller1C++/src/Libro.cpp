/*
 * Libro.cpp
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#include "Libro.h"
#include <iostream>

Libro::Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicación, std::string resumen) : MaterialBibliografico(nombre, isbn, autor) {
	this -> fechaPublicación = fechaPublicación;
	this -> resumen = resumen;
}
void Libro::mostrarInformación() const {
	std::cout<<"Libro: "<<nombre <<", con ISBN: "<<isbn<<", Autor: "<<autor<<", Fecha de Publicación: "<<fechaPublicación<<", Resumen: "<<resumen<<std::endl;
};
Libro::~Libro() {
	// TODO Auto-generated destructor stub
}

