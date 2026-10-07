/*
 * DAA Lab-07 - Q2: Super Egg Testing
 *
 * dp[e][f] = minimum number of drops needed with e eggs and f floors.
 *
 * Recurrence:
 * dp[e][f] = 1 + min over x=1..f of
 *            max(dp[e-1][x-1], dp[e][f-x])
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int E, F;

    printf("Enter number of eggs and floors: ");
    scanf("%d %d", &E, &F);

    if (E <= 0 || F < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int **dp = malloc((E + 1) * sizeof(*dp));
    if (!dp) return 1;

    for (int e = 0; e <= E; ++e) {
        dp[e] = malloc((F + 1) * sizeof(**dp));
        if (!dp[e]) return 1;
    }

    for (int e = 0; e <= E; ++e)
        dp[e][0] = 0;

    for (int f = 0; f <= F; ++f)
        dp[1][f] = f;

    for (int e = 2; e <= E; ++e) {
        for (int f = 1; f <= F; ++f) {
            dp[e][f] = INT_MAX;

            for (int x = 1; x <= f; ++x) {
                int worst = dp[e - 1][x - 1] > dp[e][f - x]
                            ? dp[e - 1][x - 1]
                            : dp[e][f - x];

                if (1 + worst < dp[e][f])
                    dp[e][f] = 1 + worst;
            }
        }
    }

    printf("Minimum guaranteed drops: %d\n", dp[E][F]);

    for (int e = 0; e <= E; ++e)
        free(dp[e]);
    free(dp);

    return 0;
}
