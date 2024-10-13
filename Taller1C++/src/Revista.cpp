/*
 * Revista.cpp
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#include "Revista.h"
#include <iostream>

Revista::Revista(std::string nombre, std::string isbn, std::string autor, int numEdición, std::string mesPublicación) : MaterialBibliografico(nombre, isbn, autor), numEdición(numEdición), mesPublicación(mesPublicación) {}

void Revista::mostrarInformación() const {
	std::cout<<"Revista: "<<nombre <<", con ISBN: "<<isbn<<", Autor: "<<autor<<", Número de edición: "<<numEdición<<", Mes de Publicación: "<<mesPublicación;
};
Revista::~Revista() {
	// TODO Auto-generated destructor stub
}

