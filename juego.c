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
char cad[151];

con= (sala* ) malloc (ncon*sizeof(conexion));

do{
    
    con= (conexion* ) realloc (con,ncon*sizeof(conexion));
    limpiar(cad);
    obtenercad(cad, fcon);
    strcpy(con[ncon-1].id_conexion , cad); //almaceno el ID de CONEXIÓN
    limpiar(cad);
    obtenercad(cad, fcon);
    strcpy(con[ncon-1].id_origen, cad); //almaceno el id_origen de CONEXIÓN
    limpiar(cad);
    obtenercad(cad, fcon); //almaceno el estado de la CONEXIÓN
    if(cad[0]=="A") con[ncon-1].estado=0; //ACTIVO (TRUE) 
    else if (cad[0]=="B") con[ncon-1].estado=1; //BLOQUEADO(FALSE) 
    limpiar(cad);
    obtenercad(cad, fcon);
    strcpy(con[ncon-1].cond, cad); //almaceno la condición de desbloqueo (Id_obj, Id_puz o 0 si no aplica)
    ncon++;
}while (!feof(fcon));

return con;
}

//formato jugadores: ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)
jugador* crearjug(char* cad){
    jugador* jug;
int njug=1;
char cad[151];

jug= (jugador* ) malloc (njug*sizeof(jugador));


do{
    
    jug= (jugador* ) realloc (jug,njug*sizeof(jugador));
    limpiar(cad);
    obtenercad(cad, fjug);
    strcpy(jug[njug-1].id_jugador , cad); //almaceno el ID de JUGADOR
    limpiar(cad);
    obtenercad(cad, fjug);
    strcpy(jug[njug-1].nomb_jugador, cad); //almaceno el nombre del JUGADOR
    limpiar(cad);
    obtenercad(cad, fjug);
    strcpy(jug[njug-1].jugador, cad); //almaceno el nombre de sistema del JUGADOR
    limpiar(cad);
    obtenercad(cad, fjug);
    strcpy(jug[njug-1].password, cad); //almaceno la contraseña del jugador
    for(int i=0; i<jug[njug-1].cant_obj-1;i++){ //almaceno todos los objetos del fichero a las estructuras
        limpiar(cad);
        obtenercad(cad, fjug);
        strcpy(jug[njug-1].inv[i].objinv, cad);
    }
    njug++;
}while (!feof(fjug));



return jug;
}

//formato objetos: ID-NOMB-DESC-LOCAL
objetos* crearobj(char* cad){
    objetos *obj;
int nobj=1;
char cad[151];

obj= (objetos* ) malloc (nobj*sizeof(objetos));


do{
    
    obj= (objetos* ) realloc (obj,nobj*sizeof(objetos));
    limpiar(cad);
    obtenercad(cad, fobj);
    strcpy(obj[nobj-1].id_obj , cad); //almaceno el ID de OBJETO
    limpiar(cad);
    obtenercad(cad, fobj);
    strcpy(obj[nobj-1].nomb_obj, cad); //almaceno el nombre del OBJETO
    limpiar(cad);
    obtenercad(cad, fobj);
    strcpy(obj[nobj-1].desc, cad); //almaceno la descripción del OBJETO
    limpiar(cad);
    obtenercad(cad, fobj);
    strcpy(obj[nobj-1].localiz, cad); //almaceno la localización del OBJETO
    nobj++;
}while (!feof(fobj));


return obj;
}


//formato puzles ID-NOMB-IDSALA-TIPO-DESC-SOL
puzle* crearpuz(char* cad){
    puzle* puz;
int npuz=1;
char cad[151];

puz= (puzle* ) malloc (npuz*sizeof(puzle));
do{
    
    puz= (puzle* ) realloc (puz,npuz*sizeof(puzle));
    limpiar(cad);
    obtenercad(cad, fpuz);
    strcpy(puz[npuz-1].id_puzle , cad); //almaceno el ID de PUZLE
    limpiar(cad);
    obtenercad(cad, fpuz);
    strcpy(puz[npuz-1].nomb_puz, cad); //almaceno el nombre del PUZLE
    limpiar(cad);
    obtenercad(cad, fpuz);
    strcpy(puz[npuz-1].id_sala, cad); //almaceno la sala del PUZLE
    limpiar(cad);
    obtenercad(cad, fpuz);
    if(cad[0]=='C') puz[npuz-1].tipo=0; //CODIGO
    if(cad[0]=='P') puz[npuz-1].tipo=1; //PALABRA
    limpiar(cad);
    obtenercad(cad, fpuz);
    strcpy(puz[npuz-1].desc, cad); //almaceno la descripción del PUZLE
    limpiar(cad);
    obtenercad(cad, fpuz);
    strcpy(puz[npuz-1].sol, cad); //almaceno la solución del PUZLE
    npuz++;
}while (!feof(fpuz));

return puz;
}

//formato partida:ID_JUG- ID_SAL(ACT)- OBJ 
//ESTE ES DIFERENTE, TENGO QUE PREGUNTAR       

    
    