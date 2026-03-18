#ifndef JUGADORES_H
#define JUGADORES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objetos.h"

typedef struct {
    objetos objinv; //el inventario tiene maximo?¿?¿
    int cant_obj;

}inventario;

typedef struct {
    char id_jugador[3];
    char nomb_jugador[21];
    char jugador[11];
    char password[9];
    inventario inv;
}jugador;



#endif