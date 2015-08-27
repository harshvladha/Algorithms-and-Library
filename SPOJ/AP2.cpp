#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
    	long long x, y, z, n, a, d;
    	cin>>x>>y>>z;

    	n = (2 * z) / (x + y);
    	d = (y - x) / (n - 5);
    	a = x - (2 * d);

    	cout<<n<<endl;
    	long long tt = 0;
    	while(tt < 10){
    		cout<<(a + (tt*d))<<" ";
    		tt++;
    	}
    	cout<<endl;
    }
    return 0;
}