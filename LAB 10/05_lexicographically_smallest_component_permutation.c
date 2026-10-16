/*
 * DAA Lab 10 - Q5: Lexicographically Smallest Connected Component Permutation
 * Input: n m; permutation A[1..n]; then m allowed-swap edges u v.
 * For each connected component, sort its values and vertex positions, then
 * place the smallest values at the smallest indices. O((n+m) alpha(n) + n log n)
 * time using global sort by (component root, value/position) in a production
 * version; this simple implementation gathers and sorts each component.
 */
#include <stdio.h>
#include <stdlib.h>
static int find(int*p,int x){if(p[x]!=x)p[x]=find(p,p[x]);return p[x];}
static void unite(int*p,int*sz,int a,int b){a=find(p,a);b=find(p,b);if(a==b)return;if(sz[a]<sz[b]){int t=a;a=b;b=t;}p[b]=a;sz[a]+=sz[b];}
static int cmpInt(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b;return (x>y)-(x<y);}
int main(void){
    int n,m;if(scanf("%d %d",&n,&m)!=2||n<=0||m<0){fprintf(stderr,"Input: n m, permutation, then m edges\n");return 1;}
    int*A=malloc((size_t)n*sizeof(int)),*p=malloc((size_t)n*sizeof(int)),*sz=malloc((size_t)n*sizeof(int)),*out=malloc((size_t)n*sizeof(int)),*pos=malloc((size_t)n*sizeof(int)),*vals=malloc((size_t)n*sizeof(int));
    if(!A||!p||!sz||!out||!pos||!vals){fprintf(stderr,"Allocation failed\n");free(A);free(p);free(sz);free(out);free(pos);free(vals);return 1;}
    for(int i=0;i<n;i++){if(scanf("%d",&A[i])!=1){fprintf(stderr,"Invalid permutation\n");return 1;}p[i]=i;sz[i]=1;out[i]=A[i];}
    for(int i=0;i<m;i++){int u,v;if(scanf("%d %d",&u,&v)!=2||u<1||u>n||v<1||v>n){fprintf(stderr,"Invalid edge\n");return 1;}unite(p,sz,u-1,v-1);}
    unsigned char*done=calloc((size_t)n,1);if(!done){perror("calloc");return 1;}
    for(int i=0;i<n;i++){int root=find(p,i);if(done[root])continue;done[root]=1;int k=0;for(int j=0;j<n;j++)if(find(p,j)==root){pos[k]=j;vals[k]=A[j];k++;}qsort(pos,(size_t)k,sizeof(int),cmpInt);qsort(vals,(size_t)k,sizeof(int),cmpInt);for(int j=0;j<k;j++)out[pos[j]]=vals[j];}
    for(int i=0;i<n;i++)printf("%d%c",out[i],i==n-1?'\n':' ');
    free(A);free(p);free(sz);free(out);free(pos);free(vals);free(done);return 0;
}
