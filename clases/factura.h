#include "../todo.h"

class factura{
    private:
        int id;
        char cliente[30];
        int cant;
        int idCarro;
        float precio;
        float total;
        int idVendedor;
        float comicion;
    public:
        int getId(){return id;}
        char getCliente(){return cliente;}
        int getCant(){return cant;}
        int getIdCarro(){return idCarro;}
        float getPrecio(){return precio;}
        float getTotal(){return total;}
        int getIdVendedor(){return idVendedor;}
        float getComicion(){return comicion;}   

        void setCliente(int dato){cliente = dato;}
        void setCant(char dato){cant= dato;}
        void setIdCarro(int dato){idCarro= dato;}
        void setPrecio(float dato){precio= dato;}
        void setTotal(float dato){total= dato;}
        void setIdVendedor(int dato){idVendedor= dato;}
        void setComicion(float dato){comicion= dato;}       
        void setId(int dato){id= dato;}

        bool crear();
        void consultar();
};
