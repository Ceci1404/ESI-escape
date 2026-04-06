#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "partida.h"
#include "salas.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "puzles.h"
#include "ficheros.h"
#include "describir.h"
#include "examinar.h"
#include "ubicacion.h"
#include "cogerobjeto.h"
#include "soltarobjeto.h"
#include "inventario.h"
#include "usarobjeto.h"
#include "resolver.h"

void menu_principal();
void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz);

#endif
