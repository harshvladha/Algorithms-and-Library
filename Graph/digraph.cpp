#include <bits/stdc++.h>
using namespace std;

struct node{
	int id;
	node* next;
};

struct adjacencylist{
	node *head;
};

class Digraph{
	int V;
	adjacencylist* array;
	public:
		Digraph(int v){
			V = v;

			/*array of adjacencylist*/
			array = (adjacencylist*)malloc(V*sizeof(adjacencylist));

			/*initialising each adjacencylist as empty by making head as NULL */
			for(int i=0;i<V;i++){
				array[i].head = NULL;
			}
		}
		/* can also be written as 
			public:
				Digraph(int v):V(v){}
		*/
		int getV(){return V;}

		void addEdge(int a, int b){
			/*add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning */
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;
			
		}

		void printDigraph(){
			for(int i=0;i<V;i++){
				node* crawl = array[i].head;
				cout<<"\nAdjacencylist of vertex "<<i<<"\n head ";
				while(crawl){
					cout<<"-> "<<crawl->id;
					crawl = crawl->next;
				}
				cout<<endl;
			}
		}
};
int main(){
  	return 0;
}
