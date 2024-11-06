
#include <stdio.h>
#include <string.h>

#include "./gbib.h"

int permutarArchClientesALU(const char* archOri, const char* archDes){
    return 0;
}

int restaurarArchClientesALU(const char* archOri, const char* archDes){
    size_t i;

    FILE* oriFile;
    FILE* permFile;
    FILE* destFile;

    Slice* clients;
    Slice* permutations;

    char lineClient[CLIENT_LINE_LENGTH];
    char linePermutation[CLIENT_LINE_LENGTH];

    Client client;
    Permutation permutation;

    Permutation* perm;
    Client* clientSource;
    Client* clientDest;

    Client* PClient;

    oriFile = fopen(archOri, "rt");
    if (oriFile == NULL) return 0;

    clients = newSlice(sizeof(Client), MAX_CLIENTS_PERMUTATIONS);
    if (clients == NULL) {
        fclose(oriFile);
        return 0;
    };

    while(fgets(lineClient, CLIENT_LINE_LENGTH, oriFile)) {
        parseToClient(lineClient, &client);
        append(clients, &client);
    };

    fclose(oriFile);

    permFile = fopen("perm.txt", "rt");
    if (permFile == NULL) {
        destroySlice(clients);
        return 0;
    };

    permutations = newSlice(sizeof(Permutation), MAX_CLIENTS_PERMUTATIONS);
    if (permutations == NULL) {
        destroySlice(clients);
        fclose(permFile);
        return 0;
    };

    while(fgets(linePermutation, PERMUTATION_LINE_LENGTH, permFile)) {
        parseToPermutation(linePermutation, &permutation);
        unshift(permutations, &permutation);
    };

    fclose(permFile);

    for (i = 0; i < permutations->length; i++) {
        perm = (((Permutation*)permutations->arr) + i);

        if (perm->source >= 0 && perm->destination < clients->length){
            clientSource = (Client*)(clients->arr) + perm->source;
            clientDest = (Client*)(clients->arr) + perm->destination;

            _swap(
                &(clientSource->salary),
                &(clientDest->salary),
                sizeof(clientSource->salary)
            );
        };
    };

    destroySlice(permutations);

    destFile = fopen(archDes, "wt");
    if (destFile == NULL) {
        destroySlice(clients);
        return 0;
    };

    for (i = 0; i < clients->length; i++) {
        PClient = (Client*)(clients->arr) + i;

        fprintf(
            destFile,
            "%d|%s|%s|%.2f\n",
            PClient->id,
            PClient->firstNameLastName,
            PClient->securityCode,
            PClient->salary
        );
    };

    fclose(destFile);
    destroySlice(clients);

    return 1;
}

Slice* newSlice(const size_t sizeOfDataType, const size_t maxLength) {
    Slice* slice = malloc(sizeof(Slice));
    if (slice == NULL) return NULL;

    slice->arr = malloc(sizeOfDataType * maxLength);
    if (slice->arr == NULL) return NULL;

    slice->length = 0;
    slice->maxLength = maxLength;
    slice->sizeOfDataType = sizeOfDataType;

    return slice;
}

void destroySlice(Slice* slice) {
    free(slice->arr);
    free(slice);
}

unsigned char append(Slice* slice, void* element) {
    void* aux;

    if (slice->length == slice->maxLength) {
        aux = realloc(slice->arr, slice->sizeOfDataType * (slice->maxLength + 1));
        if (aux == NULL) return 1;

        slice->arr = aux;
        slice->maxLength++;
    };

    memcpy(
        (char*)(slice->arr) + (slice->sizeOfDataType * slice->length),
        element,
        slice->sizeOfDataType
    );

    slice->length++;

    return 0;
}

unsigned char unshift(Slice* slice, void* element) {
    void* aux;

    size_t i;
    char* currentElem;
    char* prevElem;

    if (slice->length == slice->maxLength) {
        aux = realloc(slice->arr, slice->sizeOfDataType * (slice->maxLength + 1));
        if (aux == NULL) return 1;

        slice->arr = aux;
        slice->maxLength++;
    };

    for (i = slice->length; i > 0; i--) {
        currentElem = ((char*)slice->arr) + slice->sizeOfDataType * i;
        prevElem = currentElem - slice->sizeOfDataType;
        _swap(currentElem, prevElem, slice->sizeOfDataType);
    };

    memcpy(
        (char*)slice->arr,
        element,
        slice->sizeOfDataType
    );

    slice->length++;

    return 0;
}

void _swap(const void* a, const void* b, const size_t sizeOfDataType) {
    size_t i;
    char aux;

    for (i = 0; i < sizeOfDataType; i++) {
        aux = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = aux;
    };
}

unsigned char parseToClient(char* line, Client* client) {
    char* _line;
    const char sep = '|';

    _line = strrchr(line, sep);
    if (_line == NULL ) return 1;

    _line++;
    sscanf(_line, "%f", &(client->salary));

    _line--;
    *_line = '\0';

    _line = strrchr(line, sep);
    if (_line == NULL ) return 1;

    _line++;
    sscanf(_line, "%s", client->securityCode);

    _line--;
    *_line = '\0';

    _line = strrchr(line, sep);
    if (_line == NULL ) return 1;

    _line++;
    sscanf(_line, "%[a-zA-Z ]", client->firstNameLastName);
    *(client->firstNameLastName + strlen(client->firstNameLastName)) = '\0';

    _line--;
    *_line = '\0';

    sscanf(line, "%d", &(client->id));

    return 0;
}

unsigned char parseToPermutation(char* line, Permutation* permutation) {
    char* _line = line + strlen(line);

    _line -= PERMUTATION_FIELD_LENGTH;
    sscanf(_line, "%d", &(permutation->destination));

    *_line = '\0';
    sscanf(line, "%d", &(permutation->source));

    return 0;
}

int cmpClientsID(const void* clientA, const void* clientB) {
    Client* _clientA = (Client*)clientA;
    Client* _clientB = (Client*)clientB;
    return _clientA->id - _clientB->id;;
}

void printClientsSlice(Slice* slice) {
    size_t i;

    Client* client;

    for (i = 0; i < slice->length; i++) {
        client = (((Client*)(slice->arr)) + i);

        printf(
            "%d|%s|%s|%f\n",
            client->id,
            client->firstNameLastName,
            client->securityCode,
            client->salary
        );
    };
}

void printPermutationsSlice(Slice* slice) {
    size_t i;

    Permutation* permutation;

    for (i = 0; i < slice->length; i++) {
        permutation = (((Permutation*)(slice->arr)) + i);

        printf(
            "%d <==> %d\n",
            permutation->source,
            permutation->destination
        );
    };
}
