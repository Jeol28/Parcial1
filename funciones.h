#ifndef __FUNCIONES_H_
#define __FUNCIONES_H_
/*Creacion de Estrucutura  de Datos para el vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;


/*Firmas de las funciones*/


void vectorInicio(vectorDinamico *V);

int totalVector(vectorDinamico *V);

static void resizeVector(vectorDinamico *V, int capacidad);

void addVector(vectorDinamico *V, void *elemento);

void freeVector(vectorDinamico *V);

void *getVector(vectorDinamico *V, int indice);

void setVector(vectorDinamico *V, int indice, void *elemento);

void borrarVector(vectorDinamico *V, int indice);

#endif
