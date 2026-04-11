
#include "ficheros.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SUSANA v 

void limpiar(char* buffer) {  
    for (int i = 0; i < 200; i++) {
        buffer[i] = '\0';
    }
}

char* ficherotocad(char* filepath, char* cad) {
    int lineas = 1;
    const int maxlinea = 200;
    char buffer[200];
    
    cad = (char*)malloc(lineas * maxlinea * sizeof(char));
    if (cad == NULL) return NULL;
    cad[0] = '\0';
    
    FILE* f = fopen(filepath, "r");
    if (f == NULL) {
        printf("No se ha podido abrir fichero\n");
        free(cad);
        return NULL;
    }
    
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        strcat(cad, buffer);
        lineas++;
        
        char* temp = realloc(cad, lineas * maxlinea * sizeof(char));
        if (temp == NULL) {
            printf("Error de memoria\n");
            free(cad);
            fclose(f);
            return NULL;
        }
        cad = temp;
        
        limpiar(buffer);  
    }
    
    fclose(f);
    return cad;
}

//SUSANA ^ 


//se deben declarar en el main como variables que se actualicen cada vez que se modifique el número de jugadores o el número de partidas

void guardar_ficheros(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas) {
    
    printf("--- Guardando progreso en los ficheros ---\n");

    
    FILE *f_jug = fopen("jugadores.txt", "w");
    
    if (f_jug != NULL) {
        // Primero guardamos el total de jugadores
        fprintf(f_jug, "%d\n", total_jugadores); 

        for (int i = 0; i < total_jugadores; i++) {
            // Datos principales del jugador
            fprintf(f_jug, "%s %s %s %s %d %d\n",
                    lista_jugadores[i].id_jugador,
                    lista_jugadores[i].nomb_jugador, 
                    lista_jugadores[i].jugador,
                    lista_jugadores[i].password,
                    lista_jugadores[i].cant_obj,
                    lista_jugadores[i].tamainv);

            // Inventario dinámico del jugador
            for (int j = 0; j < lista_jugadores[i].cant_obj; j++) {
                fprintf(f_jug, "%s\n", lista_jugadores[i].inv[j].objinv);
            }
        }
        fclose(f_jug);
        printf("OK: 'jugadores.txt' guardado con %d jugadores.\n", total_jugadores);
    } else {
        printf("Error: No se pudo abrir jugadores.txt para guardar.\n");
    }

    
    FILE *f_part = fopen("partidas.txt", "w");
    
    if (f_part != NULL) {
        // Primero guardamos el total de partidas
        fprintf(f_part, "%d\n", total_partidas); 

        for (int i = 0; i < total_partidas; i++) {
            // Datos principales de la partida
            fprintf(f_part, "%d %d %d %d\n",
                    lista_partidas[i].jug_actual,
                    lista_partidas[i].sala_actual,
                    lista_partidas[i].num_conexunlocked,
                    lista_partidas[i].num_puzles);

            // Conexiones (con if-else normal)
            for (int j = 0; j < lista_partidas[i].num_conexunlocked; j++) {
                int estado_conexion;
                if (lista_partidas[i].conex_desbloqueadas[j].activa == true) {
                    estado_conexion = 1;
                } else {
                    estado_conexion = 0;
                }
                fprintf(f_part, "%s %d\n", lista_partidas[i].conex_desbloqueadas[j].id_conexion, estado_conexion);
            }

            // Puzles (con if-else normal)
            for (int j = 0; j < lista_partidas[i].num_puzles; j++) {
                int estado_puzle;
                if (lista_partidas[i].puzles_estado[j].resuelto == true) {
                    estado_puzle = 1;
                } else {
                    estado_puzle = 0;
                }
                fprintf(f_part, "%s %d\n", lista_partidas[i].puzles_estado[j].id_puzle, estado_puzle);
            }
        }
        fclose(f_part);
        printf("OK: 'partidas.txt' guardado con %d partidas.\n", total_partidas);
    } else {
        printf("Error: No se pudo abrir partidas.txt para guardar.\n");
    }

    printf("--- Proceso de guardado finalizado ---\n");
    return lista_partidas;
}
