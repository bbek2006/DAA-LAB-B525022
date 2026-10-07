#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *price = malloc((n + 1) * sizeof(int));
    int *dp = malloc((n + 1) * sizeof(int));
    int *choice = malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;

        for (int j = 1; j <= i; j++) {
            if (price[j] + dp[i-j] > dp[i]) {
                dp[i] = price[j] + dp[i-j];
                choice[i] = j;
            }
        }
    }

    printf("Maximum revenue: %d\n", dp[n]);
    printf("Pieces: ");

    int length = n;
    while (length > 0) {
        printf("%d ", choice[length]);
        length -= choice[length];
    }

    printf("\n");

    free(price);
    free(dp);
    free(choice);

    return 0;
}
