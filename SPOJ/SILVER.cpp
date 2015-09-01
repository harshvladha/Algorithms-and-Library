#include <cstdio>
#include <math.h>
int main(){
	int n;
	while(1){
		scanf("%d", &n);
		if(n==0)
			break;
		printf("%d\n", (int)(log(n)/log(2)));
	}
	return 0;	
}