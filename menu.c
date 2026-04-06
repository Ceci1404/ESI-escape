
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

#include <stdio.h>
#include <string.h>
// #include de tus cabeceras

// La función devuelve un puntero a la partida específica del usuario (o NULL si falla)
partidas* cargar_partida_existente(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas) { //funcion Mario
    char user[11];
    char pass[9];
    int id_jugador_encontrado = -1;

    printf("\n--- CARGAR PARTIDA ---\n");
    printf("Introduce tu usuario: ");
    scanf("%10s", user);
    printf("Introduce tu contrasena: ");
    scanf("%8s", pass);

    // 1. FASE DE LOGIN: Buscamos si el usuario y contraseña existen en la RAM
    for (int i = 0; i < total_jugadores; i++) {
        if (strcmp(lista_jugadores[i].jugador, user) == 0 && 
            strcmp(lista_jugadores[i].password, pass) == 0) {
            
            id_jugador_encontrado = i; // Guardamos su índice/ID
            break;
        }
    }

    // Si el bucle termina y sigue siendo -1, no se encontró
    if (id_jugador_encontrado == -1) {
        printf("Error: Usuario o contrasena incorrectos.\n");
        return NULL;
    }

    // 2. FASE DE ASIGNACIÓN: Buscamos cuál es su partida
    for (int i = 0; i < total_partidas; i++) {
        // Comprobamos si el número de jugador de la partida coincide con nuestro usuario
        if (lista_partidas[i].jug_actual == id_jugador_encontrado) {
            printf("\n¡Bienvenido de nuevo, %s!\n", lista_jugadores[id_jugador_encontrado].nomb_jugador);
            printf("Te quedaste en la sala: %d\n", lista_partidas[i].sala_actual);
            
            // Devolvemos la dirección de memoria EXACTA de su partida
            return &lista_partidas[i]; 
        }
    }

    // Si el usuario existe pero por algún motivo no se encontró una partida vinculada
    printf("Aviso: No se ha encontrado ninguna partida guardada para este usuario.\n");
    return NULL;
}
