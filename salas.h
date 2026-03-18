#ifndef SALAS_H
#define SALAS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {INICIAL,NORMAL,SALIDA} tiposal;

typedef struct {
    char id_sala[3];
    char nomb_sala[31];
    tiposal tipo;
    char descrip[151];
}sala;



#endif