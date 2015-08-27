#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int i = 1;
	while(i <= t){
		long long r;
		double ans;
		cin>>r;
		ans = double(4*r*r)+0.25;
		cout<<"Case "<<i++<<": "<<fixed<<setprecision(2)<<ans<<endl;

	}
	return 0;
}