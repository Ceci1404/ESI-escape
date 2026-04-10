#ifndef USAROBJETO_H
#define USAROBJETO_H


//Cabecera: void usarobjeto(objetos ,partida , conexiones , jugador )
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos o, partidas p, conexion *c, jugador j);

#endif