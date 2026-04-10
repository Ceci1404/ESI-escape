#include "soltarobjeto.h"
#include "partida.h"
#include "jugadores.h"
#include "objetos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void soltarobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *j, objetos *o, partidas p){
    int x,y;
    printf("Los objetos en tu inventario son:\n");
    for(x=0; x<=j.[/**/].cant_obj; x++){
        for(y=0; y<=j[/* indice del jugador */].cant_obj; y++){
            if(j[/* indice del jugador */].inventario[y].objinv == o[x].id_obj){
                printf("%d %s %s %s %s \n", x, o[x].id_obj, o[x].nomb_obj, o[x].desc, o[x].localiz);

            }
        }
    }
}