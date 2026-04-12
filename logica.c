#include "logica.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "salas.h"
#include "puzles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cabecera: void cogerobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *j, objetos *o, partidas *p, int *numobj, int *jug, int *par){
    int coger, i=0;
    int x;
    for(x=0; x<=j[*jug].cant_obj; x++) {
        if (strcmp(p[*par].sala_actual,o[x].localiz)==0){
            if (j[*jug].tamainv>j[*jug].cant_obj){     //Si el inventario del jugador no esta lleno, se le pregunta si quiere coger el objeto
                do{
                    printf("Puedes coger el objeto %s, ¿quieres cogerlo? Si:1 No:0 \n", o[p.sala_actual].nomb_obj);
                    scanf("%d", &coger);
                }while (coger!=1 && coger!=0);
                if(coger==1){
                    numinv++;
                    j[*jug].inventario=realloc(j[*jug].inventario, j[*jug].tamainv*sizeof(j[*jug].inventario[0]));
                    j[*jug].cant_obj++;
                    j[*jug].inventario[j[*jug].cant_obj-1].objinv=o[x].id_obj;

                }
            }
        }
        else printf("No hay ningun objeto en esta sala \n");
    }
   
}



//Cabecera: void describir(salas *s, partida p, int *numsal, int *par)
//Precondición: La funcion recive la estructura de salas y partida inicializada
//Postcondición: El jugador ver la descripcion de la sala en la que se encuentra y si es la salida, se le preguntara si quiere volver al menu principal
void describir( sala *s, partidas *p, int *numsal, int *par){
    int x, volver;
    for(x=0; x<=*numsal; x++){
        if(strcmp(p[*par].sala_actual, s[x].id_sala)==0){             //Si la sala actual es igual a la sala del vector se describe
            printf("Estas en la sala %s, %s \n", s[x].id_sala, s[x].descrip);
            if(s[x].tipo==SALIDA){
                printf("Felicidades, has encontrado la salida\n");
                
                do{
                    printf("Quieres volver al menu principal? Si:1 No:0 \n");       //Da la opción es afirmativa se llamara al menu principal
                    scanf("%d", &volver);
                    if (volver==1){
                        menu(/*Rellenare cuando este el menu terminado */);
                    } 
                }while(volver!=1 && volver!=0);
            }
        }
    }
}


//Cabecera: void examinar(salas *s, objetos *o, partida p, jugador j, conexion* c, int *numsal, int *numobj, int *numinv, int *numcon, int *jug)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *s, objetos *o, partidas p, jugador j, conexion* c, int *numsal, int *numobj, int *numinv, int *numcon, int *jug, int *par){ {
   int x,y,z,m;
   for(x=0; x<*numsal; x++){
        if(strcmp(p.sala_actual, s[x].id_sala)==0){     //Verificación de la sala actual con la sala en vector
            for(y=0; y<*numobj; y++){
                if(strcmp(s[x].id_sala, o[y].localiz)==0){      //Verificación de los objetos que estan en la sala
                    for(z=0; z<*numinv; z++){
                        if (strcmp(o[y].id_obj, j[*jug].inventario[z].objinv)!=0){
                            printf("Objeto: %s\nDescripcion: %s\n", o[y].nomb_obj, o[y].desc);
                        }
                    }
                }
            }

            for(m=0; m<p[*par].num_conexunlocked; m++){
                if(strcmp(p[*par].sala_actual, c[m].id_origen)==0){       //Comprobamos que la conexión tiene el mismo id que la sala actual
                    if(strcmp(p[*par].conex_desbloqueadas[m].id_conexion, c[m].id_conexion)==0){      //Comprobamos que la sala esta desbloqueada o no
                        printf("Conexion: %s\n", c[m].id_conexion);
                    }
                    else{
                        printf("Conexion: %s (bloqueada)\n", c[m].id_conexion);
                    }
                    
                }
            }
        }
    }
}


