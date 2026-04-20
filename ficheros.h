#ifndef FICHEROS_H
#define FICHEROS_H
#include "jugadores.h"
#include "partida.h"

//LECTURA Y ESCRITURA DE FICHEROS
    //SUSANA v
    //cambiar estas funciones a juego.h
    char* ficherotocad(char* filepath,char* cad);
    void limpiar(char* cad);
    //SUSANA ^
    
    void guardar_datos(jugador *lista_jugadores, int total_jugadores, partidas *p_activa);
partidas* login_jugador(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas);

#endif
