#include "../todo.h"

class factura{
    private:
        char cliente[30];
        int cant;
        int idCarro;
        float precio;
        float total;
        int idVendedor;
        float comicion;
    public:
        int id;
        char getCliente(){return cliente;}
        int getCant(){return cant;}
        int getIdCarro(){return idCarro;}
        float getPrecio(){return precio;}
        float getTotal(){return total;}
        int getIdVendedor(){return idVendedor;}
        float getComicion(){return comicion;}   

        void setCliente(int dato){cliente = dato;}
        void setCant(char dato){cant= dato;}
        void setIdCarro(int dato){idCarro= dato;}
        void setPrecio(float dato){precio= dato;}
        void setTotal(float dato){total= dato;}
        void setIdVendedor(int dato){idVendedor= dato;}
        void setComicion(float dato){comicion= dato;}       

};
class nodo {
public:
	nodo(factura v, nodo *ant = NULL, nodo *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}

private:
	factura valor;
	nodo *anterior;
	nodo *siguiente;

	friend class lista;
};
class lista {
public:
	lista(nodo *ini = NULL, nodo *fin = NULL) :inicio(ini), finali(fin) {}
	nodo *inicio;
	nodo *finali;
	void insertar(factura x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
};

void lista::insertar(factura x) {
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
		cout << nuevo->valor.getCliente() << endl;
		cout << nuevo->valor.getIdCarro() << endl;
		cout << nuevo->valor.getCant() << endl;
		cout << nuevo->valor.getPrecio() << endl;
		cout << nuevo->valor.getTotal() << endl;
		cout << nuevo->valor.getIdVendedor() << endl;
		cout << nuevo->valor.getComicion() << endl;
		cout << "-----------------------------------"<<endl;
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
			cout << nuevo->valor.getCliente() << endl;
			cout << nuevo->valor.getIdCarro() << endl;
			cout << nuevo->valor.getCant() << endl;
			cout << nuevo->valor.getPrecio() << endl;
			cout << nuevo->valor.getTotal() << endl;
			cout << nuevo->valor.getIdVendedor() << endl;
			cout << nuevo->valor.getComicion() << endl;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}

