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
#include <stdio.h>

int main() {
    int numsal = 0, numobj = 0, numcon = 0, numpuz = 0, numjug = 0, numpar = 0;
    int jug = 0;
    int par = 0;
    char *cad = NULL;

    sala *s = NULL;
    conexion *c = NULL;
    jugador *j = NULL;
    objetos *o = NULL;
    puzle *puz = NULL;
    partidas *p = NULL;

    printf("=== INICIO DEL PROGRAMA ===\n");

    // SALAS
    printf("1. Cargando salas.txt...\n");
    cad = ficherotocad("salas.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar salas.txt\n");
        return 1;
    }
    printf("   Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("2. Creando salas...\n");
    s = crearsala(cad, &numsal);
    printf("   numsal = %d\n", numsal);
    free(cad);
    cad = NULL;
    
    // CONEXIONES
    printf("3. Cargando conexiones.txt...\n");
    cad = ficherotocad("conexiones.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar conexiones.txt\n");
        return 1;
    }
    printf("   Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("4. Creando conexiones...\n");
    c = crearconex(cad, &numcon);
    printf("   numcon = %d\n", numcon);
    free(cad);
    cad = NULL;
    
    // JUGADORES
    printf("5. Cargando jugadores.txt...\n");
    cad = ficherotocad("jugadores.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar jugadores.txt\n");
        return 1;
    }
    printf("   Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("6. Creando jugadores...\n");
    j = crearjug(cad, &numjug);
    printf("   numjug = %d\n", numjug);
    free(cad);
    cad = NULL;
    
    // OBJETOS
    printf("7. Cargando objetos.txt...\n");
    cad = ficherotocad("objetos.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar objetos.txt\n");
        return 1;
    }
    printf("   Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("8. Creando objetos...\n");
    o = crearobj(cad, &numobj);
    printf("   numobj = %d\n", numobj);
    free(cad);
    cad = NULL;
    
    // PUZLES
    printf("9. Cargando puzles.txt...\n");
    cad = ficherotocad("puzles.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar puzles.txt\n");
        return 1;
    }
    printf("   Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("10. Creando puzles...\n");
    puz = crearpuz(cad, &numpuz);
    printf("    numpuz = %d\n", numpuz);
    free(cad);
    cad = NULL;
    
    // PARTIDAS
    printf("11. Cargando partida.txt...\n");
    cad = ficherotocad("partida.txt", cad);
    if(cad == NULL) {
        printf("ERROR: No se pudo cargar partida.txt\n");
        return 1;
    }
    printf("    Archivo cargado, longitud: %ld bytes\n", strlen(cad));
    
    printf("12. Creando partidas...\n");
    p = crearpar(cad, &numpar);
    printf("    numpar = %d\n", numpar);
    free(cad);
    cad = NULL;
    
    printf("=== TODO CARGADO CORRECTAMENTE ===\n");
    printf("Resumen: %d salas, %d conexiones, %d jugadores, %d objetos, %d puzles, %d partidas\n",
           numsal, numcon, numjug, numobj, numpuz, numpar);
    
    printf("\n13. Iniciando menú principal...\n");
    menu_principal(p, s, c, j, o, puz, &numsal, &numobj, &numcon, &numpuz, &numpar, &numjug, &jug, &par);

    return 0;
}