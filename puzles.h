#ifndef PUZLES_H
#define PUZLES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{codigo,palabra} tipopuz;

typedef struct {
char id_puzle[4];
char nomb_puz[16];
char id_sala[3];
tipopuz tipo;
char desc[151];
char sol[51];
}puzle;


#endif