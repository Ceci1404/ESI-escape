
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ficheros.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"


void leerficheros ();

void cargarficheros(){

Puzle registro_puzles[100]; 
int total_puzles = 0;


void carga_ficheros() {
}
mi_partida.num_puzles = 0;
    mi_partida.num_conexunlocked = 0;
    mi_partida.jug_actual.inv.cant_obj = 0;

   
    FILE* f_partida = fopen("partida_guardada.txt", "r");
    
    if (f_partida == NULL) {
        printf("Error: No se encontró el fichero para cargar.\n");
        return mi_partida; // Devolvemos la partida vacía
    }

    char etiqueta[50]; 

    
    while (fscanf(f_partida, "%49s", etiqueta) == 1) {
        
        
        if (strcmp(etiqueta, "JUGADOR") == 0) {
           
            fscanf(f_partida, "%s %s %s %s", 
                   mi_partida.jug_actual.id_jugador,
                   mi_partida.jug_actual.nomb_jugador,
                   mi_partida.jug_actual.jugador,
                   mi_partida.jug_actual.password);
        }
        
       
        else if (strcmp(etiqueta, "SALA") == 0) {
            
            fscanf(f_partida, "%2s", mi_partida.sala_actual);
        }
        
       
        else if (strcmp(etiqueta, "TOTAL_PUZLES") == 0) {
            // Primero leemos cuántos hay
            fscanf(f_partida, "%d", &mi_partida.num_puzles);
            
            
            for (int i = 0; i < mi_partida.num_puzles; i++) {
                int estado_resuelto;
               
                fscanf(f_partida, "%3s %d", 
                       mi_partida.puzles_estado[i].id_puzle, 
                       &estado_resuelto);
                
                
                mi_partida.puzles_estado[i].resuelto = (estado_resuelto == 1);
            }
        }
    
        else if (strcmp(etiqueta, "TOTAL_CONEXIONES") == 0) {
            fscanf(f_partida, "%d", &mi_partida.num_conexunlocked);
            
            for (int i = 0; i < mi_partida.num_conexunlocked; i++) {
                int estado_activa;
                fscanf(f_partida, "%3s %d", 
                       mi_partida.conex_desbloqueadas[i].id_conexion, 
                       &estado_activa);
                       
                mi_partida.conex_desbloqueadas[i].activa = (estado_activa == 1);
            }
        }
    }

    
    fclose(f_partida);
    
    printf("Infortmacion guardada\n");
    
    
    return mi_partida;
}    
  
}

void nuevapartida(jugador *);
