#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 2001
using namespace std;

int dp[MAX][MAX];
int a[1001];

int solvedp(int start, int end, int day){
	if(start > end)
		return 0;
	if(dp[start][end]!=-1)
		return dp[start][end];
	dp[start][end] = max((solvedp(start+1, end, day+1) + a[start]*day), (solvedp(start, end-1, day+1) + a[end]*day));
	return dp[start][end];
}

int main(){
	int n,i;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for(i=0;i<n;i++){
		scanf("%d", a + i);
	}
	printf("%d\n", solvedp(0, n-1, 1));
	return 0;
}