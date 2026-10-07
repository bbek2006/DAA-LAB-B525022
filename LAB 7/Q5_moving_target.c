/*
 * DAA Lab-07 - Q5: Hitting a Moving Target
 *
 * For n > 2, shoot at:
 *
 *   2, 3, ..., n-1, n-1, n-2, ..., 2
 *
 * Number of shots = 2(n-2).
 *
 * For n = 2, shoot the same spot twice.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("n must be greater than 1.\n");
        return 1;
    }

    if (n == 2) {
        printf("Shot sequence: 1 1\n");
        printf("Number of shots: 2\n");
        return 0;
    }

    printf("Shot sequence:\n");

    for (int i = 2; i <= n - 1; ++i)
        printf("%d ", i);

    for (int i = n - 1; i >= 2; --i)
        printf("%d ", i);

    printf("\nNumber of shots: %d\n", 2 * (n - 2));

    return 0;
}
