#include <iostream>
#include <bits/stdc++.h>

int main() {
    double Principle;
    double Rate;
    double Time;

    std::cout << "Principle = ";
    std::cin >> Principle;

    std::cout << "Rate = ";
    std::cin >> Rate;

    std :: cout << "Time = ";
    std :: cin >> Time;

    double A = Principle * ((pow((1 + Rate / 100),Time))); // Amount = principle * (1 + rate /100) ^ time
    double CI = A - Principle;

    std :: cout << "Compound Interest Rate = " << CI << std :: endl;
    return 0;
}