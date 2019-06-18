/*
	Name:Progra---venta 
	Author: Hugo Jessael Jirano Macias 18310154
			Maritza Hernandez Contreras 18310135
	Date: 17/06/19 19:11
	Description: clase empleado
*/
#include "../todo.h"
class Empleados{
	private:
		int Edad;
		float Sueldo,comisiones;
		char Nombre[20];
	public:
		int Codigo;
		Empleados(){}
		Empleados *siguiente,*anterior;
		void setCodigo(int c){ Codigo=c;		}
		void setEdad(int e){ Edad=e;		}
		void setSueldo(float s) {Sueldo= s;		}
		void setComisiones(float c) { comisiones = c;		}
		void setNombre(char *n){ strcpy(Nombre,n);		}
		int getCodigo(){ return Codigo;		}
		float getSueldo() {return Sueldo;		}
		float getComisiones(){ return comisiones;		}
		char* getNombre(){ return Nombre;		}
		int getEdad(){ return Edad;		}
		void registrarEmpleado();
		void ConsultarEmpleado();
		//void eliminarEmpleado();
		//void modificarEmpleado();
};
void Empleados::registrarEmpleado(){
	int edad;
	char s[20];
	float sueldo,comision;
	cout<<"Ingrese el Nombre del Empleado"<<endl; fflush(stdin); cin>>s; setNombre(s);
	cout<<"Ingrese la Edad del Empleado"<<endl; fflush(stdin); cin>>edad; setEdad(edad);
	cout<<"Ingrese el Sueldo del Empleado"<<endl; fflush(stdin); cin>>sueldo; setSueldo(sueldo);
	cout<<"Ingrese la comision del Empleado"<<endl; fflush(stdin); cin>>comision; setComisiones(comision);
}
void Empleados::ConsultarEmpleado(){
	cout<<"Nombre:    "<<getNombre();
	cout<<"Edad:      "<<getEdad();
	cout<<"Sueldo:    "<<getSueldo();
	cout<<"Comision:  "<<getComisiones();
}
class nodo {
	public:
		nodo(Empleados v, nodo *ant = NULL, nodo *sig = NULL) :
			valor(v), anterior(ant), siguiente(sig) {}
		nodo(Empleados *v, nodo *ant=NULL, nodo *sig = NULL) :
			valor(*v), anterior(ant), siguiente(sig) {}
			
