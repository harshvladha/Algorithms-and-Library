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


/*merge function for mergesort */
long long merge(long long a[],  long long left,  long long middle,  long long right){
  long long i, j, k, count=0;
  long long n1 = middle-left+1;
  long long n2 = right-middle;

  /*temp arrays*/
  long long L[n1],R[n2];

  /* copy data to temp arrays */
  for(i=0;i<n1;i++){
    L[i] = a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = a[middle+1+i];
  }

  /*merge the two temp arrays back*/
  i=0;
  j=0;
  k=left;
  while(i<n1 && j<n2){
  	if(L[i]<=R[j])
  		a[k++]=L[i++];
  	else{
  		a[k++]=R[j++];
  		count+=n1-i;
  	}
  }
  /*copy the remaining elements of L[] if any*/
  while(i<n1){
    a[k++]=L[i++];
  }
  /*copy the remaining elements of R[] if any*/
  while(j<n2){
    a[k++]=R[j++];
  }
  return count;
}

long long mergesort( long long a[],  long long left,  long long right){
	long long count=0;
  if(left < right){
    //split in half
    long long middle = (left + right)/2 ;

    //recursive sorts
    count = mergesort(a, left, middle);
    count += mergesort(a, middle+1, right);

    /*perform merging*/
    count += merge(a, left, middle, right);
  }
  return count;
}


int main(){
	ios::sync_with_stdio(false);
	ll t, n, i, j;
	string s;
	map<string, ll> dict;
	ll a[30001];
	cin>>t;
	while(t--){
		fill(a, 0);
		cin>>n;
		rep(j, 1, n){
			cin>>s;
			dict[s] = j-1;	
		}
		rep(j, 1, n){
			cin>>s;
			a[j-1] = dict[s];
		}
		cout<<mergesort(a,0, n-1)<<endl;
	}
	return 0;
}
