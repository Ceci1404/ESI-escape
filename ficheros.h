#ifndef FICHEROS_H
#define FICHEROS_H
#include "jugadores.h"
#include "partida.h"

//LECTURA Y ESCRITURA DE FICHEROS
    //SUSANA v
    //cambiar estas funciones a juego.h
    char* ficherotocad(char* filepath,char* cad);
    void limpiar(char* cad);
    //SUSANA 

//Cabecera: void guardar_datos(jugador *lista_jugadores, int total_jugadores, partidas *p_activa)
//Precondición: total_jugadores >= 0. Si total_jugadores > 0, lista_jugadores != NULL. p_activa puede ser NULL o apuntar a una estructura válida.
//Postcondición: Los datos de los jugadores y de la partida activa se vuelcan en los ficheros "Jugadores.txt" y "Partida.txt". 
//Si ocurre un error de acceso al disco o no hay partida, se notifica por pantalla sin abortar el programa.
 void guardar_datos(jugador *lista_jugadores, int total_jugadores, partidas *p_activa);

partidas* login_jugador(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas);

#endif
