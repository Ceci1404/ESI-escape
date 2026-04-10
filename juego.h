#ifndef JUEGO_H
#define JUEGO_H
//HECHO POR SUSANA

char* obtenercad(char* cad, int* pcad, char* buffer);
sala* crearsala(char* cad, int *numsal);
conexion* crearconex(char* cad, int *numcon);
jugador* crearjug(char* cad, int *numjug);
objetos* crearobj(char* cad, int* numobj);
puzle* crearpuz(char* cad, int* numpuz);

#endif
