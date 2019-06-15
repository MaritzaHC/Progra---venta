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
		float Sueldo,Comision;
		char Nombre[20];
		Empleados *siguiente,*anterior;
	public:
		Empleados(){}
		Empleados(int cod,char *nom,int eda,float sueld,float comisi){ Codigo=cod; Edad=eda; Sueldo=sueld; Comision=comisi; strcpy(Nombre,nom);		}
		void setCodigo(int c){ Codigo=c;		}
		void setEdad(int e){ Edad=e;		}
		void setSueldo(float s) {Sueldo= s;		}
		void setComisiones(float c) { Comision = c;		}
		void setNombre(char *n){ strcpy(Nombre,n);		}
		int getCodigo(){ return Codigo;		}
		float getSueldo() {return Sueldo;		}
		float getComisiones(){ return Comision;		}
		char* getNombre(){ return Nombre;		}
		int getEdad(){ return Edad;}
		void ConsultarEmpleado();
		void eliminarEmpleado();
		void modificarEmpleado();
		friend class ListaEmpleados;
		bool ConsultarCodigo(int cod);
		bool Consultar(char *nom);
};
bool Empleados::Consultar(char *nom){
	
	if(strcmp(nom,Nombre) == 0)
	return true;
	else
	return false;
}
void Empleados::ConsultarEmpleado()
{
	cout<<"Nombre :\t"<<Nombre<<endl;
	cout<<"Edad :\t"<<Edad<<endl;
	cout<<"Sueldo :\t"<<Sueldo<<endl;
	cout<<"Comision :\t"<<Comision<<endl;
}
bool Empleados::ConsultarCodigo(int cod)
{
	if(Codigo==cod)
	return true;
	else
	return false;
}

