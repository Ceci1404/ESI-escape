
#include "ficheros.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include <stdio.h>
#include <stdbool.h>
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

void guardar_datos(jugador *lista_jugadores, int total_jugadores, partidas *p_activa) {
    
    printf("\n[SISTEMA] Iniciando guardado de seguridad...\n");

    //guardar jugadores
    FILE *f_jug = fopen("Jugadores.txt", "w");
    if (f_jug == NULL) {
        printf("No se pudo acceder a Jugadores.txt para escritura.\n");
    } else {
        // Recorremos el array escribiendo directamente al buffer del archivo
        for (int i = 0; i < total_jugadores; i++) {
            fprintf(f_jug, "%s-%s-%s-%s", 
                    lista_jugadores[i].id_jugador, 
                    lista_jugadores[i].nomb_jugador, 
                    lista_jugadores[i].jugador, 
                    lista_jugadores[i].password);

            
            for (int j = 0; j < lista_jugadores[i].cant_obj; j++) {
                fprintf(f_jug, "-%s", lista_jugadores[i].inv[j].objinv);
            }
            fprintf(f_jug, "\n");
        }
        fclose(f_jug);
    }

   //Guardar datos partida
    if (p_activa != NULL) {
        FILE *f_part = fopen("Partida.txt", "w");
        if (f_part == NULL) {
            printf("[ERROR] No se pudo acceder a Partida.txt \n");
        } else {
            
            fprintf(f_part, "JUGADOR: %02d\n", p_activa->jug_actual);
            fprintf(f_part, "SALA: %02d\n", p_activa->sala_actual);

            
            for (int i = 0; i < p_activa->num_objetospar; i++) {
                fprintf(f_part, "OBJETO: %s-%s\n", p_activa->objpar[i].id_obj, p_activa->objpar[i].localiz);
            }

            // CONEXIONES: Uso de operador ternario (? :) para máxima eficiencia sin bloques if/else
            for (int i = 0; i < p_activa->num_conexunlocked; i++) {
                char *estado;
                        if (p_activa->conex_desbloqueadas[i].activa == TRUE) 
                             estado="Activa";
                        else
                           estado="Bloqueada";
                fprintf(f_part, "CONEXIÓN: %s-%s\n", 
                        p_activa->conex_desbloqueadas[i].id_conexion,estado)
            }

           
            for (int i = 0; i < p_activa->num_puzles; i++) {
                char *estado;
                 if (p_activa->puzles_estado[i].resuelto == TRUE) 
                     estado="Resuelto";
                else
                     estado="Pendiente";
                fprintf(f_part, "PUZLE: %s-%s\n",p_activa->puzles_estado[i].id_puzle,estado)
            }

            fclose(f_part);
            printf(" -> Estado de la partida actual guardado con exito.\n");
        }
    } else {
         printf(" No hay ninguna partida en curso para guardar.\n");
    }

    printf("Guardado finalizado.\n\n");
}



// Esta función es la que busca si el usuario existe y coincide la clave
partidas* login_jugador(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas) {
    char user_input[20];
    char pass_input[20];
    int encontrado = -1;

    printf("\n--- ACCESO AL SISTEMA ---\n");
    printf("Usuario: "); 
    scanf("%s", user_input);
    printf("Contrasena: "); 
    scanf("%s", pass_input);

    // 1. Buscamos en el vector de jugadores que Susana cargó del fichero
    for (int i = 0; i < total_jugadores; i++) {
        // Comparamos el usuario (campo 'jugador' o 'id_jugador' según tu estructura)
        if (strcmp(lista_jugadores[i].id_jugador, user_input) == 0) {
            // 2. Si el usuario existe, comprobamos la contraseña (campo 'password')
            if (strcmp(lista_jugadores[i].password, pass_input) == 0) {
                encontrado = i;
                break; // Salimos del bucle porque ya lo hemos encontrado
            }
        }
    }

    // 3. Resultado de la búsqueda
    if (encontrado != -1) {
        printf("\n[OK] Bienvenido, %s. Cargando tus progresos...\n", lista_jugadores[encontrado].nomb_jugador);
        
        // Devolvemos el puntero a la partida guardada que corresponde a ese jugador
        // (Asumimos que están en el mismo orden en los vectores)
        return &lista_partidas[encontrado]; 
    } else {
        printf("\n[ERROR] El usuario o la contrasena no son validos.\n");
        return NULL; // Devolvemos NULL para que el menu.c sepa que no debe entrar al juego
    }
}
