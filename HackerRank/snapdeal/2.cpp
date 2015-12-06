
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

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T min(T a, T b) { re (a > b) ? b : a; }
template<class T> T max(T a, T b) { re (a > b) ? a : b; }


int cities[2510][2510];
int n, m, i, j, k, x, y, z;

ll traverseR(int a, int b){
	if(a==n-1 && b==m-1){
		//cout<<"n : "<<a<<" m : "<<b<<endl;
		return cities[a][b];
	}
	//cout<<"n : "<<a<<" m : "<<b<<endl;
	ll c1,c3,c2;
	if(a+1<n && b+1<m)
		c1 = (cities[a][b]*traverseR(a+1,b+1))%MOD;
	else
		c1 = 0;

	if(a+1<n)
		c2 = (cities[a][b]*traverseR(a+1,b))%MOD;
	else
		c2 = 0;

	if(b+1<m)
		c3 = (cities[a][b]*traverseR(a,b+1))%MOD;
	else
		c3 = 0;

	return (c1 + c2 + c3)%MOD;
}

ll traverse(){
	ll ans = 0;
	//rep(i)
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	fill(cities,0);

	cin>>n>>m;
	rep(i,0,n-1){
		rep(j,0,m-1){
			cin>>cities[i][j];
		}
	}
	cout<<traverseR(0,0)<<endl;
	return 0;
}