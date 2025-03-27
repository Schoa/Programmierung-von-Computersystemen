#ifndef OPERATIONS_H
#define OPERATIONS_H
#define NULL ((void*)0)

struct Rectangle {
    int length;
    int width;
};

int calculateArea(const struct Rectangle *rect);
int calculatePerimeter(const struct Rectangle *rect);

#endif // OPERATIONS_H
