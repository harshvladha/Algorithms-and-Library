#include <bits/stdc++.h>
using namespace std;
#define MAX 182

struct node{
	int x, y, distance;
	node(int _x, int _y, int _distance){
		x = _x;
		y = _y;
		distance = _distance;
	}
};

int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};

int main(){
	int t, n, m, i, j, k, l;
	cin>>t;
	char d[MAX][MAX];
	int final[MAX][MAX];
	int visited[MAX][MAX];
	while(t--){
		cin>>n>>m;
		queue<node> Q;

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>d[i][j];
				final[i][j] = 0;
				visited[i][j] = 0;
				if(d[i][j]=='1'){
					Q.push(node(i,j,0));
				}
			}
		}
		//apply bfs start from 1 and where there is 0 mark the count value there and in place of 1 write 1
		

		while(!Q.empty()){
			node temp = Q.front();
			Q.pop();
			i = temp.x;
			j = temp.y;
			k = temp.distance;
			
			if(visited[i][j]){
				continue;
			}
			final[i][j] = k;
			visited[i][j] = 1;

			for(l=0;l<4;l++){
				if(i+dx[l] >= 0 && j+dy[l] >= 0 && i+dx[l] < n && j+dy[l] < m){
					Q.push(node(i+dx[l], j+dy[l], k+1));
				}
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				cout<<final[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}