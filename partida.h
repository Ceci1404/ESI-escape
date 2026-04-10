#ifndef PARTIDA_H
#define PARTIDA_H
//ESTA CABECERA NO ESTÁ TERMINADA

typedef enum {TRUE, FALSE} bool;
//cambiar esto a juego.h
typedef struct {
    char id_conexion[4];
    bool activa; 

}conexunlocked;

typedef struct {
    char id_puzle[4];   
    bool resuelto;
}puzleresuelto;


typedef struct {
    
    int jug_actual;           
    int sala_actual;          
    conexunlocked conex_desbloqueadas[50];  
    int num_conexunlocked;   
    puzleresuelto puzles_estado[50];      
    int num_puzles;


}partidas;

#endif