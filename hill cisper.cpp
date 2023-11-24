#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to encrypt a message using Hill cipher
void hillCipherEncrypt(char message[], int keyMatrix[][3], int messageSize, int keySize) {
    int cipherMatrix[messageSize][1];

    // Convert the message to numbers (A=0, B=1, ..., Z=25)
    for (int i = 0; i < messageSize; i++) {
        if (isalpha(message[i])) {
            cipherMatrix[i][0] = toupper(message[i]) - 'A';
        } else {
            cipherMatrix[i][0] = message[i];
        }
    }

    // Multiply the key matrix by the message matrix
    int resultMatrix[messageSize][1];
    for (int i = 0; i < messageSize; i++) {
        resultMatrix[i][0] = 0;
        for (int j = 0; j < keySize; j++) {
            resultMatrix[i][0] += keyMatrix[i][j] * cipherMatrix[j][0];
        }
        resultMatrix[i][0] %= 26; // Modulo 26 to keep the result in the range [0, 25]
    }

    // Convert the numbers back to letters
    printf("Encrypted message: ");
    for (int i = 0; i < messageSize; i++) {
        if (isalpha(message[i])) {
            printf("%c", resultMatrix[i][0] + 'A');
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

int main() {
    int keyMatrix[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix
    int messageSize, keySize;

    printf("Enter the size of the message: ");
    scanf("%d", &messageSize);

    char message[messageSize];

    printf("Enter the message: ");
    scanf(" %[^\n]s", message);

    keySize = 3; // Assuming a 3x3 key matrix

    // Check if the key matrix is invertible (determinant should be nonzero)
    int det = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[2][1] * keyMatrix[1][2]) -
              keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[2][0] * keyMatrix[1][2]) +
              keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[2][0] * keyMatrix[1][1]);

    if (det == 0) {
        printf("Error: The key matrix is not invertible.\n");
        return 1;
    }

    // Encrypt the message using the Hill cipher
    hillCipherEncrypt(message, keyMatrix, messageSize, keySize);

    return 0;
}

