#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
    int n;
    scanf("%d", &n);

    double *p = malloc((n + 1) * sizeof(double));
    double *q = malloc((n + 1) * sizeof(double));

    double **dp = malloc((n + 2) * sizeof(double *));
    for (int i = 0; i <= n + 1; i++)
        dp[i] = calloc(n + 1, sizeof(double));

    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);

    for (int i = 0; i <= n; i++)
        scanf("%lf", &q[i]);

    for (int i = 1; i <= n + 1; i++)
        dp[i][i-1] = q[i-1];

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n-len+1; i++) {
            int j = i + len - 1;
            dp[i][j] = DBL_MAX;

            double weight = q[i-1];
            for (int k = i; k <= j; k++)
                weight += p[k] + q[k];

            for (int r = i; r <= j; r++) {
                double cost = dp[i][r-1] +
                              dp[r+1][j] +
                              weight;

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum expected search cost: %.4lf\n", dp[1][n]);

    for (int i = 0; i <= n + 1; i++)
        free(dp[i]);

    free(dp);
    free(p);
    free(q);

    return 0;
}
