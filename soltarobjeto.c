#include "soltarobjeto.h"
#include "partida.h"
#include "jugadores.h"
#include "objetos.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void soltarobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(jugadores j, objetos o, partida p){
    char c[5];
    int soltar, i=0;
    int x,y,aux;
    printf("Los objetos en tu inventario son:\n");
    for(x=0; x<=ninv; x++){
        for(y=0; y<=j[/* indice del jugador */].cant_obj; y++){
            if(j[/* indice del jugador */].inventario[y].objinv == o[x].id_obj){
                printf("%d %s %s %s \n", cont, o[x].id_obj, o[x].nomb_obj, o[x].desc);

            }
        }
    }

    do{
        printf("¿Quieres soltar algun objeto? Si:1 No:0 \n");
        scanf("%d", &soltar);
    }while(soltar!=1 && soltar!=0 );

    if (soltar==1){
        do{
            printf("Introduce el numero del objeto que quieres soltar \n");
            scanf("%d", &aux);
         }while(aux>=0 || aux<=x);

        strcpy(c, j[/* indice del jugador */].inventario[aux].objinv);
        for (x=0; x<=nobj || strcmp(c, o[x].id_obj)==0; x++){
            if(strcmp(p.sala_actual, o[x].localiz)==0){
                for(aux; aux<x-1; aux++){
                strcpy(j[/* */].inventario[aux+1].objint,j[/* */].inventario[aux].objinv);
                }

                j[/* indice del jugador */].cant_obj--;
                realloc(j[/* indice del jugador */].inventario, j[/* indice del jugador */].cant_obj*sizeof(inventario));
            }
            else printf("No puedes soltar ese objeto en esta sala \n");
        }
            

        /*Si suelto un objeto que no es en su sala original cambiaria de localizacion
        en el txt y estructura de objeto???*/

}


/*Solucion probisional hasta que se implemente el vector de inventario */