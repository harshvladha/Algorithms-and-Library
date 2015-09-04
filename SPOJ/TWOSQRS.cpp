/*
Fermat theorem:
Every prime number of the form (4*k + 1) can be written as the sum of two squares
*/

#include <cstdio>
#define MAX 1000001
using namespace std;

int main(){
	int t,i,j=0,k;
	unsigned long long n, prime_nos[MAX/10];
	bool sieve[MAX], flag;
	for(i=2;i<MAX;i++){
		if(!sieve[i]){
			prime_nos[j] = i;
			j++;
			k = i;
			while(k+i < MAX){
				sieve[k+i] = 1;
				k+=i;
			}
		}
	}
	//j = total no. of primes
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		if(n==0){
			printf("Yes\n");
			continue;
		}
		flag = 0;
		for(i=0;i<j;i++){
			k = 0;
			while(n%prime_nos[i]==0){
				if(prime_nos[i]%4==3)
					k++; //count no. of factors of the form of (4k + 3)
				n/=prime_nos[i];
			}
			if(k%2!=0){ // (4*k + 3) factors should be of even degree for number to be sum of two squares
				printf("No\n");
				flag = 1;
				break;
			}
		}
		if(!flag && n%4!=3)
			printf("Yes\n");
		else if(!flag)
			printf("No\n");
	}
	return 0;
}