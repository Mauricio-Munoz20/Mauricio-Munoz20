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

/**
 * @brief Clase que representa a un usuario en el sistema de biblioteca.
 * 
 * La clase Usuario permite gestionar el préstamo y devolución de materiales
 * bibliográficos, así como la visualización de los materiales prestados.
 */
class Usuario {
protected:
	string nombre; /**< Nombre del usuario. */
	string id; /**< Identificación única del usuario. */
	MaterialBibliografico* materialesPrestados[5]; /**< Array de punteros a materiales bibliográficos prestados. */
	int contadorMaterialesPrestados; /**< Contador de materiales actualmente prestados por el usuario. */
public:
	/**
     	* @brief Constructor de la clase Usuario.
     	* @param nombre Nombre del usuario.
     	* @param id Identificación única del usuario.
     	* 
     	* Inicializa el nombre y el ID del usuario, así como el array de materiales
     	* prestados y el contador de materiales prestados.
     	*/
	Usuario(string nombre, string id);
	/**
     	* @brief Presta un material bibliográfico al usuario.
     	* @param material Puntero al material bibliográfico que se va a prestar.
     	* @return true si el préstamo fue exitoso, false si no se pudo realizar.
     	* 
     	* El material solo se presta si el usuario no ha alcanzado el límite de 5 materiales.
     	*/
	bool prestarMaterial(MaterialBibliografico* material);
	/**
     	* @brief Devuelve un material bibliográfico que el usuario había prestado.
     	* @param material Puntero al material bibliográfico que se va a devolver.
     	* @return true si la devolución fue exitosa, false si no se pudo realizar.
     	*/
	bool devolverMaterial(MaterialBibliografico* material);
	/**
     	* @brief Muestra la lista de materiales bibliográficos que el usuario ha prestado.
     	* 
     	* Imprime en consola la información de cada material prestado.
     	*/
	void mostrarMaterialesPrestados() const;
	/**
     	* @brief Destructor de la clase Usuario.
     	* 
     	* Libera cualquier recurso o memoria asignada al objeto Usuario.
     	*/
	virtual ~Usuario();
	/**
     	* @brief Obtiene el contador de materiales prestados.
     	* @return El número de materiales que el usuario tiene actualmente prestados.
     	*/
	int getContadorMaterialesPrestados() const {
		return contadorMaterialesPrestados;
	}
	/**
     	* @brief Establece el contador de materiales prestados.
     	* @param contadorMaterialesPrestados El nuevo valor para el contador de materiales prestados.
     	*/
	void setContadorMaterialesPrestados(int contadorMaterialesPrestados) {
		this->contadorMaterialesPrestados = contadorMaterialesPrestados;
	}
	/**
     	* @brief Obtiene la identificación del usuario.
     	* @return Una referencia constante al ID del usuario.
     	*/
	const string& getId() const {
		return id;
	}
	/**
     	* @brief Establece la identificación del usuario.
     	* @param id El nuevo ID del usuario.
     	*/
	void setId(const string &id) {
		this->id = id;
	}
	/**
     	* @brief Obtiene el nombre del usuario.
     	* @return Una referencia constante al nombre del usuario.
     	*/
	const string& getNombre() const {
		return nombre;
	}
	/**
     	* @brief Establece el nombre del usuario.
     	* @param nombre El nuevo nombre del usuario.
     	*/
	void setNombre(const string &nombre) {
		this->nombre = nombre;
	}
	/**
     	* @brief Obtiene el array de punteros a los materiales prestados.
     	* @return Un puntero doble al array de materiales prestados.
     	*/
	MaterialBibliografico** getMaterialesPrestados() {
	    return materialesPrestados;
	}
	/**
     	* @brief Obtiene el array de punteros a los materiales prestados (constante).
     	* @return Un puntero doble constante al array de materiales prestados.
     	*/
	const MaterialBibliografico* const* getMaterialesPrestados() const {
	    return materialesPrestados;
	}
};
#endif /* USUARIO_H_ */
