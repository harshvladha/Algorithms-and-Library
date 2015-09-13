#include <cstdio>
#include <climits>
#define MAX 100005
using namespace std;

typedef long long ll;

int trigraph[MAX][5],N,i,j;
ll dp[MAX][5];

ll min(ll a, ll b){
	return (a>b)?b:a;
}

//bottom-up approach dp, solving subproblems first

void solveTriGraph(){
	for(i=0;i<=N;i++)
		for(j=0;j<=3;j++)
			dp[i][j] = LLONG_MAX;

	for(i=1;i<=3;i++)
		dp[1][i] = trigraph[1][i];

	dp[2][1] = trigraph[1][2] + trigraph[2][1];
	dp[2][2] = min((trigraph[1][2] + trigraph[2][2]), (trigraph[1][2] + trigraph[1][3] + trigraph[2][2]));
	dp[2][3] = min((trigraph[1][2] + trigraph[2][3]), (trigraph[1][2] + trigraph[1][3] + trigraph[2][3]));

	for(i=2;i<=N;i++){
		for(j=1;j<=3;j++){
			//traverse all direction possible from the nodes and calculate min
			if(j==1){
				dp[i][j+1] = min(dp[i][j+1], dp[i][j] + trigraph[i][j+1]);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + trigraph[i+1][j]);
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + trigraph[i+1][j+1]);
			}else if(j==2){
				dp[i][j+1] = min(dp[i][j+1], dp[i][j] + trigraph[i][j+1]);
				dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + trigraph[i+1][j-1]);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + trigraph[i+1][j]);
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + trigraph[i+1][j+1]);
			}else{
				dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + trigraph[i+1][j-1]);
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + trigraph[i+1][j]);
			}
		}
	}
}

int main(){
	int t=1;
	while(scanf("%d", &N) == 1 && N){
		for(i=1;i<=N;i++)
			for(j=1;j<=3;j++)
				scanf("%d", &trigraph[i][j]);
		solveTriGraph();
		printf("%d. %lld\n", t++, dp[N][2]);
	}
	return 0;
}