#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- CABECERAS DE ESTRUCTURAS ---
#include "menu.h"
#include "partida.h"
#include "salas.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"


// --- CABECERAS DE MÓDULOS DE  COMPAÑEROS ---
#include "ficheros.h"
#include "logica.h"
#include "juego.h"


// --- MENÚ PRINCIPAL ---
void menu_principal(partidas *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int *numsal, int *numobj, int *numcon, int *numpuz, int *jug, int *par) {
    int x;
    do {
        printf("\n       --BIENVENIDO A ESI SCAPE--     \n");
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
                    // 1. Cargamos el mapa 
                    leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
                    
                    // 2. Gestionamos solo el registro 
                    nuevapartida(jugador *v_jug, partidas *v_partidas,int *jug, int *njug, int *par, int *numpar);
                    
                    // 3. LLAMADAAL JUEGO , Le pasamos la partida creada y todos los vectores del mapa
                    menu_juego(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
                    break;
            
                case 2:
                    // 1. Cargamos el mapa base
                    leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
                    
                    verificarusuario(jugador *v_jug, int *njug, int *jug, partidas *v_partidas, int *numpar, int *par);

                    menu_juego(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
                    break;

                case 3:
                    printf("Saliendo de ESI Escape. ¡Hasta pronto!\n");
                    guardar_ficheros(v_jug, total_jugadores, v_partidas, total_partidas);
                    return 0;
                    break;
            }
        }
    } while(x != 3); 
}


// --- MENU DE JUEGO ---
void menu_juego(partidas *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int *numsal, int *numobj, int *numcon, int *numpuz, int *jug, int *par) { 
    int p = 0;

    do {
        printf("1. Describir sala.\n");
        printf("2. Examinar (objetos y salidas).\n"); 
        printf("3. Entrar en otra sala.\n");
        printf("4. Coger objeto.\n");
        printf("5. Soltar objeto.\n"); 
        printf("6. Inventario.\n");
        printf("7. Usar objeto.\n");
        printf("8. Resolver puzle / introducir codigo.\n"); 
        printf("9. Guardar partida.\n");
        printf("10. Volver.\n");
        printf("Elige una accion: ");

        scanf("%d", &p);

        if(p < 1 || p > 10){
            printf("OPCION INCORRECTA, POR FAVOR ELIJA CORRECTAMENTE.\n");
        } else {
            switch(p) {
                case 1:
                    describir(v_salas, *p_actual, *numsal, *par); 
                    break;
                case 2:
                    examinar(v_salas, v_obj, *p_actual, *v_jug,*v_conex, *numsal, *numobj , *numcon, *jug, *par);
                    break;
                case 3: 
                    entrarsala(p_actual, v_conex, v_salas, *numcon, *numsal, *par);
                    break;
                case 4:
                    cogerobjeto(*v_jug, *v_obj, *p_actual);
                    break;
                case 5:
                    soltarobjeto(*v_puz, *p_actual, *numpuz, *v_jug, *v_obj, *jug, *par);
                    break;
                case 6:
                    mostrarinventario(*v_jug, *v_obj, *p_actual, *jug);
                    break;
                case 7:
                    usarobjeto(*v_obj, *p_actual, *v_conex, *v_jug, *jug, *numobj, *par);
                    break;
                case 8:
                    resolver(*v_puz, *p_actual, *numpuz, *par);
                    break;
                case 9:
                    printf("Guardando progreso de la partida...\n");
                    guardar_ficheros(v_jug, total_jugadores, v_partidas, total_partidas); 
                    break;
                case 10:
                    printf("Volviendo al menu principal...\n");
                    menu_principal();
                    break;
            }
        }
    } while(p != 10); 
}

// --- NUEVA PARTIDA ---
void crear_nueva_partida(partida *p_actual, jugador *v_jug, int *total_jugadores) {
    printf("\n[CREANDO NUEVA PARTIDA...]\n");
    printf("\n--- REGISTRO DE JUGADOR ---\n");
    
    printf("Introduce un ID para tu personaje (ej. J01): ");
    scanf("%s", v_jug[*total_jugadores].id_jugador);
    
    printf("Introduce tu nombre: ");
    scanf("%s", v_jug[*total_jugadores].nomb_jugador);

    // Asignamos el jugador a la partida
    p_actual->jug_actual = v_jug[*total_jugadores];
    
    // Valores por defecto
    strcpy(p_actual->sala_actual, "S1"); // Primera sala
    p_actual->num_conexunlocked = 0;
    p_actual->num_puzles = 0;
    p_actual->jug_actual.cant_obj = 0;   // Inventario vacío
    
    (*total_jugadores)++; // Sumamos el nuevo jugador al total
    
    printf("\n¡Bienvenido a ESI Escape, %s! Despiertas en una sala oscura...\n", p_actual->jug_actual.nomb_jugador);
}


int cargar_partida_existente(partida *p_actual, jugador *v_jug, int total_jugadores, partidas *v_partidas, int total_partidas) {
    printf("\n[CARGANDO PARTIDA...]\n");
    
    // Llamada real al login
    partidas *partida_encontrada = login_jugador(v_jug, total_jugadores, v_partidas, total_partidas);
    
    if (partida_encontrada != NULL) {
        // Encontramos la partida, copiamos los datos principales
        strcpy(p_actual->sala_actual, partida_encontrada->sala_actual);
        
        printf("\n¡Partida cargada! Reanudando desde la sala %s...\n", p_actual->sala_actual);
        return 1; // 1 = Login exitoso, permite entrar a menu_juego
    } else {
        return 0; // 0 = Fallo, vuelve al menu principal
    }
}

*/


