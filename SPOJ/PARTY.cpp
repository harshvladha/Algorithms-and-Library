#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#define MAX 101
using namespace std;

void knapsack(int cost[], int fun[], int budget, int n){
	int ks[n+1][budget+1], c[n+1][budget+1], i, j, mf, mc;
	
	for(i=0;i<=n;i++){
		for(j=0;j<=budget;j++){
			if(i==0 || j==0){
				ks[i][j] = 0;
				c[i][j] = 0;
			}
			else if(cost[i-1]<=j){
				if(fun[i-1] + ks[i-1][j-cost[i-1]] > ks[i-1][j]){
					ks[i][j] = fun[i-1] + ks[i-1][j-cost[i-1]];
					c[i][j] = cost[i-1] + c[i-1][j-cost[i-1]];
				}else{
					ks[i][j] = ks[i-1][j];
					c[i][j] = c[i-1][j];
				}
			}else{
				ks[i][j] = ks[i-1][j];
				c[i][j] = c[i-1][j];
			}
		}
	}

	mf = ks[n][budget]; //maximum fun which we can have

	//now we have to find minimum cost
	mc = INT_MAX;
	for(j=1;j<=budget;j++){
		if(ks[n][j] == mf){
			if(c[n][j] < mc){
				mc = c[n][j];
			}
		}
	}
	printf("%d %d\n", mc, mf);
}


int main(){
	int cost[MAX], fun[MAX], budget, n, i;
	while(1){
		scanf("%d %d", &budget, &n);
		if(budget==0 && n==0)
			break;
		for(i=0;i<n;i++){
			scanf("%d %d", cost + i, fun + i);
		}
		if(budget==0 || n==0){
			printf("0 0\n");
		}else{
			knapsack(cost, fun, budget, n);
		}
	}
	return 0;
}