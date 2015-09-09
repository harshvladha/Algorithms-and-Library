#include <cstdio>
#define MOD 10000007

//equation gets reduced to Zsum = 2(n-1)^k + n^k + 2(n-1)^(n-1) + n^n

using namespace std;

long long power(long long a, long long b){
	long ans = 1;
	while(b){
		if(b&1)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return ans;
}
int main(){
	long long n, k, zsum, a, b, c, d;
	while(true){
		scanf("%lld%lld", &n, &k);
		if(n==0 && k==0)
			break;
		a = (2*power(n-1, k))%MOD;
		b = power(n,k)%MOD;
		c = (2*power(n-1, n-1))%MOD;
		d = power(n, n)%MOD;
		zsum = (a+b+c+d)%MOD;
		printf("%lld\n", zsum);
	}
	return 0;
}