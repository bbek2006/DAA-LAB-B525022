/* Lab 09 - Q8: Minimum meeting rooms.
 * Input: n followed by n start/end pairs. Meetings with end == next start
 * can reuse a room. Sort starts and ends independently. O(n log n) time.
 */
#include <stdio.h>
#include <stdlib.h>
static int cmp(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b;return (x>y)-(x<y);}
int main(void){int n;if(scanf("%d",&n)!=1||n<0){fprintf(stderr,"Input: n then n start end pairs\n");return 1;}int*s=malloc((size_t)n*sizeof(int)),*e=malloc((size_t)n*sizeof(int));if(n&&(!s||!e)){fprintf(stderr,"Allocation failed\n");free(s);free(e);return 1;}for(int i=0;i<n;i++)if(scanf("%d %d",&s[i],&e[i])!=2||e[i]<s[i]){fprintf(stderr,"Invalid interval\n");free(s);free(e);return 1;}qsort(s,(size_t)n,sizeof(int),cmp);qsort(e,(size_t)n,sizeof(int),cmp);int rooms=0,maxrooms=0,i=0,j=0;while(i<n){if(j<n&&s[i]>=e[j]){rooms--;j++;}else{rooms++;i++;if(rooms>maxrooms)maxrooms=rooms;}}printf("Minimum rooms required: %d\n",maxrooms);free(s);free(e);return 0;}
