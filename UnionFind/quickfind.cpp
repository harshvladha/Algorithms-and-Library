#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
QuickFind data type API
Use to find whether to points are connected or not and to connect them
*/
class QuickFind{
  /**
  Initialize quick-find data structure with N objects (0 to N-1)
  Union i.e., Connect is very expensive
  Takes N^2 array access to process sequence of N union commands on N objects
  Complexity : initialize : O(N), connect: O(N), find: O(1)
  */
public:
  vector<int> id;
public:
  QuickFind(int N){
    for(int i=0; i<N; i++){
      id.push_back(i);
    }
  }
  /**
  Add connection between p and q
  */
public:
  void connect(int p, int q){
    int pid = id[p];
    int qid = id[q];
    for(int i=0;i<id.size();i++){
      if(id[i]==pid)
        id[i]=qid;
    }
  }
  /**
  Are p and q in the same connection?
  */
public:
  bool connected(int p, int q){
    return id[p]==id[q];
  }
};
int main(){
  int N,T;
  cin>>N>>T;
  QuickFind uf(N);
  while(T--){
    int p,q;
    cin>>p>>q;
    uf.connect(p,q);
  }
  for(int i=0;i<uf.id.size();i++){
    cout<<uf.id[i]<<endl;
  }
  if(uf.connected(0,6)){
    cout<<"Connected"<<endl;
  }
  else{
    cout<<"Not Connected"<<endl;
  }
}
