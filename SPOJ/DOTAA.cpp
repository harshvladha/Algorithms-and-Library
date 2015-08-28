#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int T, n, t, d, healths[501], i;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &t, &d);
		for(i=0;i<n;i++){
			scanf("%d", healths + i);
		}
		sort(healths, healths + n);
		while(i>=0){
			if(healths[i] > d){
				healths[i] -= d;
				--t;
			}else if(healths[i] <= d){
				--i;
			}
			if(!t){
				break;
			}
		}
		if(!t)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}