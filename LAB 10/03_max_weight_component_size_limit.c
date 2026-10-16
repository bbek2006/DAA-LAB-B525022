/*
 * DAA Lab 10 - Q3: Maximum Weight Component with Size Constraints
 * Input: n m K; n vertex weights; then m edges u v (1-based).
 * Edges are processed in input order. After each edge, output the maximum
 * component weight among components whose size <= K. If no component qualifies,
 * print 0. DSU union-by-size + path compression; recomputes the maximum by
 * scanning all roots after each edge: O(m*n alpha(n)) time, O(n) space.
 */
#include <stdio.h>
#include <stdlib.h>
static int find(int*p,int x){if(p[x]!=x)p[x]=find(p,p[x]);return p[x];}
static void unite(int*p,int*sz,long long*sum,int a,int b){a=find(p,a);b=find(p,b);if(a==b)return;if(sz[a]<sz[b]){int t=a;a=b;b=t;}p[b]=a;sz[a]+=sz[b];sum[a]+=sum[b];}
int main(void){
    int n,m,K;if(scanf("%d %d %d",&n,&m,&K)!=3||n<=0||m<0||K<1){fprintf(stderr,"Input: n m K, then n weights, then m edges\n");return 1;}
    int*p=malloc((size_t)n*sizeof(int)),*sz=malloc((size_t)n*sizeof(int));long long*sum=malloc((size_t)n*sizeof(long long));
    if(!p||!sz||!sum){fprintf(stderr,"Allocation failed\n");free(p);free(sz);free(sum);return 1;}
    for(int i=0;i<n;i++){if(scanf("%lld",&sum[i])!=1){fprintf(stderr,"Invalid weight\n");free(p);free(sz);free(sum);return 1;}p[i]=i;sz[i]=1;}
    for(int i=0;i<m;i++){int u,v;if(scanf("%d %d",&u,&v)!=2||u<1||u>n||v<1||v>n){fprintf(stderr,"Invalid edge\n");free(p);free(sz);free(sum);return 1;}unite(p,sz,sum,u-1,v-1);long long best=0;for(int j=0;j<n;j++)if(find(p,j)==j&&sz[j]<=K&&sum[j]>best)best=sum[j];printf("%lld\n",best);}
    free(p);free(sz);free(sum);return 0;
}
