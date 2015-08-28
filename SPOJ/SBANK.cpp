#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
	int t, n, i;
	string ac;
	map<string, int> :: iterator it;
	scanf("%d", &t);
	while(t--){
		map<string, int> accounts;
		scanf("%d\n", &n);
		for(i=0;i<n;i++){
			getline(cin, ac);
			accounts[(string)ac]++;
		}
		for(it=accounts.begin(); it!=accounts.end(); it++){
			printf("%s%d\n", (*it).first.c_str(), (*it).second);
		}
		if(t>1)
			printf("\n");
	}
	return 0;
}