
#include "../library/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char error = 0;

    const char* filePath = "./file.txt";
    const char* separatorsPath = "./separators.txt";
    const char* fileModifiedPath = "./file-modified.txt";

    char* wordToReplace = "boca";
    char* newWord = "river";

    FILE* file;
    FILE* separatorsFile;
    FILE* fileModified;

    String* fileLine;
    String* separatorsLine;

    const size_t auxFileLineLength = 5;
    char auxFileLine[auxFileLineLength];

    const size_t auxSeparatorsLineLength = 5;
    char auxSeparatorsLine[auxSeparatorsLineLength];

    unsigned char flag;

    separatorsFile = fopen(separatorsPath, "rt");
    if (separatorsFile == NULL) return 1;

    separatorsLine = newString(10, 5);
    if (separatorsLine == NULL) {
        fclose(separatorsFile);
        return 1;
    };

    while (fgets(auxSeparatorsLine, auxSeparatorsLineLength, separatorsFile)) {
        error = pushStr(separatorsLine, auxSeparatorsLine);
        if (error) {
            destroyString(separatorsLine);
            fclose(separatorsFile);
            return 1;
        };
    };

    fclose(separatorsFile);

    file = fopen(filePath, "rt");
    if (file == NULL) {
        destroyString(separatorsLine);
        return 1;
    };

    fileLine = newString(10, 5);
    if (fileLine == NULL) {
        destroyString(separatorsLine);
        fclose(file);
        return 1;
    };

    fileModified = fopen(fileModifiedPath, "wt");
    if (fileModified == NULL) {
        destroyString(separatorsLine);
        destroyString(fileLine);
        fclose(file);
        return 1;
    };

    flag = 0;

    while (fgets(auxFileLine, auxFileLineLength, file)) {
        if (*(auxFileLine + strlen(auxFileLine) - 1) != '\n') {
            error = pushStr(fileLine, auxFileLine);
            if (error) break;

            flag = 1;
            continue;
        };

        error = flag ? pushStr(fileLine, auxFileLine) : setStr(fileLine, auxFileLine);
        if (error) break;
        flag = 0;

        _replaceAllWords(fileLine, wordToReplace, newWord, getStr(separatorsLine));
        fprintf(fileModified, "%s", getStr(fileLine));
        rewindString(fileLine);
    };

    if (getLength(fileLine)) {
        _replaceAllWords(fileLine, wordToReplace, newWord, getStr(separatorsLine));
        fprintf(fileModified, "%s", getStr(fileLine));
    };

    destroyString(separatorsLine);
    destroyString(fileLine);

    fclose(file);
    fclose(fileModified);

    return error;
}
