#include <cstdio>
#define MAX 100

char final[] = "ALLIZZWELL";
char graph[MAX+1][MAX+1];
int visited[MAX+1][MAX+1];
int n, m;

bool dfs(int r, int c, int length){
	if(length==10)
		return true;
	visited[r][c] = true;

	//traverse all the 8 direction possible from the current cell
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			int adj_r = r+i, adj_c = c+j;
			if((i==0 && j==0) || adj_r < 0 || adj_r >= n || adj_c < 0 || adj_c >= m || graph[adj_r][adj_c]!=final[length]){
				continue;
			}
			if(visited[adj_r][adj_c])
				continue;
			if(dfs(adj_r, adj_c, length+1)){
				visited[r][c] = false;
				return true;
			}
		}
	}
	visited[r][c] = false;
	return false;
} 

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=0;i<n;i++){
			scanf("%s", graph[i]);
		}

		bool flag = false;
		for(i=0;i<n;i++){
			//printf("%s", graph[i]);
			for(j=0;j<m;j++){
				if(graph[i][j]=='A' && dfs(i,j,1)){
					flag = true;
					break;
				}
			}
		}

		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}