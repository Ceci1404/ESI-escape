#ifndef OBJETOS_H
#define OBJETOS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id_obj[5];
    char nomb_obj[16];
    char desc[51];
    char localiz[5]; //OBXX o INXX
   
}objetos;



#endif