#include <stdio.h>
#include <string.h>

int countVowels(char str[], int index) {
    if (str[index] == '\0')
        return 0;

    int isVowel = 0;
    char ch = str[index];

    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
        isVowel = 1;
    }

    return isVowel + countVowels(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int result = countVowels(str, 0);

    printf("Number of vowels: %d\n", result);

    return 0;
}




