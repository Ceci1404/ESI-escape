#include "juego.h"
#include "ficheros.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Cabecera: char* obtenercad(char* cad, int* pcad, char* buffer)
//Precondición: cad no es NULL, pcad apunta a un índice válido dentro de cad
//Postcondición: buffer contiene el siguiente token (hasta '-' o '\n'), pcad avanza o se pone a -1 si es fin
char* obtenercad(char* cad, int* pcad, char* buffer) {
    int j = 0;
    // FINAL
    if (cad[*pcad] == '\0') {
        *pcad = -1;
        buffer[0] = '\0';
        return buffer;
    }
    // HASTA SEPARADOR
    while (cad[*pcad] != '\0' && cad[*pcad] != '-' && cad[*pcad] != '\n') {
        buffer[j++] = cad[*pcad];
        (*pcad)++;
    }
    buffer[j] = '\0';   
    // AVANZAR SEPARADOR
    if (cad[*pcad] == '-' || cad[*pcad] == '\n') {
        (*pcad)++;
    }   
    // FIN DE LINEA
    while (cad[*pcad] == ' ' || cad[*pcad] == '\t') {
        (*pcad)++;
    }  
    return buffer;
}


//Cabecera: sala* crearsala(char* cad, int *numsal)
//Precondición: cad tiene formato "ID-NOMBRE-TIPO-DESCRIP", numsal no es NULL
//Postcondición: Devuelve array dinámico de salas, *numsal contiene el número de salas creadas

//formato salas:ID-NOMBRE-TIPO-DESCRIP 
sala* crearsala(char* cad, int *numsal) {
    sala* sal = NULL;
    int nsal = 0;
    int pcad = 0;
    char buffer[151];  
    do {    
        
        sal = (sala*)realloc(sal, (nsal + 1) * sizeof(sala));      
        obtenercad(cad, &pcad, buffer);
        strcpy(sal[nsal].id_sala, buffer); //ID       
        obtenercad(cad, &pcad, buffer);
        strcpy(sal[nsal].nomb_sala, buffer);    // NOMBRE 
        obtenercad(cad, &pcad, buffer); // TIPO 
        if (strcmp(buffer, "INICIAL") == 0) sal[nsal].tipo = INICIAL; //INICIAL           
        else if (strcmp(buffer, "NORMAL") == 0) sal[nsal].tipo = NORMAL; //NORMAL       
        else if (strcmp(buffer, "SALIDA") == 0) sal[nsal].tipo = SALIDA; //SALIDA
        obtenercad(cad, &pcad, buffer);
        strcpy(sal[nsal].descrip, buffer); //DESCRIPCIÓN
        nsal++;
    } while (pcad != -1); 
    *numsal = nsal+1;
    return sal;
}

//Cabecera: conexion* crearconex(char* cad, int *numcon)
//Precondición: cad tiene formato "ID-IDOR-IDDES-ESTADO-COND", numcon no es NULL
//Postcondición: Devuelve array dinámico de conexiones, *numcon contiene el número de conexiones creadas
    
//formato conexiones: ID-IDOR-IDDES-ESTADO-COND
conexion* crearconex(char* cad, int *numcon){
    conexion *con=NULL;
int ncon=0;
int pcon=0;
 char buffer[151];  
// con= (conexion* ) malloc (ncon*sizeof(conexion)); en vez de poner esto he inicializado a NULL
do{
    con= (conexion* ) realloc (con,(ncon+1)*sizeof(conexion));
    obtenercad(cad, &pcon, buffer);
    strcpy(con[ncon].id_conexion , buffer); //almaceno el ID de CONEXIÓN
    obtenercad(cad, &pcon, buffer);
    strcpy(con[ncon].id_origen, buffer); //almaceno el id_origen de CONEXIÓN
    obtenercad(cad, &pcon, buffer);
    if(!strcmp(buffer, "ACTIVO")) con[ncon-1].estado=0; //ACTIVO (TRUE) 
    else if (!strcmp(buffer, "BLOQUEADO")) con[ncon-1].estado=1; //BLOQUEADO(FALSE) 
    obtenercad(cad, &pcon, buffer);
    strcpy(con[ncon-1].cond, buffer); //almaceno la condición de desbloqueo (Id_obj, Id_puz o 0 si no aplica)
    ncon++;
}while (pcon != -1);
*numcon= ncon+1;
return con;
}

//Cabecera: jugador* crearjug(char* cad, int *numjug)
//Precondición: cad tiene formato "ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)", numjug no es NULL
//Postcondición: Devuelve array dinámico de jugadores, *numjug contiene el número de jugadores creados

