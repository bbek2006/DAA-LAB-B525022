#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, V;
    scanf("%d", &n);

    int *coin = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    scanf("%d", &V);

    int *dp = malloc((V + 1) * sizeof(int));

    for (int i = 0; i <= V; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int amount = 1; amount <= V; amount++) {
        for (int i = 0; i < n; i++) {
            if (coin[i] <= amount && dp[amount - coin[i]] != INT_MAX) {
                int candidate = dp[amount - coin[i]] + 1;
                if (candidate < dp[amount])
                    dp[amount] = candidate;
            }
        }
    }

    printf("%d\n", dp[V] == INT_MAX ? -1 : dp[V]);

    free(coin);
    free(dp);
    return 0;
}
