/*
 * Libro.h
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
private:
	std::string fechaPublicación;
	std::string resumen;
public:
	Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicación, std::string resumen);
	void mostrarInformación() const override;
	virtual ~Libro();
	const std::string& getFechaPublicación() const {
		return fechaPublicación;
	}
	void setFechaPublicación(const std::string &fechaPublicación) {
		this->fechaPublicación = fechaPublicación;
	}
	const std::string& getResumen() const {
		return resumen;
	}
	void setResumen(const std::string &resumen) {
		this->resumen = resumen;
	}
};

#endif /* LIBRO_H_ */
