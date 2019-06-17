#include "../todo.h"

class factura{
    private:
        char cliente[20];
        int cant;
        int idCarro;
        float precio;
        float total;
        char nomVendedor[20];
        float comicion;
    public:
        int id;
        char* getCliente(){return cliente;}
        int getCant(){return cant;}
        int getIdCarro(){return idCarro;}
        float getPrecio(){return precio;}
        float getTotal(){return total;}
        char* getnomVendedor(){return nomVendedor;}
        float getComicion(){return comicion;}   

        void setCant(int dato){cant = dato;}
        void setCliente(char *dato){strcpy(cliente,dato);}
        void setIdCarro(int dato){idCarro= dato;}
        void setPrecio(float dato){precio= dato;}
        void setTotal(float dato){total= dato;}
        void setnomVendedor(char *dato){strcpy(nomVendedor,dato);}
        void setComicion(float dato){comicion= dato;}     
		
		void registrarFactura();  

};
class nodoFactura {
public:
	nodoFactura(factura v, nodoFactura *ant = NULL, nodoFactura *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}
	nodoFactura(factura *v, nodoFactura *ant=NULL, nodoFactura *sig = NULL) :
			valor(*v), anterior(ant), siguiente(sig) {}
private:
	nodoFactura(){}
	factura valor;
	nodoFactura *anterior;
	nodoFactura *siguiente;

	friend class listaFactura;
};
class listaFactura {
public:
	int id;
	int cantidad;
	listaFactura(nodoFactura *ini = NULL, nodoFactura *fin = NULL) :inicio(ini), finali(fin) {id=0;cantidad=0;}
	nodoFactura *inicio;
	nodoFactura *finali;
	void insertar(factura x);
	void Insertarfactura(nodoFactura p);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
	void modificar(int x);
	void CargarArchivo();
	void RecargarArchivo();
};

void listaFactura::insertar(factura x) {
	nodoFactura *nuevo;
	ofstream entrada;
	x.id=cantidad;
	cantidad++;
	entrada.open("factura.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail()){
        cout<<"error al crear archivo";
        _getch();      
	}  
	else{
		if (inicio == NULL) {
			nuevo = new nodoFactura(x, inicio);
			entrada.write((char *)nuevo,sizeof(nodoFactura));
			entrada.close();
			inicio = nuevo;
			finali = nuevo;
		}
		else {
			nuevo = new nodoFactura(x, finali);
			entrada.write((char *)nuevo,sizeof(nodoFactura));
			entrada.close();
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
	} 
	entrada.close();
}
void listaFactura::borrar(int x) {
	nodoFactura *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con != true)
	{
		if (nuevo->valor.id==x) {
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
	RecargarArchivo();
}
void listaFactura::Insertarfactura(nodoFactura p){
	nodoFactura *nuevo;
		if (inicio == NULL) 
		{
			nuevo = new nodoFactura(p);
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new nodoFactura(p);
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
}
void listaFactura::mostrar() {
	nodoFactura *nuevo;
	nuevo = inicio;
	while (nuevo)
	{
		cout << "Id: \t" << nuevo->valor.id << endl;
		cout << "Cliente: \t" << nuevo->valor.getCliente() << endl;
		cout << "Carro: \t" << nuevo->valor.getIdCarro() << endl;
		cout << "Cantidad: \t" << nuevo->valor.getCant() << endl;
		cout << "Precio: \t" << nuevo->valor.getPrecio() << endl;
		cout << "Total: \t" << nuevo->valor.getTotal() << endl;
		cout << "Vendedor: \t" << nuevo->valor.getnomVendedor() << endl;
		cout << "Comicion: \t" << nuevo->valor.getComicion() << endl;
		cout << "-----------------------------------"<<endl;
		nuevo = nuevo->siguiente;
	}
}
void listaFactura::mostrarUno(int x) {
	nodoFactura *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con!=true)
	{
		if (nuevo->valor.id == x) {
			cout << "Id: \t" << nuevo->valor.id << endl;
			cout << "Cliente: \t" << nuevo->valor.getCliente() << endl;
			cout << "Carro: \t" << nuevo->valor.getIdCarro() << endl;
			cout << "Cantidad: \t" << nuevo->valor.getCant() << endl;
			cout << "Precio: \t" << nuevo->valor.getPrecio() << endl;
			cout << "Total: \t" << nuevo->valor.getTotal() << endl;
			cout << "Vendedor: \t" << nuevo->valor.getnomVendedor() << endl;
			cout << "Comicion: \t" << nuevo->valor.getComicion() << endl;
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
	char s[20];
	int a;
	float prec;
	cout << "Ingrese el cliente: ";
	fflush(stdin); cin>>s; setCliente(s);
	cout << "Ingrese la cantidad: ";
	fflush(stdin); cin>>a; setCant(a);
	cout << "Ingrese el id carro: ";
	fflush(stdin); cin >> a; setIdCarro(a);
	cout << "Ingrese el precio: ";
	fflush(stdin); cin >> prec; setPrecio(prec);
	cout << "Ingrese el total: ";
	fflush(stdin); cin >> prec; setTotal(prec);
	cout << "Ingrese el id vendedor: ";
	fflush(stdin); cin >> s; setnomVendedor(s);
	cout << "Ingrese la comicion: ";
	fflush(stdin); cin >> prec; setComicion(prec);
}
void listaFactura::CargarArchivo(){
	nodoFactura p[100];
	ifstream salida;
     salida.open("factura.dat",ios::in|ios::binary);
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos de factura guardados"<<endl;
     _getch();      
	 cantidad=0;
	 system("cls");
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);
	 nreg=salida.tellg()/sizeof(nodoFactura);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  salida.read((char *)&p[x],sizeof(nodoFactura));	
				  Insertarfactura(p[x]);
              }
	 if(x>0){
	 cout<<"Datos de factura cargados :3 :"<<x<<endl;
	  id=id+(2*x);
	 }
     _getch();
	 cantidad=finali->valor.id+1;
	 system("cls");
     }
	 salida.close();
}
void listaFactura::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempfactura.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("factura.dat",ios::in|ios::binary);
	nodoFactura *nuevo;
	nuevo=inicio;
		while(nuevo!=NULL)
		{
			entrada.write((char *)nuevo,sizeof(nodoFactura));
			nuevo=nuevo->siguiente;
		}
		entrada.close();
		salida.close();
	remove("factura.dat");
	rename("tempfactura.dat","factura.dat");
	entrada.close();
}