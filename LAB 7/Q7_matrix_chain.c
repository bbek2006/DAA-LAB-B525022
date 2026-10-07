/*
 * DAA Lab-07 - Q7: Matrix Chain Multiplication
 *
 * dp[i][j] = minimum scalar multiplications needed to multiply
 *            Ai ... Aj.
 *
 * split[i][j] stores the k at which the optimal split occurs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_parenthesization(int **split, int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }

    printf("(");
    print_parenthesization(split, i, split[i][j]);
    print_parenthesization(split, split[i][j] + 1, j);
    printf(")");
}

int main(void) {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    long long *p = malloc((n + 1) * sizeof(*p));
    int **dp = malloc((n + 1) * sizeof(*dp));
    int **split = malloc((n + 1) * sizeof(*split));

    if (!p || !dp || !split)
        return 1;

    printf("Enter dimensions p[0] ... p[%d]: ", n);
    for (int i = 0; i <= n; ++i)
        scanf("%lld", &p[i]);

    for (int i = 0; i <= n; ++i) {
        dp[i] = calloc(n + 1, sizeof(**dp));
        split[i] = calloc(n + 1, sizeof(**split));

        if (!dp[i] || !split[i])
            return 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                long long cost =
                    (long long)dp[i][k] +
                    dp[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = (int)cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum scalar multiplications: %d\n", dp[1][n]);

    printf("Optimal parenthesization: ");
    print_parenthesization(split, 1, n);
    printf("\n");

    for (int i = 0; i <= n; ++i) {
        free(dp[i]);
        free(split[i]);
    }

    free(dp);
    free(split);
    free(p);

    return 0;
}
