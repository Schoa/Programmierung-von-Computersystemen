#include <iostream>

using namespace std;
// It is static so that every class object has the same value

static int Count = 0;

class Test
{
public:
    // User - Defined Constructor
    Test() 
    {
        // Number of times constructor is called
        Count ++;
        cout << "No. of Object created:" << Count << endl;
    }
    // User-Defined Destructor
    ~Test()
    {
        cout << "No. of Object destroyed: " << Count << endl;
        Count --;
        // Number of times destructor is called
    }
};

int main()
{
    Test t, t1, t2, t3;
    return 0;
}