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
    vector<int> edgeTo;
    
	public:
        vector<int> edges;
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
                edgeTo.push_back(0);
                edges.push_back(0);
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
    
        void bfs(int v){
		queue<int> Q;
		Q.push(v);
		while(!Q.empty()){
			v = Q.front();
			Q.pop();
			node* w = array[v].head;
			marked[v] = true;
			while(w){
				if(!marked[w->id] && edges[w->id]==0){
					Q.push(w->id);
                    //cout<<v<<"->"<<w->id<<endl;
					//edgeTo[w->id] = v;
                    edges[w->id] = edges[v] + 1;
				}
				w = w->next;
			}
		}
	}
        /*returns whether v has a path from a Breadth first search of s (start node)*/
        bool hasPathTo(int v){
            return marked[v];
        }

        /*forms a stack of path*/
        stack<int> pathTo(int s, int v){
            stack<int> path;
            for(int x=v;x!=s;x=edgeTo[x]){
                path.push(x);
            }
            path.push(s);
            return path;
        }

};

int main() {
    int t,n,m,x,y,s;
    cin>>t;
    while(t--){
        cin>>n>>m;
        Graph g(n+1);
        while(m--){
            cin>>x>>y;
            g.addEdge(x,y);
        }
        cin>>s;
        g.bfs(s);
        for(int i=1;i<=n;i++){
            if(i!=s){
                if(g.hasPathTo(i)){
                    cout<<(g.edges[i])*6<<" ";
                }else{
                    cout<<-1<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
