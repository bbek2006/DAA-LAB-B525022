/* Lab 09 - Q3: Minimum initial fuel / reverse greedy.
 * Input: target_distance initial_fuel n, then n pairs: station_distance fuel_added.
 * Greedy: travel forward, and whenever fuel is insufficient, take the largest
 * available fuel amount among stations already passed. O(n log n) after sorting.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct { long long d,f; } Station;
static int cmp(const void *a,const void *b){const Station*x=a,*y=b;return (x->d>y->d)-(x->d<y->d);}
static void push(long long *h,int *n,long long x){int i=++*n;h[i]=x;while(i>1&&h[i/2]<h[i]){long long t=h[i];h[i]=h[i/2];h[i/2]=t;i/=2;}}
static long long pop(long long *h,int *n){long long r=h[1],x=h[(*n)--];int i=1;while(i*2<=*n){int c=i*2;if(c+1<=*n&&h[c+1]>h[c])c++;if(h[c]<=x)break;h[i]=h[c];i=c;}if(*n)h[i]=x;return r;}
int main(void){
    long long D,F;int n;
    if(scanf("%lld %lld %d",&D,&F,&n)!=3||D<0||F<0||n<0){fprintf(stderr,"Input: D F n, then n station pairs\n");return 1;}
    Station *s=malloc((size_t)n*sizeof(*s));long long *heap=malloc((size_t)(n+2)*sizeof(*heap));
    if(n&&(!s||!heap)){fprintf(stderr,"Allocation failed\n");free(s);free(heap);return 1;}
    for(int i=0;i<n;i++)if(scanf("%lld %lld",&s[i].d,&s[i].f)!=2||s[i].d<0||s[i].f<0){fprintf(stderr,"Invalid station\n");free(s);free(heap);return 1;}
    qsort(s,(size_t)n,sizeof(*s),cmp);
    int hn=0,stops=0;long long pos=0;
    for(int i=0;i<=n;i++){
        long long next=(i==n?D:s[i].d);
        if(next>D)next=D;
        long long need=next-pos;
        while(F<need&&hn){F+=pop(heap,&hn);stops++;}
        if(F<need){printf("-1 (target unreachable)\n");free(s);free(heap);return 0;}
        F-=need;pos=next;
        if(i<n&&s[i].d<=D)push(heap,&hn,s[i].f);
        if(pos==D)break;
    }
    printf("Minimum refuelling stops: %d\n",stops);
    free(s);free(heap);return 0;
}
