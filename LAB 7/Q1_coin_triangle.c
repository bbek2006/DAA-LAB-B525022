/*
 * DAA Lab-07 - Q1: Invert the Coin Triangle
 *
 * Minimum number of moved coins:
 *     floor(T(n) / 3)
 * where T(n) = n(n+1)/2.
 *
 * An optimal inverted triangle can be constructed by choosing a row
 * k nearest to (n+2)/3 as the common base.
 */

#include <stdio.h>

long long min_moves(long long n) {
    return n * (n + 1) / 6;
}

int main(void) {
    long long n;

    printf("Enter number of rows n: ");
    scanf("%lld", &n);

    if (n <= 0) {
        printf("n must be positive.\n");
        return 1;
    }

    long long total = n * (n + 1) / 2;
    long long k1 = (n + 2) / 3;
    long long k2 = k1 + 1;

    printf("\nNumber of rows: %lld\n", n);
    printf("Total coins: %lld\n", total);
    printf("Minimum number of coin moves: %lld\n", min_moves(n));

    printf("Optimal base-row candidate(s): ");
    if (k1 >= 1 && k1 <= n)
        printf("%lld", k1);

    if (k2 >= 1 && k2 <= n && k2 != k1)
        printf(", %lld", k2);

    printf("\n");

    return 0;
}
