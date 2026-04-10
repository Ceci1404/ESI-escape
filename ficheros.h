#ifndef FICHEROS_H
#define FICHEROS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LECTURA Y ESCRITURA DE FICHEROS
    //SUSANA v
    //cambiar estas funciones a juego.h
    char* ficherotocad(char* filepath);
    void limpiar(char* cad);
    //SUSANA ^
    
    void cargarficheros();
    void nuevapartida(jugador *);

#endif
