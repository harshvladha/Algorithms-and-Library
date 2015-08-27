#include <bits/stdc++.h>
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
	public:
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

		//dfs to check cyclic or not
		bool isCyclic(int v, int parent){
			//mark the current node as visited
			marked[v] = true;

			//recur for all vertices adjacent to this vertex
			node* it = array[v].head;
			while(it!=NULL){
				//if an adjacent is not visited, then recur for that adjacent
				if(!marked[it->id]){
					if(isCyclic(it->id, v)){
						return true;
					}
				}

				//if an adjacent is visited and not parent of current vertex
				else if(it->id != parent)
					return true;

				it = it->next;
			}

			return false;

		}

		//return true if graph is a tree
		bool isTree(){
			if(isCyclic(0,1))
				return false;

			//check if all component is connected or not

			for(int i=0; i<V; i++)
				if(!marked[i])
					return false;
			return true;
		}

		
};

int main(){
	int n,m;
	cin>>n>>m;
	Graph g(n);
	
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		g.addEdge(a-1, b-1);
	}
    
	if(g.isTree())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
