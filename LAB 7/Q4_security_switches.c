/*
 * DAA Lab-07 - Q4: Security Switches
 *
 * The minimum number of toggles is:
 *
 *     floor(2^(n+1) / 3)
 *
 * Examples:
 * n = 1 -> 1
 * n = 2 -> 2
 * n = 3 -> 5
 * n = 4 -> 10
 *
 * The number of moves is exponential, so this program computes the
 * minimum count instead of attempting to print an exponentially long
 * move sequence.
 */

#include <stdio.h>

unsigned long long min_moves(int n) {
    /*
     * floor(2^(n+1)/3) can be computed safely for n <= 62
     * using unsigned long long.
     */
    return (1ULL << (n + 1)) / 3ULL;
}

int main(void) {
    int n;

    printf("Enter number of switches (1..62): ");
    scanf("%d", &n);

    if (n < 1 || n > 62) {
        printf("n must be between 1 and 62.\n");
        return 1;
    }

    printf("Minimum number of toggles: %llu\n", min_moves(n));

    return 0;
}
