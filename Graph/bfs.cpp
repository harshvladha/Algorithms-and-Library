#include <bits/stdc++.h>
using namespace std;

class BreadthFirstPaths{
	int s; // s implies start
	
public:
	int V; //vertices of graph
	vector<bool> marked;
	vector<int> edgeTo;
	BreadthFirstPaths(Digraph G, int S){
		s = S;
		V = G.getV();
		for(int i=0;i<V;i++){
			marked.push_back(false);
			edgeTo.push_back(0);
		}
		bfs(G,s);
	}
	void bfs(Digraph G, int v){
		queue<int> Q;
		Q.push(v);
		int count=0;
		while(!Q.empty()){
			v = Q.front();
			Q.pop();
			node* w = G.array[v].head;
			marked[v] = true;
			while(w){
				if(!marked[w->id]){
					Q.push(w->id);
					edgeTo[w->id] = v;
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
	stack<int> pathTo(int v){
		stack<int> path;
		for(int x=v;x!=s;x=edgeTo[x]){
			path.push(x);
		}
		path.push(s);
		return path;
	}
};
