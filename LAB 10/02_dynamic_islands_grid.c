/*
 * DAA Lab 10 - Q2: Dynamic Connected Components in a Grid (Number of Islands II)
 * Input: R C K, followed by K coordinate pairs r c (1-based).
 * After each addition, print the number of 4-directionally connected islands.
 * DSU with path compression and union by size: O(K alpha(R*C)) time,
 * O(R*C) space.
 */
#include <stdio.h>
#include <stdlib.h>

static int find(int *p,int x){while(p[x]!=x){p[x]=p[p[x]];x=p[x];}return x;}
static int unite(int *p,int *sz,int a,int b){
    a=find(p,a);b=find(p,b);if(a==b)return 0;
    if(sz[a]<sz[b]){int t=a;a=b;b=t;}
    p[b]=a;sz[a]+=sz[b];return 1;
}
int main(void){
    int R,C,K;
    if(scanf("%d %d %d",&R,&C,&K)!=3||R<=0||C<=0||K<0||(long long)R*C>2000000000LL){
        fprintf(stderr,"Input: R C K, then K row column pairs\n");return 1;
    }
    int N=R*C;
    int *p=malloc((size_t)N*sizeof(*p)),*sz=malloc((size_t)N*sizeof(*sz));
    unsigned char *land=calloc((size_t)N,1);
    if(!p||!sz||!land){fprintf(stderr,"Allocation failed\n");free(p);free(sz);free(land);return 1;}
    for(int i=0;i<N;i++){p[i]=i;sz[i]=1;}
    int islands=0;
    const int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
    for(int t=0;t<K;t++){
        int r,c;
        if(scanf("%d %d",&r,&c)!=2||r<1||r>R||c<1||c>C){fprintf(stderr,"Invalid coordinate\n");free(p);free(sz);free(land);return 1;}
        int x=(r-1)*C+(c-1);
        if(!land[x]){
            land[x]=1;islands++;
            for(int d=0;d<4;d++){
                int nr=r-1+dr[d],nc=c-1+dc[d];
                if(nr>=0&&nr<R&&nc>=0&&nc<C){
                    int y=nr*C+nc;
                    if(land[y]&&unite(p,sz,x,y))islands--;
                }
            }
        }
        printf("%d%c",islands,t==K-1?'\n':' ');
    }
    if(K==0)printf("\n");
    free(p);free(sz);free(land);return 0;
}
