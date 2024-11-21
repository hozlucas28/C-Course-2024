
#include <stdio.h>
#include <stdlib.h>

#include "./gbib.h"

#define EXAMEN

#define TABLAORIGINAL       "tabla.txt"
#define TABLAPERMUTADA      "tablaPermutada.txt"
#define TABLARESTAURADA     "tablaRecuperada.txt"
#define NUMEROCAMPO         6

#ifdef EXAMEN
   #define restaurarColumna restaurarColumnaALU
#endif // EXAMEN


int main() {
    crearLotePrueba(TABLAORIGINAL);

    if (!permutarColumna(TABLAORIGINAL, TABLAPERMUTADA, NUMEROCAMPO)) {
        puts("La tabla no pudo ser permutada, verifique archivos y cantidad de campos.");
        return 1;
    };

    if (!restaurarColumna(TABLAPERMUTADA, TABLARESTAURADA, NUMEROCAMPO)) {
        puts("La tabla no pudo ser restaurada, verifique archivos y cantidad de campos.");
        return 1;
    };

    return 0;
}
