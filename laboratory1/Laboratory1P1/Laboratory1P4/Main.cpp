#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.

void encrypt(char s[], int n) {
    char new_str[100];
    for (int i = 0; i < strlen(s); i++) {
        char new_c = s[i];
        if (new_c >= 'a' && new_c <= 'z') {
            new_c = new_c + n;
            if (new_c > 'z')
                new_c = new_c - 'z' + 'a' - 1;
            else if (new_c < 'a')
                new_c = new_c + 'z' - 'a' + 1;
        }
        else if (new_c >= 'A' && new_c <= 'Z') {
            new_c = new_c + n;
            if (new_c > 'Z')
                new_c = new_c - 'Z' + 'A' - 1;
            else if (new_c < 'A')
                new_c = new_c + 'Z' - 'A' + 1;
        }
        new_str[i] = new_c;
    }
    new_str[strlen(s)] = '\0'; // Null-terminate the string
    printf("This is the encrypted code: %s\n", new_str);
}

int main()
{
    int k = 0;
    char s[100];
    printf("Please enter the encryption key: ");
    scanf_s("%d", &k);
    printf("Please enter the code that you want to encrypt: ");
    scanf_s("%s", s);
    encrypt(s, k);
    return 0;
}