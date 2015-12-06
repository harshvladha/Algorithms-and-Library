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


int t,T,n,k;
int blueberries[1001];
int dp[1001][1001];
int solveDP(int i, int bb){
	if(i > n)
		return bb;
	if(dp[i][bb]!=-1)
		return dp[i][bb];
	if((blueberries[i]+bb) <= k)
		dp[i][bb] = _max(solveDP(i+2,blueberries[i]+bb), solveDP(i+1,bb));
	else
		dp[i][bb] = solveDP(i+1, bb);
	return dp[i][bb];
}
int main(){
	ios::sync_with_stdio(false);
	in("%d",&t);
	rep(T,1,t){
		fill(dp,-1);
		fill(blueberries,0);
		in("%d %d", &n, &k);
		rep(i,1,n){
			in("%d",&blueberries[i]);
		}
		out("Scenario #%d: %d\n", T, solveDP(1,0));
	}
	return 0;
}
