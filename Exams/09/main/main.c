
#include <stdio.h>

#include "./main.h"

int main() {
    const char* partnersAFilePath = "./partners-a.bin";
    const char* partnersBFilePath = "./partners-b.txt";
    const char* partnersMergedFilePath = "./partners-merged.txt";

    int input;
    unsigned char error;

    crear_archivo_socios_a(partnersAFilePath);

    printf(
        "> Available operations:\n\n%s%s%s%s",
        " 1 - Merge by oldest registration date.\n",
        " 2 - Merge by minor registration date.\n",
        " 3 - Merge updating the registration date.\n",
        " 0 - Exit.\n"
    );

    printf("\n> Select an operation: ");
    scanf("%d", &input);

    while (input != 0) {
        switch (input) {
        case 1:
            error = mergePartnersFiles(
                partnersAFilePath,
                partnersBFilePath,
                partnersMergedFilePath,
                &cmpPartners,
                &cmpPartnersDate,
                &getOldestPartner
            );

            if (error) {
                printf("\n> Error! An error occurred on merge files by oldest registration date.");
                break;
            };

            printf(
                "\n> Files merged by oldest registration date. Merge file in \"%s\" path.",
                partnersMergedFilePath
            );
            break;

        case 2:
            error = mergePartnersFiles(
                partnersAFilePath,
                partnersBFilePath,
                partnersMergedFilePath,
                &cmpPartners,
                &cmpPartnersDate,
                &getYoungestPartner
            );

            if (error) {
                printf("\n> Error! An error occurred on merge files by minor registration date.");
                break;
            };

            printf(
                "\n> Files merged by minor registration date. Merge file in \"%s\" path.",
                partnersMergedFilePath
            );
            break;

        case 3:
            error = mergePartnersFiles(
                partnersAFilePath,
                partnersBFilePath,
                partnersMergedFilePath,
                &cmpPartners,
                &cmpPartnersDate,
                &getUpdatedPartner
            );

            if (error) {
                printf("\n> Error! An error occurred on merge files updating the registration date.");
                break;
            };

            printf(
                "\n> Files merged updating the registration date. Merge file in \"%s\" path.",
                partnersMergedFilePath
            );
            break;

        default:
            printf("\n> Invalid operation! Try again...");
        }

        printf(
            "\n\n> Available operations:\n\n%s%s%s%s",
            " 1 - Merge by oldest registration date.\n",
            " 2 - Merge by minor registration date.\n",
            " 3 - Merge updating the registration date.\n",
            " 0 - Exit.\n"
        );

        printf("\n> Select an operation: ");
        scanf("%d", &input);
    };

    return 0;
}
