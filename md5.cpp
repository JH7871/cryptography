#include <stdio.h>
#include <string.h>
#include <stdint.h>
void sha256(const char *message, uint8_t hash[32]) {
    for (int i = 0; i < 32; i++) {
        hash[i] = 0;
    }
}
uint64_t mod_exp(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
void sign_message(const char *message, uint64_t private_key, uint64_t modulus, uint64_t *signature) {
    uint8_t hash[32];
    sha256(message, hash);
    uint64_t message_hash = 0;
    for (int i = 0; i < 32; i++) {
        message_hash = (message_hash << 8) | hash[i];
    }
    *signature = mod_exp(message_hash, private_key, modulus);
}
int main() {
    const char *message = "Hello, this is a test message.";
    uint64_t private_key = 12345;
    uint64_t modulus = 67890;
    uint64_t signature;
    sign_message(message, private_key, modulus, &signature);
    printf("Message: %s\n", message);
    printf("Signature: %llu\n", signature);
    return 0;
}
