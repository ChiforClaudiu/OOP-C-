#include<stdio.h>
#include <iostream>
#include <stdlib.h>
// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinctand in decreasing order, and that the sum of these digits was 24. 
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints. 

int main(int argc, char* argv[]) {
	printf_s("All the possibilities for Alice pin card are:\n");
	for (int i = 9;i >= 8;i--) {
		for (int j = i - 1;j >= 2;j--) {
			for (int t = j - 1;t >= 1;t--) {
				for(int p=t-1;p>=0;p--){
				if (i + j + t + p == 24) {
					
					printf_s("%d%d%d%d \n", i, j, t, p);
					}
				}
			}
		}
	}
}