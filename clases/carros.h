#include "../todo.h"

class carros{
    private:
        char marca[10];
        char modelo[10];
        int aa;
        bool tipo;
        float precio;
        int id;
    public:
        char getMarca(){return *marca;}
        char getModelo(){return *modelo;}
        int getAa(){return aa;}
        bool getTipo(){return tipo;}
        float getPrecio(){return precio;}
        int getId(){return id;}
        void setMarca(char dato[10]){*marca=dato;}
        void setModelo(char dato[10]){*modelo=dato;}
        void setAa(int dato){aa=dato;}
        void setTipo(bool dato){tipo=dato;}
        void setPrecio(float dato){precio=dato;}
        void setId(int dato){id=dato;}

        bool agregar();
        bool modificar();
        void eliminar();
        void consultar();
};
