/*
 * DAA Lab-07 - Q3: Reve's Puzzle
 *
 * Four-peg Tower of Hanoi (Frame-Stewart strategy).
 *
 * H4(n) = min_k [2*H4(k) + H3(n-k)]
 * H3(n) = 2^n - 1
 *
 * For n = 8, the optimal solution requires 33 moves.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ull;

ull *dp;
int *best;

ull hanoi3(int n) {
    if (n == 0) return 0;
    return (1ULL << n) - 1;
}

void solve4(int n, int from, int to, int aux1, int aux2) {
    if (n == 0)
        return;

    int k = best[n];

    /* Move k smallest disks using all four pegs. */
    solve4(k, from, aux1, to, aux2);

    /* Move remaining n-k disks using the three pegs:
       from -> to, with aux2 as helper. */
    void hanoi3_print(int m, int a, int b, int c);

    hanoi3_print(n - k, from, to, aux2);

    /* Move the k disks from aux1 to target using four pegs. */
    solve4(k, aux1, to, from, aux2);
}

void hanoi3_print(int n, int from, int to, int aux) {
    if (n == 0)
        return;

    hanoi3_print(n - 1, from, aux, to);
    printf("Move disk from peg %d to peg %d\n", from, to);
    hanoi3_print(n - 1, aux, to, from);
}

int main(void) {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Choose 1 <= n <= 20 for safe move output.\n");
        return 1;
    }

    dp = malloc((n + 1) * sizeof(*dp));
    best = malloc((n + 1) * sizeof(*best));

    dp[0] = 0;
    best[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = ULLONG_MAX;

        for (int k = 1; k < i; ++k) {
            ull candidate = 2 * dp[k] + hanoi3(i - k);

            if (candidate < dp[i]) {
                dp[i] = candidate;
                best[i] = k;
            }
        }

        /* One possible split for n=1. */
        if (i == 1) {
            dp[i] = 1;
            best[i] = 0;
        }
    }

    printf("\nMinimum moves: %llu\n", dp[n]);

    if (n == 8)
        printf("For n = 8, the expected result is 33 moves.\n");

    printf("\nMove sequence:\n");
    solve4(n, 1, 4, 2, 3);

    free(dp);
    free(best);

    return 0;
}
