#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int c,k,w;
		cin>>c>>k>>w;
		if(c*w<=k)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}