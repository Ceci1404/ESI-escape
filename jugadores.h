#ifndef JUGADORES_H
#define JUGADORES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char objinv[5]; 
}inventario;


typedef struct {
    char id_jugador[3];
    char nomb_jugador[21];
    char jugador[11];
    char password[9];
    int cant_obj;
    int tamainv;
    inventario *inv; //El inventario tendrá un tamaño max de tamainv
}jugador;



#endif