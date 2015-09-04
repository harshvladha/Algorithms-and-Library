#include <cstdio>
#include <climits>
#define MAX 105

int min(int a, int b){
	return (a>b)?b:a;
}

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int dp[MAX][MAX], a[MAX][MAX]={0};
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0;i<=n+1;i++){
		a[i][0] = a[i][m+1] = INT_MAX;
	}
	for(i=1;i<=n+1;i++){
		for(j=1;j<=m;j++){
			dp[i][j] = min(dp[i-1][j+1] + a[i-1][j+1], min(dp[i-1][j-1] + a[i-1][j-1], dp[i-1][j] + a[i-1][j]));
			//printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	i = INT_MAX;
	for(j=1;j<=m;j++){
		if(dp[n+1][j] < i)
			i = dp[n+1][j];
	}

	printf("%d\n", i);
	return 0;
}