#ifndef CONEXIONES_H
#define CONEXIONES_H


typedef struct conexion{
    char id_conexion[4]; 
    char id_origen[3];
    char id_destino[3]; 
    bool estado; //TRUE para activa FALSE para bloqueada
    char cond[5]; //"Condición necesaria para el desbloqueo si la conexión está bloqueada (Cond): 0 si no aplica,Id_obj o Id_puzle.""
};


#endif