
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

partidas *epar;
int npar;
npar=contarpar(epar);
epar= (partidas*) malloc (npar*sizeof(partidas));
leerpartidas(epar,npar);

puzle *epuz;
int npuz;
npuz= contarpuz();
epuz= (puzle*) malloc (npuz* sizeof(puzle));
leerpuzles(epuz, npuz);

sala *esal;
int nsal;
nsal= contarsal();
esal= (sala*) malloc (nsal* sizeof(sala));




}