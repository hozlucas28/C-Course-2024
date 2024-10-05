
#include "./structs.h"

#include <strings.h>

unsigned short int cmpFloats(void* _float01, void* _float02){
    float* __float01 = (float*) _float01;
    float* __float02 = (float*) _float02;
    return *__float01 > *__float02;
}

unsigned short int cmpInts(void* _int01, void* _int02){
    int* __int01 = (int*) _int01;
    int* __int02 = (int*) _int02;
    return *__int01 > *__int02;
}

unsigned short int cmpStudentsByAverage(void* _student01, void* _student02){
    Student* __student01 = (Student*) _student01;
    Student* __student02 = (Student*) _student02;
    return __student01->average > __student02->average;
}

unsigned short int cmpStudentsByFullName(void* _student01, void* _student02){
    Student* __student01 = (Student*) _student01;
    Student* __student02 = (Student*) _student02;
    return strlen(__student01->fullName) > strlen(__student02->fullName);
}

unsigned short int cmpStudentsByDNI(void* _student01, void* _student02){
    Student* __student01 = (Student*) _student01;
    Student* __student02 = (Student*) _student02;
    return __student01->dni> __student02->dni;
}
