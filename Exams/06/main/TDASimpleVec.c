
#include "general.h"
#include "TDASimpleVec.h"

TDASimVec* crearTDASimVecALU(unsigned tamEle) {
    const size_t maxEle = 10;

    TDASimVec* slice = malloc(sizeof(TDASimVec));

    slice->vec = malloc(maxEle * tamEle);
    slice->ce = 0;
    slice->maxEle = maxEle;
    slice->tamEle = tamEle;

    return slice;
}

int insertarAlFinalALU(TDASimVec* sv, void* ele) {
    void* aux;
    size_t newMaxEle;

    if (sv->ce == sv->maxEle) {
        newMaxEle = sv->maxEle + (((sv->maxEle * 0.25) > 0)? sv->maxEle * 0.25 : 1);

        aux = realloc(sv->vec, newMaxEle);
        if (aux == NULL) return 1;

        sv->vec = aux;
        sv->maxEle = newMaxEle;
    };

    memcpy(
        (char*)sv->vec + sv->ce * sv->tamEle,
        ele,
        sv->tamEle
    );

    sv->ce++;

    return 0;
}

TDASimVec* ordenarALU(
    TDASimVec* sv,
    int cmp(const void* a, const void* b)
) {
    qsort(
        sv->vec,
        sv->ce,
        sv->tamEle,
        cmp
    );

    return sv;
}

TDASimVec* agruparALU(
    TDASimVec* sv,
    int cmp(const void* a, const void* b),
    int fagrup(void* dest, const void* origen)
) {
    size_t i;

    char* elem;

    TDASimVec* auxSV;
    char* elemInAux;

    auxSV = crearTDASimVecALU(sv->tamEle);
    if (auxSV == NULL) return NULL;

    if (sv->ce > 0) {
        if (insertarAlFinalALU(auxSV, sv->vec)) return NULL;;
        elemInAux = (char*)auxSV->vec + (auxSV->ce - 1) * auxSV->tamEle;
    };

    for (i = 1; i < sv->ce; i++) {
        elem = (char*)sv->vec + i * sv->tamEle;

        if (cmp(elem, elemInAux) == 0) {
            fagrup(elemInAux, elem);
        } else {
            if (insertarAlFinalALU(auxSV, elem)) return NULL;
            elemInAux = (char*)auxSV->vec + (auxSV->ce - 1) * auxSV->tamEle;
        };
    };

    free(sv->vec);

    sv->ce = auxSV->ce;
    sv->maxEle = auxSV->maxEle;
    sv->vec = auxSV->vec;

    free(auxSV);

    return sv;
}

void destruirALU(TDASimVec* sv) {
    free(sv->vec);
    free(sv);
}
