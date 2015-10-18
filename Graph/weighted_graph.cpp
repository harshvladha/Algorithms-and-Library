#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	int weight;
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
		Graph(int v);
		int getV();
		void addEdge(int a, int b, int weight);
};

Graph::Graph(int v){
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

int Graph::getV(){
	return V;
}
void Graph::addEdge(int a, int b, int weight){
	/*add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning */
	node* newNode = (node*)malloc(sizeof(node));
	newNode->id = b;
	newNode->weight = weight;
	newNode->next = array[a].head;
	array[a].head = newNode;
	
	/*Graph is undirected so add a edge from b to a */
	node* newNode2 = (node*)malloc(sizeof(node));
	newNode2->id = a;
	newNode2->weight = weight;
	newNode2->next = array[b].head;
	array[b].head = newNode2;
}

int main(){

	return 0;
}