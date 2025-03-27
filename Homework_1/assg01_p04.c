#include <stdio.h>

// Function to add two integer values
int add(int *a, int *b) {
    return *a + *b;  // Dereference pointers and sum values
}

// Function to subtract the second value from the first value
int subtract(int *a, int *b) {
    return *a - *b;  // Dereference pointers and subtract values
}

// Function to multiply two integer values
int multiply(int *a, int *b) {
    return *a * *b;  // Dereference pointers and multiply values
}

// Define function pointer type
typedef int (*Operation)(int *, int *);

// Function to perform an operation using function pointers
int performOperation(int *a, int *b, Operation op) {
    return op(a, b);  // Execute the passed operation with parameters
}

int main() {
    int a = 20, b = 10;
    
    // Test add function
    printf("Sum: %d\n", performOperation(&a, &b, add));

    // Test subtract function
    printf("Difference: %d\n", performOperation(&a, &b, subtract));

    // Test multiply function
    printf("Product: %d\n", performOperation(&a, &b, multiply));
    
    return 0;
}
