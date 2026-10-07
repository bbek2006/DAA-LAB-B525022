#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min3(int a, int b, int c) {
    int x = a < b ? a : b;
    return x < c ? x : c;
}

int main() {
    char A[1000], B[1000];
    scanf("%999s", A);
    scanf("%999s", B);

    int m = strlen(A), n = strlen(B);

    int **dp = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
        dp[i] = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min3(
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                );
        }
    }

    printf("Edit distance: %d\n", dp[m][n]);
    printf("Traceback:\n");

    int i = m, j = n;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 &&
            A[i-1] == B[j-1] &&
            dp[i][j] == dp[i-1][j-1]) {
            printf("Keep %c\n", A[i-1]);
            i--; j--;
        }
        else if (i > 0 && j > 0 &&
                 dp[i][j] == dp[i-1][j-1] + 1) {
            printf("Substitute %c -> %c\n", A[i-1], B[j-1]);
            i--; j--;
        }
        else if (i > 0 &&
                 dp[i][j] == dp[i-1][j] + 1) {
            printf("Delete %c\n", A[i-1]);
            i--;
        }
        else {
            printf("Insert %c\n", B[j-1]);
            j--;
        }
    }

    for (i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);

    return 0;
}
