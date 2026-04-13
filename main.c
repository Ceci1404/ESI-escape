
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include "ficheros.h"
#include "juego.h"
#include "logica.h"
#include "menu.h"



int main() {

    //Definición de variables necesarias para la inicialización de las funciones
    int *numsal, *numobj, *numcon, *numpuz, *numjug, *numpar;
    int *jug=0;
    int *par=0;
    char *cad=NULL;

    sala *s;
    conexion *c;
    jugador *j;
    objetos *o;
    puzle *puz;
    partidas *p;

    //Llamada a la inicialización de los vectores a partir de los ficheros
        cad= ficherotocad("sala.txt",cad);
    s = crearsala(cad,&numsal);
        cad= ficherotocad("conexiones.txt",cad);
    c = crearconex(cad,&numcon);
        cad= ficherotocad("jugadores.txt",cad);
    j = crearjug(cad,&numjug);
        cad= ficherotocad("objetos.txt",cad);
    o = crearobj(cad,&numobj);
        cad= ficherotocad("puzles.txt",cad);
    puz = crearpuz(cad,&numpuz);
        cad= ficherotocad("partida.txt",cad);
    p = crearpar(cad,&numpar);


        //Llamada a menú principal para la inicialización del juego.
    menu_principal(p, s, c, j, o, puz, &numsal, &numobj, &numcon, &numpuz, &jug, &par);

    return 0;
}