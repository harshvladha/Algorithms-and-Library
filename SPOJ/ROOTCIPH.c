#include <stdio.h>

int main(){
	int t;
	long long a, b, c, d;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld", &a, &b, &c);
		d = (a*a) - 2*b;
		printf("%lld\n", d);
	}
	return 0;
}