#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull gcd(ull a, ull b)
{
	ull k;
	while(b)
	{
		a %= b;
		k = a;
		a = b;
		b = k;
	}
	return a;
}

ull nCr(ull n, ull r)
{
	ull i, j, g, k = (r > n-r)? r : n-r, m = n-k, hor = 1, lob = 1;
	for(i=k+1, j=m; i<=n && j>0; i++, j--)
	{
		hor *= j;
		lob *= i;
		g = gcd(lob, hor);
		lob /= g;
		hor /= g;
	}
	return lob;
}


int main(){
	int t;
	cin>>t;
	ull n, k, ans, a, b, c;
	while(t--){
		cin>>n>>k;
		cout<<nCr(n-1,k-1)<<endl;
	}
	return 0;
}