/*
Dynamic Programming Solution..
It can also be done using Binary Search, and Hashing
*/
#include <cstdio>
int max(int a, int b){
	return (a>b)?a:b;
}

int main(){
	int n, m, first[10002], second[10002], i, j;
	while(scanf("%d", &n)==1 && n){

		for(i=1;i<=n;i++)
			scanf("%d", &first[i]);

		scanf("%d", &m);
		for(j=1;j<=m;j++)
			scanf("%d", &second[j]);

		
		for(i=j=1;i<=n || j<=m;){
			if(i<=n && j<=m && first[i]==second[j]){
				first[i] += first[i-1];
				second[j] += second[j-1];
				first[i] = second[j] = max(first[i], second[j]);
				i++;
				j++;
			}else if(second[j] > first[i]){
				first[i] += first[i-1];
				i++;
			}else if(first[i] > second[j]){
				second[j] += second[j-1];
				j++;
			}else if(i>n){
				second[j] += second[j-1];
				j++;
			}else if(j>m){
				first[i] += first[i-1];
				i++;
			}
		}
		printf("%d\n", max(first[n], second[m]));
	}
	return 0;
}