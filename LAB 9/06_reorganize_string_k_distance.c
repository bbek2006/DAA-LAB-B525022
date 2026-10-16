/* Lab 09 - Q6: Reorganize string so equal characters are at least K positions apart.
 * Input: a string (no spaces), then K. Greedy max-frequency selection with a
 * cooldown queue. Supports ASCII byte characters. Time O(L*256), space O(L+256).
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPH 256
int main(void){
    char s[100005];int K;
    if(scanf("%100000s %d",s,&K)!=2||K<0){fprintf(stderr,"Input: string K (K >= 0)\n");return 1;}
    int f[ALPH]={0},cool[ALPH]={0};for(int i=0;s[i];i++)f[(unsigned char)s[i]]++;
    int L=(int)strlen(s);char*out=malloc((size_t)L+1);if(!out){perror("malloc");return 1;}
    for(int p=0;p<L;p++){
        int best=-1;
        for(int c=0;c<ALPH;c++)if(f[c]>0&&cool[c]<=p&&(best<0||f[c]>f[best]))best=c;
        if(best<0){printf("\n");free(out);return 0;}
        out[p]=(char)best;f[best]--;cool[best]=p+K;
    }
    out[L]='\0';printf("%s\n",out);free(out);return 0;
}
