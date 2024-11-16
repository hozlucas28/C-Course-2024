#ifndef TDASIMPLEVEC_H_INCLUDED
#define TDASIMPLEVEC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_ELE 3


typedef struct {
    void* vec;
    unsigned ce;
    unsigned tamEle;
    unsigned maxEle;
} TDASimVec;

TDASimVec* crearTDASimVec(unsigned tamEle);

void destruir(TDASimVec* sv);

int insertarAlFinal(TDASimVec* sv, void* ele);

TDASimVec* ordenar(
    TDASimVec* sv,
    int cmp(const void* a, const void* b)
);

TDASimVec* agrupar(
    TDASimVec* sv,
    int cmp(const void* a, const void* b),
    int fagrup(void* dest, const void* origen)
);

TDASimVec* amap(
    TDASimVec* sv,
    int accion(void*)
);

int cmpSimVec(TDASimVec* sva, TDASimVec* svb);

TDASimVec* crearTDASimVecALU(unsigned tamEle);

int insertarAlFinalALU(TDASimVec* sv, void* ele);

TDASimVec* ordenarALU(
    TDASimVec* sv,
    int cmp(const void* a, const void* b)
);

TDASimVec* agruparALU(
    TDASimVec* sv,
    int cmp(const void* a, const void* b),
    int fagrup(void* dest, const void* origen)
);

void destruirALU(TDASimVec* sv);

#endif // TDASIMPLEVEC_H_INCLUDED
