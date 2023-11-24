#include<stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}
int mod_pow(int base, int exponent, int modulus) {
    int result = 1;
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
int main() {
    int p, q, n, n1, i, j, m = 5, result = 0, result2 = 0, temp;
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter another prime number (q): ");
    scanf("%d", &q);
    n = p * q;
    printf("Value of n = %d\n", n);
    n1 = (p - 1) * (q - 1);
    printf("Value of n1 = %d\n", n1);
    int e[] = {3, 5, 7, 11, 13, 17};
    for (i = 0; i < sizeof(e) / sizeof(e[0]); i++) {
        if (gcd(e[i], n1) == 1) {
            result = e[i];
            break;
        }
    }
    printf("The value of e is %d\n", result);
    result2 = mod_inverse(result, n1);
    printf("The value of d is %d\n", result2);
    temp = mod_pow(m, result, n);
    printf("Encrypted value : %d\n", temp);
    return 0;
}
