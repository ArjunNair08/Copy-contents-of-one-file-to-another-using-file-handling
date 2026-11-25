#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    int ch;

    printf("Enter source file path: ");
    scanf("%99s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%99s", destPath);

    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    destFile = fopen(destPath, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(sourceFile); 
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
