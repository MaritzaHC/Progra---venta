#include "../todo.h"

class carros{
    private:
        char marca[10];
        char modelo[10];
        int aa;
        bool tipo;
        float precio;
    public:
    	int id;
        char getMarca(){return *marca;}
        char getModelo(){return *modelo;}
        int getAa(){return aa;}
        bool getTipo(){return tipo;}
        float getPrecio(){return precio;}
        void setMarca(char dato[10]){*marca=dato;}
        void setModelo(char dato[10]){*modelo=dato;}
        void setAa(int dato){aa=dato;}
        void setTipo(bool dato){tipo=dato;}
        void setPrecio(float dato){precio=dato;}
        
        void registrarCarros();
};
class nodo {
public:
	nodo(carros v, nodo *ant = NULL, nodo *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}

private:
	carros valor;
	nodo *anterior;
	nodo *siguiente;

	friend class lista;
};
class lista {
public:
	lista(nodo *ini = NULL, nodo *fin = NULL) :inicio(ini), finali(fin) {}
	nodo *inicio;
	nodo *finali;
	void insertar(carros x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
	void modificar(int x);
};

void lista::insertar(carros x) {
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
		cout << nuevo->valor.getMarca() << endl;
		cout << nuevo->valor.getModelo() << endl;
		cout << nuevo->valor.getAa() << endl;
		cout << nuevo->valor.getPrecio() << endl;
		cout << "--------------------------------"<<endl;
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
			cout << nuevo->valor.getMarca() << endl;
			cout << nuevo->valor.getModelo() << endl;
			cout << nuevo->valor.getAa() << endl;
			cout << nuevo->valor.getPrecio() << endl;
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

	float cam;

	while (con != true)
	{
		if (nuevo->valor.id == x) {
			cout << "Ingrese el nuevo precio" << endl;
			cin >> cam;
			nuevo->valor.setPrecio(cam);
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}

void carros::registrarCarros(){
	char mar,mode;
	int a;
	float prec;
	cout << "Ingrese el modelo: ";
	cout << "Ingrese la marca: ";
	cout << "Ingrese el aa: ";
	cout << "Ingrese el precio: ";
}
