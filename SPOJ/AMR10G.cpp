#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool desc(int i, int j){
	return (i>j);
}
int main(){
	int t, k, n, i, j;
	vector<int> heights;
	scanf("%d", &t);
	while(t--){
		heights.clear();
		scanf("%d %d", &n, &k);
		for(i=0;i<n;i++){
			scanf("%d", &j);
			heights.push_back(j);
		}
		sort(heights.begin(), heights.end(), desc);
		/*
		for(i=0;i<n;i++){
			printf("%d ", heights[i]);
		}
		*/
		j = 1000000000;
		for(i=0;i<=n-k;i++){
			if(heights[i]-heights[i+k-1] < j){
				j = heights[i]-heights[i+k-1];
			}
		}
		printf("%d\n", j);
	}
}