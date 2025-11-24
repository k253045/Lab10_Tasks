#include <stdio.h>

int main() {
    FILE *file1, *file2, *fileOut;
    char ch;

    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Could not open file1.txt \n");
        return 1;
    }

    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Could not open file2.txt \n");
        fclose(file1);
        return 1;
    }

    fileOut = fopen("merged.txt", "w");
    if (fileOut == NULL) {
        printf("Could not create merged.txt \n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, fileOut);
    }

    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, fileOut);
    }

    printf("Files merged successfully into merged.txt\n");

    fclose(file1);
    fclose(file2);
    fclose(fileOut);

    return 0;
}






