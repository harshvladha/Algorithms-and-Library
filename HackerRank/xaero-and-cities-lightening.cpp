#include <bits/stdc++.h>
using namespace std;
bool lights[500001];
struct node{
	int id;
	node* next;
};

struct adjacencylist{
	node *head;
};

class Graph{
	int V;
	
	public:
        vector<bool> marked;
		adjacencylist* array;
	public:
        int isBipartite();
		Graph(int v){
			V = v;

			/*array of adjacencylist*/
			array = (adjacencylist*)malloc(V*sizeof(adjacencylist));

			/*initialising each adjacencylist as empty by making head as NULL */
			for(int i=0;i<V;i++){
				array[i].head = NULL;
			}
			for(int i=0;i<V;i++){
				marked.push_back(false);
			}
		}
		int getV(){return V;}

		void addEdge(int a, int b){
			/*add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning */
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;
			
			/*Graph is undirected so add a edge from b to a */
			node* newNode2 = (node*)malloc(sizeof(node));
			newNode2->id = a;
			newNode2->next = array[b].head;
			array[b].head = newNode2;
		}
        int bfs(int v){
            queue<int> Q;
            Q.push(v);
            int count=0;
            while(!Q.empty()){
                v = Q.front();
                Q.pop();
                node* w = array[v].head;
                marked[v] = true;
                while(w){
                    if(!marked[w->id]){
                    	if(!lights[w->id] && lights[v])
                    		count+=1;
                        //Q.push(w->id);
                    }
                    w = w->next;
                }
            }
            return count;
        }
};

int Graph::isBipartite(){

	//assign initial color -1 to each vertex
	int count = 0;
	
	queue<int> Q;
	for(int v=1;v<V;v++){
		//for non-strongly connected components
		//which are not reachable
		if(!marked[v]){

			//assign color 1 to each dis-connected components source node

			Q.push(v);
			while(!Q.empty()){
				v = Q.front();
				Q.pop();
				node* w = array[v].head;
				marked[v] = true;
				while(w){
					if(!marked[w->id]){
						//assign alternate color to this adjacent or neighbour
						//node
						if(lights[w->id] != 1 - lights[v]){
							count++;
						}
						Q.push(w->id);
					}
					w = w->next;
				}
			}
		}
	}
	//no neighbours have same colors
	return count;
	}

int main(){
	int t,n,u,v;
	cin>>t;
	while(t--){
		int count=0;
		memset(lights, 0, sizeof(lights));
		cin>>n;
        Graph g(n+1);
		for(int i=1;i<=n;i++){
			cin>>lights[i];
		}
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			g.addEdge(u,v);
		}
		count = g.isBipartite();
		cout<<count<<endl;
		
		//free(g);
	}

}