#include "../todo.h"

class factura{
    private:
        string cliente;
        int cant;
        int idCarro;
        float precio;
        float total;
        int idVendedor;
        float comicion;
    public:
        int id;
        string getCliente(){return cliente;}
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
		
		void registrarFactura();  

};
class nodoF {
public:
	nodoF(factura v, nodoF *ant = NULL, nodoF *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}

private:
	factura valor;
	nodoF *anterior;
	nodoF *siguiente;

	friend class listaF;
};
class listaF {
public:
	listaF(nodoF *ini = NULL, nodoF *fin = NULL) :inicio(ini), finali(fin) {}
	nodoF *inicio;
	nodoF *finali;
	void insertar(factura x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
};

void listaF::insertar(factura x) {
	nodoF *nuevo;
	if (inicio == NULL) {
		nuevo = new nodoF(x, inicio);
		inicio = nuevo;
		finali = nuevo;
	}
	else {
		nuevo = new nodoF(x, finali);
		finali->siguiente = nuevo;
		nuevo->anterior = finali;
		finali = nuevo;
	}
}
void listaF::borrar(int x) {
	nodoF *nuevo;
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
void listaF::mostrar() {
	nodoF *nuevo;
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
void listaF::mostrarUno(int x) {
	nodoF *nuevo;
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

void factura::registrarFactura(){
	string s;
	int a;
	float prec;
	cout << "Ingrese el cliente: ";
	fflush(stdin); cin>>a; setCliente(a);
	cout << "Ingrese la cantidad: ";
	fflush(stdin); cin>>a; setCant(a);
	cout << "Ingrese el id carro: ";
	fflush(stdin); cin >> a; setIdCarro(a);
	cout << "Ingrese el precio: ";
	fflush(stdin); cin >> prec; setPrecio(prec);
	cout << "Ingrese el total: ";
	fflush(stdin); cin >> prec; setTotal(prec);
	cout << "Ingrese el id vendedor: ";
	fflush(stdin); cin >> a; setIdVendedor(a);
	cout << "Ingrese la comicion: ";
	fflush(stdin); cin >> prec; setComicion(prec);
}

