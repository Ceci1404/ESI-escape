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
    
    //printf("  [crearsala] Iniciando...\n");
    
    do{
        //comprobación inicial de que el fichero tiene texto
        obtenercad(cad, &pcad, buffer);
        if(pcad == -1 || strlen(buffer) == 0) break;
        
        //printf("  [crearsala] Leyendo sala %d: ID=%s\n", nsal+1, buffer);
        
        sal = (sala*)realloc(sal, (nsal + 1) * sizeof(sala));
        strcpy(sal[nsal].id_sala, buffer);
        
        obtenercad(cad, &pcad, buffer);
        strcpy(sal[nsal].nomb_sala, buffer);
        
        obtenercad(cad, &pcad, buffer);
        if(strcmp(buffer, "INICIAL") == 0) 
            sal[nsal].tipo = INICIAL;
        else if(strcmp(buffer, "NORMAL") == 0) 
            sal[nsal].tipo = NORMAL;
        else if(strcmp(buffer, "SALIDA") == 0) 
            sal[nsal].tipo = SALIDA;
        
        obtenercad(cad, &pcad, buffer);
        strcpy(sal[nsal].descrip, buffer);
        
        nsal++;
    }while (pcad!=-1);
    
    *numsal = nsal;
    printf("  [crearsala] Total salas creadas: %d\n", nsal); //para comprobar funcionamiento
    return sal;
}


//Cabecera: conexion* crearconex(char* cad, int *numcon)
//Precondición: cad tiene formato "ID-IDOR-IDDES-ESTADO-COND", numcon no es NULL
//Postcondición: Devuelve array dinámico de conexiones, *numcon contiene el número de conexiones creadas
    
//formato conexiones: ID-IDOR-IDDES-ESTADO-COND
conexion* crearconex(char* cad, int *numcon){
    conexion *con = NULL;
    int ncon = 0;
    int pcon = 0;
    char buffer[151];
    
    printf("  [crearconex] Iniciando...\n");
    
    do{
        obtenercad(cad, &pcon, buffer);
        if(pcon == -1 || strlen(buffer) == 0) break;
        
        //printf("  [crearconex] Leyendo conexión %d: ID=%s\n", ncon+1, buffer);
        
        con = (conexion*) realloc(con, (ncon + 1) * sizeof(conexion));
        strcpy(con[ncon].id_conexion, buffer);
        
        obtenercad(cad, &pcon, buffer);
        strcpy(con[ncon].id_origen, buffer);
        
        obtenercad(cad, &pcon, buffer);
        strcpy(con[ncon].id_destino, buffer);
        
        obtenercad(cad, &pcon, buffer);
        if(strcmp(buffer, "Activa") == 0) 
            con[ncon].estado = 1;
        else 
            con[ncon].estado = 0;
        
        obtenercad(cad, &pcon, buffer);
        strcpy(con[ncon].cond, buffer);
        
        ncon++;
    }while (pcon!=-1);
    
    *numcon = ncon;
    printf("  [crearconex] Total conexiones creadas: %d\n", ncon);
    return con;
}

//Cabecera: jugador* crearjug(char* cad, int *numjug)
//Precondición: cad tiene formato "ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)", numjug no es NULL
//Postcondición: Devuelve array dinámico de jugadores, *numjug contiene el número de jugadores creados

//formato jugadores: ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)
jugador* crearjug(char* cad, int *numjug){
    jugador* jug = NULL;
    int njug = 0;
    int pjug = 0;
    char buffer[151];
    
    //printf("  [crearjug] Iniciando...\n");
    
    do{
        obtenercad(cad, &pjug, buffer);
        if(pjug == -1 || strlen(buffer) == 0) break;
        
        jug = (jugador*) realloc(jug, (njug + 1) * sizeof(jugador));
        
        // Inicializar
        jug[njug].cant_obj = 0;
        jug[njug].tamainv = 10;
        jug[njug].inv = (inventario*) malloc(10 * sizeof(inventario));
        
        // ID
        strcpy(jug[njug].id_jugador, buffer);
        
        // Nombre completo
        obtenercad(cad, &pjug, buffer);
        strcpy(jug[njug].nomb_jugador, buffer);
        
        // Nombre de usuario
        obtenercad(cad, &pjug, buffer);
        strcpy(jug[njug].jugador, buffer);
        
        // Contraseña
        obtenercad(cad, &pjug, buffer);
        strcpy(jug[njug].password, buffer);
        
        // Leer objetos del inventario
        while(cad[pjug] != '\n') {
            if (pjug==-1) break;
            obtenercad(cad, &pjug, buffer);
                strcpy(jug[njug].inv[jug[njug].cant_obj].objinv, buffer);
                jug[njug].cant_obj++;
        }
        /*
        printf("  [crearjug] Jugador %d: id=%s, nombre=%s, usuario=%s, pass=%s, objetos=%d\n", 
               njug, jug[njug].id_jugador, jug[njug].nomb_jugador, 
               jug[njug].jugador, jug[njug].password, jug[njug].cant_obj);
               */
        
        njug++;
    }while (pjug!=-1);
    
    *numjug = njug;
    printf("  [crearjug] Total jugadores: %d\n", njug);
    return jug;
}
//Cabecera: objetos* crearobj(char* cad, int* numobj)
//Precondición: cad tiene formato "ID-NOMB-DESC-LOCAL", numobj no es NULL
//Postcondición: Devuelve array dinámico de objetos, *numobj contiene el número de objetos creados

