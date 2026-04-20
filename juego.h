#ifndef JUEGO_H
#define JUEGO_H
#include "salas.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"
#include "partida.h"
//HECHO POR SUSANA

char* obtenercad(char* cad, int* pcad, char* buffer);
sala* crearsala(char* cad, int *numsal);
conexion* crearconex(char* cad, int *numcon);
jugador* crearjug(char* cad, int *numjug);
objetos* crearobj(char* cad, int* numobj);
puzle* crearpuz(char* cad, int* numpuz);
char* cadtipopar (char* cad, int *ppar, char* buffer);
partidas* crearpar(char* cad, int* numpar);

#endif
