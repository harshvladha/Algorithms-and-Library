#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	node* next;
};

struct list{
	node *head;
};

class Graph{
	int V;
	public:
		list* array;
	public:
		Graph(int v){
			V = v;

			/*array of adjacency list*/
			array = (list*)malloc(V*sizeof(list));

			/*initialising each adjacency list as empty by making head as NULL */
			for(int i=0;i<V;i++){
				array[i].head = NULL;
			}
		}
		/* can also be written as 
			public:
				Graph(int v):V(v){}
		*/
		int getV(){return V;}

		void addEdge(int a, int b){
			/*add an edge from a to b. A new node is added in the adjacency list of a. The node is added at the beginning */
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

		void printGraph(){
			for(int i=0;i<V;i++){
				node* crawl = array[i].head;
				cout<<"\nAdjacency list of vertex "<<i<<"\n head ";
				while(crawl){
					cout<<"-> "<<crawl->id;
					crawl = crawl->next;
				}
				cout<<endl;
			}
		}
};

class DepthFirstPaths{
	bool marked[];
	int edgeTo[];
	int s; // s implies start
public:
	DepthFirstPaths(Graph G, int s){
		bool marked[G.getV()];
		int edgeTo[G.getV()];
		dfs(G,s);
	}
private:
	void dfs(Graph G, int v){
		marked[v] = true;
		node* w = G.array[v].head;
		while(w){
			if(!marked[w->id]){
				dfs(G,w->id);
				edgeTo[w->id] = v;
			}
			w = w->next;	
		}
	}
public:
	/*returns whether v has a path from a depth first search of s (start node)*/
	bool hasPathTo(int v){
		return marked[v];
	}

	/*forms a stack of path*/
	stack<int> pathTo(int v){
		stack<int> path;
		for(int x=v;x!=s;x=edgeTo[x]){
			path.push(x);
		}
		path.push(s);
		return path;
	}
};

int main(){
	return 0;
}
