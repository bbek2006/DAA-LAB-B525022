#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int type; // +1 for entry, -1 for exit
} Event;

// Comparator for sorting events
int compare(const void *a, const void *b) {
    Event *e1 = (Event*)a;
    Event *e2 = (Event*)b;
    return e1->time - e2->time;
}

void findMaxPeople(int entry[], int exit[], int n) {
    Event *events = (Event*)malloc(2 * n * sizeof(Event));

    // Create events
    for (int i = 0; i < n; i++) {
        events[2*i].time = entry[i];
        events[2*i].type = +1;

        events[2*i + 1].time = exit[i];
        events[2*i + 1].type = -1;
    }

    // Sort events
    qsort(events, 2*n, sizeof(Event), compare);

    int current = 0, max = 0, time_of_max = -1;

    // Traverse events
    for (int i = 0; i < 2*n; i++) {
        current += events[i].type;

        if (current > max) {
            max = current;
            time_of_max = events[i].time;
        }
    }

    printf("Maximum people = %d at time = %d\n", max, time_of_max);

    free(events);
}

int main() {
    int entry[] = {1, 2, 10, 5, 5};
    int exit[]  = {4, 5, 12, 9, 12};
    int n = 5;

    findMaxPeople(entry, exit, n);

    return 0;
}
