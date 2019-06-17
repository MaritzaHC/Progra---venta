#include"todo.h"
#include"clases/Cliente.h"
#include"clases/Empleados.h"
//#include"clases/carros.h"
//#include"clases/factura.h"
int main()
{
	int opc=0;
	char cod[40];
	Empleados emp;
	lista listE;
	Cliente client;
	ListaCliente listC;
	listE.CargarArchivo();
	listC.CargarArchivo();
	do{
		cout<<"Que desea realizar?\n\n1.-Registrar\n2.-Consultar\n3.-Modificar\n4.-Eliminar\n5.-Salir\n\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				{
					system("cls");
					cout<<"Registros\n\n\n\n";
					int opc2=0;
					do{
						system("cls");
						cout<<"Que es lo que desea registrar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								//car.registrarCarros();
								break;
							case 2:
								system("cls");
								emp.registrarEmpleado();
								listE.insertar(emp);
								break;
							case 3:
								system("cls");
								client.registrarCliente();
								listC.Insertar(client);
								break;
							case 4:
								//fact.registrarfactura();
								break;
							case 5:
								system("cls");
								cout<<"Regresando..."<<endl;
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
					cout<<"Consultas\n\n\n\n";
					int opc2=0;
					do{
						system("cls");
						cout<<"Que desea consultar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								{
									system("cls");
									int opc3=0;
									cout<<"Como desea realizar su consulta?1.-Por Nombre\n2.-Mostrar Todos\n\n";
									cin>>opc3;
									if(opc3==1)
									{
										
									}
									else if(opc==2)
									{
										
									}
									else
									{
										cout<<"Opcion Invalida"<<endl;
									}
								}
								getch();
								break;
							case 2:
								{
									system("cls");
									int opc3=0;
									char nomm[20];
									cout<<"Como desea realizar su consulta?1.-Por Nombre\n2.-Mostrar Todos\n\n";
									cin>>opc3;
									if(opc3==1)
									{
										cout<<"Ingrese el nombre que quiere consultar\n\n";
										cin>>nomm;
										listE.mostrarUno(nomm);
									}
									else if(opc==2)
									{
										listE.mostrar();
									}
									else
									{
										cout<<"Opcion Invalida"<<endl;
									}
								}
								getch();
								break;
							case 3:
								{
									system("cls");
									int opc3=0;
									char nomm[20];
									cout<<"Como desea realizar su consulta?1.-Por Nombre\n2.-Mostrar Todos\n\n";
									cin>>opc3;
									if(opc3==1)
									{
										cout<<"Ingrese el nombre que quiere consultar\n\n";
										cin>>nomm;
										listC.MostrarUno(nomm);
									}
									else if(opc==2)
									{
										listC.Mostrar();
									}
									else
									{
										cout<<"Opcion Invalida"<<endl;
									}
								}
								getch();
								break;
							case 4:
								{
									system("cls");
									int opc3=0;
									char nomm[20];
									cout<<"Como desea realizar su consulta?1.-Por Nombre\n2.-Mostrar Todos\n\n";
									cin>>opc3;
									if(opc3==1)
									{
										cout<<"Ingrese el nombre que quiere consultar\n\n";
										cin>>nomm;
										
									}
									else if(opc==2)
									{
										
									}
									else
									{
										cout<<"Opcion Invalida"<<endl;
									}
								}
								getch();
								break;
								system("cls");
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
					cout<<"Modificaciones\n\n\n\n";
					int opc2=0;
					do{
						system("cls");
						cout<<"Que desea modificar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								system("cls");
								break;
							case 2:
								system("cls");
								cout<<"Ingrese el nombre del empleado que desea modificar\n\n";
								cin>>cod;
								listE.modificar(cod);
								break;
							case 3:
								system("cls");
								cout<<"Ingrese el nombre del cliente que desea modificar\n\n";
								cin>>cod;
								listC.Modificar(cod);
								break;
							case 4:
								system("cls");
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
			case 4:
				{
					system("cls");
					cout<<"Eliminar\n\n\n\n";
					int opc2=0;
					do{
						system("cls");
						cout<<"Que desea eliminar?\n\n1.-Carros\n2.-Empleados\n3.-Clientes\n4.-Factura\n5.-Regresar"<<endl;
						cin>>opc2;
						switch(opc2)
						{
							case 1:
								system("cls");
								break;
							case 2:
								system("cls");
								cout<<"Ingrese el nombre del empleado que desea eliminar\n\n";
								cin>>cod;
								listE.borrar(cod);
								break;
							case 3:
								cout<<"Ingrese el nombre del cliente que desea eliminar\n\n";
								cin>>cod;
								listC.Borrar(cod);
								system("cls");
								break;
							case 4:
								system("cls");
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
