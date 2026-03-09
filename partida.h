#ifndef PARTIDA_H
#define PARTIDA_H
//ESTA CABECERA NO ESTÁ TERMINADA
#include "librerias.h"
#include "jugadores.h"
#include "salas.h"
#include "conexiones.h"
#include "puzles.h"

typedef struct {
    char id_conexion[4];
    bool activa; 

}conexunlocked;

typedef struct {
    char id_puzle[4];   
    bool resuelto;
}puzleresuelto;


typedef struct {
    
    jugador jug_actual;           
    char sala_actual[3];          
    conexunlocked conex_desbloqueadas[50];  
    int num_conexunlocked;   
    puzleresuelto puzles_estado[50];      
    int num_puzles;


}partida;

#endif