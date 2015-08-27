#include <cstdio>
#include <iostream>

using namespace std;
int main(){
	long long t, a, b=0;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &a);
		b = a ^ b;
	}
	printf("%lld\n", b);
	return 0;
}