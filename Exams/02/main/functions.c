
#include "./functions.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "./structs.h"

void* _bsearch(
    void* key,
    void* arr,
    const size_t arrLength,
    const size_t sizeOfDataType,
    int (*cmp)(const void* key, const void* element)
) {
    char* left = (char*)arr;
    char* mid = left + sizeOfDataType * (arrLength / 2);
    char* right = mid + (arrLength != 1 ? sizeOfDataType * (arrLength % 2) : 0);

    int cmpVal;

    while (left != right) {
        cmpVal = cmp(key, mid);

        if (cmpVal < 0) {
            return _bsearch(
                        key,
                        left,
                        arrLength / 2,
                        sizeOfDataType,
                        cmp
                    );
        } else if (cmpVal > 0) {
            return _bsearch(
                        key,
                        right,
                        arrLength / 2,
                        sizeOfDataType,
                        cmp
                    );
        };

        return mid;
    };

    return arrLength == 1 && cmp(key, left) == 0 ? left : NULL;
}

int cmpTickets(const void* ticket01, const void* ticket02) {
    s_ticket* _ticket01 = (s_ticket*)ticket01;
    s_ticket* _ticket02 = (s_ticket*)ticket02;

    return strcmp(_ticket01->code, _ticket02->code);
}

int cmpTicketAndAccess(const void* access, const void* ticket) {
    s_access* _access = (s_access*)access;
    s_ticket* _ticket = (s_ticket*)ticket;

    return strcmp(_access->ticketCode, _ticket->code);
}

unsigned char createTestFile(const char* filePath) {
    FILE* file;
    s_ticket ticket;

    int i;
    const size_t maxRecords = 100;

    file = fopen(filePath, "wb");
    if (file == NULL) return 1;

    for (i = 0; i < maxRecords; i++) {
        sprintf(ticket.code, "Ticket %06d", i + 1);
        ticket.used = rand() % 2 == 0 ? 0 : 1;
        fwrite(&ticket, sizeof(s_ticket), 1, file);
    }

    fclose(file);
    return 0;
}

int getAmountOfRecords(
    const char* filePath,
    const size_t sizeOfDataType
) {
    FILE* file;

    size_t bytes;
    size_t tickets;

    file = fopen(filePath, "rb");
    if (file == NULL) return -1;

    fseek(file, 0, SEEK_END);
    bytes = ftell(file);
    tickets = bytes / sizeOfDataType;

    fclose(file);
    return tickets;
}

unsigned char getTickets(
    const char* filePath,
    s_ticket* tickets,
    const size_t amountOfTickets
) {
    FILE* file = fopen(filePath, "rb");
    if (file == NULL) return 1;

    fread(tickets, sizeof(s_ticket), amountOfTickets, file);

    fclose(file);

    return 0;
}

void printAccesses(
    s_access* accesses,
    const size_t amountOfAccesses
) {
    size_t i;

    printf("[");

    for (i = 0; i < amountOfAccesses; i++) {
        printf("\n  { ticketCode: \"%s\" }", (accesses + i)->ticketCode);
    };

    printf("\n]");
}

void printTickets(
    s_ticket* tickets,
    const size_t amountOfTickets
) {
    size_t i;

    printf("[");

    for (i = 0; i < amountOfTickets; i++) {
        printf("\n  { code: \"%s\", used: %d }", (tickets + i)->code,
               (tickets + i)->used);
    };

    printf("\n]");
}

unsigned char processAccess(
    s_ticket* tickets,
    const size_t amountOfTickets,
    s_access* access
) {
    s_ticket* ticket = bsearch(
        access,
        tickets,
        amountOfTickets,
        sizeof(s_ticket),
        &cmpTicketAndAccess
    );
    if (ticket == NULL) return 2;

    if (ticket->used) {
        return 1;
    } else {
        ticket->used = 1;
        return 0;
    };

    return UCHAR_MAX;
}

unsigned char saveTickets(
    const char* filePath,
    s_ticket* tickets,
    const size_t amountOfTickets
) {
    FILE* file = fopen(filePath, "wb");
    if (file == NULL) return 1;

    fwrite(tickets, sizeof(s_ticket), amountOfTickets, file);

    fclose(file);

    return 0;
}

unsigned char setRndAccesses(
    s_access* accesses,
    const size_t amountOfAccesses
) {
    int i;

    for (i = 0; i < amountOfAccesses; i++) {
        sprintf((accesses + i)->ticketCode, "Ticket %06d", i + 1);
    }

    return 0;
}
