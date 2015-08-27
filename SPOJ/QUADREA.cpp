#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main(){
	int t;
	double a,b,c,d,ans,temp;
	scanf("%d", &t);
	while(t--){
		scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
		temp = (a+b+c+d)/2;
		ans = sqrt((temp-a) * (temp-b) * (temp-c) * (temp-d));
		printf("%.2lf\n",ans);
	}
	return 0;
}