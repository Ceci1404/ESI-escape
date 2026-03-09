#ifndef SALAS_H
#define SALAS_H
typedef enum {INICIAL,NORMAL,SALIDA} tiposal;

typedef struct {
    char id_sala[3];
    char nomb_sala[31];
    tiposal tipo;
    char descrip[151];
}sala;



#endif