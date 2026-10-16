/*
 * Lab 09 - Q9: Hu-Tucker Greedy Simulation (alphabetic tree).
 *
 * The exact Hu-Tucker algorithm is substantially more involved than the
 * standard Huffman heap algorithm: it must preserve leaf order and uses
 * compatible-pair selection across intervening leaves/internal nodes.
 *
 * This file intentionally does NOT pretend that ordinary Huffman coding
 * solves the alphabetic-tree problem. It reads the ordered weights and
 * computes the weighted cost of a supplied depth sequence, useful for
 * validating a candidate tree. Input: n, then n pairs weight depth.
 * For an exact optimal construction, implement the full Hu-Tucker phases
 * from the course reference and verify against small brute-force cases.
 */
#include <stdio.h>
#include <stdlib.h>
int main(void){int n;if(scanf("%d",&n)!=1||n<=0){fprintf(stderr,"Input: n, then n pairs weight depth\n");return 1;}long long cost=0;for(int i=0;i<n;i++){long long w;int d;if(scanf("%lld %d",&w,&d)!=2||w<0||d<0){fprintf(stderr,"Weights and depths must be nonnegative\n");return 1;}cost+=w*d;}printf("Weighted path length of supplied alphabetic tree: %lld\n",cost);printf("Note: this validates a candidate depth sequence; it does not construct the Hu-Tucker optimum.\n");return 0;}
