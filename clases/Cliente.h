#include <iostream>
#include <string>

using namespace std;
class Cliente
{
	private:
		int CodigoCliente;
		string NombreCliente ,RFC,Domicilio,Telefono;
	public:
		Cliente(){ CodigoCliente=0;NombreCliente="";RFC="";Domicilio="";Telefono="";}
		void setCodigoCliente(int c){ CodigoCliente = c;		}
		void setNombreCliente(string n){ NombreCliente = n;		}
		void setRFC(string r){ RFC = r;		}
		void setDomicilio(string d){ Domicilio=d;		}
		void setTelefono(string t){ Telefono = t;		}
		int getCodigoCliente(){ return CodigoCliente;		}
		string getNombreCliente(){ return NombreCliente;		}
		string getRFC(){ return RFC;}
		string getDomicilio(){return Domicilio;		}
		string getTelefono(){ return Telefono;		}
		void registrarCliente();
		void consultarCliente();
		void eliminarCliente();
		void modificarCliente();
};
void Cliente::registrarCliente(){
	int c;
	string s;
	setCodigoCliente(c+1);
	cout<<"Ingrese el Nombre del Cliente"<<endl; fflush(stdin); getline(cin,s); setNombreCliente(s);
	cout<<"Ingrese el RFC del Cliente"<<endl; fflush(stdin); getline(cin,s); setRFC(s);
	cout<<"Ingrese el Domicilio del Cliente"<<endl; fflush(stdin); getline(cin,s); setDomicilio(s);
	cout<<"Ingrese el Telefono del Cliente"<<endl; fflush(stdin); getline(cin,s); setTelefono(s);
}
void Cliente::consultarCliente()
{
	
}
void Cliente::modificarCliente()
{
	
}
void Cliente::eliminarCliente()
{
	
}
