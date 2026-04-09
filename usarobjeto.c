#include "usarobjeto.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void usarobjeto(objetos o,partida p, conexiones c, jugador j, int *jug)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos o,partida p, conexiones co, jugador j,int *jug){
    int usar, i;
    int x,y,z;
    for (int i=0; i<=ncon; i++){        
        if (strcmp(co[i].id_origen,p.sala_actual)==0){                          //Comprobamos que la conexión de la sala actual
            for(y=0; y<=j[*jug].cant_obj; y++){
                if (strcmp(co[i].cond,j[*jug].inventario[y].objinv)==0){        //Buscamos en el inventario si hay un objeto que pueda abrir la conexion
                    for(z=0;z<=nobj; z++){
                        if (strcmp(o[z].id_obj,j[*jug].inventario[y].objinv)==0){    //Tomamos el objeto del vector de objetos que es igual al inventario
                            do{
                                printf("Puedes usar el objeto %s en la sala\n ¿quieres usarlo? Si:1 No:0 \n", o[z].nomb_obj);
                            }while (usar!=1 && usar!=0);

                            if (usar == 1){                                     //Si el jugador decide usar el objeto, se desbloquea la conexión y se añade a la partida
                                p.num_conexunlocked++;);
                                realloc(p.conex_desbloqueadas, p.num_conexunlocked * sizeof(conexunlocked));
                                strcpy(co[i].id_destino, p.conex_desbloqueadas[p.num_conexunlocked-1].id_conexion);
                            }
                        }
                    }
                    
                }
            }
        }
    }
}