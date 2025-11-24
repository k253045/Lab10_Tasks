#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Could not open file \n");
        return 1;
    }
    fclose(fp); 

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Could not open file for reading \n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);

    if (size == 0) {
        printf("File is empty \n");
    } else {
        printf("File is not empty \n");
    }

    return 0;
}





