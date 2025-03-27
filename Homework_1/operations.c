#include "operations.h"

int calculateArea(const struct Rectangle *rect) {
    if (rect == NULL || rect->length <= 0 || rect->width <= 0) {
        return -1; // Error: Invalid input
    }
    return rect->length * rect->width;
}

int calculatePerimeter(const struct Rectangle *rect) {
    if (rect == NULL || rect->length <= 0 || rect->width <= 0) {
        return -1; // Error: Invalid input
    }
    return 2 * (rect->length + rect->width);
}
