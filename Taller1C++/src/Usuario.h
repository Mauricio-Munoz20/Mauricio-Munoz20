/*
 * Usuario.h
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include "MaterialBibliografico.h"
#include <string>

class Usuario {
protected:
	string nombre;
	string id;
	MaterialBibliografico* materialesPrestados[5];
	int contadorMaterialesPrestados;
public:
	Usuario(string nombre, string id);

	bool prestarMaterial(MaterialBibliografico* material);
	bool devolverMaterial(MaterialBibliografico* material);
	void mostrarMaterialesPrestados() const;
	virtual ~Usuario();
	int getContadorMaterialesPrestados() const {
		return contadorMaterialesPrestados;
	}
	void setContadorMaterialesPrestados(int contadorMaterialesPrestados) {
		this->contadorMaterialesPrestados = contadorMaterialesPrestados;
	}
	const string& getId() const {
		return id;
	}
	void setId(const string &id) {
		this->id = id;
	}
	const string& getNombre() const {
		return nombre;
	}
	void setNombre(const string &nombre) {
		this->nombre = nombre;
	}
	MaterialBibliografico** getMaterialesPrestados() {
	    return materialesPrestados;
	}
	const MaterialBibliografico* const* getMaterialesPrestados() const {
	    return materialesPrestados;
	}
};

#endif /* USUARIO_H_ */
