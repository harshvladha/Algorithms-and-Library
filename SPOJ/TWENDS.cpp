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

int t = 1, n, x, total;
int a[1001];
int dp[1001][1001];

int solve(int i, int j){
	int side1, side2;
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	//picking a[i] --> player1
	if(a[i+1] >= a[j])
		side1 = a[i] + solve(i+2,j);
	else
		side1 = a[i] + solve(i+1,j-1); 

	/// OR ////
	
	//picking a[j] --> player1
	if(a[i] >= a[j-1])
		side2 = a[j] + solve(i+1,j-1);
	else
		side2 = a[j] + solve(i,j-2);

	dp[i][j] = _max(side1,side2);

	return dp[i][j];

}
int main(){
	ios::sync_with_stdio(false);
	while(1){
		in("%d", &n);
		if(n){
			fill(a,0);
			fill(dp,-1);
			total = 0;
			rep(i,0,n-1){
				in("%d",&a[i]);
				total += a[i];
			}
			int player1 = solve(0, n-1);
			int player2 = total - player1;
			int ans = player1 - player2;
			out("In game %d, the greedy strategy might lose by as many as %d points.\n", t++, (2*player1 - total));
		}
		else{
			break;
		}
		
	}
	return 0;
}
