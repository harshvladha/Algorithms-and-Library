#include <bits/stdc++.h>
using namespace std;
int distan[100001];
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

//structure to represent a min heap
struct hNode{
	int v;
	int distance;
};

//structure to represent a min heap
struct MinHeap{
	int size;
	int capacity;
	int *pos; //this is needed for the decrease key operation
	hNode **array;
};

//a utility function to create a new Min Head Node
hNode* newHNode(int v, int distance){
	hNode* newNode = (hNode*)malloc(sizeof(hNode));
	newNode->v = v;
	newNode->distance = distance;
	return newNode;
}

//a utility function to create a Min-Heap
MinHeap* createMinHeap(int capacity){
	MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
	heap->pos = (int *)malloc(capacity * sizeof(int));
	heap->size = 0;
	heap->capacity = capacity;
	heap->array = (hNode**)malloc(capacity*sizeof(hNode*));
	return heap;
}

//a utility function to swap two nodes of min heap, needed for minHeapify
void swapHNode(hNode** a, hNode** b){
	hNode* t = *a;
	*a = *b;
	*b = t;
}

//a standard function to heapify at given index
//this function also updates the position of nodes when they are swapped
//position is needed for decreaseKey()

void minHeapify(MinHeap* heap, int index){
	int smallest, left, right;
	smallest = index;
	left = 2*index + 1;
	right = 2*index + 2;

	if(left < heap->size && heap->array[left]->distance < heap->array[smallest]->distance)
		smallest = left;

	if(right < heap->size && heap->array[right]->distance < heap->array[smallest]->distance)
		smallest = right;

	if(smallest != index){
		//the nodes to be swapped in min heap
		hNode *smallestNode = heap->array[smallest];
		hNode *indexNode = heap->array[index];

		//swap positions
		heap->pos[smallestNode->v] = index;
		heap->pos[indexNode->v] = smallest;

		//swap nodes;
		swapHNode(&heap->array[smallest], &heap->array[index]);

		minHeapify(heap, smallest);
	}
}


bool isEmpty(MinHeap* heap){
	return heap->size == 0;
}

//function to extract minimum node from heap
hNode* extractMin(MinHeap* heap){
	if(isEmpty(heap))
		return NULL;

	//store the root
	hNode* root = heap->array[0];
	//cout<<"from extractMin : "<<root->v<<endl;
	//replace root with last node
	hNode* lastNode = heap->array[heap->size - 1];
	heap->array[0] = lastNode;

	//updating the position of last node
	heap->pos[root->v] = heap->size - 1;
	heap->pos[lastNode->v] = 0;

	//reduce the heap size and heapify the root
	--heap->size;
	minHeapify(heap, 0);

	return root;
}


//function to decrease the distance value of a given vertex v.
//this function uses pos[] of min heap to get the current index of node in min heap
void decreaseKey(MinHeap* heap, int v, int distance){
	
	//get the index of v in heap array
	int i = heap->pos[v];

	//get the node and update its distance value
	heap->array[i]->distance = distance;

	//travel up while the complete tree is not heapified
	//this is a O(logn) loop
	while(i && heap->array[i]->distance < heap->array[(i-1)/2]->distance){
		//swap this node with its parent
		heap->pos[heap->array[i]->v] = (i-1)/2;
		heap->pos[heap->array[(i-1)/2]->v] = i;

		//swap nodes
		swapHNode(&heap->array[(i-1)/2], &heap->array[i]);

		//move to parent index;
		i = (i-1)/2;
	}
}

//if a given vertex v is in min heap or not;
bool isInMinHeap(MinHeap* heap, int v){
	if(heap->pos[v] < heap->size)
		return true;
	return false;
}

// A utility function used to print the solution
void printArr(int dist[], int n, int src){
    for (int i = 0; i < n; ++i){
    	if(i!=src)
    		if(dist[i]!=INT_MAX)
    			cout<<dist[i]<<" ";
    		else
    			cout<<-1<<" ";
    }
        
}

void dijsktra(Graph g, int src){
	int v = g.getV();

	 //distance values used to pick minimum weight edge in cut
	int vx;
	//min heap represents set E
	MinHeap* heap = createMinHeap(v);
	//cout<<"heap created"<<endl;

	//initialize min heap with all vertices distance value of all vertices
	for(vx=0;vx<v;vx++){
		distan[vx] = INT_MAX;
		heap->array[vx] = newHNode(vx, distan[vx]);
		heap->pos[vx] = vx;
	}

	//make distance value of src vertex as 0 so that it is extracted first
	heap->array[src] = newHNode(src, distan[src]);
	heap->pos[src] = src;
	distan[src] = 0;
	decreaseKey(heap, src, distan[src]);

	//initialize size of min heap is equal to v;
	heap->size = v;
	//cout<<"heap initialized"<<endl;

	//in the following loop, min heap contains all nodes
	//whose shortest distance is not yet finalized

	while(!isEmpty(heap)){
		//extract the vertex with minimum distance value
		hNode* n = extractMin(heap);
		//cout<<"Min extracted\n";
		int u = n->v; // store the extracted vertex number

		//cout<<"u : "<<u<<"\n";
		//traverse through all adjacent vertices of u and update their distance values
		node* pCrawl = g.array[u].head;


		while(pCrawl != NULL){
			vx = pCrawl->id;

			//if shortest distance to vx is not finalized yet, and distance to vx
			//through u is less than its previously calculated distance
			if(isInMinHeap(heap, vx) && distan[u]!=INT_MAX && pCrawl->weight + distan[u] < distan[vx]){
				distan[vx] = distan[u] + pCrawl->weight;
				//update the distance value in min heap also
				
				decreaseKey(heap, vx, distan[vx]);

			}
			pCrawl = pCrawl->next;
		}
	}
}

int main(){
	register int n,t,m,x,y,w,s;
	cin>>n>>t;
	Graph g(n+1);
	m = n-1;
	while(m--){
		cin>>x>>y>>w;
		g.addEdge(x,y,w);
	}
	while(t--){
		cin>>s;
		int res[s];
		for(int i=0;i<s;i++){
			cin>>res[i];
		}
		int d = 0;
		for(register int i=0;i<s-1;i++){
			dijsktra(g,res[i]);
			for(register int j=i+1;j<s;j++){
				//cout<<dijsktra(g, res[i], res[j])<<endl;
				if(res[i]!=res[j]){
					//cout<<<<j<<" : "<<
					d += distan[res[j]];
				}
			}
		}
		cout<<d<<endl;
	}

	return 0;
}