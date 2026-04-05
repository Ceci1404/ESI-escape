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

void menu_principal();
void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz);

int main() {
    menu_principal(); // Inicia el flujo del programa
    return 0;
}

void menu_principal() {
    int x = 0;
    partida mi_partida; 
    
   // Variables para almacenar los datos cargados de ficheros
    // Usamos punteros porque tus funciones de ficheros usan malloc/realloc
    sala *v_salas = NULL;
    conexion *v_conex = NULL;
    jugador *v_jug = NULL;
    objetos *v_obj = NULL;
    puzle *v_puz = NULL;

    // Tamaños aproximados
    int nsal = 20, nobj = 20, ncon = 20, npuz = 10;

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
        }
    } while(x < 1 || x > 3);

    switch(x) {
        case 1:
            printf("\n[CREANDO NUEVA PARTIDA...]\n");
            // Llamamos a la función de lectura de ficheros
            leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
            
            // Inicialización departida (sala inicial)
            strcpy(mi_partida.sala_actual, "S1"); 
            mi_partida.num_conexunlocked = 0;
            mi_partida.num_puzles = 0;
            
          
            menu_juego(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz);
            break;
        
        case 2:
            printf("\n[CARGANDO PARTIDA...]\n");
            
            // cargamos el mundo base (salas, objetos, etc.)
            leerficheros(v_salas, v_conex, v_jug, v_obj, v_puz);
            
            //  Luego  el progreso del jugador desde el .txt de guardado
            
            cargarficheros(&mi_partida);
            
            printf("Partida cargada con exito. ¡Bienvenido de nuevo!\n");
            
            // Entramos con datos recuperados
            menu_juego(&mi_partida, v_salas, v_conex, v_jug, v_obj, v_puz, nsal, nobj, ncon, npuz);
            break;
            
        case 3:
            printf("Saliendo de ESI Escape...\n");
            break;
    }
}

void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz) { 
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
                    printf("Guardando la partida actual...\n");
                    
                    // Llamamos a la función en ficheros.c
                    guardarficheros(p_actual); 
                    
                    printf("¡Partida guardada correctamente!\n");
                    break;
                case 10:
                    printf("Volviendo al menu principal...\n");
                    break;
            }
        }
    } while(p != 10); 
}