//formato objetos: ID-NOMB-DESC-LOCAL
objetos* crearobj(char* cad, int* numobj){
    objetos *obj = NULL;
    int nobj = 0;
    int pobj = 0;
    char buffer[151];
    
    //printf("  [crearobj] Iniciando...\n");
    
    do{
        obtenercad(cad, &pobj, buffer);
        if(pobj == -1 || strlen(buffer) == 0) break;
        
        //printf("  [crearobj] Leyendo objeto %d: ID=%s\n", nobj+1, buffer);
        
        obj = (objetos*) realloc(obj, (nobj + 1) * sizeof(objetos));
        strcpy(obj[nobj].id_obj, buffer);
        
        obtenercad(cad, &pobj, buffer);
        strcpy(obj[nobj].nomb_obj, buffer);
        
        obtenercad(cad, &pobj, buffer);
        strcpy(obj[nobj].desc, buffer);
        
        obtenercad(cad, &pobj, buffer);
        strcpy(obj[nobj].localiz, buffer);
        
        nobj++;
    }while (pobj!=-1);
    
    *numobj = nobj;
    printf("  [crearobj] Total objetos creados: %d\n", nobj);
    return obj;
}
//Cabecera: puzle* crearpuz(char* cad, int* numpuz)
//Precondición: cad tiene formato "ID-NOMB-IDSALA-TIPO-DESC-SOL", numpuz no es NULL
//Postcondición: Devuelve array dinámico de puzles, *numpuz contiene el número de puzles creados


//formato puzles ID-NOMB-IDSALA-TIPO-DESC-SOL
puzle* crearpuz(char* cad, int* numpuz){
    puzle* puz = NULL;
    int npuz = 0;
    int ppuz = 0;
    char buffer[151];
    
    //printf("  [crearpuz] Iniciando...\n");
    
    do{
        obtenercad(cad, &ppuz, buffer);
        if(ppuz == -1 || strlen(buffer) == 0) break;
        
        //printf("  [crearpuz] Leyendo puzle %d: ID=%s\n", npuz+1, buffer);
        
        puz = (puzle*) realloc(puz, (npuz + 1) * sizeof(puzle));
        strcpy(puz[npuz].id_puzle, buffer);
        
        obtenercad(cad, &ppuz, buffer);
        strcpy(puz[npuz].nomb_puz, buffer);
        
        obtenercad(cad, &ppuz, buffer);
        strcpy(puz[npuz].id_sala, buffer);
        
        obtenercad(cad, &ppuz, buffer);
        if(strcmp(buffer, "Código") == 0) 
            puz[npuz].tipo = codigo;
        else 
            puz[npuz].tipo = palabra;
        
        obtenercad(cad, &ppuz, buffer);
        strcpy(puz[npuz].desc, buffer);
        
        obtenercad(cad, &ppuz, buffer);
        strcpy(puz[npuz].sol, buffer);
        
        npuz++;
    }while(ppuz!=-1);
    
    *numpuz = npuz;
    printf("  [crearpuz] Total puzles creados: %d\n", npuz);
    return puz;
}
//Cabecera: char* cadtipopar(char* cad, int *pcad, char* buffer)
//Precondición: cad no es NULL, pcad apunta a un índice válido dentro de cad
//Postcondición: buffer contiene token hasta ':' (o '\n'), pcad avanza o se pone a -1 si es fin


//formato partida:ID_JUG- ID_SAL(ACT)- OBJ 

 char* cadtipopar(char* cad, int *pcad, char* buffer){
    int j = 0;
    buffer[0] = '\0';
    
    // FINAL
    if(cad == NULL || cad[*pcad] == '\0') {
        *pcad = -1;
        return NULL;
    }
    
    // HASTA DOS PUNTOS
    while(cad[*pcad] != '\0' && cad[*pcad] != ':' && cad[*pcad] != '\n') {
        buffer[j++] = cad[*pcad];
        (*pcad)++;
    }
    buffer[j] = '\0';
    
    // AVANZAR DOS PUNTOS
    if(cad[*pcad] == ':') {
        (*pcad)++;
        if(cad[*pcad] == ' ') (*pcad)++;
    } else if(cad[*pcad] == '\n') {
        (*pcad)++;
    }
    
    return buffer;
}

