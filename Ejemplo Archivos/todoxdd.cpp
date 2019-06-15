#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"Empleados.h"
#define ASCENDENTE 1
#define DESCENDENTE 0
using namespace std;
class ListaEmpleados{
	private:
		int Longitud,Codigo;
		Empleados *Lista;
	public:
		ListaEmpleados(){ Lista=NULL;	}
		void Insertar(char *nom,int eda,float sueld,float comisi);
		void Insertar(Empleados *p);
		void CargarArchivo();
		void ordenar();
		void consultartodos();
 		void consultaruno(char *nom);
 		bool listaVacia(){ return Lista==NULL;	}
 		bool Actual(){ return Lista != NULL;}
		void Siguiente();
		void Anterior();
		void Ultimo();
		void Primero();
		void RecargarArchivo();
		void Editar(int cod);
		void ConsultarLista();
		void ConsultarListaNombre(char *nom);
		void Eliminar(int cod);
};
void ListaEmpleados::Insertar(char *nom,int eda,float sueld,float comisi)
{
	if(Lista==NULL) Codigo=1;
	ofstream entrada;
	entrada.open("Empleado.dat",ios::out|ios::app|ios::binary);
	if(entrada.fail())
	{
        cout<<"error al crear archivo";
        _getch();      
	}   
	else
	{
		Empleados *p= new Empleados(Codigo,nom,eda,sueld,comisi);
		entrada.write((char *)p,sizeof(Empleados));
		entrada.close();
		if(Lista==NULL)
		{
			Lista=p;
			p->siguiente=p;
			Longitud=1;
		}
		else
			{
			Empleados *x;
			p->siguiente=Lista;
			x=Lista;
			while(x->siguiente!=Lista)
			{
				x=x->siguiente;
			}
			x->siguiente=p;
		}
		cout<<"Tu Codigo es:"<<Codigo<<endl;
		Lista=p;
		Longitud++;
		Codigo++;
	}
  entrada.close();
}
void ListaEmpleados::Insertar(Empleados *p)
{
	if(Lista==NULL)
	{
		Lista=p;
		p->siguiente=p;
		Longitud=1;
		Codigo=1;
	}
	else
	{
		Empleados *x;
		p->siguiente=Lista;
		x=Lista;
		while(x->siguiente!=Lista)
		{
			x=x->siguiente;
		}
		x->siguiente=p;
	}
	Lista=p;
	Longitud++; 
	Codigo++;
	return;
}
void ListaEmpleados::Siguiente()
{
	if(Lista)
	{
		Lista=Lista->siguiente;
	}
}
void ListaEmpleados::Anterior()
{
	if(Lista)
	{
		Lista=Lista->anterior;
	}
}
void ListaEmpleados::Primero()
{
	while(Lista&&Lista->anterior)
	{
		Lista=Lista->anterior;
	}
}
void ListaEmpleados::Ultimo()
{
	while(Lista&&Lista->siguiente)
	{
		Lista=Lista->siguiente;
	}
}
void ListaEmpleados::RecargarArchivo(){
	ofstream entrada;
	entrada.open("tempEmpleado.dat",ios::out|ios::binary);
	ifstream salida;
	salida.open("Empleado.dat",ios::in|ios::binary);
	Empleados *x;
	if(Lista!=NULL)
	{
		x=Lista;
		while(x->siguiente!=Lista)
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
void ListaEmpleados::Editar(int cod)
{
	char nom[40];
	int edad;
	float sueldo,comi;
	bool igual;
	Empleados *x;
	x=Lista;
	for(int i=0; i<Longitud;i++)
	{
		igual=x->ConsultarCodigo(cod);
		if(igual==true)
		{
			x->ConsultarEmpleado();
	        cout<<"-------------------Ingresa datos a cambiar------------------------"<<endl;
			fflush(stdin);
			cout<<"Ingresa nombre"<<endl;
			cin>>nom;
			cout<<"Edad"<<endl;
			cin>>edad;
			fflush(stdin);
			cout<<"Ingresa sueldo"<<endl;
			cin>>sueldo;
			fflush(stdin);
			cout<<"Ingresa Comision"<<endl;
			cin>>comi;
			x->setNombre(nom);
			x->setEdad(edad);
			x->setSueldo(sueldo);
			x->setComisiones(comi);
		RecargarArchivo();
		return;
		}
		else
		{
			x=x->siguiente;
			igual=false;
		}
	}
		
}
void ListaEmpleados::ConsultarListaNombre(char *nom)
{
	bool igual;
	Empleados *x;
	x=Lista;
	for(int i=0; i<Longitud;i++)
	{
		igual=x->Consultar(nom);
		if(igual==true)
		{
			x->ConsultarEmpleado();
			return;
		}
		else
		{
			x=x->siguiente;
			igual=false;
		}
	}

}
void ListaEmpleados::CargarArchivo(){
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
void ListaEmpleados::Eliminar(int cod)
{
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
		Empleados *nodo;
		nodo=Lista;
		if((Lista->ConsultarCodigo(cod))==false)
		{
			entrada.write((char *)Lista,sizeof(Empleados));
		}
		do{
			if((Lista)->siguiente->ConsultarCodigo(cod)==false)
			{
			Lista = (Lista)->siguiente;
			entrada.write((char *)Lista,sizeof(Empleados));    
			}
		}while((Lista)->siguiente->ConsultarCodigo(cod)==false&& Lista != nodo);
		if((Lista)->siguiente->ConsultarCodigo(cod)==true) 
		{
			if(Lista == (Lista)->siguiente) 
			{
				delete(Lista);
				Lista = NULL;
				Longitud=0;
			}
			else 
			{
				nodo = (Lista)->siguiente;
				(Lista)->siguiente = nodo->siguiente;
				delete(nodo);
				Longitud=Longitud-1;
			}
		}
	}
	salida.close();
	entrada.close();
	remove("Empleado.dat");
	rename("tempEmpleado.dat","Empleado.dat");
}
void ListaEmpleados::ConsultarLista()
{
	Empleados *x;
	if(Lista!=NULL){
	x=Lista;
	while(x->siguiente!=Lista){
	cout<<"----------------------------------------------"<<endl;
	x->ConsultarEmpleado();
	cout<<"----------------------------------------------"<<endl;
	x=x->siguiente;
}
	x->ConsultarEmpleado();
	//	Lista =1 , 2 , 3
	}
	else
		cout<<"Sin Datos\n";
}


int main()
{
	ListaEmpleados listE;
	listE.CargarArchivo();
	int c,edad,opc=0;;
	char s[20];
	char nom[20];
	float sueldo,comision;
	do{
		cout<<"1.-Registar\n2.-Consultar\n3.-EliminarEmpleado\n4.-Modificar\n5.-Salir\n\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				cout<<"Ingrese el Nombre del Empleado"<<endl; fflush(stdin); cin>>s;
				cout<<"Ingrese la Edad del Empleado"<<endl; fflush(stdin); cin>>edad;
				cout<<"Ingrese el Sueldo del Empleado"<<endl; fflush(stdin); cin>>sueldo;
				cout<<"Ingrese la comision del Empleado"<<endl; fflush(stdin); cin>>comision;
				listE.Insertar(s,edad,sueldo,comision);
				break;
			case 2:
				{
				
					int opc2=0;
				cout<<"opc 1 no sirve xd1.-Consultar Toda la lista\n2.-Consultar por nombre\n\n";
				cin>>opc2;
				if(opc2==1)
				{
					listE.ConsultarLista();
				}
				else if(opc2==2)
				{
					cout<<"Ingresa el nombre de la persona que deseas buscar\n\n";
					cin>>nom;
					listE.ConsultarListaNombre(nom);
				}
				else
				{
					cout<<"Opcion invalida";
				}
				break;
				}
			case 3:
				cout<<"Ingresa el codigo que deseas eliminar\n";
				cin>>c;
				listE.Eliminar(c);
				break;
			case 4:
				cout<<"Ingresa el codigo que deseas modificar\n";
				cin>>c;
				listE.Editar(c);
				break;
			case 5:
				cout<<"Saliendo...";
				break;
		}
	}while(opc!=5);
	return 0;
}