//Cabecera: void mostrarinventario(jugadores *j, objetos *o, partida p, int *jug)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *j, objetos *o, partidas p, int * jug){
    int x,y;
    printf("Los objetos en tu inventario son:\n");
    for(x=0; x<=j[*jug].cant_obj; x++){
        for(y=0; y<=j[*jug].cant_obj; y++){            //Recorremos el vector del inventario y lo mostramos
            if(strcmp(j[*jug].inv[y].objinv,o[x].id_obj)==0){
                printf("%d %s %s %s %s \n", x, o[x].id_obj, o[x].nomb_obj, o[x].desc, o[x].localiz);

            }
        }
    }
}



//Cabecera: void resolver(puzles *puz, partida p, int *numpuz, int *par)
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *puz, partidas p, int *numpuz, int *par){
    char c[5];
    int x,y,resolver;
    for(x=0; x<=numpuz; x++){
        if(strcmp(p[*par].sala_actual, puz[x].id_sala)==0){           //Comprobamos que el puzle este en la sala actual
            printf("El puzle es de tipo %s\nDescripcion: %s\n", puz[x].tipo, puz[x].desc);
            for(y=0; y<p.num_puzles; y++){
                if(p.puzles_estado[y].resuelto==true){          //Nos dice si el puzle esta resuelto o no
                    printf("El puzle %s ya ha sido resuelto.\n", puz[x].nomb_puz);
                }
                else{
                    do{
                        printf("Puedes resolver el puzle %s, ¿quieres resolverlo? Si:1 No:0 \n", puz[x].nomb_puz);
                        scanf("%d", &resolver);
                    }while(resolver!=1 && resolver!=0);
                    if(resolver==1){
                        puz[x].sol;                             //Muestra la solución del puzle
                    }
                }
            }
        }
    }
    
}




//Cabecera: void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug, int *par)
//Precondición: La funcion recive la estructura de puzle, jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug, int *par){
    char c[5];
    int soltar, i=0;
    int x,y,aux;
    printf("Los objetos en tu inventario son:\n");  //Describe el inventario del jugador para que pueda elegir el objeto a soltar
    for(x=0; x<=j[*jug].cant_obj; x++){
        for(y=0; y<=j[*jug].cant_obj; y++){
            if(j[*jug].inv[y].objinv == o[x].id_obj){
                printf("%d %s %s %s \n",x, o[x].id_obj, o[x].nomb_obj, o[x].desc);

            }
        }
    }

    do{
        printf("¿Quieres soltar algun objeto? Si:1 No:0 \n");  //Pregunta al jugador si quiere soltar un objeto
        scanf("%d", &soltar);
    }while(soltar!=1 && soltar!=0 );

    if (soltar==1){
        do{
            printf("Introduce el numero del objeto que quieres soltar \n");
            scanf("%d", &aux);
         }while(aux>=0 || aux<=x);

        strcpy(c, j[*jug].inv[aux].objinv);
        for (x=0; x<=j[*jug].cant_obj || strcmp(c, o[x].id_obj)==0; x++){       //Desde la posición actual del objeto que se cambia, muevo los objetos una posicion hacia atras y reasigno el tamaño del vector a n-1
            if(strcmp(p[*par].sala_actual, o[x].localiz)==0){             //Comprueba si el objeto a soltar pertenece a la sala actual
                for(aux; aux<x-1; aux++){
                strcpy(j[*jug].inv[aux].objinv,j[*jug].inv[aux+1].objinv);
                }

                j[*jug].cant_obj--;
                j[*jug].inv = realloc(j[*jug].inv, j[*jug].cant_obj*sizeof(inventario));
            }
            else printf("No puedes soltar ese objeto en esta sala \n");
        }
            

}
}


