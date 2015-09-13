#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int max(int a, int b){
	return (a>b)?a:b;
}
//recursive approach
int lcsR(char *X, char *Y, int m, int n){
	if(m==0 || n==0){
		return 0;
	}
	if(X[m-1] == Y[n-1])
		return 1 + lcsR(X,Y,m-1,n-1);
	else
		return max(lcsR(X,Y,m,n-1),lcsR(X,Y,m-1,n));
}

//dynamic programming approach - bottom up - tabulation method
int lcsDP(char *X, char *Y, int m, int n){
	int dp[m+1][n+1], i, j;

	//dp[i][j] => length of LCS of X[0..i-1] and Y[0..j-1]

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[m][n];
}
int main(){
	char x[] = "fft";
	char y[] = "tff";
	int m = strlen(x);
	int n = strlen(y);
	printf("length of LCS(Recursive) is %d.\n", lcsR(x,y,m,n));
	printf("length of LCS(DP) is %d.\n", lcsDP(x,y,m,n));
	return 0;
}