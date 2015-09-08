bool isBipartite(){

			//assign initial color -1 to each vertex
			int colorOfVertex[V];
			for(int i=1;i<V;i++){
				colorOfVertex[i]=-1;
			}
			queue<int> Q;
			for(int v=1;v<V;v++){
				//for non-strongly connected components
				//which are not reachable
				if(!marked[v]){

					//assign color 1 to each dis-connected components source node
					colorOfVertex[v] = 1;

					Q.push(v);
					while(!Q.empty()){
						v = Q.front();
						Q.pop();
						node* w = array[v].head;
						marked[v] = true;
						while(w){
							if(!marked[w->id] && colorOfVertex[w->id]==-1){
								//assign alternate color to this adjacent or neighbour
								//node
								colorOfVertex[w->id] = 1 - colorOfVertex[v];
								Q.push(w->id);
							}
							else if(colorOfVertex[w->id] == colorOfVertex[v]){
								//neighbour color is same
								//not a bipartite
								return false;
							}
							w = w->next;
						}
					}
				}
			}
			//no neighbours have same colors
			return true;
		}