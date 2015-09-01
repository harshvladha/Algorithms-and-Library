#include <cstdio>
#include <deque>
using namespace std;
int main(){
	int n, k, i;
	deque<int> Q;
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d", a+i);
	}
	scanf("%d", &k);
	for(i=0;i<k;i++){
		while((!Q.empty()) && a[Q.back()] <= a[i]){
			Q.pop_back();
		}
		Q.push_back(i);
	}

	while(i<n){
		printf("%d ", a[Q.front()]);
		while((!Q.empty()) && Q.front() <= i-k){
			Q.pop_front();
		}
		while((!Q.empty()) && a[Q.back()] <= a[i]){
			Q.pop_back();
		}
		
		Q.push_back(i);

		i++;
	}
	printf("%d", a[Q.front()]);
	return 0;
}