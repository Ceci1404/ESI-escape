#include "soltarobjeto.h"
#include "partida.h"
#include "jugadores.h"
#include "objetos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void soltarobjeto(jugadores j, objetos o, partida p, int *jug)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *j, objetos *o, partidas p, int * jug){
    int x,y;
    printf("Los objetos en tu inventario son:\n");
    for(x=0; x<=j[*jug].cant_obj; x++){
        for(y=0; y<=j[*jug].cant_obj; y++){            //Recorremos el vector del inventario y lo mostramos
            if(j[*jug].inventario[y].objinv == o[x].id_obj){
                printf("%d %s %s %s %s \n", x, o[x].id_obj, o[x].nomb_obj, o[x].desc, o[x].localiz);

            }
        }
    }
}