//Cabecera: void entrarsala(partida *p, conexion *co,sala *s , conexion *econ, int *numcon, int *numsal, int *par)
//Precondición: La función recive la estructura de partida, conexion y sala y el vector de conexiones inicializados
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas *p, conexion* co, sala *s, conexion *econ, int *numcon, int *numsal, int *par){
    bool des=false;
    int entrar, x,y,z;
    for (int i=0; i<=numcon; i++){
        if (strcmp(co[i].id_conexion,p[*par].sala_actual)==0){   //Si el id de la conexion coincide con el id de la sala actual del jugador, se comprueba si la conexion esta activa o bloqueada))
            for (y=0; y<=p[*par].num_conexunlocked || strcmp(co[i].id_conexion,p[*par].conex_desbloqueadas[y].id_conexion)==0; y++){
                des=true;   //Si la conexion esta desbloqueada, se marca como desbloqueada para que el jugador pueda entrar a la sala
            }
            if (des==true){
                do {
                    for(x=0; x<*numsal; x++){       //Contador para salas
                    }
                    printf("Puedes entrar a la sala: %s, ¿quieres entrar? Si:1 No:0 \n", s[x].nomb_sala);
                    scanf("%d", &entrar);
                }while (entrar!=1 && entrar!=0);
                if(entrar==1) strcpy(co[i].id_destino,p[*par].sala_actual);      //Si la conexión esta activa, se copia el id de la sala a la que se puede entrar en la variable en la sala actual
            }
            else printf("La conexión de la sala esta bloqueada, solucion: %s",co[i].cond);
}
}
}


//Cabecera: void usarobjeto(objetos *o,partidas *p, conexion *c, jugador *j, int *jug, int *numobj, int *par)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos *o,partidas *p, conexion *c, jugador *j, int *jug, int *numobj, int *par){
    int usar, i;
    int x,y,z;
    for (int i=0; i<=numobj; i++){
        if (strcmp(c[i].id_conexion,p[*par].sala_actual)==0){                             //Comprobamos que la conexión de la sala actual
            for(y=0; y<=j[*jug].cant_obj; y++){
                if (strcmp(c[i].cond,j[*jug].inv[y].objinv)==0){             //Buscamos en el inventario si hay un objeto que pueda abrir la conexion
                    for(z=0;z<=numobj; z++){
                        if (strcmp(o[z].id_obj,j[*jug].inv[y].objinv)==0){   //Tomamos el objeto del vector de objetos que es igual al inventario
                            do{
                            printf("Puedes usar el objeto %s en la sala\n ¿quieres usarlo? Si:1 No:0 \n", o[z].nomb_obj);
                            scanf("%d", &usar);
                            }while (usar!=1 && usar!=0);
                        }
                    }

                    if (usar == 1){     //Si el jugador decide usar el objeto, se desbloquea la conexión y se añade a la partida
                        p[*par].num_conexunlocked++;;
                        p[*par].conex_desbloqueadas =  realloc(p[*par].conex_desbloqueadas, p[*par].num_conexunlocked * sizeof(conexunlocked));
                        strcpy(c[i].id_destino, p[*par].conex_desbloqueadas[p[*par].num_conexunlocked-1].id_conexion);
                    }
                }
            }
        }
    }
}


//Cabecera: void verificarusuario(jugador *j, int *numjug, int *jug, partidas *p, int *numpar, int *par)
//Precondición: La estructura de los jugadores debe estar inicializado
//Postcondición: Verifica si el usuario existe o no, y si la contraseña es correcta o no
void verificarusuario(jugador *j, int *numjug, int *jug, partidas *p, int *numpar, int *par){
    char usuario[21], password[9];
    int correcto=0,x;
    do{
        printf("Ingrese su nombre de usuario: \n");     
        scanf("%s",usuario);                            //Se pide el nombre de usuario hasta que se meta el adecuado
        for(x=0;x<*numjug;x++){
            if(strcmp(usuario,j[x].nom_jugador)==0){    //Si se encuentra el usuario, se pide la contraseña
                printf("Ingrese su contraseña: \n");
                scanf("%s",password);                   
                do{
                    if(strcmp(password,j[x].password)==0){          //Si la contraseña es correcta, se le da la bienvenida al jugador y se guarda su posición en el vector de jugadores para usarla posteriormente
                        printf("Bienvenido %s\n",j[x].nomb_jugador);
                        *jug=x;
                        correcto=1;
                    }else{
                        printf("Contraseña incorrecta, intente de nuevo: \n");      //Si la contraseña es incorrecta, se le vuelve a pedir hasta que lo sea
                        scanf("%s",password);
                    }
                }while(correcto==0);
            }
            else{
                printf("Usuario no encontrado, intente de nuevo: \n");              //Aviso si el usuario es incorrecto, luego se volvera a pedir
            }
        }
    }while(correcto!=1);

    correcto=0;
    do{
        for(x=0;x<*numpar;x++){
            if (strcmp(j[*jug].id_jugador, p[x].jug_actual)==0){      //Se compara el id del jugador con el id de la partida en el vector
                correcto=1;
                *par=x;
            }
        }
    }while(correcto!=1);
}


