#include <cstdio>
#include <cmath>
int main(){
	int t;
	double ans, n, i;
	scanf("%d", &t);
	while(t--){
		ans =0;
		scanf("%lf", &n);
		for(i=1;i<=n;i++){
			ans += 1/i;
		}
		ans *= n;
		//ans = ceilf(ans*100)/100;
		printf("%.2lf\n", ans);
	}
	return 0;
}