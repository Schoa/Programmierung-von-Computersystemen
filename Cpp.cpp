// Program 1
/*
# include <iostream>


int main() 
{
    int num1, num2;

    std :: cout << "Enter two numbers separated by a space: ";
    std :: cin >> num1 >> num2;

    std :: cout << "The sum is:" << (num1 + num2) << std::endl;

    return 0;
}
*/

// Prgram 2
/*
# include <iostream> // Input/Output
# include <math.h> // Usual C lib header file for math 

using namespace std;

int main() 
{
    float x;

    cout << "Enter a real number: " << endl;
    // std::cout << "Enter real number: " << endl;
    cin >> x; // scanf("%f", &x); in C 

     cout << "The square root  of " << x << " is: "
                << sqrt(x) << endl;
}
*/

// Prgram 3
/*

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a = 15.2;
    double b = 34.3434343;

    cout << fixed << showpoint;
    cout << setprecision(2); // 2 digits after the dot
    cout << setw(6) << a << endl; // 15.20
    cout << setw(6) << b << endl; // 34.34
}
*/

/*
// Example 3
#include <iostream>

void sort(int& x, int& y)
{
    if (x>y) {
        int temp = x;
        x = y;
        y = temp;
    }
}

int main(void) 
{
    int a = 9, b = 5;
    sort(a,b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}
*/

/*
#include <iostream>

using namespace std;

float division(int x, int y)
{
    if (y == 0) {
        throw "Attempted to divide by zero!";
    }
    return (x / y);
}

int main()
{
    int i = 25;
    int j = 5;
    float k = 0;

    try {
        k = division (i, j);
        cout << k << endl;
    } catch(const char *e) {
        cerr << e << endl;
    }

    return 0;
}
*/

/*
#include <iostream>

class Entity
{
    public:
    float x, y;

    void Move (float xa, float ya) {
        x += xa;
        y += ya;
    }
};

class Player : public Entity
{
    public:
        string name;

    void printName() {
        cout << "Name:" << name << endl;
    }
};

 

int main() {
    Player player1;
    player1.Move(10,10);
    player1.printName();
    player1.x = 5; // because x is public
}
*/

/*
# include<iostream>

using namespace std;

class Employee {
    private:
        char name[30];
        int emp_id;
    public:
        void getData() {
            cout << "Enter name: "; cin >> name;
            cout << "Enter Emp.ID: "; cin >> emp_id;
        }

        void putData() {
            cout << "Name: " << name << "\t";
            cout << "Emp.No: " << emp_id << "\t";
            cout << "Basic Salary: " << salary;
        }
    protected:
        float salary;
        void getSalary() {
            cout << "Enter salary: "; cin >> salary;
        }
};
*/

/*
#include <iostream>
using namespace std;

// Base class
class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a shape." << endl;
        }
};

// Derived Class
class Square : public Shape {
    public:
        void draw() {
            cout << "Drawing a square." << endl;
        }
};

// Derivated Class
class Circle : public Shape {
    public:
        void draw() {
            cout << "Drawing a square." << endl;
        }
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();
    shape1 -> draw();
    shape2 -> draw();

    return 0;
}
*/

#include <iostream>
using namespace std;

template <typename T>
T max(T x, T y)
{
    return(x > y) ? x : y;
}

int main() {
    cout << std::max(10, 20) << endl; // calls max<int>(10, 20)
    cout << std::max(2.5, 1.2) << endl; // Calls max<double>(2.5, 1.2)
    cout << std::max('d', 'c') << endl; // Calls max<char>('a', 'b')
    cout << std::max("Hello", "World"); // Calls max<string?("Hello", "World")
    return 0;
}