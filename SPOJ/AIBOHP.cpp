#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 6110
using namespace std;
char s[MAX];
int dp[MAX][MAX];
int max(int a, int b){
	return (a>b)?a:b;
}
int lcsDP(int slen){
	//dp[i][j] => length of LCS of X[0..i-1] and Y[0..j-1]
	for(int i=0;i<=slen;i++){
		for(int j=0;j<=slen;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(s[i-1] == s[slen-j])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[slen][slen];
}
int main(){
	int t, l, lcs;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		l = strlen(s);
		lcs = lcsDP(l);
		printf("%d\n", l-lcs);
	}
	return 0;
}