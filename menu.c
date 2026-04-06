
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "partida.h"
#include "salas.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"

#include "ficheros.h"
#include "describir.h"
#include "examinar.h"
#include "ubicacion.h"
#include "cogerobjeto.h"
#include "soltarobjeto.h"
#include "inventario.h"
#include "usarobjeto.h"
#include "resolver.h"

// --- PROTOTIPOS ---
void menu_principal();
void crear_nueva_partida(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);
void cargar_partida_existente(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);
void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);

// --- MAIN ---
int main() {
    menu_principal(); 
    return 0;
}


void menu_principal() {
    int x = 0;
    partida mi_partida; 
    
    
    sala v_salas[50];
    conexion v_conex[50];
    jugador v_jug[10];
    objetos v_obj[50];
    puzle v_puz[20];
    
    
    partidas v_partidas[10];

    
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
void crear_nueva_partida(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas) {
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


void cargar_partida_existente(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas) {
    printf("\n[CARGANDO PARTIDA...]\n");
    
    
    leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
    
    
    // Asumo que le pasas la partida para que la rellene con los datos del txt
    cargarficheros(p);
    
    printf("\n¡Partida cargada! Reanudando desde la sala %s...\n", p->sala_actual);
    
    
    menu_juego(p, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz, v_partidas, total_jugadores, total_partidas);
}


void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas) { 
    int p = 0;

    do {
        printf("\n   --Sala Actual: %s--\n", p_actual->sala_actual); 
        
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
                    describir(v_salas, *p_actual); 
                    break;
                case 2:
                    examinar(v_salas, v_obj, *p_actual, *v_jug, nsal, nobj, 10, ncon);
                    break;
                case 3: 
                    entrarsala(p_actual, v_conex, v_salas, v_conex, ncon, nsal);
                    break;
                case 4:
                    cogerobjeto(*v_jug, *v_obj, *p_actual);
                    break;
                case 5:
                    soltarobjeto(*v_jug, *v_obj, *p_actual);
                    break;
                case 6:
                    mostrarinventario(*v_jug, *v_obj, *p_actual);
                    break;
                case 7:
                    usarobjeto(*v_obj, *p_actual, *v_conex, *v_jug);
                    break;
                case 8:
                    resolver(*v_puz, *p_actual, npuz);
                    break;
                case 9:
                    printf("Guardando progreso de la partida...\n");
                    // Llamada exacta a tu función de ficheros.c original
                    guardar_ficheros(v_jug, total_jugadores, v_partidas, total_partidas); 
                    break;
                case 10:
                    printf("Volviendo al menu principal...\n");
                    break;
            }
        }
    } while(p != 10); 
}
