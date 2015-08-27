#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set> // THIS IS IMPORTANT
using namespace std;


//below time complexity O(n)
bool checkSmart(int n){
	int r;
	while(n){
		r = n%10;
		n = n/10;
		if(r!=5 && r!=8)
			return false;
	}
	return true;
}
int main(){
	int n1,n2,n3;
	cin>>n1;
	int a1[n1];
	for(int i=0;i<n1;i++){
		cin>>a1[i];
	}

	cin>>n2;
	int a2[n1];
	for(int i=0;i<n2;i++){
		cin>>a2[i];
	}

	cin>>n3;
	int a3[n1];
	for(int i=0;i<n3;i++){
		cin>>a3[i];
	}
	set<int> s;
	//three loops because each set has 50 elements, so doesn't matter a lot.
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			for(int k=0;k<n3;k++){
				int num = a3[k]+a2[j]+a1[i];
				if(checkSmart(num)){
					//cout<<num<<endl; to check numbers
					s.insert(num); //in set if same number is enetered again then it will not get inserted, 
					//worst case of insertion is O(logn)
				}
			}
		}
	}
	cout<<s.size()<<endl;

	return 0;
}