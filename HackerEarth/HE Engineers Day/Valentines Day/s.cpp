/*
Template belongs to : Himanshu Jaju [himanshujaju]
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<LL,LL>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define DRT()     int t;cin>>t;while(t--)
#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007

#define MALE      1
#define FEMALE    2

int main()
{
      inp_s;
      int p = 0;
      DRT()
      {
            int n,m;
            cin>>n>>m;
            VI edges[n];
            FOR(i,0,m)
            {
                  int a,b;
                  cin>>a>>b;
                  a--;b--;
                  edges[a].pb(b);
                  edges[b].pb(a);
            }
            int visited[n];
            FOR(i,0,n) visited[i] = 0;
            int flag = 0;
            FOR(source,0,n)
            {
                  if(visited[source]) continue;
                  queue<int> bfs;
                  bfs.push(source);
                  visited[source] = MALE;
                  while(!bfs.empty())
                  {
                        int x = bfs.front();
                        bfs.pop();
                        FOR(i,0,sz(edges[x]))
                        {
                              if(!visited[edges[x][i]])
                              {
                                    bfs.push(edges[x][i]);
                                    if(visited[x] == MALE) visited[edges[x][i]] = FEMALE;
                                    else visited[edges[x][i]] = MALE;
                              }
                              else if(visited[x] == visited[edges[x][i]])
                              {
                                    flag = 1;break;
                              }
                        }
                        if(flag) break;
                  }
                  if(flag) break;
            }
            ++p;
            cout<<p<<": ";
            if(flag) cout<<"unusal"<<endl;
            else cout<<"usual"<<endl;
      }
      return 0;
}
