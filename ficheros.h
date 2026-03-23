#ifndef FICHEROS_H
#define FICHEROS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LECTURA Y ESCRITURA DE FICHEROS
    //SUSANA v
    //cambiar estas funciones a juego.h
    void obtenercad (char*, FILE* );
    void limpiar(char* cad);
    void leersalas(sala* sal);
    void leerconex(conexion* con);
    void leerjug(jugador* jug);
    void leerobj(objetos* obj);
    void leerpuz(puzle* puz);
    void leerficheros (sala* sal, conexion* con, jugador *jug, objetos* obj, puzle* puz);
    //SUSANA ^
    
    void cargarficheros();
    void nuevapartida(jugador *);

#endif
