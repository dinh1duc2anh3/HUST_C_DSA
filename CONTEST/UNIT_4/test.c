#include <stdio.h>

#define MOD 1000000007

// Function to compute modular inverse
long long mod_inv(long long x) {
    long long result = 1;
    long long base = x;
    int exponent = MOD - 2;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return result;
}

// Function to compute C(k, n)
long long binomial_coefficient(int k, int n) {
    // Compute factorials
    long long fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    // Compute C(k, n)
    long long result = (fact[n] * mod_inv(fact[k]) % MOD * mod_inv(fact[n - k])) % MOD;
    return result;
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    // Compute and print the result
    long long result = binomial_coefficient(k, n);
    printf("%lld\n", result);

    return 0;
}
