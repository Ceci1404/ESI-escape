#include "verificarusuario.h"
#include "jugadores.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Cabecera: void verificarusuario(jugador j, int *jug)
//Precondición: La estructura de los jugadores debe estar inicializado
//Postcondición: Verifica si el usuario existe o no, y si la contraseña es correcta o no
void verificarusuario(jugador j, int *jug){
    char usuario[21], password[9];
    int correcto=0,x;
    do{
        printf("Ingrese su nombre de usuario: \n");     
        scanf("%s",usuario);                            //Se pide el nombre de usuario hasta que se meta el adecuado
        for(x=0;x<njug;x++){
            if(strcmp(usuario,j[x].nom_jugador)==0){    //Si se encuentra el usuario, se pide la contraseña
                printf("Ingrese su contraseña: \n");
                scanf("%s",password);                   
                do{
                    if(strcmp(password,j[x].password)==0){          //Si la contraseña es correcta, se le da la bienvenida al jugador y se guarda su posición en el vector de jugadores para usarla posteriormente
                        printf("Bienvenido %s\n",j[x].nom_jugador);
                        *jug=x;
                        correcto=1;
                    }else{
                        printf("Contraseña incorrecta, intente de nuevo: \n");      //Si la contraseña es incorrecta, se le vuelve a pedir hasta que lo sea
                        scanf("%s",password);
                    }
                }while(correcto==1);
            }
            else{
                printf("Usuario no encontrado, intente de nuevo: \n");              //Aviso si el usuario es incorrecto, luego se volvera a pedir
            }
        }
    }while(correcto=1);
}
