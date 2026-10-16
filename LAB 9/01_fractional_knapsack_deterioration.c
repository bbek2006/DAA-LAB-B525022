/*
 * Lab 09 - Q1: Fractional Knapsack with Deterioration Rate
 *
 * Modeling note: the question does not define precisely how time advances
 * during consumption. This implementation assumes t is the cumulative weight
 * already consumed, and evaluates density (v/w - lambda*t) at the start of
 * each selected item. It is a greedy heuristic under that assumption; it is
 * NOT a proof of global optimality for all interpretations of the problem.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { int id; double v, w, lambda; } Item;

int main(void) {
    int n;
    double W;
    if (scanf("%d %lf", &n, &W) != 2 || n < 0 || W < 0) {
        fprintf(stderr, "Input: n W, followed by n lines: value weight decay_rate\n");
        return 1;
    }
    Item *a = malloc((size_t)n * sizeof(*a));
    int *used = calloc((size_t)n, sizeof(*used));
    if (n && (!a || !used)) { fprintf(stderr, "Allocation failed\n"); free(a); free(used); return 1; }
    for (int i=0;i<n;i++) {
        a[i].id=i+1;
        if (scanf("%lf %lf %lf",&a[i].v,&a[i].w,&a[i].lambda)!=3 ||
            a[i].v<0 || a[i].w<=0 || a[i].lambda<0) {
            fprintf(stderr,"Invalid item; require value>=0, weight>0, decay>=0\n");
            free(a); free(used); return 1;
        }
    }
    double t=0, remain=W, total=0;
    printf("item fraction weight_taken effective_density value_added\n");
    while (remain > 1e-9) {
        int best=-1; double bd=0;
        for (int i=0;i<n;i++) if (!used[i]) {
            double d=a[i].v/a[i].w-a[i].lambda*t;
            if (d>bd) { bd=d; best=i; }
        }
        if (best<0) break;
        double take = a[best].w < remain ? a[best].w : remain, frac=take/a[best].w;
        double add=bd*take;
        printf("%d %.4f %.4f %.4f %.4f\n",a[best].id,frac,take,bd,add);
        total+=add; remain-=take; t+=take;
        if (frac>=1-1e-9) used[best]=1; else break;
    }
    printf("Total value under stated model: %.4f\nUnused capacity: %.4f\n",total,remain);
    free(a); free(used);
    return 0;
}
