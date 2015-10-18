#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll n,m;
ll a[55], dp[255][55];

ll solveDP(){
    for(ll i=1;i<=m;i++){
        dp[0][i] = 1;
    }
    for(ll i=1;i<=n;i++){
        dp[i][0] = 0;
        for(ll j=1;j<=m;j++){
            ll value = dp[i][j-1];
            if(a[j-1] <= i){
                value += dp[i - a[j-1]][j];
            }
            dp[i][j] = value;
        }
    }
    return dp[n][m];
}
int main() {
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<m;i++)
        cin>>a[i];
    cout<<solveDP()<<endl;
    return 0;
}