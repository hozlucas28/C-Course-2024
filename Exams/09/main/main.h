#ifndef PARTNERS_H_INCLUDED
#define PARTNERS_H_INCLUDED

#include <stdlib.h>

/* -------------------------------- PARTNERS -------------------------------- */

#define PARTNERS_LINE_LENGTH 250


/* -------------------------------------------------------------------------- */
/*                                   STRUCTS                                  */
/* -------------------------------------------------------------------------- */

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    long id;
    char fullName[30];
    Date registrationDate;
} Partner;


/* -------------------------------------------------------------------------- */
/*                                  FUNCTIONS                                 */
/* -------------------------------------------------------------------------- */

unsigned char mergePartnersFiles(
    const char* fileAPath,
    const char* fileBPath,
    const char* mergedFilePath,
    int (*cmpPartners)(const Partner* a, const Partner* b),
    int (*cmpPartnersDate)(const Partner* a, const Partner* b),
    Partner* (*onCmpDateValue)(Partner* a, Partner* b, const int cmpDateValue)
);

size_t parseDate(char* line, Date* date);
size_t parseToPartner(char* line, Partner* partner);

int cmpPartners(const Partner* a, const Partner* b);
int cmpPartnersDate(const Partner* a, const Partner* b);

Partner* getOldestPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
);

Partner* getYoungestPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
);

Partner* getUpdatedPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
);

void printPartner(const Partner* partner);


/* -------------------------------------------------------------------------- */
/*                             ORIGINAL FUNCTIONS                             */
/* -------------------------------------------------------------------------- */

void crear_archivo_socios_a(const char* path);

void mostrar_archivo_socios_a(const char* path);

void mostrar_archivo_socios_b(const char* path);

void mostrar_archivo_socios_final(const char* path);

#endif  // PARTNERS_H_INCLUDED
