#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;
 
#define ASCENDENTE 1
#define DESCENDENTE 0

class ejem /*: public nodo,lista*/{
	public:
		int x;
		string y;
		float w;
		//virtual define
	/*	ejem(){
			lista lisEjem;
		}*/
		
};

class nodo{
   public:
    nodo(ejem v, nodo *sig = NULL, nodo *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
   	//nt id;
    ejem valor;
    nodo *siguiente;
    nodo *anterior;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() : plista(NULL) {}
    ~lista();
    
    /*virtual*/void Insertar(ejem v);
    void Borrar(int b);
    bool ListaVacia() { return plista == NULL; } 
    void Mostrar(int orden);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    string ValorActual() { return plista->valor.y; }
    
   private:
    pnodo plista;
};

lista::~lista() {
   pnodo aux;
   
   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}

void lista::Insertar(ejem v) {
   pnodo nuevo;
 
   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor.x > v.x) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->valor.x <= v.x) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void lista::Borrar(int b) {
   pnodo nodo;
   
   nodo = plista;
   while(nodo && nodo->valor.x < b) nodo = nodo->siguiente;
   while(nodo && nodo->valor.x > b) nodo = nodo->anterior;

   if(!nodo || nodo->valor.x != b) return;
   // Borrar el nodo 
   
   if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
}

void lista::Mostrar(int orden) {
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor.y << "-> ";
         nodo = nodo->siguiente;
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor.y << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}

void lista::Siguiente() {
   if(plista) plista = plista->siguiente;
}

void lista::Anterior() {
   if(plista) plista = plista->anterior;
}

void lista::Primero() {
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo() {
   while(plista && plista->siguiente) plista = plista->siguiente;
}
void insertar(ejem mio,lista &pues){
	pues.Insertar(mio);
	//return pues;
}
int main() {
   lista Lista;
   ejem uno;
   ejem dos;
   
   uno.x=1;uno.y="uno";
   insertar(uno,Lista);
   uno.x=2;uno.y="dos";
   insertar(uno,Lista);
   uno.x=3;uno.y="tres";
   insertar(uno,Lista);
   uno.x=4;uno.y="cuatro";
   insertar(uno,Lista);
   uno.x=5;uno.y="aver";
   insertar(uno,Lista);

   Lista.Mostrar(ASCENDENTE);

   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
   
   Lista.Borrar(3);
   Lista.Mostrar(ASCENDENTE);
   
   Lista.Borrar(1);
   uno.x=6; uno.y="seis";
   insertar(uno,Lista);
   Lista.Mostrar(ASCENDENTE);
   
    uno.x=7; uno.y="siete";
   insertar(uno,Lista);
   Lista.Mostrar(ASCENDENTE);
   
   Lista.Borrar(4);
   Lista.Mostrar(ASCENDENTE);
   return 0;
}
