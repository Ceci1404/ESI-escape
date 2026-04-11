#include "examinar.h"

#include "conexiones.h"
#include "salas.h"
#include "objetos.h"
#include "jugadores.h"
#include "partida.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void examinar(salas s, objetos o, partida p, jugador j, int nsal, int nobj, int ninv, int ncon, int *jug)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *s, objetos *o, partidas p, jugador j, conexion* c, int nsal, int nobj, int ninv, int ncon, int *jug) {
   int x,y,z,m;
   for(x=0; x<nsal; x++){
        if(strcmp(p.sala_actual, s[x].id_sala)==0){     //Verificación de la sala actual con la sala en vector
            for(y=0; y<nobj; y++){
                if(strcmp(s[x].id_sala, o[y].localiz)==0){      //Verificación de los objetos que estan en la sala
                    for(z=0; z<ninv; z++){
                        if (strcmp(o[y].id_obj, j[*jug].inventario[z].objinv)!=0){
                            printf("Objeto: %s\nDescripcion: %s\n", o[y].nomb_obj, o[y].desc);
                        }
                    }
                }
            }

            for(m=0; m<p.num_conexunlocked; m++){
                if(strcmp(p.sala_actual, c[m].id_origen)==0){       //Comprobamos que la conexión tiene el mismo id que la sala actual
                    if(strcmp(p.conex_desbloqueadas[m].id_conexion, c[m].id_conexion)==0){      //Comprobamos que la sala esta desbloqueada o no
                        printf("Conexion: %s\n", c[m].id_conexion);
                    }
                    else{
                        printf("Conexion: %s (bloqueada)\n", c[m].id_conexion);
                    }
                    
                }
            }
        }
    }
}