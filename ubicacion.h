/*En este modulo el jugador se mueve de ubicaciones*/
#ifndef UBICACION_H
#define UBICACION_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void entrarsala(partida , sala* , sala , conexion*, int *, int *) )
//Precondición: La función recive la estructura de partida, conexion y sala
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas p, conexion* co, sala s, conexion *econ, int *, int *);

#endif
