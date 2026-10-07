#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    int *dp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;

        if (dp[i] > ans)
            ans = dp[i];
    }

    printf("%d\n", ans);

    free(a);
    free(dp);
    return 0;
}
