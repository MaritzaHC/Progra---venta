using namespace std;
class Empleados
{
	private:
		int Codigo, Edad;
		float Sueldo,comisiones;
		string Nombre;
	public:
		Empleados(string Nombre,int Edad,float Sueldo,int longitud){ Codigo=longitud; Edad=Edad; Sueldo=Sueldo; comisiones=0; Nombre=Nombre;		}
		void setCodigo(int c){ Codigo=c;		}
		void setEdad(int e){ Edad=e;		}
		void setSueldo(float s) {Sueldo= s;		}
		void setComisiones(float c) { comisiones = c;		}
		void setNombre(string n){ Nombre = n;		}
		int getCodigo(){ return Codigo;		}
		float getSueldo() {return Sueldo;		}
		float getComisiones(){ return comisiones;		}
		string getNombre(){ return Nombre;		}
		int getEdad(){ return Edad;		}
		void registrarEmpleado();
		void consultarEmpleado();
		void eliminarEmpleado();
		void modificarEmpleado();
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
/*void Empleados::consultarEmpleado()
{
	
}
void Empleados::eliminarEmpleado()
{
	
}
void Empleados::modificarEmpleado()
{
	
}*/
