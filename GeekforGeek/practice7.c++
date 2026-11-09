#include <iostream>

int main() {
    int a;
    int b;
    int c;

    std :: cout << "a = ";
    std :: cin >> a;

    std :: cout << "b = ";
    std :: cin >> b;

    std :: cout << "c = ";
    std :: cin >> c;

    if (a > b & a > c) {
        printf("a is the Largest Number");
    } else if (b > a & b > c)
    {
        printf("b is the Largest Number");
    } else {
        printf("c is the Largest Number");
    }
    
    return 0;
}