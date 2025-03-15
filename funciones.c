#define CAPACIDAD_INICIAL 4
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

/*Funcion que inicializa la estructura*/
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}

/* Funcion que retorna el totalElementos en un vector Dinamico*/
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

/*Funcion qye cambia el tamaño del vector */ 
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}
/*Funcion que añade un elementto al vector*/ 
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

/*Funcion que libera memoria */
void freeVector(vectorDinamico *V){
        free(V->elementos);
}
/*Funcion que dado una posicion del vector retorna el elemento en esa posicion*/
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}

/*Funcion que dado una posicion del vector pone un elemento en esa posición*/
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}

/*Funcion que dado una posicion de vector borra ese elemento*/
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}

