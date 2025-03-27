#include <stdio.h>

// Define a rectangular prism structure
struct RectangularPrism
{
    int length;
    int width;
    int height;
};

// Function to calculate lateral surface area
int calculateLateralSurfaceArea(struct RectangularPrism prism)
{
    return 2 * prism.height * (prism.length + prism.width);
}

// Function to calculate total surface area
int calculateTotalSurfaceArea(struct RectangularPrism prism)
{
    return 2 * (prism.length * prism.width + prism.length * prism.height + prism.height * prism.width);
}

int main()
{
    // Declare a rectangular prism variable
    struct RectangularPrism prism;
    
    printf("Enter the length, width, and height of the rectangularprism (separated by spaces): ");
    scanf("%d %d %d", &prism.length, &prism.width, &prism.height);

    // Check for valid input
    if (prism.length <= 0 || prism.length > 100 ||
        prism.width <= 0 || prism.width > 100 ||
        prism.height <= 0 || prism.height > 100) {
        printf("Invalid input. Please enter positive integers not exceeding 100.\n");
        return 1; // Exit with an error code
    }

    // Calculate and print the lateral and total surface areas
    int lateralSurfaceArea = calculateLateralSurfaceArea(prism);
    int totalSurfaceArea = calculateTotalSurfaceArea(prism);

    printf("Lateral Surface Area: %d\n", lateralSurfaceArea);
    printf("Total Surface Area: %d\n", totalSurfaceArea);
    return 0; // Exit successfully
}