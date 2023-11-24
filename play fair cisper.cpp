#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int k, i, j;
    char *keySet = (char *)malloc(25 * sizeof(char));
    int *visited = (int *)calloc(26, sizeof(int));
    for (k = 0, i = 0; i < strlen(key); ++i) {
        if (key[i] != 'J') {
            keySet[k++] = key[i];
        }
    }
    for (i = 0; i < 26; ++i) {
        if (i != ('J' - 'A')) {
            keySet[k++] = (char)('A' + i);
        }
    }     
    for (k = 0; k < 25; ++k) {
        visited[keySet[k] - 'A'] = 1;
    }
    for (k = 0, i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            keyTable[i][j] = keySet[k++];
        }
    }
    printf("Key Table:\n");
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }
}
void findPosition(char keyTable[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void encrypt(char keyTable[SIZE][SIZE], char message[100]) {
    int i, row1, row2, col1, col2;
    char cipher[100];
    for (i = 0; i < strlen(message); i += 2) {
        findPosition(keyTable, message[i], &row1, &col1);
        findPosition(keyTable, message[i + 1], &row2, &col2);
        if (row1 == row2) {
            cipher[i] = keyTable[row1][(col1 + 1) % SIZE];
            cipher[i + 1] = keyTable[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            cipher[i] = keyTable[(row1 + 1) % SIZE][col1];
            cipher[i + 1] = keyTable[(row2 + 1) % SIZE][col2];
        } else {
            cipher[i] = keyTable[row1][col2];
            cipher[i + 1] = keyTable[row2][col1];
        }
    }
    cipher[i] = '\0';
    printf("Encrypted Message: %s\n", cipher);
}
int main() {
    char key[100];
    char keyTable[SIZE][SIZE];
    char message[100];
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    generateKeyTable(key, keyTable);
    encrypt(keyTable, message);
    return 0;
}