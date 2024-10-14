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

/**
 * @brief Clase que representa una revista, derivada de MaterialBibliografico.
 * 
 * La clase Revista extiende la funcionalidad de MaterialBibliografico añadiendo
 * atributos específicos de las revistas, como el número de edición y el mes de publicación.
 */
class Revista : public MaterialBibliografico {
private:
	int numEdición; /**< Número de edición de la revista. */
	std::string mesPublicación;  /**< Mes de publicación de la revista. */
public:
	/**
     	* @brief Constructor de la clase Revista.
     	* @param nombre Nombre de la revista.
     	* @param isbn ISBN de la revista.
     	* @param autor Autor o editor de la revista.
     	* @param numEdición Número de la edición de la revista.
    	* @param mesPublicación Mes en que la revista fue publicada.
     	*/
	Revista(std::string nombre, std::string isbn, std::string autor, int numEdición, std::string mesPublicación);
	/**
     	* @brief Muestra la información de la revista.
     	* 
     	* Este método anula la función virtual pura de la clase base para
     	* proporcionar una visualización específica de los detalles de la revista.
     	*/
	void mostrarInformación() const override;
	/**
     	* @brief Destructor de la clase Revista.
     	*/
	virtual ~Revista();
	/**
     	* @brief Obtiene el mes de publicación de la revista.
     	* @return Una referencia constante al mes de publicación.
     	*/
	const std::string& getMesPublicación() const {
		return mesPublicación;
	}
	/**
     	* @brief Establece el mes de publicación de la revista.
     	* @param mesPublicación El nuevo mes de publicación.
     	*/
	void setMesPublicación(const std::string &mesPublicación) {
		this->mesPublicación = mesPublicación;
	}
	/**
     	* @brief Obtiene el número de edición de la revista.
     	* @return El número de edición de la revista.
     	*/
	int getNumEdición() const {
		return numEdición;
	}
	/**
     	* @brief Establece el número de edición de la revista.
     	* @param numEdición El nuevo número de edición.
     	*/
	void setNumEdición(int numEdición) {
		this->numEdición = numEdición;
	}
};
#endif /* REVISTA_H_ */
