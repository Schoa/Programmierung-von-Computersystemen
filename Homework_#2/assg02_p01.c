#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE * fp;
    char ch[100]; // Buffer to store the read line
    fp = open("encrypted.txt", "r"); // Open file for reading\
    //
    printf("%s", fgets(ch, 100, fp)); // Read and print the first line
    
    //
    fclose(fp);
    return 0;
}