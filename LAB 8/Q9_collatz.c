#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long ull;

typedef struct {
    ull *values;
    size_t size;
    size_t capacity;
} Trajectory;

void initTrajectory(Trajectory *t) {
    t->size = 0;
    t->capacity = 16;
    t->values = malloc(t->capacity * sizeof(ull));
}

void addValue(Trajectory *t, ull value) {
    if (t->size == t->capacity) {
        t->capacity *= 2;
        ull *temp = realloc(t->values,
                            t->capacity * sizeof(ull));
        if (!temp) {
            free(t->values);
            exit(EXIT_FAILURE);
        }
        t->values = temp;
    }

    t->values[t->size++] = value;
}

void freeTrajectory(Trajectory *t) {
    free(t->values);
}

int collatz(ull n, Trajectory *t) {
    addValue(t, n);

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            if (n > (ULLONG_MAX - 1) / 3)
                return 0;

            n = 3 * n + 1;
        }

        addValue(t, n);
    }

    return 1;
}

int main() {
    ull a, b;
    scanf("%llu %llu", &a, &b);

    if (a == 0 || a > b) {
        printf("Invalid interval.\n");
        return 1;
    }

    ull maxSteps = 0;
    ull maxValue = 0;
    ull maxStart = a;

    for (ull start = a; start <= b; start++) {
        Trajectory t;
        initTrajectory(&t);

        if (!collatz(start, &t)) {
            printf("Overflow for %llu\n", start);
            freeTrajectory(&t);
            continue;
        }

        ull steps = t.size - 1;
        ull localMax = 0;

        for (size_t i = 0; i < t.size; i++)
            if (t.values[i] > localMax)
                localMax = t.values[i];

        printf("%llu: steps=%llu, max=%llu\n",
               start, steps, localMax);

        if (steps > maxSteps) {
            maxSteps = steps;
            maxStart = start;
        }

        if (localMax > maxValue)
            maxValue = localMax;

        freeTrajectory(&t);

        if (start == ULLONG_MAX)
            break;
    }

    printf("\nMaximum stopping time: %llu\n", maxSteps);
    printf("Starting value: %llu\n", maxStart);
    printf("Maximum value reached: %llu\n", maxValue);

    return 0;
}
