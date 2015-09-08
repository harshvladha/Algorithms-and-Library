#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

bool primes[10010];
//false marked numbers are prime
void sieve(){
	//sqrt of 10010 ~= 100
	for(int i=2;i<=100;i++){
		if(!primes[i]){
			for(int j=i*i;j<=10000;j+=i){
				primes[j] = true;
			}
		}
	}
}
int changeDigitsToNum(int a[]){
	int number=0,i;
	for(i=0;i<4;i++)
		number = number*10 + a[i];

	return number;
}

void changeNumToDigits(int a[], int n){
	int i = 3;
	while(n){
		a[i--] = n%10;
		n/=10;
	}
}

int main(){
	int t, a, b, i, j, k, temp;
	scanf("%d", &t);
	sieve();
	while(t--){
		int digits[4], cost[10010];
		//int parent[10010];
		queue<int> Q;
		memset(cost,-1,sizeof(cost));
		//memset(parent,-1,sizeof(parent));

		scanf("%d %d", &a, &b);
		
		cost[a] = 0;
		//parent[a] = 0;

		Q.push(a);

		while(!Q.empty()){
			int n = Q.front();
			int number;
			//printf("%d\n", n);
			for(i=3;i>=0;i--){
				j = 3;
				changeNumToDigits(digits, n);
				for(j=0;j<10;j++){
					digits[i] = j;
					temp = changeDigitsToNum(digits);
					//temp should be of 4 digit
					if((!primes[temp]) && cost[temp]==-1 && temp>999){
						//printf("Prime : %d\n", temp);
						cost[temp] = cost[n] + 1;
						//parent[temp] = n;
						Q.push(temp);
					}
				}
			}
			Q.pop();
		}
		if(cost[b]==-1)
			printf("Impossible\n");
		else
			printf("%d\n",cost[b]);
	}
	return 0;
}