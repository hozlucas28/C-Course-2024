
#include "./structs.h"

unsigned short int cmpAscInt(void* _int01, void* _int02) {
    int* __int01 = (int*)_int01;
    int* __int02 = (int*)_int02;
    return *__int01 > *__int02;
}

unsigned short int cmpDesInt(void* _int01, void* _int02) {
    int* __int01 = (int*)_int01;
    int* __int02 = (int*)_int02;
    return *__int01 < *__int02;
}

unsigned short int cmpAscStudentByAge(void* _student01, void* _student02) {
    Student* __student01 = (Student*)_student01;
    Student* __student02 = (Student*)_student02;
    return __student01->age > __student02->age;
}

unsigned short int cmpDesStudentByAge(void* _student01, void* _student02) {
    Student* __student01 = (Student*)_student01;
    Student* __student02 = (Student*)_student02;
    return __student01->age < __student02->age;
}
