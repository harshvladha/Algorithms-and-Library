/**
Array based : 1-based index of the BIT
0-based index of the input array

*/
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


int BIT[100000], array[100000], n;

void createBIT(){

	int i,j;
	fill(BIT, 0);
	rep(i,1,n){
		int temp = array[i-1];
		j = i;
		while(j <= n){
			BIT[j] += temp;
			j += (j & (-j));
		}
	}
}

int query(int upto_position){
	int ans = 0;
	int j = upto_position + 1; //because array and query is zero-based
	while(j > 0){
		ans += BIT[j];
		j -= (j & (-j));
	}
	return ans;
}

void update(int index, int value){
	int j = index + 1; //because update query is zero based and BIT is 1-based
	while(j <= n){
		BIT[j] += value;
		j += (j & (-j));
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t, q, x, y, z;
	cin>>t;
	while(t--){
		cin>>n>>q;
		rep(i,1,n){
			cin>>array[i-1];
		}
		createBIT(); // initialize/create the BIT
		rep(i,1,q){
			cin>>x;
			if(x==1){ //update
				cin>>y>>z;
				update(y, z);
			}else{ //query
				cin>>y;
				cout<<query(y)<<endl;
			}
		}
	}
	return 0;
}
