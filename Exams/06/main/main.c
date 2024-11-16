#include <stdio.h>
#include <stdlib.h>

#include "general.h"
#include "TDASimpleVec.h"

#define EXAMEN

#ifdef EXAMEN
    #define crearTDASimVec         crearTDASimVecALU
    #define insertarAlFinal        insertarAlFinalALU
    #define ordenar                ordenarALU
    #define agrupar                agruparALU
#endif // EXAMEN

int main() {
    size_t i;

    tMovimiento movs[] = {
        {
            .CodProducto = "PR01",
            .cantidad = 10
        },
        {
            .CodProducto = "PR02",
            .cantidad = 5
        },
        {
            .CodProducto = "PR01",
            .cantidad = -1
        },
        {
            .CodProducto = "PR03",
            .cantidad = 98
        },
        {
            .CodProducto = "PR01",
            .cantidad = -5
        },
        {
            .CodProducto = "PR02",
            .cantidad = 2
        }
    };

    TDASimVec* svm = crearTDASimVec(sizeof(*movs));
    if (svm == NULL) {
        printf("Error! An error occurred on array creation.");
        return 1;
    };

    for(i = 0; i < (sizeof(movs) / sizeof(*movs)); i++) {
        if (insertarAlFinal(svm, movs + i)) {
            printf("Error! An error occurred on insert an element.");
            return 1;
        };
    };

    printf("> Slice after insertions...\n\n");
    amap(svm, mostrarMovimiento);

    ordenar(svm, cmpMovimiento);

    printf("\n> Slice before sort...\n\n");
    amap(svm, mostrarMovimiento);

    agrupar(svm, cmpMovimiento, agruparMovimiento);

    printf("\n> Slice after join...\n\n");
    amap(svm, mostrarMovimiento);

    destruir(svm);

    return 0;
}