//formato jugadores: ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)
jugador* crearjug(char* cad, int *numjug){
    jugador* jug=NULL;
int njug=0;
int pjug=0;
char buffer[151]; 
do{
    jug= (jugador* ) realloc (jug,(njug+1)*sizeof(jugador));
    obtenercad(cad, &pjug, buffer);
    strcpy(jug[njug].id_jugador , buffer); //almaceno el ID de JUGADOR
    obtenercad(cad, &pjug, buffer);
    strcpy(jug[njug].nomb_jugador, buffer); //almaceno el nombre del JUGADOR
    obtenercad(cad, &pjug, buffer);
    strcpy(jug[njug].jugador,buffer); //almaceno el nombre de sistema del JUGADOR
    obtenercad(cad, &pjug, buffer);
    strcpy(jug[njug].password, buffer); //almaceno la contraseña del jugador
    for(int i=0; i<jug[njug].cant_obj-1;i++){ //almaceno todos los objetos del fichero a las estructuras
        obtenercad(cad, &pjug, buffer);
        strcpy(jug[njug-1].inv[i].objinv, buffer);
    }
    njug++;
}while (pjug != -1);
*numjug=njug+1;
return jug;
}

//Cabecera: objetos* crearobj(char* cad, int* numobj)
//Precondición: cad tiene formato "ID-NOMB-DESC-LOCAL", numobj no es NULL
//Postcondición: Devuelve array dinámico de objetos, *numobj contiene el número de objetos creados

//formato objetos: ID-NOMB-DESC-LOCAL
objetos* crearobj(char* cad, int* numobj){
    objetos *obj=NULL;
int nobj=0;
int pobj=0;
char buffer[151]; 

do{   
    obj= (objetos* ) realloc (obj,(nobj+1)*sizeof(objetos));
    obtenercad(cad, &pobj, buffer);
    strcpy(obj[nobj].id_obj , buffer); //almaceno el ID de OBJETO
    obtenercad(cad, &pobj, buffer);
    strcpy(obj[nobj].nomb_obj, buffer); //almaceno el nombre del OBJETO
    obtenercad(cad, &pobj, buffer);
    strcpy(obj[nobj].desc, buffer); //almaceno la descripción del OBJETO
    obtenercad(cad, &pobj, buffer);
    strcpy(obj[nobj].localiz, buffer); //almaceno la localización del OBJETO
    nobj++;
}while (pobj != -1);
*numobj=nobj+1;
return obj;
}

//Cabecera: puzle* crearpuz(char* cad, int* numpuz)
//Precondición: cad tiene formato "ID-NOMB-IDSALA-TIPO-DESC-SOL", numpuz no es NULL
//Postcondición: Devuelve array dinámico de puzles, *numpuz contiene el número de puzles creados


//formato puzles ID-NOMB-IDSALA-TIPO-DESC-SOL
puzle* crearpuz(char* cad, int* numpuz){
    puzle* puz=NULL;
int npuz=0;
int ppuz=0;
char buffer[151]; 
do{
    puz= (puzle* ) realloc (puz,(npuz+1)*sizeof(puzle));
    obtenercad(cad, &ppuz, buffer);
    strcpy(puz[npuz].id_puzle , buffer); //almaceno el ID de PUZLE
    obtenercad(cad, &ppuz, buffer);
    strcpy(puz[npuz].nomb_puz, buffer); //almaceno el nombre del PUZLE
    obtenercad(cad, &ppuz, buffer);
    strcpy(puz[npuz].id_sala, buffer); //almaceno la sala del PUZLE
    obtenercad(cad, &ppuz, buffer);
    if(strcmp(buffer, "CODIGO")) puz[npuz].tipo=0; //CODIGO
    else if (strcmp(buffer,"PALABRA")) puz[npuz].tipo=1; //PALABRA
    obtenercad(cad, &ppuz, buffer);
    strcpy(puz[npuz].desc, buffer); //almaceno la descripción del PUZLE
    obtenercad(cad, &ppuz, buffer);
    strcpy(puz[npuz].sol, buffer); //almaceno la solución del PUZLE
    npuz++;
}while (ppuz != -1);
*numpuz= npuz+1;
return puz;
}

//Cabecera: char* cadtipopar(char* cad, int *pcad, char* buffer)
//Precondición: cad no es NULL, pcad apunta a un índice válido dentro de cad
//Postcondición: buffer contiene token hasta ':' (o '\n'), pcad avanza o se pone a -1 si es fin


//formato partida:ID_JUG- ID_SAL(ACT)- OBJ 

    char* cadtipopar (char* cad, int *pcad, char* buffer){

            int j = 0;
             buffer[0] = '\0';
    // FINAL
    if (cad[*pcad] == '\0') {
        *pcad = -1;
        buffer[0] = '\0';
        return buffer;
    }
    // HASTA DOS PUNTOS
    while (cad[*pcad] != '\0' && cad[*pcad] != ':' && cad[*pcad] != '\n') {
        buffer[j++] = cad[*pcad];
        (*pcad)++;
    }
        // AVANZAR DOS PUNTOS (Y ESPACIO?)
    if (cad[*pcad] == ':') {
    (*pcad)++;
    if (cad[*pcad] == ' ') (*pcad)++;
}
else if (cad[*pcad] == '\n') { //MANEJO DE SALTO DE LINEA
    (*pcad)++;
}
    return buffer;

    }

