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

/**
 * @brief Clase que representa un libro, hereda de MaterialBibliografico.
 * 
 * La clase Libro extiende la funcionalidad de MaterialBibliografico añadiendo
 * atributos específicos de los libros, como la fecha de publicación y un resumen.
 */
class Libro : public MaterialBibliografico {
private:
	std::string fechaPublicación; /**< Fecha de publicación del libro. */
	std::string resumen; /**< Resumen del contenido del libro. */
public:
	/**
     	* @brief Constructor de la clase Libro.
     	* @param nombre Nombre del libro.
     	* @param isbn ISBN del libro.
     	* @param autor Autor del libro.
     	* @param fechaPublicación Fecha de publicación del libro.
     	* @param resumen Resumen del libro.
     	*/
	Libro(std::string nombre, std::string isbn, std::string autor, std::string fechaPublicación, std::string resumen);
	/**
     	* @brief Muestra la información del libro.
     	* 
     	* Este método anula la función virtual pura de la clase base para
     	* proporcionar una visualización específica de los detalles del libro.
     	*/
	void mostrarInformación() const override;
	/**
     	* @brief Destructor de la clase Libro.
     	*/
	virtual ~Libro();
	/**
     	* @brief Obtiene la fecha de publicación del libro.
     	* @return Una referencia constante a la fecha de publicación.
     	*/
	const std::string& getFechaPublicación() const {
		return fechaPublicación;
	}
	/**
     	* @brief Establece la fecha de publicación del libro.
     	* @param fechaPublicación La nueva fecha de publicación.
     	*/
	void setFechaPublicación(const std::string &fechaPublicación) {
		this->fechaPublicación = fechaPublicación;
	}
	/**
     	* @brief Obtiene el resumen del libro.
     	* @return Una referencia constante al resumen.
     	*/
	const std::string& getResumen() const {
		return resumen;
	}
	/**
     	* @brief Establece el resumen del libro.
     	* @param resumen El nuevo resumen.
     	*/
	void setResumen(const std::string &resumen) {
		this->resumen = resumen;
	}
};

#endif /* LIBRO_H_ */
