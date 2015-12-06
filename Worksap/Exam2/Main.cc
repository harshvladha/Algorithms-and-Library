/**
	@package Worksap
	@name Exam2
	@description Undirected Graph and BFS
	@author Harsh Vardhan Ladha, 12-1-5-003
	@email harsh.ladha@gmail.com	
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <climits>

#define endl "\n"

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

	//maintains distance of nearest festive city for each city
	vector<int> festive;
	adjacencylist* array;
	
	public:
		queue<int> bfsQueue;
		Graph(int v);
		~Graph();
		int getV(){return V;}
		void addEdge(int a, int b);
		void updateCities();
		void makeFestive(int city){ festive[city] = 0; }
		int distFestive(int city){ return festive[city]; }
};

Graph::Graph(int v){
	V = v;

	/*
	array of adjacencylist
	dynamic memory, adjaceny list graph
	*/
	array = (adjacencylist*)malloc(V*sizeof(adjacencylist));

	/*initialising each adjacencylist as empty by making head as NULL */
	for(int i=0;i<V;i++){
		array[i].head = NULL;
	}
	//mark all city non-festive, initially, by giving them distance of INT_MAX
	for(int i=0;i<V;i++){
		festive.push_back(INT_MAX);
	}

	//declare first city as festive
	bfsQueue.push(1);
	//so its distance for nearest festive city becomes 0
	makeFestive(1);
}
Graph::~Graph(){
	//remove dynamic allocated memory, and mark pointer as NULL
	delete[] array;
	array = NULL;
}
void Graph::addEdge(int a, int b){
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
void Graph::updateCities(){
	int currentCity;

	/* 
		for all the city which needs to be announced as festive
		update distances for their childs to now maintain nearest festive city
		 if the new distance is less than the previous distance
	*/
	while(!bfsQueue.empty()){
		currentCity = bfsQueue.front();
		
		bfsQueue.pop();
		node* w = array[currentCity].head;
		while(w){
			// bfs only till we're getting cities whose new festive distance is shorter than earlier
			if(festive[w->id] > festive[currentCity] + 1){	
				festive[w->id] = festive[currentCity] + 1;
				bfsQueue.push(w->id);
			}
			w = w->next;
		}
	}

}
int main(){
	int n, m, t, a, b, q, c;
	bool flag = true; //for checking whether new city is announced as festive
	cin>>n>>m;
	/*
	if(n<2 || m < 1)
		return 0;
	*/
	Graph g(n+1); //1-based indexed nodes
	t = n - 1; //n-1 edges
	while(t--){
		cin>>a>>b;
		g.addEdge(a,b);
	}
	while(m--){
		cin>>q>>c;
		if(q==1){
			g.makeFestive(c);
			g.bfsQueue.push(c); //maintain queue for all city needed to be declared as festive
			flag = true; //some city is announced festive
		}
		else if(q==2){
			if(flag == true){ //few cities announed festive
				g.updateCities(); //update distances for all the cities from the bfsQueue
				flag = false;
			}
			cout<<g.distFestive(c)<<endl;
		}
	}

	return 0;
}