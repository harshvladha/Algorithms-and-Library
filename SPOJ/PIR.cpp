#include <iostream>
#include <cmath> //pow //sqrt
#include <iomanip>
#include <cstdio>
using namespace std;
int main(){
	int t;
	double ab, ac, ad, bc, bd, cd, sa, base=12, volume;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>ab>>ac>>ad>>bc>>bd>>cd;
		sa = 4*(pow(ab,2)*pow(ac,2)*pow(ad,2)) - pow(ab,2)*pow((pow(ac,2)+pow(ad,2)-pow(cd,2)),2) - pow(ac,2)*pow((pow(ad,2)+pow(ab,2)-pow(bd,2)),2) - pow(ad,2)*pow((pow(ab,2)+pow(ac,2)-pow(bc,2)),2) + (pow(ac,2)+pow(ad,2)-pow(cd,2))*(pow(ad,2)+pow(ab,2)-pow(bd,2))*(pow(ab,2)+pow(ac,2)-pow(bc,2));
		volume = sqrt(sa);
		volume = volume/base;
		printf("%.4lf\n",volume);
	}
	return 0;
}