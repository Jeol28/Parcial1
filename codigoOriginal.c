/********************************************************
* Fecha: 13 de marzo de 2025
* Pontificia Universidad Javeriana
* Materia: Sistemas Operativos
* Parcial Sistemas Operativos
* Autor:Jorge Enrique Olaya Liévano
* Profesor: J. Corredor
* IP: 10.43.103.218
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(){
        vectorDinamico editor;
        vectorInicio(&editor);

        addVector(&editor, "Hola ");
        addVector(&editor, "Profesional ");
	addVector(&editor, "En ");
        addVector(&editor, "Formacion ");
        addVctor(&editor,"De ");
        addVector(&editor, "Ingenieria");

        for (int i = 0; i < totalVector(&editor); i++)
        printf("%s", (char *) getVector(&editor, i));
	printf("\n");
        borrarVector(&editor, 1);

        setVector(&editor, 1, "Buenos");


        for (int i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
	printf("\n");
}
