#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int id;
	node* next;
};

struct adjacencylist{
	node *head;
};

class Graph{
	int V;
	vector<bool> marked;
	public:
		adjacencylist* array;

		Graph(int v){
			V = v+1;

			//array of adjacencylist
			array = (adjacencylist*)malloc(V*sizeof(adjacencylist));

			//index of graph start from 1 not 0
			//initialising each adjacencylist as empty by making head as NULL
			for(int i=1;i<V;i++){
				array[i].head = NULL;
			}
			//mark all the nodes as unvisited
			for(int i=1;i<V;i++){
				marked.push_back(false);
			}
		}
		int getV(){return V;}

		void addEdge(int a, int b){
			//add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;
			
			//Graph is undirected so add a edge from b to a
			node* newNode2 = (node*)malloc(sizeof(node));
			newNode2->id = a;
			newNode2->next = array[b].head;
			array[b].head = newNode2;
		}


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
								//vertex
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
};

int main(){
	int t, i, bugs, fucks, j, a, b;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &bugs, &fucks);
		//initialize the graph
		Graph g(bugs);

		//add the fucking edges in the graph -.-
		for(j=0;j<fucks;j++){
			scanf("%d %d", &a, &b);
			g.addEdge(a, b);
		}
		printf("%d: ", i+1);
		if(g.isBipartite())
			printf("usual\n");
		else
			printf("unusal\n");
	}
  	return 0;
}