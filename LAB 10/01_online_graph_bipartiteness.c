/*
 * DAA Lab 10 - Q1: Online Graph Bipartiteness Testing
 * Input: V E, followed by E candidate edges u v (vertices 1..V).
 * Accept an edge only if it preserves bipartiteness; rejected edges are skipped.
 *
 * BFS two-coloring is run on the accepted graph for each candidate edge.
 * Complexity: O(E(V+E)) total in the worst case; space O(V+E).
 * This is a straightforward validation implementation, not the most optimized
 * dynamic-bipartiteness data structure.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v; } Edge;
int main(void) {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2 || V <= 0 || E < 0) {
        fprintf(stderr, "Input: V E, followed by E edges u v\n");
        return 1;
    }
    Edge *edges = malloc((size_t)(E ? E : 1) * sizeof(*edges));
    int *head = malloc((size_t)V * sizeof(*head));
    int *to = malloc((size_t)(2 * (E ? E : 1)) * sizeof(*to));
    int *next = malloc((size_t)(2 * (E ? E : 1)) * sizeof(*next));
    int *color = malloc((size_t)V * sizeof(*color));
    int *queue = malloc((size_t)V * sizeof(*queue));
    if (!edges || !head || !to || !next || !color || !queue) {
        fprintf(stderr, "Allocation failed\n");
        free(edges); free(head); free(to); free(next); free(color); free(queue);
        return 1;
    }
    for (int i=0;i<V;i++) head[i]=-1;
    int ec=0;
    for (int i=0;i<E;i++) {
        int u,v;
        if (scanf("%d %d",&u,&v)!=2 || u<1 || u>V || v<1 || v>V) {
            fprintf(stderr,"Invalid edge\n");
            free(edges);free(head);free(to);free(next);free(color);free(queue);return 1;
        }
        edges[i]=(Edge){u-1,v-1};
    }

    for (int k=0;k<E;k++) {
        int u=edges[k].u,v=edges[k].v;
        /* Temporarily add candidate edge. */
        to[ec]=v; next[ec]=head[u]; head[u]=ec++;
        to[ec]=u; next[ec]=head[v]; head[v]=ec++;

        for(int i=0;i<V;i++) color[i]=-1;
        int bip=1;
        for(int start=0;start<V && bip;start++) if(color[start]==-1) {
            int qh=0,qt=0; queue[qt++]=start; color[start]=0;
            while(qh<qt && bip) {
                int x=queue[qh++];
                for(int e=head[x];e!=-1;e=next[e]) {
                    int y=to[e];
                    if(color[y]==-1){color[y]=color[x]^1;queue[qt++]=y;}
                    else if(color[y]==color[x]){bip=0;break;}
                }
            }
        }
        if(bip) printf("Edge (%d,%d): accepted\n",u+1,v+1);
        else {
            printf("Edge (%d,%d): rejected (would violate bipartiteness)\n",u+1,v+1);
            /* Remove the just-added edge: it was inserted at the heads. */
            head[u]=next[head[u]];
            head[v]=next[head[v]];
            ec-=2;
        }
    }
    free(edges);free(head);free(to);free(next);free(color);free(queue);
    return 0;
}
