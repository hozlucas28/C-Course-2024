
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./main.h"

unsigned char mergePartnersFiles(
    const char* fileAPath,
    const char* fileBPath,
    const char* mergedFilePath,
    int (*cmpPartners)(const Partner* a, const Partner* b),
    int (*cmpPartnersDate)(const Partner* a, const Partner* b),
    Partner* (*onCmpDateValue)(Partner* partnerA, Partner* partnerB, const int cmpDateValue)
) {
    FILE* fileA;
    FILE* fileB;
    FILE* mergedFile;

    const size_t fileBLineLength = PARTNERS_LINE_LENGTH;
    char fileBLine[fileBLineLength];

    Partner partnerFileA;
    Partner partnerFileB;

    size_t fieldsRead;

    int cmpPartnersValue;
    unsigned char allRecordsRead;

    int cmpDateValue;
    Partner* partnerMerged;

    fileA = fopen(fileAPath, "rb");
    if (fileA == NULL) return 1;

    fileB = fopen(fileBPath, "rt");
    if (fileB == NULL) {
        fclose(fileA);
        return 1;
    };

    mergedFile = fopen(mergedFilePath, "wt");
    if (mergedFile == NULL) {
        fclose(fileA);
        fclose(fileB);
        return 1;
    };

    size_t counterA = 0;
    size_t counterB = 0;

    while (
        fread(&partnerFileA, sizeof(Partner), 1, fileA) &&
           fgets(fileBLine, fileBLineLength, fileB)
    ) {
        fieldsRead = parseToPartner(fileBLine, &partnerFileB);
        if (fieldsRead != 3) continue;

        cmpPartnersValue = cmpPartners(&partnerFileA, &partnerFileB);

        while (cmpPartnersValue != 0) {
            if (cmpPartnersValue > 0) {
                fprintf(
                    mergedFile,
                    "%02d|%s|%02d/%02d/%04d\n",
                    partnerFileB.id,
                    partnerFileB.fullName,
                    partnerFileB.registrationDate.day,
                    partnerFileB.registrationDate.month,
                    partnerFileB.registrationDate.year
                );

                if (!fgets(fileBLine, fileBLineLength, fileB)) break;
                fieldsRead = parseToPartner(fileBLine, &partnerFileB);
            } else {
                fprintf(
                    mergedFile,
                    "%02d|%s|%02d/%02d/%04d\n",
                    partnerFileA.id,
                    partnerFileA.fullName,
                    partnerFileA.registrationDate.day,
                    partnerFileA.registrationDate.month,
                    partnerFileA.registrationDate.year
                );

                if (!fread(&partnerFileA, sizeof(Partner), 1, fileA)) break;
            };

            cmpPartnersValue = cmpPartners(&partnerFileA, &partnerFileB);
        };

        if (feof(fileA) == EOF || feof(fileB) == EOF) break;

        cmpDateValue = cmpPartnersDate(&partnerFileA, &partnerFileB);
        partnerMerged = onCmpDateValue(&partnerFileA, &partnerFileB, cmpDateValue);

        fprintf(
            mergedFile,
            "%02d|%s|%02d/%02d/%04d\n",
            partnerMerged->id,
            partnerMerged->fullName,
            partnerMerged->registrationDate.day,
            partnerMerged->registrationDate.month,
            partnerMerged->registrationDate.year
        );
    };

    while (fread(&partnerFileA, sizeof(Partner), 1, fileA)) {
        fprintf(
            mergedFile,
            "%02d|%s|%02d/%02d/%04d\n",
            partnerFileA.id,
            partnerFileA.fullName,
            partnerFileA.registrationDate.day,
            partnerFileA.registrationDate.month,
            partnerFileA.registrationDate.year
        );
    };

    while (fgets(fileBLine, fileBLineLength, fileB)) {
        fieldsRead = parseToPartner(fileBLine, &partnerFileB);
        if (fieldsRead != 3) continue;

        fprintf(
            mergedFile,
            "%02d|%s|%02d/%02d/%04d\n",
            partnerFileB.id,
            partnerFileB.fullName,
            partnerFileB.registrationDate.day,
            partnerFileB.registrationDate.month,
            partnerFileB.registrationDate.year
        );
    };

    fclose(fileA);
    fclose(fileB);
    fclose(mergedFile);

    return 0;
}

