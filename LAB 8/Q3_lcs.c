#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char X[1000], Y[1000];
    scanf("%999s", X);
    scanf("%999s", Y);

    int m = strlen(X), n = strlen(Y);

    int **dp = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
        dp[i] = calloc(n + 1, sizeof(int));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = dp[i-1][j] > dp[i][j-1]
                         ? dp[i-1][j] : dp[i][j-1];

    int len = dp[m][n];
    char *lcs = malloc(len + 1);
    lcs[len] = '\0';

    int i = m, j = n, k = len - 1;

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[k--] = X[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Length: %d\n", len);
    printf("LCS: %s\n", lcs);

    for (i = 0; i <= m; i++)
        free(dp[i]);

    free(dp);
    free(lcs);
    return 0;
}
