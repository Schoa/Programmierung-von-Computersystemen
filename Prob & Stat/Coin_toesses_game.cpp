#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    // 1 = Head
    // 2 = Tail

    srand(time(0)); // Seed the random number generator

    char n[11];
    int p = 0; // Game 1

    for (int i = 0; i < 10; i++)
    { // Loop 10 times
        int randomNum = (rand() % 2) + 1;
        n[i] = randomNum + '0'; // Store as character '1' or '2'
    }

    n[10] = '\0';

    // Game 1: Recivce 1$ each time a head comes up
    for (int i = 0; i < 10; i++)
    { 
        if (n[i] == '1')
        {
            p++;
        }
    }

    // Game 2: Recive 1$ every coin toss, up to and including the first time a head comes up. Then recive a 2$ for every coin toss, up to the second time a head comes up. More gernerly, the dollar amount per toss is doubled each time a head comes up
    int o = 0; // Reset total for Game 2
    int q = 1; // Start at $1 per toss
    for (int i = 0; i < 10; i++)
    {
        o += q; // Add current dollar amount for this toss
        if (n[i] == '1')
        {
            q *= 2; // Double the dollar amount after a head
        }
    }

    cout << "Game 1: " << p << "$ \n"; // Game 1
    cout << "Game 2: " << o << "$ \n"; // Game 2
    return 0;
}