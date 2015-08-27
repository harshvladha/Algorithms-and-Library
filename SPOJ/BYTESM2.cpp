#include <bits/stdc++.h>
using namespace std;
int dp[101][102];

int main(){
	int  i, j, t, h ,w;
	cin>>t;
	while(t--){
		cin>>h>>w;


		for (i = 1; i <= h; i++){
			dp[i][w+1] = 0;
		}

		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				cin>>dp[i][j];
			}
		}

		for(i=h-1;i>0;i--){ //it was i++ that is why I was getting seg fault :/ 
			for(j=1;j<=w;j++){
				dp[i][j] += max(max(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]);
			}
		}
		int ans = 0;
		for(i=0;i<=w;i++){
			ans = max(ans, dp[1][i]);
		}

		cout<<ans<<endl;
	}
	return 0;
}