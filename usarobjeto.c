#include "usarobjeto.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void usarobjeto(objetos o,partida p, conexiones c, jugador j)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos *o,partidas p, conexion *c, jugador j){
    int usar, i;
    int x,y,z;
    for (int i=0; i<=sizeof(c); i++){
        if (strcmp(c[i].id_conexion,p.sala_actual)==0){
            for(y=0; y<=j[/**/].cant_obj; y++){
                if (strcmp(c[i].cond,j[/**/].inventario[y].objinv)==0){
                    for(z=0;z<=sizeof(o); z++){
                        if (strcmp(o[z].id_obj,j[/**/].inventario[y].objinv)==0)
                    }
                    do{
                        printf("Puedes usar el objeto %s en la sala\n ¿quieres usarlo? Si:1 No:0 \n", o[z].nomb_obj);
                    }while (usar!=1 && usar!=0);

                    if (usar == 1){
                        p.num_conexunlocked++;;
                        realloc(p.conex_desbloqueadas, p.num_conexunlocked * sizeof(conexunlocked));
                        strcpy(c[i].id_destino, p.conex_desbloqueadas[p.num_conexunlocked-1].id_conexion);
                    }
                }
            }
        }
    }
}