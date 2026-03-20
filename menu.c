#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "conexiones.h"
#include "puzles.h"
#include "jugadores.h"
#include "partida.h"
#include "salas.h"

void menu_principal();
void menu_juego(partida *p_actual);

int main() {
    menu_principal();
    return 0;
}

void menu_principal() {
    int x = 0;
    //Creamos la variable que almacenará todo eljuego
    partida mi_partida; 

    do {
        printf("       --ESI SCAPE--     \n");
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
        
            menu_juego(&mi_partida); // Entra a jugar pasándole los datos
            break;
        
        case 2:
            printf("\n[CARGANDO PARTIDA...]\n");
            // llamamos a  función de leer el txt
           
            menu_juego(&mi_partida); 
            break;
        
        case 3:
            printf("\nSaliendo del juego... ¡Hasta pronto!\n");
            break;
    } 
}


void menu_juego(partida *p_actual) { // recibe el estado completo del juego
    int p = 0;

    do {
        // imprimimos sala actual usando la estructura
        printf("\n   --Sala: %s--\n", p_actual->sala_actual); 
        
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
                    printf("Describiendo la sala...\n");
                    break;
            case 2:
                    break;
             case 3: // Entrar en otra sala
                    
                    break;
             case 4:
                    break;
             case 5:
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8:
                    break;
            case 9:
                    printf("Guardando la partida actual...\n");
                    // se debe llamar a otra funcion
                    break;
            case 10:
                    printf("Volviendo al menu principal...\n");
                    return; 
            }
        }
    } while(p <1|| p>10);
}
