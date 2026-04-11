#ifndef LOGICA_H
#define LOGICA_H



//Cabecera: void cogerobjeto(jugadores, objetos, partida)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *j, objetos *o, partidas p,/*inventario *einv, int ninv, int nobj */ );


//Cabecera: void describir(salas s, partida p)
//Precondición: La funcion recive la estructura de salas y partida inicializada
//Postcondición: El jugador ver la descripcion de la sala en la que se encuentra y si es la salida, se le preguntara si quiere volver al menu principal
void describir( sala *s, partidas p);

//Cabecera: void examinar(salas s, objetos o, partida p, jugador j, int nsal, int nobj, int ninv, int ncon, int *jug)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *s, objetos *o, partidas p, jugador j, conexion* c, int nsal, int nobj, int ninv, int ncon, int *jug);


//Cabecera: void soltarobjeto(jugadores , objetos , partida , int *)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *, objetos *, partidas , int *);


//Cabecera: void resolver(puzles , partida , int )
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *, partidas , int);


//Cabecera: void soltarobjeto(puzle *, partidas , int , jugador *, objetos *, int *)
//Precondición: La funcion recive la estructura de puzle, jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug);


//Cabecera: void entrarsala(partida , sala* , sala , conexion*, int *, int *) )
//Precondición: La función recive la estructura de partida, conexion y sala
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas p, conexion* co, sala *s, conexion *econ, int *, int *);


//Cabecera: void usarobjeto(objetos ,partida , conexiones , jugador , int *, int *)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos *, partidas , conexion *, jugador* , int* , int* );


//Cabecera: void verificarusuario()
//Precondición: La estructura de los jugadores debe estar inicializado
//Postcondición: Verifica si el usuario existe o no, y si la contraseña es correcta o no
void verificarusuario(jugador, int *);

#endif