#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

class ejem {
	public:
		int id;
		string x;
};
class nodo {
public:
	nodo(ejem v, nodo *ant = NULL, nodo *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}

private:
	ejem valor;
	nodo *anterior;
	nodo *siguiente;

	friend class lista;
};
class lista {
public:
	lista(nodo *ini = NULL, nodo *fin = NULL) :inicio(ini), finali(fin) {}
	nodo *inicio;
	nodo *finali;
	void insertar(ejem x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
	void modificar(int x);
};

void lista::insertar(ejem x) {
	nodo *nuevo;
	if (inicio == NULL) {
		nuevo = new nodo(x, inicio);
		inicio = nuevo;
		finali = nuevo;
	}
	else {
		nuevo = new nodo(x, finali);
		finali->siguiente = nuevo;
		nuevo->anterior = finali;
		finali = nuevo;
	}
}
void lista::borrar(int x) {
	nodo *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con != true)
	{
		if (nuevo->valor.id == x) {
			if (nuevo == inicio) {
				inicio->siguiente->anterior = NULL;
				inicio = inicio->siguiente;
			}
			else if (nuevo == finali) {
				finali->anterior->siguiente = NULL;
				finali = finali->anterior;
			}
			else {
				nuevo->anterior->siguiente = nuevo->siguiente;
				nuevo->siguiente->anterior = nuevo->anterior;
			}
			con = true;
		}
		if (con == true) delete nuevo;
		else if (nuevo->siguiente == NULL) {
			con = true; 
			cout << "No se pudo borrar" << endl;
		}
		else nuevo = nuevo->siguiente; 
	}
}
void lista::mostrar() {
	nodo *nuevo;
	nuevo = inicio;
	while (nuevo)
	{
		cout << nuevo->valor.x << endl;
		nuevo = nuevo->siguiente;
	}
}
void lista::mostrarUno(int x) {
	nodo *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con!=true)
	{
		if (nuevo->valor.id == x) {
			cout << nuevo->valor.x << endl;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}
void lista::modificar(int x) {
	nodo *nuevo;
	nuevo = inicio;
	bool con = false;

	string cam;

	while (con != true)
	{
		if (nuevo->valor.id == x) {
			cout << "Ingrese el nuevo valor" << endl;
			cin >> cam;
			nuevo->valor.x = cam;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}
int main() {
	lista miLis;
	ejem uno;

	uno.id = 1;
	uno.x = "uno";
	miLis.insertar(uno);
	uno.id = 2;
	uno.x = "dos";
	miLis.insertar(uno);
	uno.id = 3;
	uno.x = "tres";
	miLis.insertar(uno);
	miLis.mostrar();

	miLis.borrar(3);
	cout <<endl<<endl;
	miLis.mostrar();

	uno.id = 4;
	uno.x = "cuatro";
	miLis.insertar(uno);
	uno.id = 5;
	uno.x = "cinco";
	miLis.insertar(uno);
	uno.id = 6;
	uno.x = "sies";
	miLis.insertar(uno);
	cout << endl << endl;
	miLis.mostrar();

	miLis.borrar(5);
	cout << endl << endl;
	miLis.mostrar();

	miLis.borrar(6);
	miLis.borrar(1);
	cout << endl << endl;
	miLis.mostrar();

	uno.id = 7;
	uno.x = "siete";
	miLis.insertar(uno);
	cout << endl << endl;
	miLis.mostrar();

	//247
	cout << endl << endl;
	miLis.mostrarUno(9);
	miLis.borrar(8);
	cout << endl << endl;
	miLis.mostrar();

	cout << endl << endl;
	miLis.modificar(4);
	cout << endl << endl;
	miLis.mostrar();


	return 0;
}
