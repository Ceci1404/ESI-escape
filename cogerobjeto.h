#ifndef COGEROBJETO_H
#define COGEROBJETO_H


//Cabecera: void cogerobjeto(jugadores, objetos, partida)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *j, objetos *o, partidas p,/*inventario *einv, int ninv, int nobj */ );

#endif