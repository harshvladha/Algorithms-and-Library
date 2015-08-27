#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	double speeds[n];
	double fuels[n];
	double totalfuel;
	for(int i=0;i<n;i++)
		cin>>speeds[i];
	for(int i=0;i<n;i++)
		cin>>fuels[i];
	cin>>totalfuel;

	double maxDistance=0;

	for(int i=0;i<n;i++){
		if((totalfuel/fuels[i])*speeds[i] > maxDistance)
			maxDistance = (totalfuel/fuels[i])*speeds[i];	
	}	
	cout<<fixed<<std::setprecision(3)<<maxDistance<<endl;
	
	return 0;

}