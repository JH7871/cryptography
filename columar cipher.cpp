#include <stdio.h>
#include <string.h>
void encryptColumnarCipher(char plaintext[], int key) {
    int len = strlen(plaintext);
    int rows = len / key;
    if (len % key != 0) {
        rows++;
    }
    char grid[rows][key];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            grid[i][j] = ' ';
        }
    }
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < len) {
                grid[i][j] = plaintext[index++];
            }
        }
    }
    printf("Encrypted Text: ");
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            if (grid[i][j] != ' ') {
                printf("%c", grid[i][j]);
            }
        }
    }
    printf("\n");
}
int main() {
    char plaintext[100];
    int key;
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter the key: ");
    scanf("%d", &key);
    encryptColumnarCipher(plaintext, key);
    return 0;
}