//Cabecera: char* caddatpar(char* cad, int *pcad, char* buffer)
//Precondición: cad no es NULL, pcad apunta a un índice válido dentro de cad
//Postcondición: buffer contiene token hasta '-' o '\n', pcad avanza o se pone a -1 si es fin

char* caddatpar(char* cad, int *pcad, char* buffer){
    int j = 0;
    buffer[0] = '\0';
    
    // FINAL
    if(cad == NULL || cad[*pcad] == '\0') {
        *pcad = -1;
        return NULL;
    }
    
    // HASTA SEPARADOR
    while(cad[*pcad] != '\0' && cad[*pcad] != '-' && cad[*pcad] != '\n') {
        buffer[j++] = cad[*pcad];
        (*pcad)++;
    }
    buffer[j] = '\0';
    
    // AVANZAR SEPARADOR
    if(cad[*pcad] == '-' || cad[*pcad] == '\n') {
        (*pcad)++;
    }
    
    // Saltar espacios
    while(cad[*pcad] == ' ' || cad[*pcad] == '\t') {
        (*pcad)++;
    }
    
    return buffer;
}
//Cabecera: partidas* crearpar(char* cad, int* numpar)
//Precondición: cad tiene formato de partida (JUGADOR:ID SALA: \n ID OBJETO:... \nCONEXIÓN:... \nPUZLE:...\n), numpar no es NULL
//Postcondición: Devuelve array dinámico de partidas, *numpar contiene el número de partidas creadas



//ALMACENO TODAS LAS PARTIDAS
partidas* crearpar(char* cad, int* numpar){
    partidas* par = NULL;
    int npar = 0;
    int ppar = 0;
    char buffer[151];
    
    //printf("  [crearpar] Iniciando...\n");

    do{
        int nobj = 0, ncond = 0, npuz = 0;
        
        // Leer "JUGADOR:"
        if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        if(ppar == -1) break;
        
        par = (partidas*) realloc(par, (npar + 1) * sizeof(partidas));
        
        // INICIALIZAR
        par[npar].conex_desbloqueadas = NULL;
        par[npar].puzles_estado = NULL;
        par[npar].num_conexunlocked = 0;
        par[npar].num_puzles = 0;
        par[npar].num_objetospar = 0;
        
        // Leer ID_JUGADOR
        if(caddatpar(cad, &ppar, buffer) == NULL) break;
        strcpy(par[npar].jug_actual, buffer);
        
        // Leer "SALA:"
        if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        
        // Leer ID_SALA
        if(caddatpar(cad, &ppar, buffer) == NULL) break;
        strcpy(par[npar].sala_actual, buffer);
        
        // Leer "OBJETO:"
        if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        
        // Leer objetos
        while(strcmp(buffer, "OBJETO") == 0 && ppar != -1) {
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            strcpy(par[npar].objpar[nobj].id_obj, buffer);
            
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            strcpy(par[npar].objpar[nobj].localiz, buffer);
            
            nobj++;
            if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        }
        par[npar].num_objetospar = nobj;
        
        // Leer conexiones
        while(strcmp(buffer, "CONEXIÓN") == 0 && ppar != -1) {
            par[npar].conex_desbloqueadas = (conexunlocked*) realloc(par[npar].conex_desbloqueadas, (ncond + 1) * sizeof(conexunlocked));
            
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            strcpy(par[npar].conex_desbloqueadas[ncond].id_conexion, buffer);
            
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            if(strcmp(buffer, "Activo") == 0) 
                par[npar].conex_desbloqueadas[ncond].activa = true;
            else 
                par[npar].conex_desbloqueadas[ncond].activa = false;
            
            ncond++;
            if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        }
        par[npar].num_conexunlocked = ncond;
        
        // Leer puzles
        while(strcmp(buffer, "PUZLE") == 0 && ppar != -1) {
            par[npar].puzles_estado = (puzleresuelto*) realloc(par[npar].puzles_estado, (npuz + 1) * sizeof(puzleresuelto));
            
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            strcpy(par[npar].puzles_estado[npuz].id_puzle, buffer);
            
            if(caddatpar(cad, &ppar, buffer) == NULL) break;
            if(strcmp(buffer, "Resuelto") == 0) 
                par[npar].puzles_estado[npuz].resuelto = true;
            else 
                par[npar].puzles_estado[npuz].resuelto = false;
            
            npuz++;
            if(cadtipopar(cad, &ppar, buffer) == NULL) break;
        }
        par[npar].num_puzles = npuz;
        
        npar++;
        //printf("  [crearpar] Partida %d cargada: Jugador=%s, Sala=%s\n", npar, par[npar-1].jug_actual, par[npar-1].sala_actual);
    }while (ppar!=-1);
    
    *numpar = npar;
    printf("  [crearpar] Total partidas creadas: %d\n", npar);
    return par;
}