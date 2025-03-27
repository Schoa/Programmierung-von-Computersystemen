#include <stdio.h>

int main()
{
    int n = 12;
    int fib[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    FILE * ftext = fopen("number.txt", "w");
    FILE * fbin = fopen("number.bin", "w");

    for (int i = 0; i < n; i++) {
        fprintf(ftext, "%d\n", fib[i]);
    }
    fclose(ftext);

    fwrite(fib, sizeof(int), n, fbin);
    fclose(fbin);

    return 0;
}