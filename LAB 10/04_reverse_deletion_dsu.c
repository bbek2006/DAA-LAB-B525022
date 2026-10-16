/*
 * DAA Lab 10 - Q4: Reverse Time-Step DSU Application
 * Input: n m; n vertex weights; m edges u v; then n deletion-order vertices.
 * Outputs the maximum remaining component weight after each deletion.
 * Process deletions in reverse (vertex additions), using DSU. O((n+m) alpha(n))
 * time, O(n+m) space. Assumes each vertex appears exactly once in deletion order.
 */
#include <stdio.h>
#include <stdlib.h>
static int find(int*p,int x){if(p[x]!=x)p[x]=find(p,p[x]);return p[x];}
static void unite(int*p,long long*sum,int a,int b){a=find(p,a);b=find(p,b);if(a==b)return;if(sum[a]<sum[b]){int t=a;a=b;b=t;}p[b]=a;sum[a]+=sum[b];}
int main(void){
    int n,m;if(scanf("%d %d",&n,&m)!=2||n<=0||m<0){fprintf(stderr,"Input: n m, weights, edges, deletion permutation\n");return 1;}
    long long*w=malloc((size_t)n*sizeof(*w));int*eu=malloc((size_t)m*sizeof(int)),*ev=malloc((size_t)m*sizeof(int)),*order=malloc((size_t)n*sizeof(int)),*p=malloc((size_t)n*sizeof(int));long long*sum=malloc((size_t)n*sizeof(*sum));unsigned char*active=calloc((size_t)n,1),*seen=calloc((size_t)n,1);
    if(!w||(!eu&&m)||(!ev&&m)||!order||!p||!sum||!active||!seen){fprintf(stderr,"Allocation failed\n");free(w);free(eu);free(ev);free(order);free(p);free(sum);free(active);free(seen);return 1;}
    for(int i=0;i<n;i++){if(scanf("%lld",&w[i])!=1){fprintf(stderr,"Invalid weight\n");return 1;}p[i]=i;sum[i]=w[i];}
    for(int i=0;i<m;i++)if(scanf("%d %d",&eu[i],&ev[i])!=2||eu[i]<1||eu[i]>n||ev[i]<1||ev[i]>n){fprintf(stderr,"Invalid edge\n");return 1;}else{eu[i]--;ev[i]--;}
    for(int i=0;i<n;i++){if(scanf("%d",&order[i])!=1||order[i]<1||order[i]>n||seen[order[i]-1]){fprintf(stderr,"Deletion order must be a permutation\n");return 1;}order[i]--;seen[order[i]]=1;}
    long long*ans=malloc((size_t)n*sizeof(*ans));if(!ans){perror("malloc");return 1;}long long best=0;
    for(int i=n-1;i>=0;i--){
        int x=order[i];active[x]=1;if(w[x]>best)best=w[x];
        for(int e=0;e<m;e++)if((eu[e]==x&&active[ev[e]])||(ev[e]==x&&active[eu[e]])){int y=eu[e]==x?ev[e]:eu[e];unite(p,sum,x,y);long long root=sum[find(p,x)];if(root>best)best=root;}
        ans[i]=best;
    }
    /* ans[i] describes the graph after deleting order[0..i], i.e. before
       deletion order[i]. To report after each forward deletion, use ans[i+1],
       with final deletion yielding 0. */
    for(int i=0;i<n;i++)printf("%lld\n",i+1<n?ans[i+1]:0LL);
    free(w);free(eu);free(ev);free(order);free(p);free(sum);free(active);free(seen);free(ans);return 0;
}
