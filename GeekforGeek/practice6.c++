#include <iostream>

int main() {
    int n;

    std :: cout << "Number = ";
    std :: cin >> n;

    if (n % 2 == 0) {
        printf("%d is Even Number", n);
    } else {
        printf("%d is Odd Number", n);
    }
    
    return 0;
}