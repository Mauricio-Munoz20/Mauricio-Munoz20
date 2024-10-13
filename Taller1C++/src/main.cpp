/*
 * main.cpp
 *
 *  Created on: 14-09-2024
 *      Author: Mauricio Muñoz
 *      RUT: 21.542.213-5
 */

#include <iostream>
#include <fstream>
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

using namespace std;

void agregarMaterial(MaterialBibliografico* biblioteca[], int &contadorMateriales){
	if (contadorMateriales >= 15) {
		cout<<"Fatal error: La biblioteca está llena de material. No es posible agregar más materiales."<<endl;
		return;
	}
	int tipo;
	cout<<"¿Qué tipo de material quiere agregar?"<<endl;
	cout<<"1. Libro"<<endl;
	cout<<"";
	cout<<"2. Revista"<<endl;
	cin>>tipo;
	switch(tipo){
	case 1: {
		string nombre, isbn, autor, resumen, fechaPublicacion;
		cout<<"Perfecto, usted seleccionó Libro."<<endl;
		cout<<"";
		cout<<" Ingrese el nombre del libro: "<<endl;
		cin>>nombre;
		cin.ignore();
		cout<<" Ingrese el codigo ISBN: "<<endl;
		cin>>isbn;
		cin.ignore();
		cout<<" Ingrese el autor del libro: "<<endl;
		cin>>autor;
		cin.ignore();
		cout<<" Ingrese la fecha de publicación del libro: "<<endl;
		cin>>fechaPublicacion;
		cin.ignore();
		cout<<" Ingrese un breve resumen del libro: "<<endl;
		cin>>resumen;
		cin.ignore();
		Libro* libro = new Libro(nombre, isbn, autor, fechaPublicacion, resumen);
		biblioteca[contadorMateriales] = libro;
		contadorMateriales++;
		cout<<"Libro de nombre "<<nombre<<" agregado exitosamente."<<endl;
		break;
	}
	case 2: {
	    string nombre, isbn, autor, mesPublicacion;
	    int numEdicion;
	    cout << "Perfecto, usted seleccionó Revista." << endl;
	    cout << "" << endl;
	    cout << "o Ingrese el nombre de la revista: " << endl;
	    cin >> nombre;
	    cin.ignore();
	    cout << "o Ingrese el código ISBN: " << endl;
	    cin >> isbn;
	    cin.ignore();
	    cout << "o Ingrese el autor de la revista: " << endl;
	    cin >> autor;
	    cin.ignore();
	    cout << "o Ingrese el número de edición de la revista: " << endl;
	    cin >> numEdicion;
	    cin.ignore();
	    cout << "o Ingrese el mes de publicación de esta revista: " << endl;
	    cin >> mesPublicacion;
	    cin.ignore();

	    Revista* revista = new Revista(nombre, isbn, autor, numEdicion, mesPublicacion);
	    biblioteca[contadorMateriales] = revista;
	    contadorMateriales++;
	    cout << "Revista de nombre " << nombre << " agregado exitosamente." << endl;
	    break;
	}
	default:
	    cout << "Opción no válida!" << endl;
	    break;
	}
}
void mostrarInformacionMateriales(MaterialBibliografico* biblioteca[], int contadorMateriales){
	if(contadorMateriales == 0){
		cout<<"No tenemos libros ni revistas en la biblioteca, adiós!"<<endl;
		return;
	}
	cout<<"Usted ha solicitado ver la información de nuestros materiales, aquí la tiene!"<<endl;
	for (int i = 0; i < contadorMateriales; i++) {
		biblioteca[i] -> mostrarInformación();
		cout << "------------------" << endl;
	}
}
void buscarMaterial(MaterialBibliografico* biblioteca[], int contadorMateriales){
	int opcion;
	string busq;
	cout<<"¿Cuál es tu filtro de búsqueda? (a/b)"<<endl;
	cout<<"1. Por Título."<<endl;
	cout<<"2. Por Autor."<<endl;
	cin>>opcion;
	switch(opcion){
	case 1: {
		cout<<"Usted ha escogido el filtro de título, ingrese el título del material solicitado: ";
		cin>>busq;
		bool está = false;
		for (int i = 0; i < contadorMateriales; i++) {
			if(biblioteca[i] -> getNombre() == busq){
				cout<<"El material ha sido encontrado!"<<endl;
				biblioteca[i] -> mostrarInformación();
				está = true;
			}
		}
		if(!está){
			cout<<"El material no ha sido encontrado :C."<<endl;
		}
		break;
	}
	case 2: {
		cout<<"Usted ha escogido el filtro del autor, ingrese el autor del material solicitado: ";
		cin>>busq;
		bool está = false;
		for (int i = 0; i < contadorMateriales; i++) {
			if(biblioteca[i] -> getAutor() == busq){
				cout<<"El autor ha sido encontrado!!"<<endl;
				biblioteca[i] -> mostrarInformación();
				está = true;
			}
		}
		if(!está){
			cout<<"El autor no ha sido encontrado :C."<<endl;
		}
		break;
	}
	default:
		cout<<"Opción no válida."<<endl;
	}
}
void prestarMaterial(Usuario* usuarios[], Usuario* usuario, MaterialBibliografico* biblioteca[], int contadorMateriales) {
	string nombreMaterialPrestar, isbnMaterialPrestar;
	cout<<"Ingrese el nombre del material a prestar: "<<endl;
	cin>> nombreMaterialPrestar;
	cout<<"Ingrese el ISBN del material a prestar: "<<endl;
	cin>> isbnMaterialPrestar;
	MaterialBibliografico* material = nullptr;
	for (int i = 0; i < contadorMateriales; i++) {
		if(biblioteca[i] -> getNombre() == nombreMaterialPrestar && biblioteca[i] -> getIsbn() == isbnMaterialPrestar && !biblioteca[i] -> isPrestado()) {
			material = biblioteca[i];
			break;
		}
	}
	if(material == nullptr){
		cout<<"No se ha encontrado el material solicitado o ya ha sido prestado."<<endl;
		return;
	} else {
		if (usuario -> prestarMaterial(material)){
			material -> prestar();
			cout<<"El material "<< nombreMaterialPrestar<<" ha sido prestado con éxito rotundo!."<<endl;
		} else {
			cout<<"El usuario ya tiene el máximo de materiales prestados."<<endl;
		}
	}
}
void devolverMaterial(Usuario* usuario, MaterialBibliografico* biblioteca[], int contadorMateriales) {
	string nombreMaterialDevolver, isbnMaterialDevolver;
	cout<<"Ingrese el nombre del material a devolver: "<<endl;
	cin>> nombreMaterialDevolver;
	cin.ignore();
	cout<<"Ingrese el ISBN del material a devolver: "<<endl;
	cin>> isbnMaterialDevolver;
	cin.ignore();
	MaterialBibliografico* material = nullptr;
	for (int i = 0; i < contadorMateriales; i++) {
		if(biblioteca[i] -> getNombre() == nombreMaterialDevolver && biblioteca[i] -> getIsbn() == isbnMaterialDevolver && biblioteca[i] -> isPrestado()) {
			material = biblioteca[i];
			break;
		}
	}
	if(material == nullptr){
		cout<<"El material no ha sido encontrado o no está prestado."<<endl;
		return;
	} else {
		if(usuario -> devolverMaterial(material)){
			material -> devolver();
			cout<<"El material "<< nombreMaterialDevolver <<" ha sido devuelto con total seguridad!."<<endl;
		} else {
			cout<<"El material solicitado no está entre los prestados al usuario."<<endl;
		}
	}
}
void gestionarMaterial(Usuario* usuarios[], MaterialBibliografico* biblioteca[], int contadorUsuarios, int contadorMateriales){
	int opcion;
	string idUsuario;
	cout<<"Gestionar material...¿que desea realizar?"<<endl;
	cout<<""<<endl;
	cout<<"1. Prestar material."<<endl;
	cout<<"2. Devolver Material"<<endl;
	cin>>opcion;
	cin.ignore();

	cout<<"Ingrese su ID de Usuario: "<<endl;
	cin>> idUsuario;
	Usuario* usuario = nullptr;
	for (int i = 0; i < contadorUsuarios; i++) {
		if(usuarios[i] -> getId() == idUsuario){
			usuario = usuarios[i];
			break;
		}
	}
	if(usuario == nullptr){
		cout<<"No se ha encontrado al usuario :c."<<endl;
		return;
	}
	switch(opcion){
	case 1:
		prestarMaterial(usuarios, usuario, biblioteca, contadorMateriales);
		break;
	case 2:
		devolverMaterial(usuario, biblioteca, contadorMateriales);
		break;
	default:
		cout<<"Opción no válida, es imposible realizar lo que usted quiere."<<endl;
		break;
	}
}
void crearUsuario(Usuario* usuarios[], int &contadorUsuarios){
	string nombre, id;
	if(contadorUsuarios > 10){
		cout<<"Error: Lista de usuarios llena con "<<contadorUsuarios<<", no se pueden agregar usuarios."<<endl;
		return;
	}
	cout<<"Ingrese su nombre: "<<endl;
	cin>>nombre;
	cin.ignore();
	cout<<"Ingrese su nuevo ID: "<<endl;
	cin>> id;
	cin.ignore();
	Usuario* usuario = new Usuario(nombre, id);
	usuarios[contadorUsuarios] = usuario;
	contadorUsuarios++;
	cout<<"Usuario de nombre "<<nombre<<" y de ID - "<<id<<" ha sido agregado con éxito!"<<endl;
}
void buscarUsuario(Usuario* usuarios[], int contadorUsuarios){
	string id;
	cout<<"Como opción predeterminada y beta, usted tiene que buscar un usuario por su id debido a un problema con el nombre del usuario."<<endl;
	cout<<""<<endl;
	cout << "Ingrese el ID del usuario: " << endl;
	cin >> id;
	cin.ignore();
	bool teEncontré = false;
	for (int i = 0; i < contadorUsuarios; i++) {
		if(usuarios[i] -> getId() == id){
			cout<<"El usuario ha sido encontrado con éxito!!"<<endl;
			usuarios[i] -> mostrarMaterialesPrestados();
			teEncontré = true;
		}
	}
	if(!teEncontré) {
		cout<<"El usuario con ese ID no ha sido encontrado."<<endl;
	}
}
void eliminarUsuario(Usuario* usuarios[], int &contadorUsuarios){
	string idNewEliminado;
	cout<<"\nUsted ha escogido eliminar usuario..."<<endl;
	cout<<"Ingrese la id del usuario: "<<endl;
	cin>>idNewEliminado;
	bool founded = false;
	for (int i = 0; i < contadorUsuarios; i++) {
		if(usuarios[i] -> getId() == idNewEliminado){
			delete usuarios[i];
			for (int j = i; j < contadorUsuarios - 1; j++) {
				usuarios[j] = usuarios[j+1];
			}
			contadorUsuarios--;
			cout<<"Usuario de la ID "<< idNewEliminado <<" ha sido encontrado y eliminado."<<endl;
			founded = true;
			break;
		}
	}
	if(!founded){
		cout<<"El usuario de la ID "<< idNewEliminado <<" no ha sido encontrado por el sistema."<<endl;
	}
}
void gestionarUsuarios(Usuario* usuarios[], int contadorUsuarios){
	int alternativa;
	cout<<"Perfecto, bienvenido a la opción de Gestionar Usuarios, ¿que desea realizar?"<<endl;
	cout<<""<<endl;
	cout<<"1. Añadir un usuario."<<endl;
	cout<<"2. Buscar un usuario."<<endl;
	cout<<"3. Eliminar un usuario."<<endl;
	cin>>alternativa;
	switch(alternativa){
	case 1:
		crearUsuario(usuarios, contadorUsuarios);
		break;
	case 2:
		buscarUsuario(usuarios, contadorUsuarios);
		break;
	case 3:
		eliminarUsuario(usuarios, contadorUsuarios);
		break;
	default:
		cout<<"Opción no válida :c."<<endl;
		break;
	}
}
void menú(MaterialBibliografico* biblioteca[], Usuario* usuarios[], int contadorMateriales, int contadorUsuarios) {
	int opcion;
	bool cont = true;
	while(cont){
		cout<<"Bienvenidos al Sistema de Biblioteca Digital UCN!";
		cout<<"\nEste es un sistema digital hecho para los usuarios de la Biblioteca UCN..., seleccione una de las opciones."<<endl;
		cout<<"";
		cout<<"1. Agregar Material a la Biblioteca (Libros/Revistas)."<<endl;
		cout<<"";
		cout<<"2. Mostrar información de los materiales."<<endl;
		cout<<"";
		cout<<"3. Buscar material (Libros/Revistas)."<<endl;
		cout<<"";
		cout<<"4. Prestar o devolver material."<<endl;
		cout<<"";
		cout<<"5. Gestión de usuarios"<<endl;
		cout<<"";
		cout<<"6. Salir del sistema."<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			agregarMaterial(biblioteca, contadorMateriales);
			break;
		case 2:
			mostrarInformacionMateriales(biblioteca, contadorMateriales);
			break;
		case 3:
			buscarMaterial(biblioteca, contadorMateriales);
			break;
		case 4:
			gestionarMaterial(usuarios, biblioteca, contadorUsuarios, contadorMateriales);
			break;
		case 5:
			gestionarUsuarios(usuarios, contadorUsuarios);
			break;
		case 6:
			cout<<"Usted salió del sistema exitosamente!! No vuelva más."<<endl;
			cont = false;
			break;
		default:
			cout<<"Opción no válida, vuelva a seleccionar una válida entre 1 y 6!"<<endl;
			break;
		}
	}
}
void cargarDatosBiblio(MaterialBibliografico* biblio[], Usuario* personas[], int contMat, int contUsua){
	fstream txtBiblioteca("Biblioteca.txt", ios::in);
	if (txtBiblioteca) {
		txtBiblioteca >> contMat;
		txtBiblioteca.ignore();  // Ignorar el salto de línea
		for (int i = 0; i < contMat; i++) {
			string tipo, nombre, isbn, autor, extra1, extra2;
			bool prestado;
			getline(txtBiblioteca, tipo);
			getline(txtBiblioteca, nombre);
			getline(txtBiblioteca, isbn);
			getline(txtBiblioteca, autor);
			if (tipo == "Libro") {
				getline(txtBiblioteca, extra1);  // Fecha de publicación
				getline(txtBiblioteca, extra2);  // Resumen
				Libro* libro = new Libro(nombre, isbn, autor, extra1, extra2);
				txtBiblioteca >> prestado;
				libro->setPrestado(prestado);
				biblio[i] = libro;
			} else if (tipo == "Revista") {
				getline(txtBiblioteca, extra1);  // Número de edición
				getline(txtBiblioteca, extra2);  // Mes de publicación
				Revista* revista = new Revista(nombre, isbn, autor, stoi(extra1), extra2);
				txtBiblioteca >> prestado;
				revista->setPrestado(prestado);
				biblio[i] = revista;
			}
			txtBiblioteca.ignore();  // Ignorar el salto de línea
		}
		txtBiblioteca.close();
		cout << "Materiales cargados desde Biblioteca.txt." << endl;
	} else {
		cout << "Error al cargar los materiales." << endl;
	}
	fstream txtUsuarios("Usuarios.txt", ios::in);
	if (txtUsuarios) {
		txtUsuarios >> contUsua;
		txtUsuarios.ignore();  // Ignorar el salto de línea

		for (int i = 0; i < contUsua; i++) {
			string idUsuario, nombreUsuario;
			getline(txtUsuarios, idUsuario);
			getline(txtUsuarios, nombreUsuario);
			Usuario* usuario = new Usuario(idUsuario, nombreUsuario);

			int cantidadPrestados;
			txtUsuarios >> cantidadPrestados;
			txtUsuarios.ignore();  // Ignorar el salto de línea

			for (int j = 0; j < cantidadPrestados; j++) {
				string nombreMaterial, isbnMaterial;
				getline(txtUsuarios, nombreMaterial);
				getline(txtUsuarios, isbnMaterial);
				// Buscar el material en la biblioteca
				for (int k = 0; k < contMat; k++) {
					if (biblio[k]->getNombre() == nombreMaterial && biblio[k]->getIsbn() == isbnMaterial) {
						usuario->prestarMaterial(biblio[k]);
						break;
					}
				}
			}
			personas[i] = usuario;
		}
		txtUsuarios.close();
		cout << "Usuarios cargados desde Usuarios.txt." << endl;
	} else {
		cout << "Error al cargar los usuarios." << endl;
	}
}
void guardarDatosBiblio(MaterialBibliografico* biblio[], Usuario* personas[], int contMat, int contUsua){
	ofstream txtBiblioteca("Biblioteca.txt", ios::out);
	if(txtBiblioteca){
		txtBiblioteca << contMat << endl;
		for (int i = 0; i < contMat; i++) {
			txtBiblioteca << biblio[i] -> getNombre() <<endl;
			txtBiblioteca << biblio[i] -> getIsbn() <<endl;
			txtBiblioteca << biblio[i] -> getAutor() <<endl;
			txtBiblioteca << biblio[i] -> isPrestado() <<endl;
		}
		txtBiblioteca.close();
		cout<<"Datos guardados en Biblioteca.txt."<<endl;
	} else {
		cout<<"Grave error al guardar los datos de la biblioteca."<<endl;
	}
	ofstream txtUsuarios("Usuarios.txt", ios::out);
	if(txtUsuarios){
		txtUsuarios << contUsua << endl;
		for (int i = 0; i < contUsua; i++) {
			txtUsuarios << personas[i] -> getNombre() <<endl;
			txtUsuarios << personas[i] -> getId() <<endl;

		}
		txtUsuarios.close();
		cout<<"Datos guardados en Usuarios.txt."<<endl;
	} else {
		cout<<"Grave error al guardar los datos de los usuarios."<<endl;
	}
}
void liberarMemoria(MaterialBibliografico* biblio[], Usuario* personas[], int contMat, int contUsua){
	for (int i = 0; i < contMat; i++) {
		delete biblio[i];
	}
	for(int i = 0; i < contUsua; i++){
		delete personas[i];
	}
}
int main(){
	MaterialBibliografico* biblioteca[15];
	Usuario* usuarios[10];
	int contadorMateriales = 0;
	int contadorUsuarios = 0;

	cargarDatosBiblio(biblioteca, usuarios, contadorMateriales, contadorUsuarios);
	menú(biblioteca, usuarios, contadorMateriales, contadorUsuarios);
	guardarDatosBiblio(biblioteca, usuarios, contadorMateriales, contadorUsuarios);
	liberarMemoria(biblioteca, usuarios, contadorMateriales, contadorUsuarios);

	return 0;
}

