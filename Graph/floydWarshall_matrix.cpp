//dynamic programming solution

//O(V^3)

//n == V

void floydWarshall(){
	int k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dist[i][j] = graph[i][j];
			//cout<<dist[i][j]<<" ";
		}
		//cout<<endl;
	}

	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

}