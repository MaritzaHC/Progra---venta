class Cliente
{
	private:
		int CodigoCliente;
		string NombreCliente ,RFC,Domicilio,Telefono;
	public:
		Cliente(){ CodigoCliente=0;NombreCliente="";RFC="";Domicilio="";telefono="";}
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
};
