
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include "ficheros.h"
#include "menu.h"



int main(){
int *numpuz;
char* cad;

ficherotocad("puzles.txt", cad);
puzle* p= crearpuz(cad, &numpuz);


}