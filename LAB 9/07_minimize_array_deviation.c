/* Lab 09 - Q7: Minimize array deviation.
 * Standard transformation: make every number even by doubling odds, then
 * repeatedly halve the current maximum while it is even. A max-heap is
 * represented here by a simple scan for clarity. O(n * log(max_value)) time
 * with heap; this scan implementation is O(n * log(max_value)) as each
 * reduction requires O(n) work, hence O(n log(max_value)) reductions? More
 * precisely O(n * R), where R is the number of halvings performed.
 */
#include <stdio.h>
#include <stdlib.h>
long long maxv(long long*a,int n,int*idx){long long m=a[0];*idx=0;for(int i=1;i<n;i++)if(a[i]>m){m=a[i];*idx=i;}return m;}
int main(void){int n;if(scanf("%d",&n)!=1||n<=0){fprintf(stderr,"Input: positive n followed by n positive integers\n");return 1;}long long*a=malloc((size_t)n*sizeof(*a));if(!a){perror("malloc");return 1;}for(int i=0;i<n;i++){if(scanf("%lld",&a[i])!=1||a[i]<=0){fprintf(stderr,"Values must be positive\n");free(a);return 1;}if(a[i]&1)a[i]*=2;}long long ans=0;for(;;){int idx;long long mx=maxv(a,n,&idx),mn=a[0];for(int i=1;i<n;i++)if(a[i]<mn)mn=a[i];if(mx-mn>0&&(!ans||mx-mn<ans))ans=mx-mn;else if(!ans)ans=mx-mn;if((mx&1)||mx==0)break;a[idx]/=2;}printf("Minimum deviation: %lld\n",ans);free(a);return 0;}
