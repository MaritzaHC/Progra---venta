
class ListaEmpleados
{
	private:
	const int longitud=0;
		Empleados *lista;
	public:
		void agregarinicio();
		
		
};
void ListaEmpleados::agregarinicio()
{
		int c;
	string s;
	float f;
	setCodigo(c+1);
	cout<<"Ingrese el Nombre del Empleado"<<endl; fflush(stdin); getline(cin,s); setNombre(s);
	cout<<"Ingrese la Edad del Empleado"<<endl; fflush(stdin); getline(cin,s); setEdad(s);
	cout<<"Ingrese el Sueldo del Empleado"<<endl; fflush(stdin); cin>>f; setSueldo(f);
	cout<<"Ingrese la comision del Empleado"<<endl; fflush(stdin); cin>>f; setComisiones(f);
	Empleados *nuevo, *actual;
	//Crear un nodo nuevo 
   nuevo = new Empleados(string Nombre,int Edad,float Sueldo,int longitud);
   actual = lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   longitud++;
	if(!actual || actual->valor > v) {
      //Añadimos la lista a continuación del nuevo nodo 
      nuevo->siguiente = actual; 
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!lista) lista = nuevo;
   }
   else {
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v 
      while(actual->siguiente && actual->siguiente->valor <= v) 
         actual = actual->siguiente;
      // Insertamos el nuevo nodo después del nodo anterior 
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
/*void Insertar(Lista *lista, int v) {
   pNodo nuevo, actual;

    Crear un nodo nuevo 
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Colocamos actual en la primera posición de la lista 
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo 
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo 
      nuevo->siguiente = actual; 
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v 
      while(actual->siguiente && actual->siguiente->valor <= v) 
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior 
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}*/
