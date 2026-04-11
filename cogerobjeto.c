#include "cogerobjeto.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void cogerobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *j, objetos *o, partidas p,/*inventario *einv, int ninv, int nobj */ , int *jug){
    int coger, i=0;
    int x;
    for(x=0; x<=j.[jug].cant_obj; x++) {
        if (strcmp(p.sala_actual,o[x].localiz)==0){
            if (j[*jug].tamainv>j.[*jug].cant_obj){     //Si el inventario del jugador no esta lleno, se le pregunta si quiere coger el objeto
                do{
                    printf("Puedes coger el objeto %s, ¿quieres cogerlo? Si:1 No:0 \n", o[p.sala_actual].nomb_obj);
                    scanf("%d", &coger);
                }while (coger!=1 && coger!=0);
                if(coger==1){
                    /* ninv++;
                    realloc(einv, ninv*sizeof(inventario));
                    j[jug].cant_obj++;
                    j[jug].inventario[j[x].cant_obj].objinv=o[x].id_obj;

                    */
                }
            }
        }
        else printf("No hay ningun objeto en esta sala \n");
    }
   
}

/*No hay vector dinamico para inventario, solucion probisional mientras se implementa*/