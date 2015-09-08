#include <iostream>
#include <map>
using namespace std;
int main(){
	int t, m, x;
	float n;
	bool flag;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		map<int, int> a;
		map<int, int> :: iterator it;
		flag = false;
		cin>>n;
		m = (int)n;
		for(int i=0;i<m;i++){
			cin>>x;
			a[x]++;
		}

		for(it=a.begin();it!=a.end();it++){
			if((*it).second > n/2){
				if(!flag){
					flag = true;
					cout<<"YES";
				}
				cout<<" "<<(*it).first;
			}
		}
		if(flag){
			cout<<"\n";
			
		}else{
			cout<<"NO"<<"\n";
		}

		cout<<"\n";
	}
	return 0;
}