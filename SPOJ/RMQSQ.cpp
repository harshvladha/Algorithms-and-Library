/*
Array based Segment Tree
*/


#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int getMid(int s, int e){
	return (s + (e-s)/2);
}

int getRMQUtil(int *st, int ss, int se, int qs, int qe, int i){
	if(qs<=ss && qe>=se){
		return st[i];
	}

	if(se < qs || ss > qe){
		return INT_MAX;
	}
	int mid = getMid(ss, se);
	return min(getRMQUtil(st, ss, mid, qs, qe, 2*i + 1),
		   getRMQUtil(st, mid + 1, se, qs, qe, 2*i + 2));
}

int getRMQ(int *st, int n, int qs, int qe){
	
	return getRMQUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTutil(int a[], int ss, int se, int *st, int si){
	if(ss==se){
		st[si] = a[ss];
		return a[ss];
	}

	int mid = getMid(ss, se);

	st[si] = min(constructSTutil(a, ss, mid, st, si*2 + 1),
			 constructSTutil(a, mid+1, se, st, si*2 + 2));

	return st[si];
}

int *constructST(int a[], int n){

	//allocate memory for segment tree
	int x = (int)ceil(log2(n)); //height of segment tree
	int max_size = 2*(int)pow(2,x) - 1;
	int *st = new int[max_size];

	constructSTutil(a, 0, n-1, st, 0);

	return st;
}
int main(){
	int n, q, x, y, i;
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d", a + i);
	//build segment tree
	int *st = constructST(a,n);
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		printf("%d\n", getRMQ(st, n, x, y));
	}
}