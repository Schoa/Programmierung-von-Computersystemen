
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to decode the encrypted data
void decode_data(unsigned char *encrypted_data, size_t size, char *decoded_data) {
    for (size_t i = 0; i < size; i++) {
        decoded_data[i] = (char)(encrypted_data[i] - 5); // Subtract 5 and convert to char
    }
    decoded_data[size] = '\0'; // Null-terminate the decoded string
}

int main() {
    FILE *encrypted_file, *decoded_file;
    char *output_filename = "C:\\Users\\Admin\\OneDrive\\Dokumentation\\Programmierung von Computersystemen\\Homework_#2\\decoded.txt";
    unsigned char *encrypted_data = NULL;
    size_t encrypted_size = 0;
    char buffer[BUFFER_SIZE]; // Buffer to store the read line

    // Open the encrypted file for reading
    encrypted_file = fopen("C:\\Users\\Admin\\OneDrive\\Dokumentation\\Programmierung von Computersystemen\\Homework_#2\\encrypted.txt", "r");
    if (encrypted_file == NULL) {
        printf("ERROR: Unable to open file 'encrypted.txt'.\n");
        return 1;
    }

    // Read the encrypted file and store the hexadecimal values
    while (fgets(buffer, BUFFER_SIZE, encrypted_file)) {
        char *token = strtok(buffer, " \n");
        while (token) {
            encrypted_data = realloc(encrypted_data, encrypted_size + 1);
            encrypted_data[encrypted_size++] = (unsigned char)strtol(token, NULL, 16);
            token = strtok(NULL, " \n");
        }
    }
    fclose(encrypted_file);

    // Decode the encrypted data
    char *decoded_data = malloc(encrypted_size + 1);
    decode_data(encrypted_data, encrypted_size, decoded_data);

    // Print the decoded text to the console
    printf("Decoded text:\n%s\n", decoded_data);

    // Write the decoded text to the output file
    decoded_file = fopen(output_filename, "w");
    if (decoded_file == NULL) {
        printf("ERROR: Unable to open file '%s' for writing.\n", output_filename);
        free(encrypted_data);
        free(decoded_data);
        return 1;
    }
    fprintf(decoded_file, "%s", decoded_data);
    fclose(decoded_file);

    printf("Decoded text written to '%s'.\n", output_filename);

    // Free allocated memory
    free(encrypted_data);
    free(decoded_data);

    return 0;
}
*/