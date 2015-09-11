#include <cstdio>
typedef long long ll;

int main(){
	ll mnos[500001],k,i,size,p,q;
	bool marked[4000000] = {0};
	mnos[0] = 0;
	marked[0] = 1;
	size = 1;
	while(true){
		scanf("%lld", &k);
		if(k==-1)
			break;
		if(k < size)
			printf("%lld\n", mnos[k]);
		else{
			for(i=size;i<=k;i++,size++){
				p = mnos[i-1] - i;
				q = mnos[i-1] + i;
				if(p > 0 && marked[p] == 0){
					mnos[i] = p;
					marked[p] = 1;
				}else{
					mnos[i] = q;
					marked[q] = 1;
				}
			}
			printf("%lld\n", mnos[k]);
		}
	}
	return 0;
}