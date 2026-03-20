#include "ubicacion.h"
#include "librerias.h"

#include "partida.h"
#include "conexiones.h"
#include "salas.h"

//Cabecera: void entrarsala(partida p, sala s, conexion co, conexion *econ, int ncon)
//Precondición: La función recive la estructura de partida, conexion y sala y el vector de conexiones inicializados
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas p, conexion co, sala s, conexion *econ, int ncon){
    int entrar,i=0;
    strcpy(c,p.sala_actual);
    while (i!=ncon){
        if (strcmp(co.id_conexion,p.sala_actual)==0){   //Si el id de la conexion coincide con el id de la sala actual del jugador, se comprueba si la conexion esta activa o bloqueada))
            if co.estado[i]==TRUE{
                do {
                    printf("Puedes entrar a la sala: %s, ¿quieres entrar? Si:1 No:0 \n", s.nomb_sala[co.id_destino]);
                    scanf("%d", &entrar)
                }while (entrar!=1 && entrar!=0);
                if(entrar==1) strcpy(co.id_destino,p.sala_actual);      //Si la conexión esta activa, se copia el id de la sala a la que se puede entrar en la variable en la sala actual
            }
            else printf("La conexión de la sala esta bloqueada, solucion: %s",co.cond);
        i++;}
}