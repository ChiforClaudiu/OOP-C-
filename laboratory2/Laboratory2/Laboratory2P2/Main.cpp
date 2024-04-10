#include <stdio.h>
#include<string.h>
#include <limits.h>


// The strchr function is used to locate a character in a string. 
// More specifically, it returns a pointer to the first occurrence of the character in the string and NULL otherwise. 
// Write a function my_strchr, with the same parametersand return value as strchr.
const char* my_strchr(const char* s, char character) {
    const char* it = s;
    if (s == NULL)
        return NULL;
    while (*it != '\0') {
        if (*it == character)
            return it;
        it++; // Increment the pointer correctly
    }
    return NULL;
}

int main() {
    char s[120];
    char c;
    printf("Please input a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline character if present
    printf("Now enter the letter you are looking for: ");
    scanf_s(" %c", &c); // Added space before %c to consume any leading whitespace

    const char* result = my_strchr(s, c);
    if (result != NULL) {
        // Calculate the position/index of the character within the string
        int position = result - s;
        printf("Character '%c' found at position: %d\n", c, position);
    }
    else {
        printf("Character '%c' not found in the string.\n", c);
    }

    return 0;
}