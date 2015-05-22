#include <bits/stdc++.h>
using namespace std;

class DepthFirstPaths{	
	int s; // s implies start
public:
	int V; //vertices of graph
	vector<bool> marked;
	vector<int> edgeTo;
	DepthFirstPaths(Graph G, int S){
		s = S;
		V = G.getV();
		for(int i=0;i<V;i++){
			marked.push_back(false);
			edgeTo.push_back(0);
		}
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
