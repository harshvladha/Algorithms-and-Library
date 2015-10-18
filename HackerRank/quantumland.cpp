#include <bits/stdc++.h>
using namespace std;
double ans1;

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
	
	public:
		vector<bool> marked;
		adjacencylist* array;
		Graph(int v);
		int getV();
		void addEdge(int a, int b, int weight);
		int isCyclic(int v);
		double evalCycle(int source, int parent);
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

//dfs to check cyclic or not
int Graph::isCyclic(int v){
	int check[V+1];
	memset(check,0,sizeof(check));
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
		node* w = array[v].head;
		marked[v] = true;
		check[v] = 1;
		while(w){
			if(!marked[w->id] ){
				q.push(w->id);
			}else if(marked[w->id] && check[w->id]){
				return w->id;
			}
			w = w->next;
		}
	}
	return -1;
}

double Graph::evalCycle(int source, int parent){
	node* it = array[source].head;
	while(it!=NULL){
		if(it->id != parent){
			return evalCycle(it->id, parent)*(((double)(it->weight))/100.00);
		}else{
			return ((double)(it->weight))/100.00;
		}
	}
	return 0;
}
void Graph::addEdge(int a, int b, int weight){
	/*add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning */
	node* newNode = (node*)malloc(sizeof(node));
	newNode->id = b;
	newNode->weight = weight;
	newNode->next = array[a].head;
	array[a].head = newNode;
	
}
int main(){
	int n,w,p;
	scanf("%d", &n);
	Graph g(n+1);
	for(register int i=1;i<=n;i++){
		scanf("%d %d",&w ,&p);
		g.addEdge(i,w,p);
	}
	
	double ans = 0, temp = 0;
	for(int i=1;i<=n;i++){
		if(!g.marked[i]){
			int a = g.isCyclic(i);
			//cout<<a<<endl;
			if(a!=-1){
				ans+=g.evalCycle(a,a);
			}
		}
	}
	printf("%.2lf\n", ans);

	return 0;
}