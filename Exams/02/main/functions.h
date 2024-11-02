#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdlib.h>

#include "./structs.h"

void* _bsearch(
    void* key,
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
);

int cmpTickets(
    const void* ticket01,
    const void* ticket02
);

int cmpTicketAndAccess(
    const void* access,
    const void* ticket
);

unsigned char createTestFile(
    const char* filePath
);

int getAmountOfRecords(
    const char* filePath,
    const size_t sizeOfDataType
);

unsigned char getTickets(
    const char* filePath,
    s_ticket* tickets,
    const size_t amountOfTickets
);

void printAccesses(
    s_access* accesses,
    const size_t amountOfAccesses
);

void printTickets(
    s_ticket* tickets,
    const size_t amountOfTickets
);

unsigned char processAccess(
    s_ticket* tickets,
    const size_t amountOfTickets,
    s_access* access
);

unsigned char saveTickets(
    const char * filePath,
    s_ticket* tickets,
    const size_t amountOfTickets
);

unsigned char setRndAccesses(
    s_access* accesses,
    const size_t amountOfAccesses
);

#endif // FUNCTIONS_H_INCLUDED
