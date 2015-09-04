/*
Both updateUtil and getSumUtil is modified for lazy propagation

Lazy Propagation in Segment Tree :
We only mark the childs of the node which needs to be updated and update it when needed.
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

 
ll lazy[450000],tree[450000];

void update_tree(ll node, ll a, ll b, ll i, ll j, ll val)
{
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
			lazy[2*node+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
		}
		lazy[node]=0;
	}
	if(a>b || a>j || b<i)
	{
		return;
	}
	if(a>=i && b<=j)
	{
		tree[node]+=val*(b-a+1);
		if(a!=b)
		{
			ll mid=(a+b)/2;
			lazy[node*2+1]+=val*(mid-a+1);
			lazy[node*2+2]+=val*(b-mid);
		}
		return;
	}
	ll mid=(a+b)/2;
	update_tree(node*2+1,a,mid,i,j,val);
	update_tree(node*2+2,mid+1,b,i,j,val);
	tree[node]=tree[node*2+1]+tree[node*2+2];
}
ll query(ll node, ll a, ll b, ll i, ll j)
{
	if(a>b || a>j || b<i)
	{
		return 0;
	}
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(a!=b)
		{
			lazy[2*node+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
			lazy[2*node+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
		}
		lazy[node]=0;
	}
	if(a>=i && b<=j)
	{
		return tree[node];
	}
	ll mid=(a+b)/2;
	ll q1=query(node*2+1,a,mid,i,j);
	ll q2=query(node*2+2,mid+1,b,i,j);
	ll res=q1+q2;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	long long t;
	cin >> t;
	ll i;
	

	while(t--)
	{
		ll n,c;
		for(i=0;i<450000;i++)
		{
			lazy[i]=0;
			tree[i]=0;
		}
		int type;
		cin>>n>>c;
		while(c--)
		{
			cin>>type;
			if(type==0)
			{
				ll p,q,v;
				cin>>p>>q>>v;
				update_tree(0,0,n-1,p-1,q-1,v);
			}
			else
			{
				ll p,q;
				cin >> p >>q;
				cout << query(0,0,n-1,p-1,q-1) << "\n";
			}	
		}
	}
	return 0;
}