//Cabecera: char* caddatpar(char* cad, int *pcad, char* buffer)
//Precondición: cad no es NULL, pcad apunta a un índice válido dentro de cad
//Postcondición: buffer contiene token hasta '-' o '\n', pcad avanza o se pone a -1 si es fin


    char* caddatpar (char *cad, int *pcad, char* buffer){
        int j = 0;
         buffer[0] = '\0';
    // FINAL
    if (cad[*pcad] == '\0') {
        *pcad = -1;
        buffer[0] = '\0';
        return buffer;
    }
    // HASTA SEPARADOR
    while (cad[*pcad] != '\0' && cad[*pcad] != '-' && cad[*pcad] != '\n') {
        buffer[j++] = cad[*pcad];
        (*pcad)++;
    }
    buffer[j] = '\0';   
    // AVANZAR SEPARADOR
    if (cad[*pcad] == '-' || cad[*pcad] == '\n') {
        (*pcad)++;
    }   
    // FIN DE LINEA
    while (cad[*pcad] == ' ' || cad[*pcad] == '\t') {
        (*pcad)++;
    }  
    return buffer;

    }

//Cabecera: partidas* crearpar(char* cad, int* numpar)
//Precondición: cad tiene formato de partida (JUGADOR:ID SALA: \n ID OBJETO:... \nCONEXIÓN:... \nPUZLE:...\n), numpar no es NULL
//Postcondición: Devuelve array dinámico de partidas, *numpar contiene el número de partidas creadas



//ALMACENO TODAS LAS PARTIDAS
partidas* crearpar(char* cad, int* numpar){
    partidas* par=NULL;
    int npar=0; //Número de partidas
    int ppar=0;
    char buffer[151];
     /// v ESTO LO HAGO ANTES DEL BUCLE PARA QUE LUEGO AL FINAL NO SE REPITA
    cadtipopar(cad,&ppar,buffer); //"JUGADOR: "
    do{ 
        int  nobj=0, ncond=0, npuz=0; //número de objetos de partida, número de conexiones desbloqueadas y número de puzles
        par= (partidas* ) realloc (par,(npar+1)*sizeof(partidas));
        //--------------------
        caddatpar(cad,&ppar, buffer);
        strcpy(par[npar].jug_actual, buffer);
        //--------------------
        cadtipopar(cad,&ppar,buffer); //"SALA: "
        caddatpar(cad,&ppar, buffer);
        strcpy(par[npar].sala_actual, buffer);
        //--------------------
        cadtipopar(cad,&ppar,buffer); //"OBJETO: "
        while (strcmp(buffer,"OBJETO")==0){
            caddatpar(cad,&ppar, buffer);
            strcpy(par[npar].objpar[nobj].id_obj, buffer);
            caddatpar(cad,&ppar, buffer);
            strcpy(par[npar].objpar[nobj].localiz, buffer);
            nobj++;
            cadtipopar(cad,&ppar,buffer); //"OBJETO: " / "CONEXIÓN: "
        }
        par[npar].num_objetospar=nobj;
        //--------------------

         while (strcmp(buffer,"CONEXIÓN")==0){
            caddatpar(cad,&ppar, buffer);
            strcpy(par[npar].conex_desbloqueadas[ncond].id_conexion, buffer);
            caddatpar(cad,&ppar, buffer);
            if (!strcmp(buffer,"Activa")) par[npar].conex_desbloqueadas[ncond].activa=1;
            else if (!strcmp(buffer,"Bloqueado")) par[npar].conex_desbloqueadas[ncond].activa=0;
            ncond++;
            cadtipopar(cad,&ppar,buffer); //"CONEXIÓN: " / "PUZLE: "
        }
        par[npar].num_conexunlocked=ncond;
        
        //--------------------

            while (strcmp(buffer,"PUZLE")==0){
            caddatpar(cad,&ppar, buffer);
            strcpy(par[npar].puzles_estado[npuz].id_puzle, buffer);
            caddatpar(cad,&ppar, buffer);
            if (!strcmp(buffer,"Pendiente")) par[npar].puzles_estado[npuz].resuelto=0;
            else if (!strcmp(buffer,"Resuelto")) par[npar].puzles_estado[npuz].resuelto=1;
            npuz++;
            cadtipopar(cad,&ppar,buffer); //"PUZLE: "/ "JUGADOR: " / "\0"
        }
        par[npar].num_puzles= npuz;
        npar++; 
    
    }while (ppar != -1);
   
    *numpar=npar;
return par;
}

    
    