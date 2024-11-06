#ifndef GBIB_H_INCLUDED
#define GBIB_H_INCLUDED

#include <stdlib.h>

#define MAX_CLIENTS_PERMUTATIONS 50000

#define LEGAJO_LENGTH sizeof(int)
#define NAME_LASTNAME_LENGTH 64
#define SECURITY_CODE_LENGTH 512
#define SALARY_LENGTH sizeof(float)

#define CLIENT_LINE_LENGTH LEGAJO_LENGTH + NAME_LASTNAME_LENGTH + SECURITY_CODE_LENGTH + SALARY_LENGTH + 2

#define PERMUTATION_FIELD_LENGTH 5

#define PERMUTATION_LINE_LENGTH PERMUTATION_FIELD_LENGTH * 2 + 2

typedef struct {
    int id;
    char firstNameLastName[NAME_LASTNAME_LENGTH];
    char securityCode[SECURITY_CODE_LENGTH];
    float salary;
} Client;

typedef struct {
    int source;
    int destination;
} Permutation;

typedef struct {
    void* arr;
    size_t length;
    size_t maxLength;
    size_t sizeOfDataType;
} Slice;

int crearLotePruebaClientes(const char* nomArchivo);
int permutarArchClientes(const char* archOri, const char* archDes);
int restaurarArchClientes(const char* archOri, const char* archDes);

int permutarArchClientesALU(const char* archOri, const char* archDes);
int restaurarArchClientesALU(const char* archOri, const char* archDes);

Slice* newSlice(const size_t sizeOfDataType, const size_t maxLength);
void destroySlice(Slice* slice);
unsigned char append(Slice* slice, void* element);
unsigned char unshift(Slice* slice, void* element);

void _swap(const void* a, const void* b, const size_t sizeOfDataType);

unsigned char parseToClient(char* line, Client* client);
unsigned char parseToPermutation(char* line, Permutation* permutation);

int cmpClientsID(const void* clientA, const void* clientB);

void printClientsSlice(Slice* slice);
void printPermutationsSlice(Slice* slice);

#endif // GBIB_H_INCLUDED
