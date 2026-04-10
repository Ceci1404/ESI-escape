#include "resolver.h"
#include "partida.h"
#include "puzles.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: void resolver(puzles puz, partida p, int npuz)
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *puz, partidas p, int npuz){
    char c[5];
    int x,y,resolver;
    for(x=0; x<=npuz; x++){
        if(strcmp(p.sala_actual, puz[x].id_sala)==0){
            printf("El puzle es de tipo %s\nDescripcion: %s\n", puz[x].tipo, puz[x].desc);
            for(y=0; y<p.num_puzles; y++){
                if(p.puzles_estado[y].resuelto==true){
                    printf("El puzle %s ya ha sido resuelto.\n", puz[x].nomb_puz);
                }
                else{
                    do{
                        printf("Puedes resolver el puzle %s, ¿quieres resolverlo? Si:1 No:0 \n", puz[x].nomb_puz);
                    }while(resolver!=1 && resolver!=0);
                    if(resolver==1){
                        puz[x].sol;
                    }
                }
            }
        }
    }
    
}