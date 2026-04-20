#include "logica.h"
#include "partida.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "salas.h"
#include "puzles.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Cabecera: void cogerobjeto(jugadores j, objetos o, partida p)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida
//Postcondición: El jugador podra coger objetos que esten en la sala actual y se añadiran en el inventario
void cogerobjeto(jugador *j, objetos *o, partidas *p, int *numobj, int *jug, int *par){
    int coger, i=0;
    int x;
    int objetos_en_sala=0;
    for(x=0; x<=j[*jug].cant_obj; x++) {
    
        if (strcmp(p[*par].sala_actual,o[x].localiz)==0){
            objetos_en_sala=1;
            if (j[*jug].tamainv>j[*jug].cant_obj){     //Si el inventario del jugador no esta lleno, se le pregunta si quiere coger el objeto
                do{
                    printf("Puedes coger el objeto %s, ¿quieres cogerlo? Si:1 No:0 \n", o[x].nomb_obj);
                    scanf("%d", &coger);
                }while (coger!=1 && coger!=0);
                if(coger==1){
                    j[*jug].tamainv++;
                    j[*jug].inv=realloc(j[*jug].inv, j[*jug].tamainv*sizeof(j[*jug].inv[0]));
                    j[*jug].cant_obj++;
                    strcpy(j[*jug].inv[j[*jug].cant_obj-1].objinv,o[x].id_obj);

                }
            }
        }
        
    }
if (objetos_en_sala == 0) {
printf("No hay ningún objeto en esta sala\n");
}
   printf("Presiona Enter para volver al menú principal...");
                getchar();
                getchar();
}



//Cabecera: void describir(salas *s, partida p, int *numsal, int *par)
//Precondición: La funcion recive la estructura de salas y partida inicializada
//Postcondición: El jugador ver la descripcion de la sala en la que se encuentra y si es la salida, se le preguntara si quiere volver al menu principal
partidas *, sala *, conexion *, jugador *, objetos *, puzle *,int*, int* , int *, int *, int *, int *, int *, int *
void describir( partidas * p, sala *s, conexion *c, jugador *j, objetos *o, puzle *pu,int *numsal, int *numobj, int *numcon, int *numpuz, int *numpar, int *numjug, int *jug, int *par){
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
                        menu(p, s, c, j,o,p,numsal, numobj, numcon, numpuz, numpar, numjug, jug, par);
                }
                    } 
                }while(volver!=1 && volver!=0);
            }
        }
    }
}

