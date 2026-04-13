
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
    int *numsal=0;
    int *numobj=0;
    int *numcon=0;
    int *numpuz=0;
    int *jug=0;
    int *par=0;
    char *cad=NULL;

    sala *s=NULL;
    conexion *c=NULL;
    jugador *j=NULL;
    objetos *o=NULL;
    puzle *puz=NULL;
    partidas *p=NULL;

    //Llamada a la inicialización de los vectores a partir de los ficheros
    s = crearsala(cad,&numsal);
    c = crearconex(cad,&numcon);
    j = crearjug(cad,&numjug);
    o = crearobj(cad,&numobj);
    puz = crearpuz(cad,&numpuz);
    p = crearpartida(cad,&numpar);


        //Llamada a menú principal para la inicialización del juego.
    menu_principal(*p, s, c, j, o, puz, &numsal, &numobj, &numcon, &numpuz, &jug, &par);

    return 0;
}