#include <cstdio>

unsigned long long gcd(unsigned long long a, unsigned long long b){
	unsigned long long k;
	while(b){
		a%=b;
		k=a;
		a=b;
		b=k;
	}
	return a;
}

int main(){
	int t;
	unsigned long long a, b, c, x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &a, &b);
		c = gcd(a, b);
		y = a/c;
		x = b/c;
		printf("%lld %lld\n", x, y);
	}
	return 0;
}