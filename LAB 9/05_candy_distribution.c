/* Lab 09 - Q5: Candy distribution. Input: n then n ratings.
 * Two passes: left-to-right and right-to-left. Time O(n), space O(n).
 */
#include <stdio.h>
#include <stdlib.h>
int main(void){int n;if(scanf("%d",&n)!=1||n<0){fprintf(stderr,"Input: n followed by n ratings\n");return 1;}int*r=malloc((size_t)n*sizeof(int));long long*c=malloc((size_t)n*sizeof(long long));if(n&&(!r||!c)){fprintf(stderr,"Allocation failed\n");free(r);free(c);return 1;}for(int i=0;i<n;i++)if(scanf("%d",&r[i])!=1){fprintf(stderr,"Invalid rating\n");free(r);free(c);return 1;}for(int i=0;i<n;i++)c[i]=(i>0&&r[i]>r[i-1])?c[i-1]+1:1;for(int i=n-2;i>=0;i--)if(r[i]>r[i+1]&&c[i]<=c[i+1])c[i]=c[i+1]+1;long long sum=0;for(int i=0;i<n;i++)sum+=c[i];printf("Minimum candies: %lld\n",sum);printf("Candies per child:");for(int i=0;i<n;i++)printf(" %lld",c[i]);printf("\n");free(r);free(c);return 0;}
