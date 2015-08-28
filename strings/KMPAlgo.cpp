#include <cstdio>
#include <string.h>
#include <stdlib.h>

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
void KMPSearch(char *pattern, char *text){
	int m = strlen(pattern);
	int n = strlen(text);
	//lps array

	int *lps = (int *)malloc(sizeof(int)*m);
	int j = 0; //index for pattern
	int i = 0; //index for text
	//compute values in lps array
	computeLPSArray(pattern, m, lps);
	while(i < n){
		if(pattern[j]==text[i]){
			i++;
			j++;
		}
		if(j==m){
			printf("Found pattern at index %d \n", i-j);
			j = lps[j-1];
		}else if(i < n && pattern[j]!=text[i]){
			if(j!=0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	free(lps);
}

int main(){
	char *txt = "ABABDABACDABABCABAB";
   	char *pat = "ABABCABAB";
  	KMPSearch(pat, txt);
   	return 0;
}