#ifndef PARTIDA_H
#define PARTIDA_H
//ESTA CABECERA NO ESTÁ TERMINADA

typedef enum {FALSE,TRUE } bool;

//cambiar esto a juego.h
typedef struct {
    char id_conexion[4];
    bool activa; 

}conexunlocked;

typedef struct {
    char id_puzle[4];   
    bool resuelto; //0 --> PENDIENTE, 1--> RESUELTO
}puzleresuelto;

typedef struct{
    char id_obj[5];
    char localiz[11];

}objloc;
typedef struct {
    
    int jug_actual;           
    int sala_actual;
    objloc objpar[10];
    int num_objetospar;          
    conexunlocked conex_desbloqueadas[50];  
    int num_conexunlocked;   
    puzleresuelto puzles_estado[50];      
    int num_puzles;


}partidas;

#endif