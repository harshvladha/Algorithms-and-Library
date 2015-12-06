#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define rep(i, begin, end) for(__typeof(begin) i = (begin); i != (end) + 1 - 2 * ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define MAX 10000000 //10^7
#define MOD 1000000007 // 10^9+7
#define endl "\n" //faster endl..
#define in scanf
#define out printf

using namespace std;                         

typedef long long ll;
typedef long double ld;
typedef double D;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> matrix;

template<class T> T _abs(T x) { re x > 0 ? x : -x; }
template<class T> T _min(T a, T b) { re (a > b) ? b : a; }
template<class T> T _max(T a, T b) { re (a > b) ? a : b; }

int n, k, i, j, l;
int price[101];
int dp[101];

int solvedp(){
	int ans = 0;
	dp[0] = 0;
	rep(i, 1, k){

		if(price[i]==-1)
			continue;

		rep(j, i, k){
			if(dp[j-i] == -1)
				continue;
			if(dp[j] == -1)
				dp[j] = price[i] + dp[j-i];
			else
				dp[j] = min(dp[j], price[i] + dp[j-i]);

			//out("j:%d %d\n",j, dp[j]);
		}
		/*
		rep(l,0,k){
			out("%d ", dp[l]);
		}
		out("\n");
		in("%d",&l);
		*/
	}
	ans = dp[k];
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t, temp;
	in("%d", &t);
	while(t--){
		fill(price, 0);
		fill(dp, -1);
		in("%d %d", &n, &k);
		rep(i,1,k){
			in("%d",&price[i]);
		}

		out("%d\n", solvedp());
	}
	return 0;
}
