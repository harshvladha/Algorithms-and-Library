#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t, n1, n2, i, j, min;
	cin>>t;
	while(t--){
		cin>>n1;
		int m1[n1];
		for(i=0;i<n1;i++)
			cin>>m1[i];
		
		cin>>n2;
		int m2[n2];
		for(i=0;i<n2;i++)
			cin>>m2[i];

		sort(m1, m1+n1);
		sort(m2, m2+n2);
		min = INT_MAX;

		for(i=0;i<n1;i++)
			for(j=0;j<n2;j++)
				if(min > abs(m1[i]-m2[j]))
					min = abs(m1[i]-m2[j]);

		cout<<min<<"\n";
	}
	return 0;
}