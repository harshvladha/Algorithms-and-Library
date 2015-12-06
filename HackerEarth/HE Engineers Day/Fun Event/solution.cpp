#include <iostream>
using namespace std;
typedef long long ll;
ll reverse(ll n){
	ll rev = 0;
	while(n){
		rev = rev*10 + n%10;
		n /= 10;
	}
	return rev;
}

ll count(ll n){
	ll base = 1;
	while(base*base <= n)
		base *= 10;
	ll ans = 0;
	while(n >= 10){
		while((base/10) * (base/10) > n)
			base /= 10;
		ll y = n % base;
		if(y){
			ans += y;
			n = n - y + 1;
			ll z = reverse(n);
			if(n!=z)
				n = z;
			else
				n--;
		}else{
			ans++;
			n--;
		}
	}
	return ans + n;
}
int main(){
	int t;
	ll n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}