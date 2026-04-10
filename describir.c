#include "describir.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "salas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

//Cabecera: void describir(salas s, partida p)
//Precondición: La funcion recive la estructura de salas y partida inicializada
//Postcondición: El jugador ver la descripcion de la sala en la que se encuentra y si es la salida, se le preguntara si quiere volver al menu principal
void describir( sala *s, partidas p){
    int x, volver;
    for(x=0; x<=sizeof(s); x++){
        if(strcmp(p.sala_actual, s[x].id_sala)==0){
            printf("Estas en la sala %s, %s \n", s[x].id_sala, s[x].descrip);
            if(s[x].tipo==SALIDA){
                printf("Felicidades, has encontrado la salida\n");
                
                do{
                    printf("Quieres volver al menu principal? Si:1 No:0 \n");
                    if (volver==1){
                        menu(/*Rellenare cuando este el menu terminado */);
                    } 
                }while(volver!=1 && volver!=0);
            }
        }
    }
}