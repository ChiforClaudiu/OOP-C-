#include<stdio.h>
#include<limits.h>
//Write a function that takes as an input an array of integer numbers (both positive and
//negative numbers) and returns the value of the triplet with the maximum product, as well as the
//elements that form this triplet(in increasing order).Use pass by pointer / address to return the
//elements that form that triplet.Think about the appropriate data type for the result.If the size of
//the array is less than 3, you should return the minimum representable value of the data type and the
//elements that form the triplet should be set to 0.
//If the size of the array is less than 3 display the message : The array has less than 3 elements.Application
//will now stop.
//To read the input data, you will first read the size of the array n, and then n integers.
//For example, if the user types : 5, -3, 10, 200, 4, -900, then the size of the array is n = 5 and the
//array elements are{ -3, 10, 200, 4, -900 }.
//You should display “The maximum triplet is(-900, -3, 200) with a product of 540000”. (the elements of
//the triplet should be displayed in increasing order).

long long int findMaxTriplet(int arr[], int n, int* result) {
    if (n < 3) {
        printf("The array has less than 3 elements. Application will now stop.\n");
        *result = 0;
        return LLONG_MIN; // Return minimum representable value
    }

    long long int maxProduct = LLONG_MIN;
    int triplet[3] = { 0 }; // Initialize triplet to 0

    // Iterate through the array to find the maximum product triplet
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                long long int product = (long long int)arr[i] * arr[j] * arr[k];
                if (product > maxProduct) {
                    maxProduct = product;
                    triplet[0] = arr[i];
                    triplet[1] = arr[j];
                    triplet[2] = arr[k];
                }
            }
        }
    }

    // Sort the triplet in increasing order
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (triplet[j] > triplet[j + 1]) {
                int temp = triplet[j];
                triplet[j] = triplet[j + 1];
                triplet[j + 1] = temp;
            }
        }
    }

    // Assign the triplet elements to the result pointer
    if (result != NULL) {
        for (int i = 0; i < 3; i++) {
            result[i] = triplet[i];
        }
    }

    return maxProduct;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf_s("%d", &n);

    int arr[1000];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    int triplet[3];
    long long int maxProduct = findMaxTriplet(arr, n, triplet);

    if (maxProduct != LLONG_MIN) {
        printf("The maximum triplet is (%d, %d, %d) with a product of %lld\n",
            triplet[0], triplet[1], triplet[2], maxProduct);
    }

    return 0;
}