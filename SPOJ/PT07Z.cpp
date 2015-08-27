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
		int total;
	public:
		Graph(int v){
			V = v;

			/*array of adjacencylist*/
			array = (adjacencylist*)malloc(V*sizeof(adjacencylist));
			total = 0;
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

		int dfs(int s){
			int m,m1=-1,m2=-1;
			marked[s] = true;
			node* w = array[s].head;
			
			while(w){
				if(!marked[w->id]){
					m = dfs(w->id);
					if(m>=m1){
						m2 = m1;
						m1 = m;
					}else if(m>m2){
						m2 = m;
					}
				}
				w = w->next;	
			}
			total = max(total, m1+m2+2);
			return (m1 + 1);
		}

};

int main(){
	int N;
	cin>>N;
	Graph g(N);

	int i = 0,u,v;
	while(i < N-1){
		cin>>u>>v;
		g.addEdge(u-1,v-1);
		i++;
	}
	g.dfs(0);
	cout<<g.total<<endl;
	return 0;
}