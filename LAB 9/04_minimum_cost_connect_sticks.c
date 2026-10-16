/* Lab 09 - Q4: Minimum cost to connect sticks. Input: n then n nonnegative lengths.
 * Repeatedly combine two smallest lengths using a min-heap. O(n log n).
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct{long long *a;int n;}Heap;
static void push(Heap*h,long long x){int i=++h->n;h->a[i]=x;while(i>1&&h->a[i]<h->a[i/2]){long long t=h->a[i];h->a[i]=h->a[i/2];h->a[i/2]=t;i/=2;}}
static long long pop(Heap*h){long long r=h->a[1],x=h->a[h->n--];int i=1;while(i*2<=h->n){int c=i*2;if(c+1<=h->n&&h->a[c+1]<h->a[c])c++;if(h->a[c]>=x)break;h->a[i]=h->a[c];i=c;}if(h->n)h->a[i]=x;return r;}
int main(void){int n;if(scanf("%d",&n)!=1||n<0){fprintf(stderr,"Input: n followed by n lengths\n");return 1;}Heap h={malloc((size_t)(n+2)*sizeof(long long)),0};if(!h.a){perror("malloc");return 1;}for(int i=0;i<n;i++){long long x;if(scanf("%lld",&x)!=1||x<0){fprintf(stderr,"Lengths must be nonnegative\n");free(h.a);return 1;}push(&h,x);}long long total=0;while(h.n>1){long long x=pop(&h),y=pop(&h),z=x+y;total+=z;push(&h,z);}printf("Minimum total cost: %lld\n",total);free(h.a);return 0;}
