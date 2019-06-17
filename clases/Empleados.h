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
	cout<<"Nombre :\t"<<getNombre();
	cout<<"Edad :\t"<<getEdad();
	cout<<"Sueldo :\t"<<getSueldo();
	cout<<"Comision :\t"<<getComisiones();
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
	entrada.open("Empleado.dat",ios::out|ios::app|ios::binary);
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
			entrada.write((char *)nuevo,sizeof(nodo));
			entrada.close();
			inicio = nuevo;
			finali = nuevo;
		}
		else 
		{
			nuevo = new nodo(x, finali);
			entrada.write((char *)nuevo,sizeof(nodo));
			entrada.close();
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
		cout <<"Nombre :\t"<< nuevo->valor.getNombre()<< endl;
		cout <<"Edad :\t"<< nuevo->valor.getEdad() << endl;
		cout <<"Sueldo :\t"<< nuevo->valor.getSueldo() << endl;
		cout <<"Comision :\t"<< nuevo->valor.getComisiones() << endl;
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
			cout <<"Nombre :\t"<< nuevo->valor.getNombre() << endl;
			cout <<"Edad :\t"<< nuevo->valor.getEdad() << endl;
			cout <<"Sueldo :\t"<< nuevo->valor.getSueldo() << endl;
			cout <<"Comision :\t"<< nuevo->valor.getComisiones() << endl;
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
     salida.open("Empleado.dat",ios::in|ios::binary);
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
     salida.seekg(0,ios::end);
	 nreg=salida.tellg()/sizeof(nodo);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  salida.read((char *)&p[x],sizeof(nodo));	
				  InsertarEmpleado(p[x]);
              }
	 if(x>0){
	 cout<<"Datos de Empleados cargados :3 :"<<x<<endl;
	  Codigo=Codigo+(2*x);
	 }
     _getch();
	 system("cls");
     }
	 salida.close();
}
void lista::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Empleado.dat",ios::in|ios::binary);
	nodo *nuevo;
	nuevo=inicio;
		while(nuevo!=NULL)
		{
			entrada.write((char *)nuevo,sizeof(nodo));
			nuevo=nuevo->siguiente;
		}
		entrada.close();
		salida.close();
	remove("Empleado.dat");
	rename("tempEmpleado.dat","Empleado.dat");
	entrada.close();
}
