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
class QuickUnion{
  /**
  Initialize quick-union data structure with N objects (0 to N-1)
  Complexity : initialize : O(N), connect: O(lgN), find: O(lgN) => worst case
  In theory it is not linear. But practically it is linear.... 
  */
public:
  vector<int> id, size;
public:
  QuickUnion(int N){
    for(int i=0; i<N; i++){
      id.push_back(i);
      size.push_back(0);
    }
  }
  /**
  Find the root(top most parent) of the given node.
  */
  int root(int i){
    while(i!=id[i])
      id[i] = id[id[i]]; // Finding the grand parent of the node. not just root
      i=id[i];
      return i;
    }
    /**
    Add connection between p and q
    */
  public:
    void connect(int p, int q){
      int i = root(p);
      int j = root(q);
      if(i==j) return;
      if(size[i]>size[j]){
        id[j] = i;
        size[i]+=size[j];
      }else{
        id[i] = j;
        size[j]+=size[i];
      }
    }
    /**
    Are p and q in the same connection?
    */
  public:
    bool connected(int p, int q){
      return root(p)==root(q);
    }
  };
  int main(){
    int N,T;
    cin>>N>>T;
    QuickUnion uf(N);
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
