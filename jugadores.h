#ifndef JUGADORES_H
#define JUGADORES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char objinv[5]; 
    int cant_obj;
}inventario;


typedef struct {
    char id_jugador[3];
    char nomb_jugador[21];
    char jugador[11];
    char password[9];
    inventario inv[10]; //inicialmente el inventario tendrá 10 huecos, si el jugador encuentra una mochila o algo para ampliar pues se reserva más  memoria
}jugador;



#endif