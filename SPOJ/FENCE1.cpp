//AC in one go

#include <bits/stdc++.h>
using namespace std;
int main() {
    while(true){
    	int l;
    	cin>>l;
    	if(l==0)
    		break;
    	float ans = (l*l)/(2*3.1415926);
    	cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}