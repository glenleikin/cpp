#include <stdio.h>
#include <string.h>
#include <string.h>
#include <iostream>


using namespace std;

class OrdenT{
            public:
            OrdenT(char [30], int);
            char tipoCerveza[30];
            int litros;
            OrdenT * sig;
};

OrdenT::OrdenT(char C[30], int L){
    strcpy(tipoCerveza, C);
    litros = L;
};

class Cliente{
        public:
                    Cliente (char *);
                    char nombre [30];
                    Cliente * sig;
                    OrdenT * inicioOrden;
                    void agregarOrden(char [30], int);
};

Cliente::Cliente(char n [30]){
            inicioOrden = NULL;
            strcpy(nombre, n);
};

void Cliente::agregarOrden(char C [30], int L){
            OrdenT * orden;

            orden = new OrdenT(C, L);
            orden->sig = inicioOrden;
            inicioOrden = orden;
};

class Cerveceria{
        private:
                    Cliente * inicio;
        public:
                    Cerveceria();
                    void agregarCliente(char [30]);
                    Cliente * buscarCliente(char [30]);
                    void imprimeMenorLitros();
                    void imprimeClientes();
};

Cerveceria::Cerveceria(){
            inicio = NULL;
};

void Cerveceria::agregarCliente(char nombre [30]){
            Cliente * cliente;

            cliente = new Cliente(nombre);
            cliente->sig = inicio;
            inicio = cliente;
};

Cliente * Cerveceria::buscarCliente(char n [30]){
            Cliente * cliente = inicio;

            while(cliente){
                    if(strcmp(cliente->nombre, n) == 0){
                                return cliente;
                    }
            cliente = cliente ->sig;
         }
            return cliente;
};

void Cerveceria::imprimeMenorLitros(){

    cout<<"Quien consumio menos litros fue:"<<endl;
    char Menor [50];
    int contLitros = 0, menorLitros = 999999999;

    Cliente * cliente = inicio;
    OrdenT * orden;

            while(cliente != NULL){
                        orden = cliente -> inicioOrden;
                        while(orden != NULL){
                                contLitros = contLitros + orden->litros;
                                orden = orden->sig;
                        }
                        if(contLitros<menorLitros && contLitros != NULL){
                                menorLitros = contLitros;
                                strcpy(Menor, cliente->nombre);
                        }
                        contLitros = 0;
                        cliente = cliente->sig;
            }

            cout<<Menor;
};

void Cerveceria::imprimeClientes(){


        cout<<"Lista de clientes"<<endl;
        Cliente * cliente = inicio;
        int cont = 0, i, j;
        while(cliente != NULL){
                    cout<<cliente->nombre<<endl;
                    cont++;
                    cliente = cliente->sig;
        }

/*
        Si quiero imprimir al reves
        for(i=cont;i>=0;i--){
        cliente = inicio;
        j = 0;
        while(cliente != NULL){
        if(i == j) {
        cout<<cliente->nombre<<endl;
        }
        cliente = cliente->sig;
        j++;
        }
    }*/

};

int main(){
    Cerveceria C;

    C.agregarCliente("Pepe");
    C.agregarCliente("Maria");
    C.agregarCliente("Sofia");
    C.agregarCliente("Carlos");
    C.agregarCliente("Juana");

    C.buscarCliente("Pepe")->agregarOrden("RUBIA", 200);
    C.buscarCliente("Maria")->agregarOrden("Rubia", 200);
    C.buscarCliente("Sofia")->agregarOrden("Rubia", 120);
    C.buscarCliente("Pepe")->agregarOrden("IPA", 200);
    C.buscarCliente("Juana")->agregarOrden("IPA", 100);
    C.buscarCliente("Juana")->agregarOrden("Rubia", 100);

    C.imprimeMenorLitros();
    cout<<endl;
    C.imprimeClientes();

    return 0;
};
