#include"todo.h"
#include"Empleados.h"
#include"carros.h"
#include"factura.h"
int main()
{
	int opc=0,ids;
	int cantEmp=0, cantCar=0, cantFac=0;//para la id
	carros car;
	factura fac;
	Empleados emp;
	lista listE;
	listaC carrosL;
	listaF facturaL;
	do{
		cout<<"Que desea realizar?\n\n1.-Registrar\n2.-Consultar\n3.-Modificar\n4.-Eliminar\n5.-Salir\n\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				{
					system("cls");
					cout<<"Registros\n\n";
					int opc2=0;
					do{
						cout<<"Que es lo que desea registrar?\n\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								car.registrarCarros();
								car.id=cantCar;
								cantCar++;
								carrosL.insertar(car);
								break;
							case 2:
								emp.registrarEmpleado();
								emp.Codigo=cantEmp;
								cantEmp++;
								listE.insertar(emp);
								break;
							case 3:
								//client.registrarCliente();
								break;
							case 4:
								fac.registrarFactura();
								fac.id=cantFac;
								cantFac++;
								facturaL.insertar(fac);
								break;
							case 5:
								cout<<"Regresando..."<<endl;
								system("cls");
								break;
							default:
								cout<<"Opcion inexistente"<<endl;
						}
					}while(opc2!=5);
				}
				break;
			case 2:
				{
					system("cls");
					cout<<"Consultas\n\n";
					int opc2=0;
					do{
						cout<<"Que desea consultar?\n\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								cout<<"Ingrese el codigo del carro: ";
								cin >> ids;
								carrosL.mostrarUno(ids);
								break;
							case 2:
								listE.mostrar();
								break;
							case 3:
								break;
							case 4:
								cout<<"Ingrese el codigo de la factura: ";
								cin >> ids;
								facturaL.mostrarUno(ids);
								break;
							case 5:
								system("cls");
								break;
							default:
								cout<<"Opcion inexistente"<<endl;
						}
					}while(opc2!=5);
				}
				break;
			case 3:
				{
					system("cls");
					cout<<"Modificaciones\n\n";
					int opc2=0;
					do{
						cout<<"Que desea modificar?1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								cout << "ingrese el id del carro";
								cin >> ids;
								carrosL.modificar(ids);
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								system("cls");
								break;
							default:
								cout<<"Opcion inexistente"<<endl;
						}
					}while(opc2!=4);
				}
				break;
			case 4:
				{
					system("cls");
					cout<<"Eliminar\n\n";
					int opc2=0;
					do{
						cout<<"Que desea eliminar?\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								cout << "ingrese el id del carro";
								cin >> ids;
								carrosL.borrar(ids);
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								cout << "ingrese el id de la factura";
								cin >> ids;
								facturaL.borrar(ids);
								break;
							case 5:
								system("cls");
								break;
							default:
								cout<<"Opcion inexistente"<<endl;
						}
					}while(opc2!=5);
				}
				break;
			case 5:
				cout<<"Saliendo..."<<endl;
				break;
			default:
				cout<<"Opcion inexistente"<<endl;
		}
	}while(opc!=5);
}
