#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
class Candi{
    public:
        Candi(char *);
        char nom [20];
        Candi * sig;
};

Candi::Candi(char * n){
    strcpy(nom,n);
};

class Lista{
    private:
        Candi*inicio;
        Candi * Maximo();
    public:
        Lista();
        void Agregar(char*);
        int Buscar(Candi *);
        void Depura();
        void Mirar();
        int Eliminar(Candi *);
        Candi * accederInicio();
        void Ordenar();
        void Sacar(Candi *);
        ~Lista();
};
Lista::Lista(){
    inicio = NULL;
}
Lista::~Lista(){

    Candi * P;
    P = inicio;
    while(P!=NULL){
        cout<<"\n eliminando a "<<P->nom;
        Eliminar(P);
        P = P->sig;
    }

    cout<<"\n termine de destruir";
}
void Lista::Agregar(char * n){

    Candi * P, * P2;
    P = new Candi(n);
    P->sig = NULL;
    P2 = inicio;

    if(!inicio){
        inicio = P;
        return;
    }
    while(P2->sig){
        P2 = P2->sig;
    }
    P2-> sig = P;
}

void Lista::Mirar(){

    Candi * P;
    cout<<"\n\n Contenido de la lista \n\n";
    P = inicio;
    while(P){
        cout<<"\n\t"<<P->nom;
        P = P->sig;
    }
    getchar();

}
void Lista::Depura(){

    Candi * P, *Aux;
    P = inicio;

    while(P){
        Aux = P->sig;
        while(Aux){
            if(!strcmpi(P->nom, Aux->nom)){
                Eliminar(Aux);
                Aux=P;
            }
            Aux = Aux->sig;
        }
    P = P->sig;
    }


};
int Lista::Eliminar(Candi * Eliminar){

    Candi * P;
    P = inicio;

    if(inicio == Eliminar){
        inicio = Eliminar->sig;
        delete Eliminar;
        return 0;
    }
    while(P->sig != Eliminar && P)
        P = P->sig;
    if(P){
    P->sig = P->sig->sig;
    delete Eliminar;
    }
    return 0;

}
Candi * Lista::accederInicio(){
    Candi * obtenerInicio;
    obtenerInicio = inicio;
    return obtenerInicio;
};
Candi* Lista::Maximo(){

    Candi * P = inicio;
    Candi * PMax = inicio;

    while(P != NULL){
        if(strcmp(P->nom, PMax->nom)>0){
            PMax = P;
        }
            P = P->sig;
    }

    return PMax;

}

void Lista::Sacar(Candi * Quitar){

    Candi * P = inicio;

    if(inicio == Quitar){
        inicio = Quitar->sig;
        return;
    }
    while(P->sig != Quitar && P)
        P = P->sig;
    if(P){
    P->sig = P->sig->sig;
    }
}
void Lista::Ordenar(){

Candi * P;
Candi * Aux = NULL;

    while(inicio){
        P = Maximo();
        Sacar(P);
        P->sig = Aux;
        Aux = P;
    }
    inicio = Aux;

};


int main(){

    Lista L, *PL;
    int i = 0;
    char n [20];
    while(i<10){
        cout<<"\n\n Ingrese un nombre\t";
        cin>>n;
        L.Agregar(n);
        i++;
    }
    L.Mirar();
    L.Depura();
    cout<<"\n\n Despues de eliminar repetidos";
    L.Mirar();
    L.Ordenar();
    cout<<"\n\n Despues de ordenar";
    L.Mirar();
    PL = &L;

}
