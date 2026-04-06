
#include "ficheros.h"
#include "conexiones.h"
#include "jugadores.h"
#include "objetos.h"
#include "partida.h"
#include "puzles.h"
#include "salas.h"


//SUSANA v 
void limpiar(char* cad){
for (int i=0;i<151;i++){
cad[i]='\0';}
}

void obtenercad(char* cad, FILE* f){
    char c;
for (int i=0 ;c !='-'|| c!="\n" ;i++){
c=fgetc(f);
if (c!='-' && c!="\n")
    cad[i]=c;
}
}

 //formato salas:ID-NOMBRE-TIPO-DESCRIP 
void leersalas(sala* sal){
int nsal=1;
char cad[151];


sal= (sala* ) malloc (nsal*sizeof(sala));

FILE *fsal=fopen("salas.txt", "r");
if (fsal==NULL) printf("No se ha podido abrir salas.txt");
else{
do{
    
    sal= (sala* ) realloc (sal,nsal*sizeof(sala));
    limpiar(cad);
    obtenercad(cad, fsal);
    strcpy(sal[nsal-1].id_sala , cad); //almaceno el ID
    limpiar(cad);
    obtenercad(cad, fsal);
    strcpy(sal[nsal-1].nomb_sala, cad); //almaceno el nombre
    limpiar(cad);
    obtenercad(cad, fsal); //almaceno el tipo
    if(cad[0]=="I") sal[nsal-1].tipo=0; //INICIAL
    else if (cad[0]=="N") sal[nsal-1].tipo=1; //NORMAL
    else if (cad[0]=="S") sal[nsal-1].tipo=2; //SALIDA
    limpiar(cad);
    obtenercad(cad, fsal);
    strcpy(sal[nsal-1].descrip, cad); //almaceno la descripción
    nsal++;
}while (!feof(fsal));

}
fclose(fsal);
}

//formato conexiones: ID-IDOR-IDDES-ESTADO-COND
void leerconex(conexion* con){
int ncon=1;
char cad[151];

con= (sala* ) malloc (ncon*sizeof(conexion));

FILE *fcon=fopen("conexiones.txt", "r");
if (fcon==NULL) printf("No se ha podido abrir salas.txt");
else{
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

}
fclose(fcon);
}

//formato jugadores: ID-NOMB-JUGADOR-PASSWD-IDOBJ(s)
void leerjug(jugador* jug){
int njug=1;
char cad[151];

jug= (jugador* ) malloc (njug*sizeof(jugador));

FILE *fjug=fopen("jugadores.txt", "r");
if (fjug==NULL) printf("No se ha podido abrir jugadores.txt");
else{
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

}
fclose(fjug);
}

//formato objetos: ID-NOMB-DESC-LOCAL
void leerobj(objetos* obj){
int nobj=1;
char cad[151];

obj= (objetos* ) malloc (nobj*sizeof(objetos));

FILE *fobj=fopen("objetos.txt", "r");
if (fobj==NULL) printf("No se ha podido abrir objetos.txt");
else{
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

}
fclose(fobj);
}


//formato puzles ID-NOMB-IDSALA-TIPO-DESC-SOL
void leerpuz(puzle* puz){
int npuz=1;
char cad[151];

puz= (puzle* ) malloc (npuz*sizeof(puzle));

FILE *fpuz=fopen("puzles.txt", "r");
if (fpuz==NULL) printf("No se ha podido abrir puzles.txt");
else{
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

}
fclose(fpuz);
}

//formato partida:ID_JUG- ID_SAL(ACT)- OBJ 
//ESTE ES DIFERENTE, TENGO QUE PREGUNTAR       

void leerficheros (sala* sal, conexion* con, jugador *jug, objetos* obj, puzle* puz){
    leersalas(sal);
    leerconex(con);
    leerjug(jug);
    leerobj(obj);
    leerpuz(puz);
}
    
    
    
//SUSANA ^ 

void leerficheros ();

//se deben declarar en el main como variables que se actualicen cada vez que se modifique el número de jugadores o el número de partidas

void guardar_ficheros(jugador *lista_jugadores, int total_jugadores, partidas *lista_partidas, int total_partidas) {
    
    printf("--- Guardando progreso en los ficheros ---\n");

    
    FILE *f_jug = fopen("jugadores.txt", "w");
    
    if (f_jug != NULL) {
        // Primero guardamos el total de jugadores
        fprintf(f_jug, "%d\n", total_jugadores); 

        for (int i = 0; i < total_jugadores; i++) {
            // Datos principales del jugador
            fprintf(f_jug, "%s %s %s %s %d %d\n",
                    lista_jugadores[i].id_jugador,
                    lista_jugadores[i].nomb_jugador, 
                    lista_jugadores[i].jugador,
                    lista_jugadores[i].password,
                    lista_jugadores[i].cant_obj,
                    lista_jugadores[i].tamainv);

            // Inventario dinámico del jugador
            for (int j = 0; j < lista_jugadores[i].cant_obj; j++) {
                fprintf(f_jug, "%s\n", lista_jugadores[i].inv[j].objinv);
            }
        }
        fclose(f_jug);
        printf("OK: 'jugadores.txt' guardado con %d jugadores.\n", total_jugadores);
    } else {
        printf("Error: No se pudo abrir jugadores.txt para guardar.\n");
    }

    
    FILE *f_part = fopen("partidas.txt", "w");
    
    if (f_part != NULL) {
        // Primero guardamos el total de partidas
        fprintf(f_part, "%d\n", total_partidas); 

        for (int i = 0; i < total_partidas; i++) {
            // Datos principales de la partida
            fprintf(f_part, "%d %d %d %d\n",
                    lista_partidas[i].jug_actual,
                    lista_partidas[i].sala_actual,
                    lista_partidas[i].num_conexunlocked,
                    lista_partidas[i].num_puzles);

            // Conexiones (con if-else normal)
            for (int j = 0; j < lista_partidas[i].num_conexunlocked; j++) {
                int estado_conexion;
                if (lista_partidas[i].conex_desbloqueadas[j].activa == true) {
                    estado_conexion = 1;
                } else {
                    estado_conexion = 0;
                }
                fprintf(f_part, "%s %d\n", lista_partidas[i].conex_desbloqueadas[j].id_conexion, estado_conexion);
            }

            // Puzles (con if-else normal)
            for (int j = 0; j < lista_partidas[i].num_puzles; j++) {
                int estado_puzle;
                if (lista_partidas[i].puzles_estado[j].resuelto == true) {
                    estado_puzle = 1;
                } else {
                    estado_puzle = 0;
                }
                fprintf(f_part, "%s %d\n", lista_partidas[i].puzles_estado[j].id_puzle, estado_puzle);
            }
        }
        fclose(f_part);
        printf("OK: 'partidas.txt' guardado con %d partidas.\n", total_partidas);
    } else {
        printf("Error: No se pudo abrir partidas.txt para guardar.\n");
    }

    printf("--- Proceso de guardado finalizado ---\n");
}

  
}

void nuevapartida(jugador *){
