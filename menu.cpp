#include"todo.h"
#include"clases/Cliente.h"
#include"clases/Empleados.h"
#include"clases/carros.h"
#include"clases/factura.h"
int main()
{
	int opc=0;
	Carros car;
	Empleados emp;
	lista listE;
	Cliente client;
	do{
		cout<<"Que desea realizar?\n\n1.-Registrar\n2.-Consultar\n3.-Modificar\n4.-Eliminar\n5.-Salir\n\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				cout<<"Registros\n\n\n\n";
				int opc2=0;
				do{
					cout<<"Que es lo que desea registrar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
					cin>>opc2;
					switch(opc2)
					{
						case 1:
							car.registrarCarros();
							break;
						case 2:
							emp.registrarEmpleado();
							listE.insertar(emp);
							break;
						case 3:
							client.registrarCliente();
							break;
						case 4:
							fact.registrarfactura();
							break;
						case 5:
							cout<<"Regresando..."<<endl;
							break;
						default:
							cout<<"Opcion inexistente"<<endl;
					}
				}while(opc2!=5);
				break;
			case 2:
				cout<<"Consultas\n\n\n\n";
				int opc2=0;
				do{
					cout<<"Que desea consultar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
					cin>>opc2;
					switch(opc2)
					{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						default:
							cout<<"Opcion inexistente"<<endl;
					}
				}while(opc2!=5);
				break;
			case 3:
				cout<<"Modificaciones\n\n\n\n";
				int opc2=0;
				do{
					cout<<"Que desea modificar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
					cin>>opc2;
					switch(opc2)
					{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						default:
							cout<<"Opcion inexistente"<<endl;
					}
				}while(opc2!=5);
				break;
			case 4:
				cout<<"Eliminar\n\n\n\n";
				int opc2=0;
				do{
					cout<<"Que desea eliminar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
					cin>>opc2;
					switch(opc2)
					{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						default:
							cout<<"Opcion inexistente"<<endl;
					}
				}while(opc2!=5);
				break;
			case 5:
				cout<<"Saliendo..."<<endl;
				break;
			default:
				cout<<"Opcion inexistente"<<endl;
		}
	}while(opc!=5);
}
