#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        // Matching word -> print G
        // Not matchng word -> print B

        char c[6];
        scanf("%s", c);
        char s[6];
        scanf("%s", s);

        for (int i = 0; i < 5; i ++) 
        {
            if (c[i] == s[i]) {
                printf("G");
            }
            else {
                printf("B");
            }
        }
        printf("\n");
    }

    return 0;
}