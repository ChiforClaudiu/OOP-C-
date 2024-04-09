#include <stdio.h>
//Given a natural number n write a C program that computes the number of 1s in its binary representation.
//For example, if N = 10, your program should display 2 (because 10 in binary is 1010).If N = 32 your program should display 1 (because 32 in binary is 100000).

int countSetBits(int n) {
    int count = 0;
    while (n) {
        // Increment count if the least significant bit is set
        count += n & 1;
        // Right shift the number by 1 bit
        n >>= 1;
    }
    return count;
}

int main() {
    int n;
    printf_s("Enter a natural number: ");
    scanf_s("%d", &n);
    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }
    printf("Number of 1s in binary representation of %d: %d\n", n, countSetBits(n));
    return 0;
}