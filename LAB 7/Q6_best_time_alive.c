/*
 * DAA Lab-07 - Q6: The Best Time to Be Alive
 *
 * Each scientist produces:
 *   birth -> +1
 *   death -> -1
 *
 * If death year == birth year, process death BEFORE birth.
 * This follows the problem statement: the former event happens first.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int type;       /* -1 = death, +1 = birth */
} Event;

int compare_events(const void *a, const void *b) {
    const Event *x = (const Event *)a;
    const Event *y = (const Event *)b;

    if (x->year != y->year)
        return x->year - y->year;

    /* Death before birth for equal years. */
    return x->type - y->type;
}

int main(void) {
    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of scientists.\n");
        return 1;
    }

    Event *events = malloc(2 * n * sizeof(*events));
    if (!events)
        return 1;

    char name[100];
    int birth, death;

    for (int i = 0; i < n; ++i) {
        printf("Enter name, birth year, death year: ");
        scanf("%99s %d %d", name, &birth, &death);

        events[2 * i].year = birth;
        events[2 * i].type = +1;

        events[2 * i + 1].year = death;
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(*events), compare_events);

    int alive = 0;
    int maximum = 0;
    int best_year = events[0].year;

    for (int i = 0; i < 2 * n; ++i) {
        alive += events[i].type;

        if (alive > maximum) {
            maximum = alive;
            best_year = events[i].year;
        }
    }

    printf("\nYear with the largest number of scientists alive: %d\n", best_year);
    printf("Maximum number alive: %d\n", maximum);

    free(events);
    return 0;
}
