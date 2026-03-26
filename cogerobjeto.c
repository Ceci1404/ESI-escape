#include "cogerobjeto.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void cogerobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugadores j, objetos o, partida p,/*inventario *einv, int ninv, int nobj */ ){
    int coger, i=0;
    int x;
    for(x=0; x<=nobj; x++) {
        if (strcmp(p.sala_actual,o[x].localiz)==0){
            if (j/*[tengo que pensar como verificar que jug es]*/.taminvninv>ninv){     //Si el inventario del jugador no esta lleno, se le pregunta si quiere coger el objeto
                do{
                    printf("Puedes coger el objeto %s, ¿quieres cogerlo? Si:1 No:0 \n", o.nomb_obj[p.sala_actual]);
                    scanf("%d", &coger);
                }while (coger!=1 && coger!=0);
                if(coger==1){
                    /* ninv++;
                    realloc(einv, ninv*sizeof(inventario));
                    j[/*tengo que pensar como verificar que jug es].cant_obj++;
                    j[/*tengo que pensar como verificar que jug es].inventario[j[x].cant_obj].objinv=o[x].id_obj;

                    */
                }
            }
        }
        else printf("No hay ningun objeto en esta sala \n");
    }
   
}

/*No hay vector dinamico para inventario, solucion probisional mientras se implementa*/