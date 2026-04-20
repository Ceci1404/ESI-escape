#ifndef LOGICA_H
#define LOGICA_H

#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "salas.h"
#include "conexiones.h"
#include "puzles.h"

//Cabecera: void cogerobjeto(jugadores *, objetos *, partidas *, int *, int *, int *)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *, objetos *, partidas *, int *, int *, int *);


//Cabecera: void describir(salas *, partida , int *, int *)
//Precondición: La funcion recive la estructura de salas y partida inicializada
//Postcondición: El jugador ver la descripcion de la sala en la que se encuentra y si es la salida, se le preguntara si quiere volver al menu principal
void describir(partidas *, sala *, conexion *, jugador *, objetos *, puzle *,int*, int* , int *, int *, int *, int *, int *, int *);

//Cabecera: void examinar(salas *, objetos *, partida , jugador *, conexion*, int *, int *, int *, int *)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *, objetos *, partidas* , jugador *, conexion* , int *, int *, int *, int *, int *);
//Cabecera: void soltarobjeto(jugadores *, objetos *, partida , int *)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *, objetos *, partidas* , int *);


//Cabecera: void resolver(puzles *, partida , int *, int *)
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *, partidas *, int *, int *);


//Cabecera: void soltarobjeto(puzle *, partidas , int *, jugador *, objetos *, int *, int *)
//Precondición: La funcion recive la estructura de puzle, jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(puzle *, partidas *, int * , jugador *, objetos *, int *, int *);


//Cabecera: void entrarsala(partidas *,sala* , sala , conexion*, int *, int *, int *)
//Precondición: La función recive la estructura de partida, conexion y sala
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas *, conexion* , sala *, int *, int *, int *);


//Cabecera: void usarobjeto(objetos *,partidas *, conexion *, jugador *, int *, int * , int *)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos *, partidas *, conexion *, jugador* , int* , int* , int *);


//Cabecera: void verificarusuario(jugador *, int *, int *, partidas *, int *, int *)
//Precondición: La estructura de los jugadores debe estar inicializado
//Postcondición: Verifica si el usuario existe o no, y si la contraseña es correcta o no
void verificarusuario(jugador *, int *, int *, partidas *, int *, int *);

//Cabecera: void nuevapartida(jugador *, partidas *, int *, int *, int *, int *)
//Precondición:  Las estructuras jugadorespartida deben estar inicializadas
//Postcondición: Se añadira un nuevo jugador en el vector de jugadores y se inicializara la partida con los datos del nuevo jugador
void nuevapartida(jugador *, partidas *,sala *, int *, int *, int *, int *);
#endif
