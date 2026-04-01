#include "examinar.h"
#include "partida.h"
#include "conexiones.h"
#include "salas.h"
#include "objetos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void examinar(salas s, objetos o, partida p, jugador j, int nsal, int nobj, int ninv, int ncon) {
   int x,y,z,m;
   for(x=0; x<nsal; x++){
        if(strcmp(p.sala_actual, s[x].id_sala)==0){
            for(y=0; y<nobj; y++){
                if(strcmp(s[x].id_sala, o[y].localiz)==0){
                    for(z=0; z<ninv; z++){
                        if (strcmp(o[y].id_objetos,j[/* */].inventario[z].objinv)!=0){
                            printf("Objeto: %s\nDescripcion: %s\n", o[y].nomb_obj, o[y].desc);
                        }
                    }
                }
            }

            for(m=0; m<p.num_conexunlocked; m++){
                if(strcmp(p.sala_actual, c[m].id_origen)==0){
                    if(strcmp(p.conex_desbloqueadas[m].id_conexion, c[m].id_conexion)==0){
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