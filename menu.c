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
void menu_principal(partidas *v_partidas, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int *numsal, int *numobj, int *numcon, int *numpuz, int* numpar, int* numjug,  int *jug, int *par) {
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
                    
                    // 2. Gestionamos solo el registro 
                    nuevapartida(v_jug,  v_partidas, v_salas, jug, numjug, par,  numpar);
                    
                    // 3. LLAMADAAL JUEGO , Le pasamos la partida creada y todos los vectores del mapa
                    menu_juego(v_partidas, v_salas, v_conex, v_jug, v_obj, v_puz, numsal, numobj, numcon, numpuz,numpar, numjug, jug,par);
                    break;
            
                case 2:       
            
                    
                    verificarusuario( v_jug, numjug, jug, v_partidas, numpar,par);

                    menu_juego(v_partidas, v_salas, v_conex, v_jug, v_obj, v_puz, numsal, numobj, numcon, numpuz,numpar, numjug, jug , par);
                    break;

                case 3:
                    printf("Saliendo de ESI Escape. ¡Hasta pronto!\n");
                    guardar_datos(v_jug, *numjug , v_partidas);
                    break;
            }
        }
    } while(x != 3); 
}


// --- MENU DE JUEGO ---
void menu_juego(partidas *v_partidas, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int *numsal, int *numobj, int *numcon, int *numpuz, int* numpar, int* numjug,  int *jug, int *par) { 
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
                    describir(v_partidas,  v_salas,  v_conex,  v_jug,  v_obj,  v_puz,  numsal,  numobj,  numcon,  numpuz,  numpar,  numjug, jug,  par); 
                    break;
                case 2:
                
                    examinar(v_salas, v_obj, v_partidas, v_jug, v_conex, numsal, numobj , numcon, jug, par);
                    break;
                case 3: 
                    entrarsala(v_partidas, v_conex, v_salas, numcon, numsal, par);
                    break;
                case 4:
                    cogerobjeto(v_jug, v_obj, v_partidas, numobj, jug, par);
                    break;
                case 5:
                    soltarobjeto(v_puz, v_partidas, numpuz, v_jug, v_obj, jug, par);
                    break;
                case 6:
                    mostrarinventario(v_jug, v_obj, v_partidas, jug);
                    break;
                case 7:
                    usarobjeto(v_obj, v_partidas, v_conex, v_jug, jug, numobj, par);
                    break;
                case 8:
                    resolver(v_puz, v_partidas, numpuz, par);
                    break;
                case 9:
                    printf("Guardando progreso de la partida...\n");
                    guardar_datos(v_jug, *numjug, v_partidas); 
                    break;
                case 10:
                    printf("Volviendo al menu principal...\n");
                    menu_principal(v_partidas,  v_salas,  v_conex,  v_jug,  v_obj,  v_puz,  numsal,  numobj,  numcon,  numpuz,  numpar,  numjug, jug,  par);
                    break;
            }
        }
    } while(p != 10); 
}