//Cabecera: void examinar(salas *s, objetos *o, partida p, jugador j, conexion* c, int *numsal, int *numobj, int *numcon, int *jug)
//Precondición: La funcion recive la  estructura de salas, objetos, partida y jugador inicializadas
//Postcondición: Se le describira al jugador los objetos de la sala actual y las conexiones de salida.
void examinar(sala *s, objetos *o, partidas *p, jugador *j, conexion* c, int *numsal, int *numobj, int *numcon, int *jug, int *par) {
   int x,y,z,m;
   for(x=0; x<*numsal; x++){
        if(strcmp(p[*par].sala_actual, s[x].id_sala)==0){     //Verificación de la sala actual con la sala en vector
            for(y=0; y<*numobj; y++){
                if(strcmp(s[x].id_sala, o[y].localiz)==0){      //Verificación de los objetos que estan en la sala
                    for(z=0; z<j[*jug].tamainv; z++){
                        if (strcmp(o[y].id_obj, j[*jug].inv[z].objinv)!=0){
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
       printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
}


//Cabecera: void mostrarinventario(jugadores *j, objetos *o, partida p, int *jug)
//Precondición: La funcion recive la estructura de jugadores, objetos y partida inicializada
//Postcondición: El jugador mostrara los objetos que tiene en su inventario
void mostrarinventario(jugador *j, objetos *o, partidas *p, int * jug){
    int x,y;
    printf("Los objetos en tu inventario son:\n");
    for(x=0; x<=j[*jug].cant_obj; x++){
        for(y=0; y<=j[*jug].cant_obj; y++){            //Recorremos el vector del inventario y lo mostramos
            if(strcmp(j[*jug].inv[y].objinv,o[x].id_obj)==0){
                printf("%d %s %s %s %s \n", x, o[x].id_obj, o[x].nomb_obj, o[x].desc, o[x].localiz);

            }
        }
    }
       printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
}



//Cabecera: void resolver(puzles *puz, partida p, int *numpuz, int *par)
//Precondición: La función recive la estructura de puzles y partida inicializada
//Postcondición: El jugador podra resolver puzles
void resolver(puzle *puz, partidas *p, int *numpuz, int *par){
    char c[5];
    int x,y,resolver;
    for(x=0; x<=*numpuz; x++){
        if(strcmp(p[*par].sala_actual, puz[x].id_sala)==0){           //Comprobamos que el puzle este en la sala actual
            printf("El puzle es de tipo %s\nDescripcion: %s\n", puz[x].tipo, puz[x].desc);
            for(y=0; y<p[*par].num_puzles; y++){
                if(p[*par].puzles_estado[y].resuelto==1){          //Nos dice si el puzle esta resuelto o no
                    printf("El puzle %s ya ha sido resuelto.\n", puz[x].nomb_puz);
                }
                else{
                    do{
                        printf("Puedes resolver el puzle %s, ¿quieres resolverlo? Si:1 No:0 \n", puz[x].nomb_puz);
                        scanf("%d", &resolver);
                    }while(resolver!=1 && resolver!=0);
                    if(resolver==1){
                        printf("%s\n", puz[x].sol);                             //Muestra la solución del puzle
                    }
                }
            }
        }
    }
       printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
    
}




//Cabecera: void soltarobjeto(puzle *puz, partidas p, int numpuz, jugador *j, objetos *o, int *jug, int *par)
//Precondición: La funcion recive la estructura de puzle, jugadores, objetos y partida inicializada
//Postcondición: El jugador soltara un objeto del inventario en la sala actual
void soltarobjeto(puzle *puz, partidas *p, int *numpuz, jugador *j, objetos *o, int *jug, int *par){
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
   printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
}


//Cabecera: void entrarsala(partida *p, conexion *co,sala *s , conexion *econ, int *numcon, int *numsal, int *par)
//Precondición: La función recive la estructura de partida, conexion y sala y el vector de conexiones inicializados
//Postcondición: El jugador se movera entre salas si es posible
void entrarsala(partidas *p, conexion* co, sala *s,int *numcon, int *numsal, int *par){
    bool des=0;
    int entrar, x,y,z;
    for (int i=0; i<=*numcon; i++){
        if (strcmp(co[i].id_conexion,p[*par].sala_actual)==0){   //Si el id de la conexion coincide con el id de la sala actual del jugador, se comprueba si la conexion esta activa o bloqueada))
            for (y=0; y<=p[*par].num_conexunlocked || strcmp(co[i].id_conexion,p[*par].conex_desbloqueadas[y].id_conexion)==0; y++){
                des=1;   //Si la conexion esta desbloqueada, se marca como desbloqueada para que el jugador pueda entrar a la sala
            }
            if (des==1){
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
   printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
}


//Cabecera: void usarobjeto(objetos *o,partidas *p, conexion *c, jugador *j, int *jug, int *numobj, int *par)
//Precondición: La función recive la estructura de objetos, partida, conexiones y jugador inicializada
//Poscondición: El jugador podra usar un objeto del inventario para desbloquear conexiones
void usarobjeto(objetos *o,partidas *p, conexion *c, jugador *j, int *jug, int *numobj, int *par){
    int usar, i;
    int x,y,z;
    p[*par].conex_desbloqueadas=NULL;
    for (int i=0; i<=*numobj; i++){
        if (strcmp(c[i].id_conexion,p[*par].sala_actual)==0){                             //Comprobamos que la conexión de la sala actual
            for(y=0; y<=j[*jug].cant_obj; y++){
                if (strcmp(c[i].cond,j[*jug].inv[y].objinv)==0){             //Buscamos en el inventario si hay un objeto que pueda abrir la conexion
                    for(z=0;z<=*numobj; z++){
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
       printf("Presiona Enter para volver al menú de juego...");
                getchar();
                getchar();
}


//Cabecera: void verificarusuario(jugador *j, int *numjug, int *jug, partidas *p, int *numpar, int *par)
//Precondición: La estructura de los jugadores debe estar inicializado
//Postcondición: Verifica si el usuario existe o no, y si la contraseña es correcta o no
void verificarusuario(jugador *j, int *numjug, int *jug, partidas *p, int *numpar, int *par){
    char usuario[21], password[9];
    int x;
    
    printf("\n=== ACCESO AL SISTEMA ===\n");
    
    while(1) {
        printf("Ingrese su nombre de usuario: ");
        scanf("%s", usuario);
        
        printf("Ingrese su contrasena: ");
        scanf("%s", password);
        
        for(x = 0; x < *numjug; x++) {
            if(strcmp(usuario, j[x].jugador) == 0 && strcmp(password, j[x].password) == 0) {
                printf("Bienvenido %s\n", j[x].nomb_jugador);
                *jug = x;
                
                // Buscar partida
                for(x = 0; x < *numpar; x++) {
                    if(strcmp(j[*jug].id_jugador, p[x].jug_actual) == 0) {
                        *par = x;
                        printf("Partida cargada.\n");
                        return;
                    }
                }
                
                printf("No se encontro partida. Se creara una nueva.\n");
                *par = 0;
                return;
            }
        }
        
        printf("Usuario o contrasena incorrectos.\n");
    }
}

//Cabecera: void nuevapartida(jugador *j, partida *p, int *jug, int *numpar)
//Precondición: Las estructuras de  jugadores y partida deben estar inicializadas
//Postcondición: Se añadira un nuevo jugador en el vector de jugadores y se inicializara la partida con los datos del nuevo jugador
void nuevapartida(jugador *j, partidas *p, sala *s, int *jug, int *njug , int *par, int *numpar){
    int correcto=0,repetido=0, x, y;

    j= (jugador*) realloc(j, ((*njug)+1)*sizeof(jugador));
    *jug = (*njug) - 1;

    /*Comienzo con la estructura del jugador*/
    //Creación del identificador del jugador
    if(*jug<10){
        sprintf(j[*(njug-1)].id_jugador, "%02d", *jug);         //Si el numero es menor a 10 se le añade delante un 0
    }
    else{
        sprintf(j[*(njug-1)].id_jugador, "%d", *jug);
    }
    //Petición del nombre Completo del jugador
    do{
        printf("Introduce tu nombre completo: \n");
        scanf("%s", j[*(njug-1)].nomb_jugador);
        do{
            printf("El nombre introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*(njug-1)].nomb_jugador);
            scanf("%d", &correcto);
        }while (correcto!=0 && correcto!=1);

    }while(correcto!=1);

    correcto=0;

    //Nombre de usuario
    do{
        printf("Introduce tu nombre de usuario: \n");
        scanf("%s", j[*(njug-1)].jugador);

        do{
            for (y=0; y<*njug; y++){
                if(strcmp(j[*(njug-1)].jugador, j[y].jugador)==0){        //Comprobamos que el nombre de usuario no esta repetido
                    printf("El nombre de usuario ya existe, introduce otro: \n");
                    scanf("%s", j[*(njug-1)].jugador);
                }
            }
        }while(repetido!=0);

        do{
            printf("El nombre de usuario introducido es: %s, ¿es correcto? Si:1 No:0 \n", j[*(njug-1)].jugador);
            scanf("%d", &correcto);
        }while (correcto!=0 && correcto!=1);

    }while(correcto!=1);

    correcto=0;

    //Contraseña
    do{
        printf("Introduce tu contraseña: \n");
        scanf("%s", j[*(njug-1)].password);
        
        do{
        printf("La contraseña introducida es: %s, ¿es correcta? Si:1 No:0 \n", j[*njug].password);
        scanf("%d", &correcto);
        }while (correcto!=0 && correcto!=1);
    }while(correcto!=1);


    //El inventario se inicializa vacio y el jugador empieza en la sala de inicio
    j[*(njug-1)].inv=NULL;
    int cant_obj=0;
    int tamainv=10;

    j[*(njug-1)].inv = (inventario*) realloc(j[*(njug-1)].inv, tamainv*sizeof(inventario));

    /*Inicialización de la estructura de la partida*/
    //Jugador actual
   
    *par++; 
    p = (partidas*) realloc(p, (*par+1)*sizeof(partidas));
    p[*par].puzles_estado=NULL;
    p[*par].conex_desbloqueadas=NULL;
    strcpy(j[*(njug-1)].id_jugador, p[*(par)].jug_actual);

   // Sala actual
for(x = 0; x < *numpar; x++){
    if(s[x].tipo == INICIAL){
        strcpy(p[*par].sala_actual, s[x].id_sala);
        break;
    }
}
    //La partida empieza sin conexiones desbloqueadas ni puzles resueltos
    p[*par].num_conexunlocked=0;
    p[*par].conex_desbloqueadas = realloc(p[*par].conex_desbloqueadas, p[*par].num_conexunlocked*sizeof(conexunlocked));

    p[*par].num_puzles=0;
    p[*par].puzles_estado = realloc(p[*par].puzles_estado, p[*par].num_puzles*sizeof(puzleresuelto));
   printf("Presiona Enter para ir al menú de juego...");
                getchar();
                getchar();
}

