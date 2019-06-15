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
	while (nuevo || con != true)
	{
		if (nuevo->valor.id == x) {
			if (nuevo == inicio) {
				inicio->siguiente->anterior = NULL;
				inicio = inicio->siguiente;
			}
			else if (nuevo->valor.id == x) {
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
	miLis.borrar(2);
	cout << "otra"<<endl;
	miLis.mostrar();

	return 0;
}
