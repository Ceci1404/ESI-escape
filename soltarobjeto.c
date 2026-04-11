#include "soltarobjeto.h"
#include "partida.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug)
//Precondición: La funcion recive la estructura de puzle, jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug){
    char c[5];
    int soltar, i=0;
    int x,y,aux;
    printf("Los objetos en tu inventario son:\n");  //Describe el inventario del jugador para que pueda elegir el objeto a soltar
    for(x=0; x<=j[*jug].cant_obj; x++){
        for(y=0; y<=j[*jug].cant_obj; y++){
            if(j[*jug].inventario[y].objinv == o[x].id_obj){
                printf("%d %s %s %s \n",x, o[x].id_obj, o[x].nomb_obj, o[x].desc);

            }
        }
    }

    do{
        printf("¿Quieres soltar algun objeto? Si:1 No:0 \n");  //Pregunta al jugador si quiere soltar un objeto
        scanf("%d", &soltar);
    }while(soltar!=1 && soltar!=0 );

    if (soltar==1){
        do{
            printf("Introduce el numero del objeto que quieres soltar \n");
            scanf("%d", &aux);
         }while(aux>=0 || aux<=x);

        strcpy(c, j[*jug].inventario[aux].objinv);
        for (x=0; x<=j[*jug].cant_obj || strcmp(c, o[x].id_obj)==0; x++){       //Desde la posición actual del objeto que se cambia, muevo los objetos una posicion hacia atras y reasigno el tamaño del vector a n-1
            if(strcmp(p.sala_actual, o[x].localiz)==0){             //Comprueba si el objeto a soltar pertenece a la sala actual
                for(aux; aux<x-1; aux++){
                strcpy(j[*jug].inventario[aux+1].objint,j[*jug].inventario[aux].objinv);
                }

                j[*jug].cant_obj--;
                realloc(j[*jug].inventario, j[*jug].cant_obj*sizeof(inventario));
            }
            else printf("No puedes soltar ese objeto en esta sala \n");
        }
            

        /*Si suelto un objeto que no es en su sala original cambiaria de localizacion
        en el txt y estructura de objeto???*/

}
}


/*Solucion probisional hasta que se implemente el vector de inventario */
