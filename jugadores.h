#ifndef JUGADORES_H
#define JUGADORES_H
#include "objetos.h"

typedef struct inventario{
    objetos objinv; //el inventario tiene maximo?¿?¿
    int cant_obj;

};

typedef struct jugador{
    char id_jugador[3];
    char nomb_jugador[21];
    char jugador[11];
    char password[9];
    inventario inv;
};



#endif