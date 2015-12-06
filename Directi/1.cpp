#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main() {
    long long t;
    cin>>t;
    while(t--){
    	long long N;
    	cin>>N;
    	long long a[N];
    	int b[N];
    for(long long i=0;i<N;i++){
    	cin>>a[i];
    }
    b[0] = a[0];
    long long ans = 0;
    for(int i =1 ;i < N; i ++){
    	if(a[i] > b[i-1]){
    		b[i] = b[i-1];
    		ans++;
    	}else{
    		b[i] = a[i];
    	}
    }
    cout<<ans<<endl;
    }
    return 0;
}