	private:
		nodo(){	}
		Empleados valor;
		nodo *anterior;
		nodo *siguiente;
		friend class lista;
};
class lista {
public:
	int Codigo,Longitud;
	nodo *Lista;
	lista(nodo *ini = NULL, nodo *fin = NULL) :inicio(ini), finali(fin) {Codigo=0;}
	nodo *inicio;
	nodo *finali;
	void insertar(Empleados x);
	void InsertarEmpleado(nodo p);
	void borrar(char *x);
	void mostrar();
	void mostrarUno(char *x);
	void modificar(char *x);
	void CargarArchivo();
	void RecargarArchivo();
};
void lista::insertar(Empleados x) {
	nodo *nuevo;
	ofstream entrada;
	entrada.open("Empleado.dat",ios::out|ios::app|ios::binary);//Creamos un archivo binario cliente con nombre Empleado.dat
	if(entrada.fail())
	{
        cout<<"error al crear archivo";
        _getch();      
	}   
	else
	{
		if (inicio == NULL) 
		{
			nuevo = new nodo(x, inicio);
			entrada.write((char *)nuevo,sizeof(nodo));//Escritura en el archivo Cliente.dat con la informacion de la clase Empleados
			entrada.close();//Cierra Archivo Cliente.dat
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new nodo(x, finali);
			entrada.write((char *)nuevo,sizeof(nodo));//Escritura en el archivo Cliente.dat con la informacion de la clase Cliente
			entrada.close();//Cierra Archivo Cliente.dat
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
	}
	entrada.close();
}
void lista::borrar(char *x) {
		nodo *nuevo;
		nuevo = inicio;
		bool con = false;
		while (con!=true)
		{
			if (strcmp(nuevo->valor.getNombre(),x)==0)
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
			if (con == true)
			{
				cout<<"Hola1";
				delete nuevo;
				cout<<"Hola2";
			}
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
void lista::InsertarEmpleado(nodo p){
	nodo *nuevo;
		if (inicio == NULL) 
		{
			nuevo = new nodo(p);
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new nodo(p);
			finali->siguiente = nuevo;
			nuevo->anterior = finali;
			finali = nuevo;
		}
}
void lista::mostrar() {
	nodo *nuevo;
	nuevo = inicio;
	while (nuevo!=NULL)
	{
		cout <<"Nombre:   "<< nuevo->valor.getNombre()<< endl;
		cout <<"Edad:     "<< nuevo->valor.getEdad() << endl;
		cout <<"Sueldo:   "<< nuevo->valor.getSueldo() << endl;
		cout <<"Comision: "<< nuevo->valor.getComisiones() << endl;
		cout << "--------------------------------"<<endl;
		nuevo = nuevo->siguiente;
	}
}
void lista::mostrarUno(char *x) {
	nodo *nuevo;
	nuevo = inicio;
	bool con = false;
	while (con!=true)
	{
		if (strcmp(nuevo->valor.getNombre(),x)==0) {
			cout <<"Nombre:   "<< nuevo->valor.getNombre() << endl;
			cout <<"Edad:     "<< nuevo->valor.getEdad() << endl;
			cout <<"Sueldo:   "<< nuevo->valor.getSueldo() << endl;
			cout <<"Comision: "<< nuevo->valor.getComisiones() << endl;
			con = true;
		}
		else if (nuevo->siguiente == NULL) {
			cout << "No se encontro" << endl;
			con = true;
		}
		else nuevo = nuevo->siguiente;
	}
}
void lista::modificar(char *x) {
	nodo *nuevo;
	nuevo = inicio;
	bool con = false;
	char nom[20];
	int ed;
	float cam;

	while (con != true)
	{
		if (strcmp(nuevo->valor.getNombre(),x)==0) {
			cout << "Ingrese el Nombre" << endl;
			cin >> nom;
			nuevo->valor.setNombre(nom);
			cout << "Ingrese la Edad" << endl;
			cin >> ed;
			nuevo->valor.setEdad(ed);
			cout << "Ingrese el Sueldo" << endl;
			cin >> cam;
			nuevo->valor.setSueldo(cam);
			cout << "Ingrese la Comision" << endl;
			cin >> cam;
			nuevo->valor.setComisiones(cam);
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
void lista::CargarArchivo(){
	nodo p[100];
	ifstream salida;
     salida.open("Empleado.dat",ios::in|ios::binary);//Abrimos archivo Empleado.dat para cargar los datos en el programa
     int x;
     if (salida.fail())
     {
     cout<<"No existen datos de empleados guardados"<<endl;
     _getch();      
	 system("cls");
     }
     else       
     {
     int nreg;
     salida.seekg(0,ios::end);//Manda la posicion del siguiente caracter extraido desde la entrada
	 nreg=salida.tellg()/sizeof(nodo);//Me dice cuantos son los elementos que tiene el archivo
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  salida.read((char *)&p[x],sizeof(nodo));	//Lee el nodo y lo copia a p
				  InsertarEmpleado(p[x]);// Manda como parametros p y lo inserta al archivo
              }
	 if(x>0){
	 cout<<"Datos de Empleados cargados :3 :"<<x<<endl;
	  Codigo=Codigo+(2*x);
	 }
	 system("cls");
     }
	 salida.close(); //Cierra el archivo
}
void lista::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);//Creacion de archivo temporal binario tempEmpleado.dat
	ifstream salida;
	salida.open("Empleado.dat",ios::in|ios::binary);//Abre archivo Empleado.dat
	nodo *nuevo;
	nuevo=inicio;
		while(nuevo!=NULL)
		{
			entrada.write((char *)nuevo,sizeof(nodo));
			nuevo=nuevo->siguiente;
		}
		entrada.close();
		salida.close();
	remove("Empleado.dat");//Eliminacion del archivo Empleado.dat
	rename("tempEmpleado.dat","Empleado.dat");//Cambio de nombre de tempEmpleado.dat a Empleado.dat
	entrada.close();
}
