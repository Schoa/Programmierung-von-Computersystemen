#include <iostream>

int main() {
    int n;
    int i;

    std :: cout << "Number to check = ";
    std :: cin >> n;

    if (n < 1) {
        printf("%d is not a Prime Number", n);

        exit(1);
    }
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            printf("%d is not a Prime Number", n);

            exit(1);
        }
    }

    std :: cout << n << " is a Prime Number" << std :: endl;

    return 0;
}