#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[256];

    // If user passed a filename on the command line, use it.
    if (argc >= 2) {
        strncpy(filename, argv[1], sizeof(filename) - 1);
        filename[sizeof(filename) - 1] = '\0';
    } else {
        // Otherwise, ask the user for a file name.
        printf("Enter log file name: ");
        if (scanf("%255s", filename) != 1) {
            printf("Error reading file name.\n");
            return 1;
        }
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[512];
    int totalLines = 0;
    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        totalLines++;

        if (strstr(line, "INFO") != NULL) {
            infoCount++;
        }
        if (strstr(line, "WARNING") != NULL) {
            warningCount++;
        }
        if (strstr(line, "ERROR") != NULL) {
            errorCount++;
        }
    }

    fclose(fp);

    printf("\nLog analysis for file: %s\n", filename);
    printf("---------------------------------\n");
    printf("Total lines   : %d\n", totalLines);
    printf("INFO lines    : %d\n", infoCount);
    printf("WARNING lines : %d\n", warningCount);
    printf("ERROR lines   : %d\n", errorCount);

    return 0;
}

