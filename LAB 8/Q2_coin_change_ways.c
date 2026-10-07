#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, V;
    scanf("%d", &n);

    int *coin = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    scanf("%d", &V);

    long long *dp = calloc(V + 1, sizeof(long long));
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int amount = coin[i]; amount <= V; amount++)
            dp[amount] += dp[amount - coin[i]];

    printf("%lld\n", dp[V]);

    free(coin);
    free(dp);
    return 0;
}
