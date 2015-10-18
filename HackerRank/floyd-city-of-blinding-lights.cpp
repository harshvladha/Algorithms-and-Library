#include <bits/stdc++.h>
#define MAX 401
using namespace std;

int t,n,m,x,y,w,s,i,j;
int graph[MAX][MAX];
long dist[MAX][MAX];
long min(long a, long b){
	return (a>b)?b:a;
}
void floydWarshall(){
	int k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = graph[i][j];
		}
	}

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

}
int main(){
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			graph[i][j] = INT_MAX;
	
	t=1;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=m;i++){
			cin>>x>>y>>w;
			graph[x][y] = w;
		}
		floydWarshall();
		cin>>s;
		while(s--){
			cin>>x>>y;
            if (x==y)
                cout<<0<<endl;
			else if(dist[x][y] != INT_MAX)
				cout<<dist[x][y]<<endl;
			else
				cout<<"-1"<<endl;
		}
	}
	return 0;
}