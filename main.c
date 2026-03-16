
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include "ficheros.h"
#include "menu.h"

void leerficheros();

int main(){

leerficheros();



}

// HAY QUE CAMBIAR TODO ESTO

void leerficheros(){
jugador *ejug;
int njug;
njug=contarjug(ejug);
ejug= (jugador*) malloc (njug*sizeof(jugador));
leerjugadores(ejug, njug);

conexion *econ;
int ncon;
ncon=contarcon(econ);
econ=(conexion*) malloc (ncon*sizeof(conexion));
leerconexiones(econ, ncon);

objetos *eobj;
int nobj;
nobj= contarobj(eobj);
eobj= (objetos*) malloc (nobj*sizeof(objetos));
leerobjetos(eobj,nobj);

 //partida será un único objeto tipo estructura así que no habrá que almacenar sus datos dinámicamente
/*
partidas *epar;
int npar;
npar=contarpar(epar);
epar= (partidas*) malloc (npar*sizeof(partidas));
leerpartidas(epar,npar);
*/


puzle *epuz;
int npuz;
npuz= contarpuz();
epuz= (puzle*) malloc (npuz* sizeof(puzle));
leerpuzles(epuz, npuz);

sala *esal;
int nsal;
nsal= contarsal();
esal= (sala*) malloc (nsal* sizeof(sala));
leersalas(esal, nsal);
//mejor hacerlo con un realloc en una misma función para abrir solo una vez el fichero, 
//en vez de abrirlo una vez para ver la cantidad de lineas que hay y otra para almacenar



}