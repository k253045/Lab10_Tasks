#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (right > 0 && (str[right] == '\n' || str[right] == ' '))
        right--;

    while (left < right) {
        if (str[left] != str[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char words[5][20];

    printf("Enter 5 words \n");
    for (int i = 0; i < 5; i++)
        fgets(words[i], sizeof(words[i]), stdin);

    for (int i = 0; i < 5; i++) {
        if (isPalindrome(words[i]))
            printf("%s Palindrome\n", words[i]);
        else
            printf("%s Not Palindrome\n", words[i]);
    }

    return 0;
}





