#include <stdio.h>
#include <string.h>

int main() {
    char words[5][20] = {"apple", "banana", "orange", "grape", "mango"};
    char input[20];
    int found = 0;

    printf("Enter a word to search: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; i < 5; i++) {
        if (strcmp(words[i], input) == 0) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}






