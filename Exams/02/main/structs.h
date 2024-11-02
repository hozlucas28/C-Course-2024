#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define CODE_LENGTH 16

typedef struct {
    char code[CODE_LENGTH];
    int used;
} s_ticket;

typedef struct {
    char ticketCode[CODE_LENGTH];
} s_access;

#endif // STRUCTS_H_INCLUDED
