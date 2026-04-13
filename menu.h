#ifndef MENU_H
#define MENU_H


// --- PROTOTIPOS DE LAS FUNCIONES DEL MENÚ ---

// Inicia el programa y muestra las opciones de Nueva Partida, Cargar o Salir
void menu_principal(partidas *, sala *, conexion *, jugador *, objetos *, puzle *, int *, int *, int *, int *, int *, int *, int *);

// Bucle principal donde el jugador decide qué acciones tomar dentro de la sala
void menu_juego(partidas *, sala *, conexion *, jugador *, objetos *, puzle *, int *, int *, int*, int *, int *, int *, int *);


// Gestiona la creación de un nuevo jugador y el inicio desde cero
void crear_nueva_partida(partidas *, jugador *, int *);*/
// Gestiona la carga de datos del disco duro para restaurar el progreso
int cargar_partida_existente(partidas *, jugador *, int *, int *);

#endif // MENU_H