//Cabecera: void nuevapartida(jugador *j, partida *p, int *jug)
//Precondición: Las estructuras de  jugadores y partida deben estar inicializadas
//Postcondición: Se añadira un nuevo jugador en el vector de jugadores y se inicializara la partida con los datos del nuevo jugador
void nuevapartida(jugador *j, partidas *p, int *jug, int *njug , int *par){
    int correcto=0,repetido=0, x, y;

    realloc(j, (njug+1)*sizeof(jugador));
    *jug=njug-1;

    /*Comienzo con la estructura del jugador*/
    //Creación del identificador del jugador
    if(jug<10){
        sprintf(j[*(njug-1)].id_jugador, "%02d", *jug);         //Si el numero es menor a 10 se le añade delante un 0
    }
    else{
        sprintf(j[*(njug-1)].id_jugador, "%d", *jug);
    }
    //Petición del nombre Completo del jugador
    do{
        printf("Introduce tu nombre completo: \n");
        scanf("%s", j[*(njug-1)].nom_jugador);
        do{
            printf("El nombre introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*(njug-1)].nom_jugador);
            scanf("%d", &Correcto);
        }while (Correcto!=0 && Correcto!=1);

    }while(Correcto!=0);

    Correcto=0;

    //Nombre de usuario
    do{
        printf("Introduce tu nombre de usuario: \n");
        scanf("%s", j[*(njug-1)].jugador);

        do{
            for (y=0; y<njug; y++){
                if(strcmp(j[*(njug-1)].jugador, j[y].jugador)==0){        //Comprobamos que el nombre de usuario no esta repetido
                    printf("El nombre de usuario ya existe, introduce otro: \n");
                    scanf("%s", j[*(njug-1)].jugador);
                }
            }
        }while(repetido!=0);

        do{
            printf("El nombre de usuario introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*(njug-1)].jugador);
            scanf("%d", &Correcto);
        }while (Correcto!=0 && Correcto!=1);

    while(Correcto!=0);

    Correcto=0;

    //Contraseña
    do{
        printf("Introduce tu contraseña: \n");
        scanf("%s", j[*(njug-1)].password);
        
        do{
        printf("La contraseña introducida es: %s, ¿es correcta? Si:1 No:0 \n", j[*njug].password);
        scanf("%d", &Correcto);
        }while (Correcto!=0 && Correcto!=1);
    }while(Correcto!=0);


    //El inventario se inicializa vacio y el jugador empieza en la sala de inicio
    int cant_obj=0;
    int tamainv=10;

    j[*(njug-1)].inv = (inventario*) realloc(j[*(njug-1)].inventario, tamainv*sizeof(inventario));

    /*Inicialización de la estructura de la partida*/
    //Jugador actual
    *par++;
    p[*par] = (partidas*) realloc(p, (*par+1)*sizeof(partidas));
    strcpy(j[*(njug-1)].id_jugador, p[*(par)].id_jugador);

    //Sala actual
    for(x=0; x<=numsal; x++){
        if(strcmp(s[x].tipo, INICIO)==0){
            strcpy(p[*par].sala_actual, s[x].id_sala);
        }
    }

    //La partida empieza sin conexiones desbloqueadas ni puzles resueltos
    p.num_conexunlocked=0;
    p[*par].conex_desbloqueadas = realloc(p[*par].conex_desbloqueadas, p[*par].num_conexunlocked*sizeof(conexunlocked));

    p.num_puzles=0;
    p[*par].puzles_estado = realloc(p[*par].puzles_estado, p[*par].num_puzles*sizeof(puzleestado));

}