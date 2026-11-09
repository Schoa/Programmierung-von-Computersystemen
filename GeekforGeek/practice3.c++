// Q4
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    // temporary value
    int temp;
    
    // Swapping 
    temp = a;
    a = b;
    b = temp;

    cout << "" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}