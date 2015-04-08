#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
	int id;
	node* next;
};

struct list{
	node *head;
};

class digraph{
	int V;
	list* array;
	public:
		digraph(int v){
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
				graph(int v):V(v){}
		*/
		int getV(){return V;}

		void addEdge(int a, int b){
			/*add an edge from a to b. A new node is added in the adjacency list of a. The node is added at the beginning */
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;
			
		}

		void printDigraph(){
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
int main(){
	int V = 5;
	digraph g1(V);
	g1.addEdge(0,1);
	g1.addEdge(0,4);
	g1.addEdge(1,2);
	g1.addEdge(1,3);
	g1.addEdge(1,4);
	g1.addEdge(2,3);
	g1.addEdge(3,4);

	digraph g2(3);
	g2.addEdge(0,1);
	g2.addEdge(1,2);

	g1.printDigraph();
	g2.printDigraph();
  	return 0;
}
