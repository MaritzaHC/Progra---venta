#include "../todo.h"
class Empleados
{
	private:
		int Edad;
		float Sueldo,comisiones;
		string Nombre;
	public:
		Empleados(){}
		int Codigo;
		void setCodigo(int c){ Codigo=c;		}
		void setEdad(int e){ Edad=e;		}
		void setSueldo(float s) {Sueldo= s;		}
		void setComisiones(float c) { comisiones = c;		}
		void setNombre(string n){ Nombre = n;		}
		int getCodigo(){ return Codigo;		}
		float getSueldo() {return Sueldo;		}
		float getComisiones(){ return comisiones;		}
		string getNombre(){ return Nombre;		}
		int getEdad(){ return Edad;		}
		void registrarEmpleado();
		//void consultarEmpleado();
		//void eliminarEmpleado();
		//void modificarEmpleado();
};
void Empleados::registrarEmpleado()
{
	int edad;
	string s;
	float sueldo,comision;
	cout<<"Ingrese el Nombre del Empleado"<<endl; fflush(stdin); getline(cin,s); setNombre(s);
	cout<<"Ingrese la Edad del Empleado"<<endl; fflush(stdin); cin>>edad; setEdad(edad);
	cout<<"Ingrese el Sueldo del Empleado"<<endl; fflush(stdin); cin>>sueldo; setSueldo(sueldo);
	cout<<"Ingrese la comision del Empleado"<<endl; fflush(stdin); cin>>comision; setComisiones(comision);
}
class nodo 
{
	public:
		nodo(ejem v, nodo *ant = NULL, nodo *sig = NULL) :
			valor(v), anterior(ant), siguiente(sig) {}
	private:
		Empleados valor;
		nodo *anterior;
		nodo *siguiente;
		friend class lista;
};
class lista {
public:
	lista(nodo *ini = NULL, nodo *fin = NULL) :inicio(ini), finali(fin) {}
	nodo *inicio;
	nodo *finali;
	void insertar(Empleados x);
	void borrar(int x);
	void mostrar();
	void mostrarUno(int x);
	void modificar(int x);
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
			Codigo=1;
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
void lista::borrar(int x) {
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Empleado.dat",ios::in|ios::binary);
	if (salida.fail()||entrada.fail())
	{
		cout<<"error al abrir el archivo"<<endl;
		_getch();                  
	}
	else
	{
		nodo *nuevo;
		nuevo = inicio;
		bool con = false;
		while (con != true)
		{
			if (nuevo->valor.id == x) 
			{
				entrada.write((char *)Lista,sizeof(Empleados));
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
				entrada.write((char *)Lista,sizeof(Empleados));
				con = true; 
				cout << "No se pudo borrar" << endl;
			}
			else nuevo = nuevo->siguiente; 
		}
	}
	salida.close();
	entrada.close();
	remove("Empleado.dat");
	rename("tempEmpleado.dat","Empleado.dat");
}
void lista::mostrar() {
	nodo *nuevo;
	nuevo = inicio;
	while (nuevo)
	{
		cout << nuevo->valor.getNombre()<< endl;
		cout << nuevo->valor.getEdad() << endl;
		cout << nuevo->valor.getSueldo() << endl;
		cout << nuevo->valor.getComisiones() << endl;
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
			cout << nuevo->valor.getNombre() << endl;
			cout << nuevo->valor.getEdad() << endl;
			cout << nuevo->valor.getSueldo() << endl;
			cout << nuevo->valor.getComisiones() << endl;
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
	string nom;
	int ed;
	float cam;

	while (con != true)
	{
		if (nuevo->valor.Codigo == x) {
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
	Empleados *p[100];
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
	 nreg=salida.tellg()/sizeof(Empleados);
     salida.seekg(0);  
     for( x=0;x<nreg;x++)
              {
				  p[x]=new Empleados();
				  salida.read((char *)p[x],sizeof(Empleados));	
				  Insertar(p[x]);
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
	Empleados *x;
	if(valor!=NULL)
	{
		x=valor;
		while(x->siguiente!=valor)
		{
			entrada.write((char *)x,sizeof(Empleados));
			x=x->siguiente;
		}
		entrada.write((char *)x,sizeof(Empleados));
	}
	remove("Empleado.dat");
	rename("tempEmpleado.dat","Empleado.dat");
	entrada.close();
}
