#include <stdio.h>
#include "operations.h"

// Function to get and validate user input
int getInput(const char *prompt, int *value) {
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", value) == 1 && *value > 0) {
            return 0; // Success
        } else {
            printf("Invalid input. Please enter a positive integer.\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

int main() {
    struct Rectangle rect;

    // Prompt user for input
    if (getInput("Enter the length of the rectangle: ", &rect.length) != 0) {
        printf("Failed to get length.\n");
        return 1;
    }
    if (getInput("Enter the width of the rectangle: ", &rect.width) != 0) {
        printf("Failed to get width.\n");
        return 1;
    }

    // Calculate and display area and perimeter
    int area = calculateArea(&rect);
    int perimeter = calculatePerimeter(&rect);

    if (area == -1 || perimeter == -1) {
        printf("Error calculating area or perimeter.\n");
    } else {
        printf("Area of the rectangle: %d\n", area);
        printf("Perimeter of the rectangle: %d\n", perimeter);
    }

    return 0;
}
