/*
 * Lab 09 - Q2: Huffman coding and canonical codebook.
 * Input: n, then n lines: symbol frequency. Symbols are single non-whitespace
 * characters and must be unique. Output canonical codes ordered by length,
 * then symbol. Uses a binary min-heap; code lengths are derived from Huffman.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 256
typedef struct Node { long long f; int minSym; int left,right; unsigned char sym; int leaf; } Node;
typedef struct { int a[MAXN*2]; int size; Node *nodes; } Heap;
static int lessNode(Heap *h,int x,int y) {
    Node *a=&h->nodes[x], *b=&h->nodes[y];
    return a->f!=b->f ? a->f<b->f : a->minSym<b->minSym;
}
static void push(Heap *h,int x) {
    int i=++h->size; h->a[i]=x;
    while(i>1 && lessNode(h,h->a[i],h->a[i/2])) {
        int t=h->a[i];h->a[i]=h->a[i/2];h->a[i/2]=t;i/=2;
    }
}
static int pop(Heap *h) {
    int out=h->a[1], x=h->a[h->size--], i=1;
    while(i*2<=h->size) {
        int c=i*2; if(c+1<=h->size && lessNode(h,h->a[c+1],h->a[c])) c++;
        if(!lessNode(h,h->a[c],x)) break;
        h->a[i]=h->a[c];i=c;
    }
    if(h->size) h->a[i]=x;
    return out;
}
typedef struct { unsigned char sym; int len; char code[300]; } Entry;
static Entry entries[MAXN];
static int ec;
static void lengths(Node *nodes,int idx,int depth) {
    if(nodes[idx].leaf) { entries[ec].sym=nodes[idx].sym; entries[ec].len=depth?depth:1; ec++; return; }
    lengths(nodes,nodes[idx].left,depth+1); lengths(nodes,nodes[idx].right,depth+1);
}
static int cmpEntry(const void *p,const void *q) {
    const Entry *a=p,*b=q;
    if(a->len!=b->len) return a->len-b->len;
    return (int)a->sym-(int)b->sym;
}
static void increment(char *s,int len) {
    for(int i=len-1;i>=0;i--) { if(s[i]=='0'){s[i]='1';return;} s[i]='0'; }
}
int main(void) {
    int n;
    if(scanf("%d",&n)!=1 || n<1 || n>MAXN){fprintf(stderr,"n must be 1..256\n");return 1;}
    Node *nodes=calloc((size_t)(2*n),sizeof(*nodes));
    if(!nodes){perror("calloc");return 1;}
    Heap h={{0},0,nodes}; int used[256]={0};
    for(int i=0;i<n;i++) {
        char s; long long f;
        if(scanf(" %c %lld",&s,&f)!=2 || f<0 || used[(unsigned char)s]) {
            fprintf(stderr,"Use unique single-character symbols and nonnegative frequencies\n");free(nodes);return 1;
        }
        used[(unsigned char)s]=1;
        nodes[i]=(Node){f,(unsigned char)s,-1,-1,(unsigned char)s,1}; push(&h,i);
    }
    int count=n;
    while(h.size>1) {
        int x=pop(&h),y=pop(&h);
        nodes[count]=(Node){nodes[x].f+nodes[y].f,
            nodes[x].minSym<nodes[y].minSym?nodes[x].minSym:nodes[y].minSym,x,y,0,0};
        push(&h,count++);
    }
    ec=0; lengths(nodes,pop(&h),0); qsort(entries,(size_t)ec,sizeof(Entry),cmpEntry);
    char code[300]; memset(code,'0',sizeof(code)); int prev=entries[0].len;
    for(int j=0;j<prev;j++) code[j]='0'; code[prev]='\0';
    strcpy(entries[0].code,code);
    for(int i=1;i<ec;i++) {
        increment(code,prev);
        int newlen=entries[i].len;
        for(int j=prev;j<newlen;j++) code[j]='0';
        code[newlen]='\0'; prev=newlen;
        strcpy(entries[i].code,code);
    }
    printf("Symbol Frequency CanonicalCode\n");
    for(int i=0;i<ec;i++) {
        long long f=0;
        for(int j=0;j<n;j++) if(nodes[j].sym==entries[i].sym){f=nodes[j].f;break;}
        printf("%c %lld %s\n",entries[i].sym,f,entries[i].code);
    }
    free(nodes); return 0;
}
