/*
 * MaterialBibliografico.h
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#ifndef MATERIALBIBLIOGRAFICO_H_
#define MATERIALBIBLIOGRAFICO_H_
#include <string>
using namespace std;

class MaterialBibliografico {
protected:
	string nombre;
	string isbn;
	string autor;
	bool prestado;
public:
	MaterialBibliografico(string nombre, string isbn, string autor);
	virtual void mostrarInformación() const = 0;

	bool isPrestado();
	void prestar();
	void devolver();
	virtual ~MaterialBibliografico();
	const string& getAutor() const {
		return autor;
	}
	void setAutor(const string &autor) {
		this->autor = autor;
	}
	const string& getIsbn() const {
		return isbn;
	}
	void setIsbn(const string &isbn) {
		this->isbn = isbn;
	}
	const string& getNombre() const {
		return nombre;
	}
	void setNombre(const string &nombre) {
		this->nombre = nombre;
	}
	void setPrestado(bool prestado) {
		this->prestado = prestado;
	}
};
#endif /* MATERIALBIBLIOGRAFICO_H_ */
