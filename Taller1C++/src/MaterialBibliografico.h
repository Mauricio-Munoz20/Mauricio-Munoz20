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
/**
* @brief Clase base que representa un material bibliográfico.
*
* Esta clase proporciona la funcionalidad básica para manejar materiales
* bibliográficos como libros y revistas, incluyendo información sobre el 
* nombre, ISBN, autor y estado de préstamo del material.
*/
class MaterialBibliografico {
protected:
	string nombre; /**< Nombre del material bibliográfico. */
	string isbn; /**< ISBN del material bibliográfico. */
	string autor; /**< Autor del material bibliográfico. */
	bool prestado; /**< Indica si el material está prestado (true) o no (false). */
public:
	/**
 	* @brief Constructor de la clase Material Bibliográfico.
  	* @param nombre Nombre del material bibliográfico.
   	* @param isbn ISBN del material bibliográfico.
   	* @param autor Autor del material bibliográfico.
	MaterialBibliografico(string nombre, string isbn, string autor);
 	/**
     	* @brief Muestra la información del material bibliográfico.
     	* Esta función debe ser implementada por las clases derivadas.
     	*/
	virtual void mostrarInformación() const = 0;
	/**
     	* @brief Verifica si el material bibliográfico está prestado.
     	* @return true si el material está prestado, false en caso contrario.
     	*/
	bool isPrestado();
	/**
     	* @brief Marca el material bibliográfico como prestado.
     	*/
	void prestar();
	/**
     	* @brief Marca el material bibliográfico como devuelto.
     	*/
	void devolver();
	/**
     	* @brief Destructor virtual de la clase MaterialBibliografico.
     	*/
	virtual ~MaterialBibliografico();
	/**
     	* @brief Obtiene el autor del material bibliográfico.
     	* @return Una referencia constante al autor.
     	*/
	const string& getAutor() const {
		return autor;
	}
	/**
     	* @brief Establece el autor del material bibliográfico.
     	* @param autor El nuevo autor.
     	*/	
	void setAutor(const string &autor) {
		this->autor = autor;
	}
	/**
     	* @brief Obtiene el ISBN del material bibliográfico.
     	* @return Una referencia constante al ISBN.
     	*/
	const string& getIsbn() const {
		return isbn;
	}
	/**
	* @brief Establece el ISBN del material bibliográfico.
	* @param isbn El nuevo ISBN.
	*/
	void setIsbn(const string &isbn) {
		this->isbn = isbn;
	}
	/**
     	* @brief Obtiene el nombre del material bibliográfico.
     	* @return Una referencia constante al nombre.
     	*/
	const string& getNombre() const {
		return nombre;
	}
	/**
     	* @brief Establece el nombre del material bibliográfico.
     	* @param nombre El nuevo nombre.
     	*/
	void setNombre(const string &nombre) {
		this->nombre = nombre;
	}
	/**
     	* @brief Establece el estado de préstamo del material bibliográfico.
     	* @param prestado El nuevo estado de préstamo (true para prestado, false para disponible).
     	*/
	void setPrestado(bool prestado) {
		this->prestado = prestado;
	}
};
#endif /* MATERIALBIBLIOGRAFICO_H_ */
