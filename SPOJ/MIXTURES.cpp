#include <cstdio>
#include <cstring>

#define MAX 101
#define MOD 100
using namespace std;

int array[MAX];
int dp[MAX][MAX]; //dp[a][b] = minimum smoke produced on mixing mixtures a to b


//mod wala sum :p
int sumtillhere(int a, int b){
	int sum = 0;
	for(int i=a;i<=b;i++){
		sum+=array[i];
		sum%=100;
	}
	return sum;
}

//top-down approach is used as base case is dp[i][i] = 0
//top-down approach == memoization
//bottom-up approach == solving sub problems first then proceeding to bigger sub problem

int solveDP(int a, int b){
	int i,temp1,temp2;

	if(dp[a][b]!=-1)
		return dp[a][b];
	if(a==b)
		return 0;
	
	temp1 = dp[a][b];
	for(i=a;i+1<=b;i++){
		temp2 = solveDP(a,i) + solveDP(i+1,b) + sumtillhere(a,i)*sumtillhere(i+1,b);
		if(temp1==-1 || temp2 < temp1)
			temp1 = temp2;
	}
	dp[a][b] = temp1;
	return dp[a][b];

}
int main(){
	int n, i;
	while(scanf("%d", &n)==1){
		for(i=1;i<=n;i++){
			scanf("%d", &array[i]);
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solveDP(1, n));
	}

	return 0;
}