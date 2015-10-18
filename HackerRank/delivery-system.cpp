#include <bits/stdc++.h>
using namespace std;
vector<int> cities;
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
			}
		}
		int getV(){return V;}

		void addEdge(int a, int b){
			/*add an edge from a to b. A new node is added in the adjacencylist of a. The node is added at the beginning */
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;			
		}
		bool bfs(int source, int search){
			queue<int> Q;
			Q.push(source);
			int count=0;
			while(!Q.empty()){
				source = Q.front();
				if(source == search){
					for(int i=0;i<V;i++){
						marked[i] = false;
					}
					return true;
				}
				Q.pop();
				node* w = array[source].head;
				marked[source] = true;
				while(w){
					if(!marked[w->id]){
						Q.push(w->id);
					}
					w = w->next;
				}
			}
			//not found
			for(int i=0;i<V;i++){
				marked[i] = false;
			}
			return false;
		}

};

int main(){
	int t,n,m,k,x,y,z;
	cin>>t;
	while(t--){
		cities.clear();
		cin>>n>>m>>k;
		Graph g(n+1);
		for(int i=0;i<k;i++){
			cin>>z;
			cities.push_back(z);
		}

		sort(cities.begin(),cities.end());
		for(int i=0;i<m;i++){
			cin>>x>>y;
			g.addEdge(x,y);
		}

		int flag = 0;
		int last = -1;
		vector<int> out;
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				if(i==j)
					continue;
				if(last==-1){
					last = i;
				}
				//cout<<"check 1 : "<<cities[last]<<" "<<cities[j]<<" "<<endl;
				if(!g.bfs(cities[last],cities[j])){
					out.clear();
					//cout<<"nhi milgya "<<cities[last]<<" "<<cities[j]<<endl;
					flag = 0;
					last = i+1;
					break;
				}else{
					//cout<<"milgya "<<cities[last]<<" "<<cities[j]<<endl;
					if(!flag)
						out.push_back(cities[last]);
					out.push_back(cities[j]);
					flag = 1;
					last = j;
				}
			}
			if(flag){
				break;
			}
		}
		if(out.size() > 0)
			for (std::vector<int>::iterator i = out.begin(); i != out.end(); ++i)
		    	std::cout << *i << " ";
		else
			cout<<-1<<endl
		cout<<endl;
	}
	return 0;
}