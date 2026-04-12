
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cabeceras de estructuras
#include "menu.h"
#include "partida.h"
#include "salas.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"

// Cabeceras de módulos de acciones
#include "ficheros.h"
#include "logica.h"

// --- PROTOTIPOS ---
void menu_principal();
void crear_nueva_partida(partidas *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);
void cargar_partida_existente(partidas *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);
void menu_juego(partidas *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);




void menu_principal() {
    int x = 0;
    partidas mi_partida; 
    
    
    sala *v_salas = NULL;
    conexion *v_conex = NULL;
    jugador *v_jug = NULL;
    objetos *v_obj = NULL;
    puzle *v_puz = NULL;
    
    partidas *v_partidas = NULL;
    
    int nsal = 20, nobj = 20, ncon = 20, npuz = 10;
    int total_jugadores = 1; // Asumimos 1 para empezar
    int total_partidas = 1;  // Asumimos 1 para empezar

    do {
        printf("\n       --ESI SCAPE--     \n");
        printf("        ----------\n");
        printf("1. Nueva partida.\n");
        printf("2. Cargar partida.\n"); 
        printf("3. Salir.\n");
        printf("Elige una opcion: ");
        scanf("%d", &x);

        if(x < 1 || x > 3){
            printf("OPCION INCORRECTA, POR FAVOR ELIJA CORRECTAMENTE.\n");
        } else {
            switch(x) {
                case 1:
                    crear_nueva_partida(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
                    break;
            
                case 2:
            
            cargar_partida_existente(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
            break;
                        case 3:
                    printf("Saliendo de ESI Escape. ¡Hasta pronto!\n");
                    break;
            }
        }
    } while(x != 3); 
}

// --- NUEVA PARTIDA ---
void crear_nueva_partida(partidas *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas) {
    printf("\n[CREANDO NUEVA PARTIDA...]\n");
    
   
    leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
    
   
    printf("\n--- REGISTRO DE JUGADOR ---\n");
    printf("Introduce un ID para tu personaje (ej. J01): ");
    scanf("%s", p->jug_actual.id_jugador);
    
    printf("Introduce tu nombre: ");
    scanf("%s", p->jug_actual.nomb_jugador);

   
    strcpy(p->sala_actual, "S1"); // Primera sala
    p->num_conexunlocked = 0;
    p->num_puzles = 0;
    p->jug_actual.cant_obj = 0;   // Inventario vacío
    
    printf("\n¡Bienvenido a ESI Escape, %s! Despiertas en una sala oscura...\n", p->jug_actual.nomb_jugador);
    
    // 4. Entrar al juego
    menu_juego(p, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
}





partidas* cargar_partida_existente(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas) {
    char user[11];
    char pass[9];
    int id_numerico_jugador = -1;

    printf("\nACCESO ESI-ESCAPE \n");
    printf("Usuario: ");
    scanf("%10s", user);
    printf("Contraseña: ");
    scanf("%8s", pass);

    // 1. Buscamos al jugador en el array de jugadores
    for (int i = 0; i < total_jugadores; i++) {
        
        // Comprobamos si coinciden jugador y contraseña
        if (strcmp(lista_jugadores[i].jugador, user) == 0 && 
            strcmp(lista_jugadores[i].password, pass) == 0) {
            
            // Convertimos su ID de texto ("01") a número (1)
            id_numerico_jugador = atoi(lista_jugadores[i].id_jugador);
            printf("\n¡Bienvenido, %s!\n", lista_jugadores[i].nomb_jugador);
            break; // Rompemos el bucle porque ya lo hemos encontrado
        }
    }

    // Si el ID sigue siendo -1, es que el 'if' anterior nunca se cumplió
    if (id_numerico_jugador == -1) {
        printf("Error: Usuario o contrasena incorrectos.\n");
        return NULL;
    }

    // 2. Buscamos su partida correspondiente en el array de partidas
    for (int i = 0; i < total_partidas; i++) {
        
        // Si el número de jugador de la partida coincide con el nuestro...
        if (lista_partidas[i].jug_actual == id_numerico_jugador) {
            printf("Partida encontrada. Cargando sala %d...\n", lista_partidas[i].sala_actual);
            
            // Devolvemos el puntero exacto a su partida
            return &lista_partidas[i]; 
        }
    }

    // Si el bucle termina y no ha devuelto nada (return), es que no hay partida
    printf("Aviso: No se encontraron datos de partida para este usuario.\n");
    return NULL;
}
