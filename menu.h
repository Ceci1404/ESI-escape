#ifndef MENU_H
#define MENU_H


// --- PROTOTIPOS DE LAS FUNCIONES DEL MENÚ ---

// Inicia el programa y muestra las opciones de Nueva Partida, Cargar o Salir
void menu_principal();

// Gestiona la creación de un nuevo jugador y el inicio desde cero
void crear_nueva_partida(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);

// Gestiona la carga de datos del disco duro para restaurar el progreso
void cargar_partida_existente(partida *p, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);

// Bucle principal donde el jugador decide qué acciones tomar dentro de la sala
void menu_juego(partida *p_actual, sala *v_salas, conexion *v_conex, jugador *v_jug, objetos *v_obj, puzle *v_puz, int nsal, int nobj, int ncon, int npuz, partidas *v_partidas, int total_jugadores, int total_partidas);

#endif // MENU_H
