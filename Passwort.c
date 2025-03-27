#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024

int main() {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char password[BUFFER_SIZE];
    FILE *file;

    // Get password input
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    
    // Remove newline character
    password[strcspn(password, "\n")] = '\0';

    // Calculate SHA-256 hash
    SHA256((unsigned char*)password, strlen(password), hash);

    // Save hash to binary file
    file = fopen("password_hash.bin", "wb");
    if(file == NULL) {
        perror("Error creating file");
        return 1;
    }
    
    fwrite(hash, sizeof(unsigned char), SHA256_DIGEST_LENGTH, file);
    fclose(file);
    
    printf("Hash saved to password_hash.bin\n");
    return 0;
}
