#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int N;
		cin>>N;
		if(N==0){
			break;
		}
		int ans = (N*(N+1)*(2*N + 1))/6;
		cout<<ans<<endl;
	}
	return 0;
}

