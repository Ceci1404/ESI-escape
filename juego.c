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

char* obtenercad(char* cad, int* pcad){
int j=0; //puntero para buffer
char buffer[151];
do{
    if (cad[*pcad]=='\0'){ *pcad=-1; break;}
    buffer[j]=cad[*pcad];
    j++;
    *pcad++;
}while (cad[*pcad]!='-' || cad[*pcad]!='\n');
return buffer;
}




 //formato salas:ID-NOMBRE-TIPO-DESCRIP 
sala* crearsala(char* cad){
    sala* sal;
int nsal=1;
int *pcad=0;
do{
    sal= (sala* ) realloc (sal,nsal*sizeof(sala));
    strcpy(sal[nsal-1].id_sala , obtenercad(cad, *pcad)); //almaceno el ID
    strcpy(sal[nsal-1].nomb_sala, obtenercad(cad, *pcad)); //almaceno el nombre
    if(strcmp(obtenercad(cad, *pcad), "INICIAL")) sal[nsal-1].tipo=0; //INICIAL
    else if (strcmp(obtenercad(cad, *pcad), "NORMAL")) sal[nsal-1].tipo=1; //NORMAL
    else if (strcmp(obtenercad(cad, *pcad), "SALIDA")) sal[nsal-1].tipo=2; //SALIDA
    strcpy(sal[nsal-1].descrip, obtenercad(cad, *pcad)); //almaceno la descripción
    nsal++;
}while (*pcad!=-1);

return sal;
}



    
//formato conexiones: ID-IDOR-IDDES-ESTADO-COND
conexion* crearconex(char* cad){
    conexion *con;
int ncon=1;
int *pcon=0;
con= (sala* ) malloc (ncon*sizeof(conexion));
do{
    con= (conexion* ) realloc (con,ncon*sizeof(conexion));
    strcpy(con[ncon-1].id_conexion , obtenercad(cad, *pcon)); //almaceno el ID de CONEXIÓN
    strcpy(con[ncon-1].id_origen, obtenercad(cad, *pcon)); //almaceno el id_origen de CONEXIÓN
    if(strcmp(obtenercad(cad, *pcon), "ACTIVO")) con[ncon-1].estado=0; //ACTIVO (TRUE) 
    else if (strcmp(obtenercad(cad, *pcon), "BLOQUEADO")) con[ncon-1].estado=1; //BLOQUEADO(FALSE) 
    strcpy(con[ncon-1].cond, obtenercad(cad, *pcon)); //almaceno la condición de desbloqueo (Id_obj, Id_puz o 0 si no aplica)
    ncon++;
}while (*pcon!=-1);
return con;
}



//formato jugadores: ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)
jugador* crearjug(char* cad){
    jugador* jug;
int njug=1;
int *pjug=0;
jug= (jugador* ) malloc (njug*sizeof(jugador));
do{
    jug= (jugador* ) realloc (jug,njug*sizeof(jugador));
    strcpy(jug[njug-1].id_jugador , obtenercad(cad, *pjug)); //almaceno el ID de JUGADOR
    strcpy(jug[njug-1].nomb_jugador, obtenercad(cad, *pjug)); //almaceno el nombre del JUGADOR
    strcpy(jug[njug-1].jugador, obtenercad(cad, *pjug)); //almaceno el nombre de sistema del JUGADOR
    strcpy(jug[njug-1].password, obtenercad(cad, *pjug)); //almaceno la contraseña del jugador
    for(int i=0; i<jug[njug-1].cant_obj-1;i++){ //almaceno todos los objetos del fichero a las estructuras
        strcpy(jug[njug-1].inv[i].objinv, obtenercad(cad, *pjug));
    }
    njug++;
}while (*pjug!=-1);
return jug;
}

//formato objetos: ID-NOMB-DESC-LOCAL
objetos* crearobj(char* cad){
    objetos *obj;
int nobj=1;
int *pobj=0;
obj= (objetos* ) malloc (nobj*sizeof(objetos));
do{   
    obj= (objetos* ) realloc (obj,nobj*sizeof(objetos));
    strcpy(obj[nobj-1].id_obj , obtenercad(cad, *pobj)); //almaceno el ID de OBJETO
    strcpy(obj[nobj-1].nomb_obj, obtenercad(cad, *pobj)); //almaceno el nombre del OBJETO
    strcpy(obj[nobj-1].desc, obtenercad(cad, *pobj)); //almaceno la descripción del OBJETO
    strcpy(obj[nobj-1].localiz, obtenercad(cad, *pobj)); //almaceno la localización del OBJETO
    nobj++;
}while (*pobj!=-1);
return obj;
}


//formato puzles ID-NOMB-IDSALA-TIPO-DESC-SOL
puzle* crearpuz(char* cad){
    puzle* puz;
int npuz=1;
int *ppuz=0;
puz= (puzle* ) malloc (npuz*sizeof(puzle));
do{
    puz= (puzle* ) realloc (puz,npuz*sizeof(puzle));
    strcpy(puz[npuz-1].id_puzle , obtenercad(cad, *ppuz)); //almaceno el ID de PUZLE
    strcpy(puz[npuz-1].nomb_puz, obtenercad(cad, *ppuz)); //almaceno el nombre del PUZLE
    strcpy(puz[npuz-1].id_sala, obtenercad(cad, *ppuz)); //almaceno la sala del PUZLE
    if(strcmp(obtenercad(cad, *ppuz), "CODIGO")) puz[npuz-1].tipo=0; //CODIGO
    else if (strcmp(obtenercad(cad, *ppuz),"PALABRA")) puz[npuz-1].tipo=1; //PALABRA
    strcpy(puz[npuz-1].desc, obtenercad(cad, *ppuz)); //almaceno la descripción del PUZLE
    strcpy(puz[npuz-1].sol, obtenercad(cad, *ppuz)); //almaceno la solución del PUZLE
    npuz++;
}while (*ppuz!=-1);
return puz;
}

//formato partida:ID_JUG- ID_SAL(ACT)- OBJ 
//ESTE ES DIFERENTE, TENGO QUE PREGUNTAR       

    
    