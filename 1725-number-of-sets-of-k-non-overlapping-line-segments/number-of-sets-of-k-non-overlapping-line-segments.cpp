class Solution {
    int MOD = 1e9 + 7;

    // Helper function to calculate (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular Multiplicative Inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long total_items = n + k - 1;
        long long choose = 2 * k;

        if (choose > total_items) return 0;

        long long numerator = 1;
        long long denominator = 1;

        // Calculate (n+k-1) * (n+k-2) * ... / (2k)!
        for (int i = 0; i < choose; i++) {
            numerator = (numerator * (total_items - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }

        return (numerator * modInverse(denominator)) % MOD;
    }
};