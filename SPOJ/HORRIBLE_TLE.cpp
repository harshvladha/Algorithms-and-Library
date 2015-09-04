/*
Array based Segment Tree (without Lazy propagation)
*/

#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int getMid(int s, int e){
	return (s + (e-s)/2);
}
void updateValueUtil(long long *st, int ss, int se, int i, long long diff, int index){
	if(i < ss || i > se){
		return ;
	}

	st[index] = st[index] + diff;

	if(se!=ss){
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2*index + 2);
	}
}
void updateValue(long long *st, int n, int i, long long new_val){

	if(i < 0 || i > n-1){
		printf("Invalid Input!");
		return ;
	}

	updateValueUtil(st, 0, n-1, i, new_val, 0);
}

long long getSumUtil(long long *st, int ss, int se, int qs, int qe, int i){
	if(qs<=ss && qe>=se){
		return st[i];
	}

	if(se < qs || ss > qe){
		return 0;
	}
	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*i + 1) +
		   getSumUtil(st, mid + 1, se, qs, qe, 2*i + 2);
}

long long getSum(long long *st, int n, int qs, int qe){
	if(qs < 0 || qe > n-1 || qs > qe){
		printf("Invalid Input!!");
		return -1;
	}
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int main(){
	int t,n,x,max_size,c,type,p,q,i;
	long long v;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &c);
		x = (int)ceil(log2(n)); //height of segment tree
		max_size = 2*(int)pow(2,x) - 1;
		long long st[max_size];
		memset(st, 0, sizeof(st)); //segment tree of all 0s
		while(c--){
			scanf("%d", &type);
			if(type==0){
				//update query
				scanf("%d %d %lld", &p, &q, &v);
				for(i=p-1;i<q;i++){
					updateValue(st, n, i, v);	
				}
			}else{
				//get sum query
				scanf("%d %d", &p, &q);
				printf("%lld\n", getSum(st, n, p-1, q-1));
			}
		}
	}
}