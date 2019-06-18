/*
	Name:Progra---venta 
	Author: Hugo Jessael Jirano Macias 18310154
			Maritza Hernandez Contreras 18310135
	Date: 17/06/19 19:11
	Description: clase carros
*/
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
		carros(){}
        char* getMarca(){return marca;}
        char* getModelo(){return modelo;}
        int getAa(){return aa;}
        bool getTipo(){return tipo;}
        float getPrecio(){return precio;}
        void setMarca(char *dato){strcpy(marca,dato);}
        void setModelo(char *dato){strcpy(modelo,dato);}
        void setAa(int dato){aa=dato;}
        void setTipo(bool dato){tipo=dato;}
        void setPrecio(float dato){precio=dato;}
        
        void registrarCarros();
};
class nodoCarro {
public:
	nodoCarro(carros v, nodoCarro *ant = NULL, nodoCarro *sig = NULL) :
		valor(v), anterior(ant), siguiente(sig) {}
	nodoCarro(carros *v, nodoCarro *ant=NULL, nodoCarro *sig = NULL) :
			valor(*v), anterior(ant), siguiente(sig) {}
private:
	nodoCarro(){}
	carros valor;
	nodoCarro *anterior;
	nodoCarro *siguiente;

	friend class listaCarros;
};
class listaCarros {
public:
	int id;
	listaCarros(nodoCarro *ini = NULL, nodoCarro *fin = NULL) :inicio(ini), finali(fin) {id=0;}
	nodoCarro *inicio;
	nodoCarro *finali;
	void insertar(carros x);
	void InsertarCarros(nodoCarro p);
	void borrar(char *x);
	void mostrar();
	void mostrarUno(char *x);
	void modificar(char *x);
	void CargarArchivo();
	void RecargarArchivo();
};

void listaCarros::insertar(carros x) {
	nodoCarro *nuevo;
	ofstream entrada;
	entrada.open("carros.dat",ios::out|ios::app|ios::binary);//Creamos un archivo binario cliente con nombre carros.dat
	if(entrada.fail()){
        cout<<"error al crear archivo";
        _getch();      
	}  
	else{
		if (inicio == NULL) {
			nuevo = new nodoCarro(x, inicio);
			entrada.write((char *)nuevo,sizeof(nodoCarro));//Escritura en el archivo carros.dat con la informacion de la clase carros
			entrada.close();//Cierra Archivo carros.dat
			inicio = nuevo;
			finali = nuevo;
		}
		else {
			nuevo = new nodoCarro(x, finali);
			entrada.write((char *)nuevo,sizeof(nodoCarro));//Escritura en el archivo carros.dat con la informacion de la clase carros
			entrada.close();//Cierra Archivo carros.dat
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
	} 
	entrada.close();
}
void listaCarros::borrar(char *x) {
	nodoCarro *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con != true)
	{
		if (strcmp(nuevo->valor.getModelo(),x)==0) {
			if(inicio == finali)
				{
					cout<<"Hola"<<endl;
					finali = NULL;
					inicio = NULL;
				}
			else if (nuevo == inicio) {
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
void listaCarros::InsertarCarros(nodoCarro p){
	nodoCarro *nuevo;
		if (inicio == NULL) 
		{
			nuevo = new nodoCarro(p);
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new nodoCarro(p);
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
}
void listaCarros::mostrar() {
	nodoCarro *nuevo;
	nuevo = inicio;
	while (nuevo)
	{
		cout << "Marca:   " << nuevo->valor.getMarca() << endl;
		cout << "Modelo:  " << nuevo->valor.getModelo() << endl;
		cout << "Aa:      " << nuevo->valor.getAa() << endl;
		cout << "Precio:  " << nuevo->valor.getPrecio() << endl;
		cout << "--------------------------------"<<endl;
		nuevo = nuevo->siguiente;
	}
}
void listaCarros::mostrarUno(char *x) {
	nodoCarro *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con!=true)
	{
		if (strcmp(nuevo->valor.getModelo(),x)==0) {
			cout << "Marca:   " << nuevo->valor.getMarca() << endl;
			cout << "Modelo:  " << nuevo->valor.getModelo() << endl;
			cout << "Aa:      " << nuevo->valor.getAa() << endl;
			cout << "Precio:  " << nuevo->valor.getPrecio() << endl;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}
void listaCarros::modificar(char *x) {
	nodoCarro *nuevo;
	nuevo = inicio;
	bool con = false;

	float cam;

	while (con != true)
	{
		if (strcmp(nuevo->valor.getModelo(),x)==0) {
			cout << "Ingrese el nuevo precio" << endl;
			cin >> cam;
			nuevo->valor.setPrecio(cam);
			con = true;
			RecargarArchivo();
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}

void carros::registrarCarros(){
	char s[10];
	int a;
	float prec;
	cout << "Ingrese el modelo: ";
	fflush(stdin); cin>>s; setModelo(s);
	cout << "Ingrese la marca: ";
	fflush(stdin); cin>>s; setMarca(s);
	cout << "Ingrese el aa: ";
	fflush(stdin); cin >> a; setAa(a);
	cout << "Ingrese el precio: ";
	fflush(stdin); cin >> prec; setPrecio(prec);
}
void listaCarros::CargarArchivo(){
	nodoCarro p[100];
	ifstream salida;
     salida.open("carros.dat",ios::in|ios::binary);//Abrimos archivo carros.dat para cargar los datos en el programa
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos de carros guardados"<<endl;
     _getch();      
	 system("cls");
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);//Manda la posicion del siguiente caracter extraido desde la entrada
	 nreg=salida.tellg()/sizeof(nodoCarro);//Me dice cuantos son los elementos que tiene el archivo
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  salida.read((char *)&p[x],sizeof(nodoCarro));	//Lee el nodo y lo copia a p
				  InsertarCarros(p[x]);// Manda como parametros p y lo inserta al archivo
              }
	 if(x>0){
	 cout<<"Datos de carros cargados :3 :"<<x<<endl;
	  id=id+(2*x);
	 }
	 system("cls");
     }
	 salida.close();//Cierra el archivo
}
void listaCarros::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempCarros.dat",ios::out|ios::binary);//Creacion de archivo temporal binario tempCarros.dat
	ifstream salida;
	salida.open("carros.dat",ios::in|ios::binary);//Abre archivo carros.dat
	nodoCarro *nuevo;
	nuevo=inicio;
		while(nuevo!=NULL)
		{
			entrada.write((char *)nuevo,sizeof(nodoCarro));
			nuevo=nuevo->siguiente;
		}
		entrada.close();
		salida.close();
	remove("carros.dat");//Eliminacion del archivo carros.dat
	rename("tempCarros.dat","carros.dat");//Cambio de nombre de tempCarros.dat a carros.dat
	entrada.close();
}
