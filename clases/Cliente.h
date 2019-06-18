/*
	Name:Progra---venta 
	Author: Hugo Jessael Jirano Macias 18310154
			Maritza Hernandez Contreras 18310135
	Date: 17/06/19 19:11
	Description: clase cliente
*/
#include "../todo.h"
class Cliente{
	private:
		char NombreCliente[20],RFC[20],Domicilio[20],Telefono[20];
	public:
		int Codigo;
		Cliente(){}
		Cliente *siguiente,*anterior;
		void setCodigoCliente(int c){ Codigo = c;		}
		void setNombreCliente(char *n){ strcpy(NombreCliente,n);		}
		void setRFC(char *r){ strcpy(RFC,r);}
		void setDomicilio(char *d){ strcpy(Domicilio,d);	}
		void setTelefono(char *t){ strcpy(Telefono,t);		}
		int getCodigoCliente(){ return Codigo;		}
		char* getNombreCliente(){ return NombreCliente;		}
		char* getRFC(){ return RFC;}
		char* getDomicilio(){return Domicilio;		}
		char* getTelefono(){ return Telefono;		}
		void registrarCliente();
		void consultarCliente();
};
void Cliente::registrarCliente(){
	char nom[20],rfc[20],dom[20],tel[20];
	cout<<"Ingrese el Nombre del Cliente"<<endl; fflush(stdin); cin>>nom; setNombreCliente(nom);
	cout<<"Ingrese el RFC del Cliente"<<endl; fflush(stdin); cin>>rfc; setRFC(rfc);
	cout<<"Ingrese el Domicilio del Cliente"<<endl; fflush(stdin); cin>>dom; setDomicilio(dom);
	cout<<"Ingrese el Telefono del Cliente"<<endl; fflush(stdin); cin>>tel; setTelefono(tel);
}
void Cliente::consultarCliente(){
	
	cout<<"Nombre:     "<<getNombreCliente();
	cout<<"RFC:        "<<getRFC();
	cout<<"Domicilio:  "<<getDomicilio();
	cout<<"Telefono:   "<<getTelefono();
}
class NodoCliente {
	public:
		NodoCliente(Cliente v, NodoCliente *ant = NULL, NodoCliente *sig = NULL) :
			valor(v), anterior(ant), siguiente(sig) {}
		NodoCliente(Cliente *v, NodoCliente *ant=NULL, NodoCliente *sig = NULL) :
			valor(*v), anterior(ant), siguiente(sig) {}
	private:
		NodoCliente(){}
		Cliente valor;
		NodoCliente *anterior;
		NodoCliente *siguiente;
		friend class ListaCliente;
};
class ListaCliente{
public:
	int Codigo,Longitud;
	NodoCliente *Lista;
	ListaCliente(NodoCliente *ini = NULL, NodoCliente *fin = NULL) :inicio(ini), finali(fin) {Codigo=0;}
	NodoCliente *inicio;
	NodoCliente *finali;
	void Insertar(Cliente x);
	void InsertarCliente(NodoCliente p);
	void Borrar(char *x);
	void Mostrar();
	void MostrarUno(char *x);
	void Modificar(char *x);
	void CargarArchivo();
	void RecargarArchivo();
};
void ListaCliente::Insertar(Cliente x) {
	NodoCliente *nuevo;
	ofstream entrada;
	entrada.open("Cliente.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
        cout<<"error al crear archivo";
        _getch();      
	}   
	else
	{
		if (inicio == NULL) 
		{
			nuevo = new NodoCliente(x, inicio);
			entrada.write((char *)nuevo,sizeof(NodoCliente));
			entrada.close();
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new NodoCliente(x, finali);
			entrada.write((char *)nuevo,sizeof(NodoCliente));
			entrada.close();
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
	}
	entrada.close();
}
void ListaCliente::Borrar(char *x) {
		NodoCliente *nuevo;
		nuevo = inicio;
		bool con = false;
		while (con!=true)
		{
			if (strcmp(nuevo->valor.getNombreCliente(),x)==0)
			{
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
			if (con == true)delete nuevo;
			else if (nuevo->siguiente == NULL) {
				con = true; 
				cout << "No se pudo borrar" << endl;
			}
			else{
				nuevo = nuevo->siguiente;
			} 
	}
RecargarArchivo();
}
void ListaCliente::InsertarCliente(NodoCliente p){
	NodoCliente *nuevo;
		if (inicio == NULL) 
		{
			nuevo = new NodoCliente(p);
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new NodoCliente(p);
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
}
void ListaCliente::Mostrar() {
	NodoCliente *nuevo;
	nuevo = inicio;
	while (nuevo!=NULL)
	{
		cout <<"Nombre :\t"<< nuevo->valor.getNombreCliente()<< endl;
		cout <<"RFC :\t"<< nuevo->valor.getRFC() << endl;
		cout <<"Domicilio :\t"<< nuevo->valor.getDomicilio() << endl;
		cout <<"Telefono :\t"<< nuevo->valor.getTelefono() << endl;
		cout << "--------------------------------"<<endl;
		nuevo = nuevo->siguiente;
	}
}
void ListaCliente::MostrarUno(char *x) {
	NodoCliente *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con!=true)
	{
		if (strcmp(nuevo->valor.getNombreCliente(),x)==0) {
			cout <<"Nombre:     "<< nuevo->valor.getNombreCliente() << endl;
			cout <<"RFC:        "<< nuevo->valor.getRFC() << endl;
			cout <<"Domicilio:  "<< nuevo->valor.getDomicilio() << endl;
			cout <<"Telefono:   "<< nuevo->valor.getTelefono() << endl;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}
void ListaCliente::Modificar(char *x) {
	NodoCliente *nuevo;
	nuevo = inicio;
	bool con = false;
	char nom[20],rfc[20],dom[20],tel[20];
	while (con != true)
	{
		if (strcmp(nuevo->valor.getNombreCliente(),x)==0) {
			cout << "Ingrese el Nombre" << endl;
			cin >> nom;
			nuevo->valor.setNombreCliente(nom);
			cout << "Ingrese el RFC" << endl;
			cin >> rfc;
			nuevo->valor.setRFC(rfc);
			cout << "Ingrese el Domicilio" << endl;
			cin >> dom;
			nuevo->valor.setDomicilio(dom);
			cout << "Ingrese el Telefono" << endl;
			cin >> tel;
			nuevo->valor.setTelefono(tel);
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
void ListaCliente::CargarArchivo(){
	 NodoCliente p[100];
	 ifstream salida;
     salida.open("Cliente.dat",ios::in|ios::binary);
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos de clientes guardados"<<endl;
     _getch();      
	 system("cls");
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);
	 nreg=salida.tellg()/sizeof(NodoCliente);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  salida.read((char *)&p[x],sizeof(NodoCliente));	
				  InsertarCliente(p[x]);
              }
	 if(x>0){
	 cout<<"Datos de Clientes cargados :3 :"<<x<<endl;
	  Codigo=Codigo+(2*x);
	 }
     _getch();
	 system("cls");
     }
	 salida.close();
}
void ListaCliente::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempCliente.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Cliente.dat",ios::in|ios::binary);
	NodoCliente *nuevo;
	nuevo=inicio;
		while(nuevo!=NULL)
		{
			entrada.write((char *)nuevo,sizeof(NodoCliente));
			nuevo=nuevo->siguiente;
		}
		entrada.close();
		salida.close();
	remove("Cliente.dat");
	rename("tempCliente.dat","Cliente.dat");
	entrada.close();
}
