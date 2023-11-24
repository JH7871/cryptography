#include <stdio.h>
#include <string.h>

void encryptRailFence(char* text, int rails, char* encryptedText) {
    for (int i = 0, len = strlen(text), k = 0, dir = -1, row = 0, col = 0; i < len; ++i) {
        encryptedText[k++] = text[row];
        if (row == 0 || row == rails - 1) dir = -dir;
        row += dir;
        col += 1;
    }
    encryptedText[strlen(text)] = '\0';
}
void decryptRailFence(char* ciphertext, int rails, char* decryptedText) {
    for (int i = 0, len = strlen(ciphertext), k = 0, dir = -1, row = 0, col = 0; i < len; ++i) {
        decryptedText[k++] = ciphertext[row];
        if (row == 0 || row == rails - 1) dir = -dir;
        row += dir;
        col += 1;
    }
    decryptedText[strlen(ciphertext)] = '\0';
}
int main() {
    char message[] = "HELLOWORLD";
    int rails = 3;
    char encryptedMessage[strlen(message) + 1];
    encryptRailFence(message, rails, encryptedMessage);
    printf("Encrypted: %s\n", encryptedMessage);
    char decryptedMessage[strlen(message) + 1];
    decryptRailFence(encryptedMessage, rails, decryptedMessage);
    printf("Decrypted: %s\n", decryptedMessage);
    return 0;
}