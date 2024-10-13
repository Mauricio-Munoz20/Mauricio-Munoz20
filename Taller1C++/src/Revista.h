/*
 * Revista.h
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#ifndef REVISTA_H_
#define REVISTA_H_
#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
private:
	int numEdición;
	std::string mesPublicación;
public:
	Revista(std::string nombre, std::string isbn, std::string autor, int numEdición, std::string mesPublicación);
	void mostrarInformación() const override;
	virtual ~Revista();
	const std::string& getMesPublicación() const {
		return mesPublicación;
	}
	void setMesPublicación(const std::string &mesPublicación) {
		this->mesPublicación = mesPublicación;
	}
	int getNumEdición() const {
		return numEdición;
	}
	void setNumEdición(int numEdición) {
		this->numEdición = numEdición;
	}
};

#endif /* REVISTA_H_ */
