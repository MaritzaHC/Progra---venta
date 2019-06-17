#include "../todo.h"

class carros{
    private:
        string marca;
        string modelo;
        int aa;
        bool tipo;
        float precio;
    public:
    	int id;
        string getMarca(){return marca;}
        string getModelo(){return modelo;}
        int getAa(){return aa;}
        bool getTipo(){return tipo;}
        float getPrecio(){return precio;}
        void setMarca(string dato){marca=dato;}
        void setModelo(string dato){modelo=dato;}
        void setAa(int dato){aa=dato;}
        void setTipo(bool dato){tipo=dato;}
        void setPrecio(float dato){precio=dato;}
        
        void registrarCarros();
};
class nodoC {
public:
	nodoC(carros v, nodoC *ant = NULL, nodoC *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}

private:
	carros valor;
	nodoC *anterior;
	nodoC *siguiente;

	friend class listaC;
};
class listaC {
public:
	listaC(nodoC *ini = NULL, nodoC *fin = NULL) :inicio(ini), finali(fin) {}
	nodoC *inicio;
	nodoC *finali;
	void insertar(carros x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
	void modificar(int x);
};

void listaC::insertar(carros x) {
	nodoC *nuevo;
	if (inicio == NULL) {
		nuevo = new nodoC(x, inicio);
		inicio = nuevo;
		finali = nuevo;
	}
	else {
		nuevo = new nodoC(x, finali);
		finali->siguiente = nuevo;
		nuevo->anterior = finali;
		finali = nuevo;
	}
}
void listaC::borrar(int x) {
	nodoC *nuevo;
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
void listaC::mostrar() {
	nodoC *nuevo;
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
void listaC::mostrarUno(int x) {
	nodoC *nuevo;
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
void listaC::modificar(int x) {
	nodoC *nuevo;
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
	string s;
	int a;
	float prec;
	cout << "Ingrese el modelo: ";
	fflush(stdin); getline(cin,s); setModelo(s);
	cout << "Ingrese la marca: ";
	fflush(stdin); getline(cin,s); setMarca(s);
	cout << "Ingrese el aa: ";
	fflush(stdin); cin >> a; setAa(a);
	cout << "Ingrese el precio: ";
	fflush(stdin); cin >> prec; setPrecio(prec);
}
