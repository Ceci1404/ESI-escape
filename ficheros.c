#include<stdio.h>
#include<fichero.h>
#include "partida.h"
#include "jugadores.h"
#include "librerias.h"


void leerficheros ();

void cargarficheros(){

Puzle registro_puzles[100]; 
int total_puzles = 0;


void carga_ficheros() {
    printf("--- Iniciando carga de ficheros ---\n");

    FILE* fichero_puzles = fopen("puzles.txt", "r");

    if (fichero_puzles == NULL) {
        printf("Aviso: No se encontro 'puzles.txt'. Se usaran los valores por defecto.\n");
        return; 

    
    char id_temporal[50];
    int estado_temporal;

    
    while (fscanf(fichero_puzles, "%49s %d", id_temporal, &estado_temporal) == 2) {
        
        strcpy(registro_puzles[total_puzles].id, id_temporal);
        
        if (estado_temporal == 1) {
            registro_puzles[total_puzles].resuelto = true;
        } else {
            registro_puzles[total_puzles].resuelto = false;
        }
        
        total_puzles++; 
    }

    
    fclose(fichero_puzles);
    
    printf("Exito: Se han cargado %d puzles en la memoria.\n", total_puzles);
}
    
  
}

void nuevapartida(jugador *);
