#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class Empleados
{
	private:
		int Codigo, Edad;
		float Sueldo,comisiones;
		char Nombre[20];
		Empleados *siguiente,*anterior;
	public:
		Empleados(int cod,char *nom,int eda,float sueld,int longitud){ Codigo=cod; Edad=eda; Sueldo=sueld; comisiones=0; strcpy(Nombre,nom);		}
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
		void consultarEmpleado();
		void eliminarEmpleado();
		void modificarEmpleado();
		friend class ListaEmpleados;
};
void Empleados::registrarEmpleado()
{
	int c=0,edad;
	string s;
	float sueldo,comision;
	setCodigo(c+1);
	cout<<"Ingrese el Nombre del Empleado"<<endl; fflush(stdin); getline(cin,s); setNombre(s);
	cout<<"Ingrese la Edad del Empleado"<<endl; fflush(stdin); cin>>edad; setEdad(edad);
	cout<<"Ingrese el Sueldo del Empleado"<<endl; fflush(stdin); cin>>sueldo; setSueldo(sueldo);
	cout<<"Ingrese la comision del Empleado"<<endl; fflush(stdin); cin>>comision; setComisiones(comision);
	
}
void Empleados::consultarEmpleado()
{
	cout<<"Nombre :\t"<<Nombre<<endl;
	cout<<"Edad :\t"<<Edad<<endl;
	cout<<"Sueldo :\t"<<Sueldo<<endl;
	cout<<"Comision :\t"<<Comision<<endl;
}



class ListaEmpleados{
	private:
		int Longitud,Codigo;
		Empleados *Lista;
	public:
		ListaEmpleados(){ Lista=NULL;	}
		~ListaEmpleados();
		void Insertar(char *nom,int eda,float sueld,float comisi);
		void Insertar(Empleados *p);
		void CargarArchivo();
		void ordenar();
		void consultartodos();
 		void consultaruno(char *nom);
 		bool listaVacia(){ return Lista==NULL;	}
 		bool Actual(){ return Lista != NULL;}
 		
		
};
ListaEmpleados::~ListaEmpleados()
{
	pnodo aux;
	Primero();
	while(plista)
	{
		aux=plista;
		plista=plista->siguiente;
		delete aux;
	}
}
void ListaEmpleados::siguiente()
{
	if(Lista)
	{
		Lista=Lista->siguiente;
	}
}
void ListaEmpleados::anterior()
{
	if(Lista)
	{
		Lista=Lista->anterior;
	}
}
