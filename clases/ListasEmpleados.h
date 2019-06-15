#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
#define ASCENDENTE 1

class nodo
{
	private:
		int Edad;
		const int Codigo=0;
		float Sueldo,comisiones;
		char *Nombre;
		nodo *anterior,*siguiente;
		friend class lista;
	public:
		nodo(int c,int e, float com, float sueld,char *nom,nodo *ant=NULL,nodo *sig=NULL):Codigo(c),Edad(e),comisiones(com),Sueldo(sueld),anterior(ant),siguiente(sig){}    //Asignaciones de paso valor
};
typedef nodo *pnodo;

class lista{
	private:
		pnodo plista;
	public:
		lista(): plista(NULL){	}
		~lista();
		void Insertar(int v,int e, float com, float sueld,char *nom);
		void Borrar(int c);
		bool listaVacia(){ return plista==NULL;	}
		void Mostrar(int v);
		void siguiente();
		void anterior();
		void Primero();
		void Ultimo();
		int ValorActual(){ return plista -> Codigo;}
		bool Actual(){ return plista != NULL;}
		friend class Empleados;
};
lista::~lista()
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

void lista::Insertar(int v,int e, float com, float sueld,char *nom)
{
	pnodo nuevo;
	if(listaVacia()||plista->Codigo>v)
	{
		v=1;
		nuevo = new nodo (v,e,com,sueld,nom,plista);
		if(!plista)
		{
			plista=nuevo;
		}
		else
		{
			plista->anterior=nuevo;
		}
	}
	else
	{
		while(plista->siguiente&&plista->siguiente->Codigo<=v)
		{
			siguiente();
		}
		nuevo = new nodo(v,e,com,sueld,nom,plista,plista->siguiente);
		plista->siguiente=nuevo;
		if(nuevo->siguiente)
		{
			nuevo->siguiente->anterior=nuevo;
		}
	}
}
void lista::Borrar(int c)
{
	pnodo nodo;
	nodo = plista;
	while(nodo&&nodo->Codigo<c)
	{
		nodo = nodo->siguiente;
	}
	while(nodo&&nodo->Codigo>c)
	{
		nodo = nodo->anterior;
	}
	if(nodo->anterior)
	{
		nodo->anterior->siguiente=nodo->siguiente;
	}
	if(nodo->siguiente)
	{
		nodo->siguiente->anterior=nodo->anterior;
	}
	delete nodo;
}
void lista::Mostrar(int v)
{
	pnodo nodo;
	if(v==ASCENDENTE)
	{
		Primero();
		nodo=plista;
		while(nodo)
		{
			cout<<nodo->Codigo<<"->";
			nodo=nodo->siguiente;
		}
	}
	else
	{
		Ultimo();
		nodo=plista;
		while(nodo)
		{
			cout<<nodo->Codigo<<"->";
			nodo=nodo->anterior;
		}
	}
	cout<<endl;
}
void lista::siguiente()
{
	if(plista)
	{
		plista=plista->siguiente;
	}
}
void lista::anterior()
{
	if(plista)
	{
		plista=plista->anterior;
	}
}
void lista::Primero()
{
	while(plista&&plista->anterior)
	{
		plista=plista->anterior;
	}
}
void lista::Ultimo()
{
	while(plista&&plista->siguiente)
	{
		plista=plista->siguiente;
	}
}

/*int main()
{
	int algo;
	lista Lista;
	cout<<"Ingrese un numero"<<endl;
	cin>>algo;
	Lista.Insertar(algo);
	Lista.Mostrar(ASCENDENTE);
}*/
