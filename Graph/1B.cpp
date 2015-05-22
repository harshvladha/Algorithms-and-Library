#include <bits/stdc++.h>
using namespace std;

#define floop1(i, begin, end) for(__typeof(begin) i = (begin); i != (end) + 1 - 2 * ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define mem(a,x) memset(a,x,sizeof(a))

#define MAX 10000000 //10^7
#define MOD 1000000007 // 10^9+7

#define endl "\n" //faster endl..

typedef long long int ll;


ll modPow(ll n, ll p, ll mod){
	if(p<2)
		return n%mod;
	int i=2;
	ll ans = (n*n)%mod;
	while(i<p){
		ans=(ans*n)%mod;
		i++;
	}
	return ans;
}
int totalDigits(long number){
	return floor(log10(abs(number))) + 1;
}
long reverseDigits(long number){
	int length = totalDigits(number)-1;
	long reverse=0;
	long multiplier;
	while(number>0){
		multiplier = pow(10,length);
		reverse += (number%10)*multiplier;
		number = number/10;
		length--;
	}
	return reverse;

}

struct node{
	int id;
	node* next;
};

struct alist{
	node *head;
};

class Digraph{
	int V;
public:
		alist* array;
		Digraph(int v){
			V = v;

			/*array of adjacency alist*/
			array = (alist*)malloc(V*sizeof(alist));

			/*initialising each adjacency list as empty by making head as NULL */
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
			/*add an edge from a to b. A new node is added in the adjacency alist of a. The node is added at the beginning */
			node* newNode = (node*)malloc(sizeof(node));
			newNode->id = b;
			newNode->next = array[a].head;
			array[a].head = newNode;

		}

		void printDigraph(){
			for(int i=0;i<V;i++){
				node* crawl = array[i].head;
				cout<<"\nAdjacency alist of vertex "<<i<<"\n head ";
				while(crawl){
					cout<<"-> "<<crawl->id;
					crawl = crawl->next;
				}
				cout<<endl;
			}
		}
};

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
	void bfs(Digraph G, int start){
		queue<int> Q;
		Q.push(start);
		int count=0,v;
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
			cout<<"Path : "<<x<<"\t";
		}
		path.push(s);
		cout<<s<<endl;
		return path;
	}
};
int main(){
	int numnodes = 100000000;
	Digraph g(numnodes+1);
	int i,j;
	floop1(i,2,11){
		j=i-1;
		g.addEdge(j,i);
	}
	int p=12,q=numnodes;
	floop1(i,p,q){
		j=i-1;
		g.addEdge(j,i);
		j = reverseDigits(i);
		if(j>i && j<=numnodes)
			g.addEdge(i,j);
	}
	int t;
	i = 0;
	cout<<"graph created"<<endl;
	cin>>t;/*
	breadthfirstpaths bf(g, 12);
	cout<<"bfs completed!!"<<endl;
	while(i<t){
		int n;
		cin>>n;
		int ans;
		if(n<=12){
			ans = n;
		}else{
			ans=11+bf.pathto(n).size();
		}
		cout<<"case #"<<i+1<<": "<<ans<<endl;
		i++;
	}*/
	return 0;
}
