#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

class Visitante
{
	public:
            Visitante(char [30]);
			char NOM [20];
			Visitante * SIG;
			~Visitante();
};

Visitante::Visitante(char n [30]){
    strcpy(NOM, n);
}

Visitante::~Visitante(){
    cout<<"\n eliminando a "<<NOM;
}
class Museo
{
	public:
			char NOM [20];
			Visitante * PVIS;
			Museo * SIG;
			Museo(char *);
			void nuevoVisitante(char *);
};

Museo::Museo(char * m ){
    strcpy(NOM,m);
    PVIS = NULL;
};

void Museo::nuevoVisitante(char * nv){

    Visitante * visitante;
    visitante = new Visitante(nv);
    visitante->SIG = PVIS;
    PVIS = visitante;

};

class RegistroVisitas
{
	public:
            RegistroVisitas();
			Museo * INICIO;
			void nuevoMuseo(char *);
			void registrarVisita(char *, char *);
			void mirar();
			void verVisitantesPerfectos();
			void borrarMuseosMenosVisitados();
			void Matar (Museo *);

};

RegistroVisitas::RegistroVisitas(){
    INICIO = NULL;
}

void RegistroVisitas::nuevoMuseo(char * m){

    Museo * museo;
    museo = new Museo (m);
    museo->SIG = INICIO;
    INICIO = museo;
};

void RegistroVisitas::registrarVisita(char * m , char * n){

    Museo * museo;
    museo = INICIO;

    while(museo!= NULL){
        if(strcmp(museo->NOM, m)==0){
            museo->nuevoVisitante(n);
        }
        museo = museo->SIG;
    }

};

void RegistroVisitas::mirar(){

    Museo * museo = INICIO;
    Visitante * visitante;

    while(museo != NULL){
        cout<<"\n\n\n El museo es "<<museo->NOM;
        visitante = museo->PVIS;
        cout<<" y los visitanes son ";
        while(visitante != NULL){
            cout<<visitante->NOM;
            cout<<", ";
            visitante = visitante->SIG;

        }
        museo = museo->SIG;
    }
};

void RegistroVisitas::Matar(Museo * borrar){

    Museo * P;
    P = INICIO;

    if(INICIO == borrar){
        INICIO = borrar->SIG;
        delete borrar;
        return;
    }

    while(P->SIG != borrar && P)
          P = P->SIG;
    if(P){
    P->SIG = P->SIG->SIG;
    delete borrar;
    }
};

void RegistroVisitas::verVisitantesPerfectos(){

    char vp [30];
    int mayorVisitas = -1, visitaParcial = 0;

    Museo * museo = INICIO;
    Visitante * visitante;

    while(museo != NULL){
        visitante = museo->PVIS;
        while(visitante != NULL){
            visitaParcial++;
            if(visitaParcial>mayorVisitas){
                mayorVisitas = visitaParcial;
                strcpy(vp, visitante->NOM);
            }
            visitante = visitante->SIG;

        }
        visitaParcial = 0;
        museo = museo->SIG;
    }

    cout<<"\n\n El visitante perfecto es "<<vp;

};

void RegistroVisitas::borrarMuseosMenosVisitados(){

    char menosVisitado [50];
    int visitaParcial = 0, menorVisitas = 1000;

    Museo * museo = INICIO;
    Museo * aux;
    Visitante * visitante;

    while(museo != NULL){
        visitante = museo->PVIS;
        while(visitante != NULL){
            visitaParcial++;
            visitante = visitante->SIG;
        }
        if(visitaParcial<menorVisitas){
            menorVisitas = visitaParcial;
            strcpy(menosVisitado, museo->NOM);
        }
        visitaParcial = 0;
        museo = museo->SIG;
    }

    museo = INICIO;
    visitante = museo->PVIS;

    while(museo!= NULL){
        if(strcmp(museo->NOM,menosVisitado)==0){
             aux = museo;
             Matar(aux);
            }
        museo = museo->SIG;
        }
}

int main()
{
	RegistroVisitas * lista = new RegistroVisitas;

	lista->nuevoMuseo("MALBA");
	lista->nuevoMuseo("MUSEO HISTORICO NAC.");
	lista->nuevoMuseo("MUSEO DE CS. NATURALES");

	lista->registrarVisita("MALBA", "Pepe");
	lista->registrarVisita("MUSEO HISTORICO NAC.", "Pepe");
	lista->registrarVisita("MALBA", "Maria Alvarez");
	lista->registrarVisita("MUSEO DE CS. NATURALES", "Pepe");
	lista->registrarVisita("MUSEO DE CS. NATURALES", "Roberto Sanchez");

	lista ->mirar();

	lista->verVisitantesPerfectos();
	lista->borrarMuseosMenosVisitados(); //borra el historico nacional

	cout<<"\n\n\n Despues de borrar";

	lista ->mirar();

return 0;
}
