#include <iostream>
#include <cstring>
#define MAX 10002
//#define ll long long
using namespace std;
typedef long long ll;
ll max(ll a, ll b){
	return (a>b)?a:b;
}
ll dp[MAX];

int main(){
	ios::sync_with_stdio(false);
	int t, i, j, n;
	ll coins;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		memset(dp, 0,sizeof(dp));
		for(j=1;j<=n;j++){
			cin>>coins;
			if(j==1)
				dp[j] = coins;
			if(j==2)
				dp[j] = max(coins, dp[j-1]);
			if(j>2)
				dp[j] = max(coins+dp[j-2], dp[j-1]);
		}
		cout<<"Case "<<i+1<<": "<<dp[n]<<"\n";
	}
	return 0;
}
