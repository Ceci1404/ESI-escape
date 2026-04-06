
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


void carga_ficheros() {

mi_partida.num_puzles = 0;
    mi_partida.num_conexunlocked = 0;
    mi_partida.jug_actual.inv.cant_obj = 0;

   
    FILE* f_partida = fopen("partida_guardada.txt", "r");
    
    if (f_partida == NULL) {
        printf("Error: No se encontró el fichero para cargar.\n");
        return mi_partida; // Devolvemos la partida vacía
    }

    char etiqueta[50]; 

    
    while (fscanf(f_partida, "%49s", etiqueta) == 1) {
        
        
        if (strcmp(etiqueta, "JUGADOR") == 0) {
           
            fscanf(f_partida, "%s %s %s %s", 
                   mi_partida.jug_actual.id_jugador,
                   mi_partida.jug_actual.nomb_jugador,
                   mi_partida.jug_actual.jugador,
                   mi_partida.jug_actual.password);
        }
        
       
        else if (strcmp(etiqueta, "SALA") == 0) {
            
            fscanf(f_partida, "%2s", mi_partida.sala_actual);
        }
        
       
        else if (strcmp(etiqueta, "TOTAL_PUZLES") == 0) {
            // Primero leemos cuántos hay
            fscanf(f_partida, "%d", &mi_partida.num_puzles);
            
            
            for (int i = 0; i < mi_partida.num_puzles; i++) {
                int estado_resuelto;
               
                fscanf(f_partida, "%3s %d", 
                       mi_partida.puzles_estado[i].id_puzle, 
                       &estado_resuelto);
                
                
                mi_partida.puzles_estado[i].resuelto = (estado_resuelto == 1);
            }
        }
    
        else if (strcmp(etiqueta, "TOTAL_CONEXIONES") == 0) {
            fscanf(f_partida, "%d", &mi_partida.num_conexunlocked);
            
            for (int i = 0; i < mi_partida.num_conexunlocked; i++) {
                int estado_activa;
                fscanf(f_partida, "%3s %d", 
                       mi_partida.conex_desbloqueadas[i].id_conexion, 
                       &estado_activa);
                       
                mi_partida.conex_desbloqueadas[i].activa = (estado_activa == 1);
            }
        }
    }

    
    fclose(f_partida);
    
    printf("Infortmacion guardada\n");
    
    
    return mi_partida;
}

  
}

void nuevapartida(jugador *);
