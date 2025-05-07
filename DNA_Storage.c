#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        char s[n + 1];
        scanf("%s", s);

        // 00 is replaced with A
        // 01 is replaced with T
        // 10 is replaced with C
        // 11 is replaced with G
        for (int i = 0; i < n; i += 2)
        {
            if (s[i] == '0' && s[i + 1] == '0') {
                printf("A");
            } 
            else if (s[i] == '0' && s[i + 1] == '1')
            {
                printf("T");
            }
            else if (s[i] == '1' && s[i + 1] == '0')
            {
                printf("C");
            }
            else if (s[i] == '1' && s[i + 1] == '1')
            {
                printf("G");
            }
        }
        printf("\n");
    }

    return 0;
}
