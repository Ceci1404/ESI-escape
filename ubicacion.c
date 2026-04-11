#include "ubicacion.h"
#include "partida.h"
#include "conexiones.h"
#include "salas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void entrarsala(partida p, sala s, conexion co, conexion *econ, int *numcon, int *numsal)
//Precondición: La función recive la estructura de partida, conexion y sala y el vector de conexiones inicializados
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas p, conexion* co, sala s, conexion *econ, int *numcon, int *numsal){
    bool des=false;
    int entrar, x,y,z;
    for (int i=0; i<=ncon; i++){
        if (strcmp(co[i].id_conexion,p.sala_actual)==0){   //Si el id de la conexion coincide con el id de la sala actual del jugador, se comprueba si la conexion esta activa o bloqueada))
            for (y=0; y<=p.num_conexunlocked || strcmp(co[i].id_conexion,p.conex_desbloqueadas[y].id_conexion)==0; y++){
                des=true;   //Si la conexion esta desbloqueada, se marca como desbloqueada para que el jugador pueda entrar a la sala
            }
            if (des==true){
                do {
                    while(x=0; x<nsal || strcmp(s[x].id_sala,co[i].id_destino)!=0){ //ESTO HAY QUE CAMBIARLO
                        x++;
                    }
                    printf("Puedes entrar a la sala: %s, ¿quieres entrar? Si:1 No:0 \n", s[x].nomb_sala);
                    scanf("%d", &entrar);
                }while (entrar!=1 && entrar!=0);
                if(entrar==1) strcpy(co[i].id_destino,p.sala_actual);      //Si la conexión esta activa, se copia el id de la sala a la que se puede entrar en la variable en la sala actual
            }
            else printf("La conexión de la sala esta bloqueada, solucion: %s",co[i].cond);
}
}
}
