#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1005
typedef long long ll;
using namespace std;
ll t, n, k, p;
ll A[MAX], B[MAX], dp[1005][300];

ll solvedp(ll i, char stair) {
    if(n == 1){
    	return min(A[0], B[0]);
    }
    if(i == n-1){
    	return stair == 'a' ? A[i] : B[i];
    }
    if(i >= n){
    	return 0;
    }
    if(dp[i][stair] != INT_MAX){
    	return dp[i][stair];	
    } 
    ll include = LLONG_MAX;
    ll exclude = LLONG_MAX;
    if(stair == 'a') {
    	for(int j=1;j<=k;j++){
    		if(i+j < n) 
    			exclude = min(exclude, A[i] + solvedp(i+j, 'a'));
    	}
    	for(int j=1;j<=k;j++){
    		if(i+j < n) 
    			include = min(include, A[i] + p + solvedp(i+j, 'b'));
    	}

        return dp[i][stair] = min(include, exclude);
    }
    else {
    	for(int j=1;j<=k;j++){
    		if(i+j < n) 
    			exclude = min(exclude, B[i] + solvedp(i+j,'b'));
    	}
        for(int j=1;j<=k; j++){
        	if(i+j < n)
          		include = min(include, B[i] + p + solvedp(i+j,'a'));
        }        	
        return dp[i][stair] = min(include, exclude);
    }
}



int main(){
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &k, &p);
		for(int i=0;i<n;i++){
			scanf("%lld", &A[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%lld", &B[i]);
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=300;j++){
				dp[i][j] = INT_MAX;
			}
		}
		ll ans = min(solvedp(0, 'a'), solvedp(0, 'b'));
		printf("%lld\n", ans);
	}
	return 0;
}