size_t parseDate(char* line, Date* date) {
    size_t fieldsRead = 0;
    const char separator = '/';

    char* field = strrchr(line, separator);
    if (field == NULL) return fieldsRead;

    fieldsRead += sscanf(field + 1, "%d", &(date->year));
    *field = '\0';

    field = strrchr(line, separator);
    if (field == NULL) return fieldsRead;

    fieldsRead += sscanf(field + 1, "%d", &(date->month));
    *field = '\0';

    fieldsRead += sscanf(line, "%d", &(date->day));

    return fieldsRead;
}

size_t parseToPartner(char* line, Partner* partner) {
    size_t fieldsRead = 0;
    const char separator = '|';

    char* field = strrchr(line, separator);
    if (field == NULL) return fieldsRead;

    if (parseDate(field + 1, &(partner->registrationDate)) != 3) return fieldsRead;
    *field = '\0';
    fieldsRead++;

    field = strrchr(line, separator);
    if (field == NULL) return fieldsRead;

    strcpy(partner->fullName, field + 1);
    *field = '\0';
    fieldsRead++;

    fieldsRead += sscanf(line, "%d", &(partner->id));

    return fieldsRead;
}

int cmpPartners(const Partner* a, const Partner* b) {
    return a->id - b->id;
}

int cmpPartnersDate(const Partner* a, const Partner* b) {
    struct tm partnerATime;
    struct tm partnerBTime;

    time_t epochDateA;
    time_t epochDateB;

    partnerATime.tm_sec = 0;
    partnerATime.tm_min = 0;
    partnerATime.tm_hour = 0;
    partnerATime.tm_mday = a->registrationDate.day;
    partnerATime.tm_mon = a->registrationDate.month - 1;
    partnerATime.tm_year = a->registrationDate.year - 1900;
    partnerATime.tm_isdst = -1;

    partnerBTime.tm_sec = 0;
    partnerBTime.tm_min = 0;
    partnerBTime.tm_hour = 0;
    partnerBTime.tm_mday = b->registrationDate.day;
    partnerBTime.tm_mon = b->registrationDate.month - 1;
    partnerBTime.tm_year = b->registrationDate.year - 1900;
    partnerBTime.tm_isdst = -1;

    epochDateA = mktime(&partnerATime);
    epochDateB = mktime(&partnerBTime);

    return (int)epochDateA - (int)epochDateB;
}

Partner* getOldestPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
) {
    if (cmpDateValue == 0) return partnerA;
    return cmpDateValue > 0 ? partnerB : partnerA;
}

Partner* getYoungestPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
) {
    if (cmpDateValue == 0) return partnerA;
    return cmpDateValue > 0 ? partnerA : partnerB;
}

Partner* getUpdatedPartner(
    Partner* partnerA,
    Partner* partnerB,
    const int cmpDateValue
) {
    struct tm *nowGMTime;

    time_t nowTime = time(NULL);
    nowGMTime = gmtime(&nowTime);

    partnerA->registrationDate.day = nowGMTime->tm_mday;
    partnerA->registrationDate.month = nowGMTime->tm_mon + 1;
    partnerA->registrationDate.year = nowGMTime->tm_year + 1900;

    return partnerA;
}

void printPartner(const Partner* partner) {
    printf(
        "%d|%s|%d/%d/%d",
        partner->id,
        partner->fullName,
        partner->registrationDate.day,
        partner->registrationDate.month,
        partner->registrationDate.year
    );
}
