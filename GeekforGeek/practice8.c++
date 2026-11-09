#include <iostream>

int main() {
    int year;

    std :: cout << "Year = ";
    std :: cin >> year;

    if (year % 4 == 0)
    {
        printf("%d is a Leap Year", year);
    }
    else
    {
        printf("%d is not a Leap Year", year);
    }
    

    return 0;
}