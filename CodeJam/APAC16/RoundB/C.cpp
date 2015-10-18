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
bool primes[150];

void markMultiples(bool a[], int start, int size){
  int i=2, j;
  while((j=i*start)<=size){
    a[j-1]=1; //not prime mark it as true
    i++;
  }
}
void Sieve(){
  if(MAX >= 2){
     //set all false initially which implies all are prime

    for(int i=1; i<150 ; i++){
      if(!primes[i]){
        markMultiples(primes, i+1, 150);
      }
    }
  }
}

int main(){
	memset(primes, 0, sizeof(primes));
	Sieve();
	int t;
	ll n;
	cin>>t;
	rep(i,1,t){
		cin>>n;
		
		cout<<"Case #"<<i<<": "<<endl;
	}

}