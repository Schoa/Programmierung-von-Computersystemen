#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char ch[100]; // Buffer to store the read line
    fp = fopen("encrypted.txt", "r"); // Open file for reading

    if (fp == NULL) // Check file
    {
        printf("ERROR: Unable to open file. \n");
        return 1;
    }

    //
    if (fgets(ch, sizeof(ch), fp) != NULL) {
        printf("%s", ch);
    }
    
    while (fgets(ch, sizeof(ch), fp) != NULL) { // Read and print the rest of the lines
        int asciiValue = atoi(ch); // Convert the line of the interger (ASCII value)
        printf("%c", (char)asciiValue); // Print the corresponding charecter
    }
    //
    fclose(fp);
    return 0;
}