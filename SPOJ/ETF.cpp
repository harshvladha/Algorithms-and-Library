#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t,n,ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = n;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				ans -= ans/i;
			}
			while(n%i==0){
				n/=i;
			}
		}
		if(n>1){
			ans-=ans/n;
		}
		printf("%d\n", ans);
	}
	return 0;
}