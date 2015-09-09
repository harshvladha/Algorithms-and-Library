#include <cstdio>
#include <cstring>
#define MAX 52

char graph[MAX][MAX];
int distance[MAX][MAX];

int n, m;

int max(int a, int b){
	return (a>b)?a:b;
}

int dfs(int r, int c){
	if(distance[r][c]!=-1)
		return distance[r][c];
	
	distance[r][c] = 0; //marked visited and distance also, -1 implies not visited

	//traverse all the 8 direction possible from the current cell
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			int adj_r = r+i, adj_c = c+j;
			if((i==0 && j==0) || adj_r < 0 || adj_r >= n || adj_c < 0 || adj_c >= m){
				continue;
			}
			if(graph[adj_r][adj_c] == graph[r][c]+1){
				distance[r][c] = max(distance[r][c], 1 + dfs(adj_r, adj_c));
			}
		}
	}
	return distance[r][c];
}

int main(){
	int t = 1,i,j;
	while(true){
		scanf("%d %d", &n, &m);
		if(n==0 || m==0)
			break;

		for(i=0;i<n;i++){
			scanf("%s", graph[i]);
		}
		
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				distance[i][j] = -1;

		int length = 0;
		bool flag = false;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(graph[i][j]=='A' && distance[i][j]==-1){
					flag = true;
					length = max(length, dfs(i, j));
				}
			}
		}
		if(flag)
			printf("Case %d: %d\n", t++, length + 1);
		else
			printf("Case %d: 0\n", t++);
	}
	return 0;
}