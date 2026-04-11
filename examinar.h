#ifndef EXAMINAR_H
#define EXAMINAR_H


//Cabecera: void examinar(salas s, objetos o, partida p, jugador j, int nsal, int nobj, int ninv, int ncon, int *jug)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *s, objetos *o, partidas p, jugador j, conexion* c, int nsal, int nobj, int ninv, int ncon, int *jug);

#endif