#include <stdio.h>
#include <string.h>
#include <string.h>
#include <iostream>


using namespace std;
class Auto {
    public:
    Auto(char [30], int);
    char modelo[30];
    int anio;
    Auto * sig;
    ~Auto();
};

Auto::Auto(char m [30], int a){
    strcpy(modelo, m);
    anio = a;
};
Auto::~Auto(){
};

class Cliente {
    public:
    Cliente(char*, char*);
    ~Cliente();
    char nombre[30];
    char telefono[20];
    Cliente * sig;
    Auto * primerauto;
    void agregarAuto(char [30], int);
    int cantAutos();
    void vaciarAutos();

};

Cliente::Cliente(char n[30], char t[20]){
    primerauto = NULL;
    strcpy(nombre, n);
    strcpy(telefono, t);
};

Cliente::~Cliente(){
    vaciarAutos();
};

void Cliente::agregarAuto(char m [30], int a){
    Auto * automovil;

    automovil = new Auto(m,a);
    automovil->sig = primerauto;
    primerauto = automovil;

};

int Cliente::cantAutos(){

    Auto * automovil;
    automovil = primerauto;

    int i = 0;
        while(automovil != NULL){
        automovil  = automovil->sig;
        i++;
    };

    return i;
};
void Cliente::vaciarAutos(){

    Auto * P, * Eliminar;
    P = primerauto;

        while(primerauto){
        Eliminar = primerauto;
        primerauto = primerauto->sig;
        delete Eliminar;
    };
};

class ListaClientes {
    private:
    Cliente * inicio;
    public:
        ListaClientes();
        ~ListaClientes();
        void agregar(char [30], char [20]);
        Cliente * buscar(char [30]);
        int cantClientes();
};
ListaClientes::ListaClientes(){
    inicio = NULL;
};

void ListaClientes::agregar(char nombre [30], char telefono [20]){
    Cliente * cliente;

    cliente = new Cliente(nombre,telefono);
    cliente->sig = inicio;
    inicio = cliente;

};

Cliente* ListaClientes::buscar(char n[30]){
    Cliente * cliente = inicio;

    while(cliente){
        if(strcmp(cliente->nombre, n)==0){
            return cliente;
        }
        cliente = cliente->sig;
    }
    return cliente;
}
int ListaClientes::cantClientes(){

    Cliente * cliente;
    cliente = inicio;

    int i = 0;
        while(cliente != NULL){
        cliente = cliente->sig;
        i++;
    };

    return i;
};

int main() {
    ListaClientes * lc = new ListaClientes;

    lc->agregar("Pepe", "4555-6565");  //agrega Cliente (lista principal)
    lc->agregar("Maria", "4444-3232");
    lc->agregar("Carlos", "5460-1111");

    lc->buscar("Pepe")->agregarAuto("Renault 12", 1980);  //agrega Auto a un Cliente (lista secundaria)
    lc->buscar("Pepe")->agregarAuto("Renault Fluence", 2013);

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 2

    lc->buscar("Pepe")->vaciarAutos();

    printf("\n Pepe tiene %d autos" , lc->buscar("Pepe")->cantAutos() );  //debe dar 0

    printf("\n Hay %d clientes" , lc->cantClientes() );  //debe dar 3

}
