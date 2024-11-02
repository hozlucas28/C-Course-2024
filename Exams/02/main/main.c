#include <stdio.h>
#include <stdlib.h>

#include "./functions.h"
#include "./structs.h"

int main() {
    const char* filePath = "./data.dat";

    unsigned char error;

    s_ticket* tickets;
    int amountOfTickets;

    size_t amountOfAccesses = 120;
    s_access accesses[amountOfAccesses];

    size_t i;
    unsigned char status;

    error = createTestFile(filePath);
    if (error) {
        printf("Error! An error occurred on create test file.");
        return 1;
    };

    amountOfTickets = getAmountOfRecords(filePath, sizeof(s_ticket));
    if (amountOfTickets == -1) {
        printf("Error! An error occurred on get amount of tickets.");
        return 1;
    };

    tickets = malloc(sizeof(s_ticket) * amountOfTickets);

    error = getTickets(filePath, tickets, amountOfTickets);
    if (error) {
        printf("Error! An error occurred on get tickets.");
        return 1;
    };

    qsort(tickets, amountOfTickets, sizeof(s_ticket), &cmpTickets);

    printf("> Tickets (before process acceses): ");
    printTickets(tickets, amountOfTickets);

    error = setRndAccesses(accesses, amountOfAccesses);
    if (error) {
        printf("Error! An error occurred on create random accesses.");
        return 1;
    };

    printf("\n\n> Accesses: ");
    printAccesses(accesses, amountOfAccesses);

    printf("\n\n> Accesses:");
    for (i = 0; i < amountOfAccesses; i++ ) {
        status = processAccess(tickets, amountOfTickets, accesses + i);

        switch (status) {
        case 0:
            printf(
                "\n  Access with \"%s\" (ticket code) authorized.",
                (accesses + i)->ticketCode
            );
            break;

        case 1:
            printf(
                "\n  Access with \"%s\" (ticket code) not authorized, ticket already used.",
                (accesses + i)->ticketCode
            );
            break;

        case 2:
            printf(
                "\n  Access with \"%s\" (ticket code) not authorized, ticket code doesn't exist.",
                (accesses + i)->ticketCode
            );
            break;

        default:
            printf(
                "  \nAccess with \"%s\" ticket code can't access, unknown reason.",
                (accesses + i)->ticketCode
            );
        };
    };

    printf("\n\n> Tickets (after process acceses): ");
    printTickets(tickets, amountOfTickets);

    error = saveTickets(filePath, tickets, amountOfTickets);
    if (error) {
        printf("Error! An error occurred on save updated tickets.");
        return 1;
    };

    free(tickets);

    return 0;
}
