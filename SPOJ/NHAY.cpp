#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;
void computeLPSArray(char *pattern, int m, int *lps){
	lps[0] = 0; //lps[0] is always 0	
	//l is length of the previous longest suffix
	int l = 0, i = 1;
	while(i < m){
		if(pattern[i] == pattern[l]){
			l++;
			lps[i] = l;
			i++;
		}else{
			if(l!=0){
				l = lps[l-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main(){
	int m, n, j, pos=0, k;
	char s;
	while(1){
		scanf("%d", &m);
		char pattern[m];
		cin>>pattern;
		int *lps = (int *)malloc(sizeof(int)*m);
		computeLPSArray(pattern, m, lps);
		scanf("%c", &s);
		k = 0; //for main while loop
		j = 0; //index for pattern
		while(scanf("%c", &s)!=EOF){
			if(s=='\n'){
				pos = 0;
				k=1;
				printf("\n");
				break;
			}
			while(1){
				if(s==pattern[j]){
					j++;
					if(j==m){
						printf("%d\n", pos-m+1);
						j = lps[j-1];
					}
					break;
				}else if(j > 0){
					j = lps[j-1];
				}else
					break;
			}
			pos++;
		}
		if(k==0)
			break;
	}
   	return 0;
}