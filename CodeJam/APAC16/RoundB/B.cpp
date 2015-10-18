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

int Np[20], Ne[20], Nt[20];


int main(){
	int _t,p,e,t,m,P,Q;
	cin>>_t;
	rep(i,1,_t){
		cin>>p>>e>>t;
		rep(j,1,p){
			cin>>Np[j];
		}
		rep(j,1,e){
			cin>>Ne[j];
		}
		rep(j,1,t){
			cin>>Nt[j];
		}
		cin>>m;
		cout<<"Case #"<<i<<":"<<endl;
		rep(j,1,m){
			int flag = 0;
			cin>>P>>Q;
			P = P/__gcd(P,Q);
			Q = Q/__gcd(P,Q);
			rep(i1,1,p){
				rep(i2,1,e){
					rep(i3,1,e){
						if(i2==i3)
							continue;
						rep(i4,1,t){
							if(Np[i1]*Ne[i3]*P == Ne[i2]*Nt[i4]*Q){
								flag == 1;
								goto Yes;
							}
						}
					}
				}
			}
			//cout<<"j : "<<j<<endl;
			Yes:
				//cout<<"j : "<<j<<endl;
				if(flag==1)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;

		}
	}

	return 0;
}