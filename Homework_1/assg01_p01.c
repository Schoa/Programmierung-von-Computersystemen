#include <stdio.h>
/*
Collatz conjunction

Even number: Divide by 2
Odd number: Multiply by three, than add 1
*/

int main()
{
    int a;
    scanf("%d", &a);

    if (a == 0) // Check input
    {
        printf("N/A");
    }
    else{
        int b = a * a;

        printf("%d", b);  // Initial value

        while (b != 1) // Continue until we reach 1
        {
            if (b % 2 == 0)
            {
                b = b / 2;
            }
            else
            {
                b = b * 3 + 1;
            }
            printf(" -> %d", b);
        }
    }

    return 0;
}