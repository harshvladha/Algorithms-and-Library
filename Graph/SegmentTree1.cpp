/*
Array based Segment Tree
*/

#include <cstdio>
#include <cmath>

using namespace std;
int getMid(int s, int e){
	return (s + (e-s)/2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index){
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
void updateValue(int a[], int *st, int n, int i, int new_val){

	if(i < 0 || i > n-1){
		printf("Invalid Input!");
		return ;
	}

	int diff = new_val - a[i];

	a[i] = new_val;

	updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int i){
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

int getSum(int *st, int n, int qs, int qe){
	if(qs < 0 || qe > n-1 || qs > qe){
		printf("Invalid Input!!");
		return -1;
	}
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTutil(int a[], int ss, int se, int *st, int si){
	if(ss==se){
		st[si] = a[ss];
		return a[ss];
	}

	int mid = getMid(ss, se);

	st[si] = constructSTutil(a, ss, mid, st, si*2 + 1) + 
			 constructSTutil(a, mid+1, se, st, si*2 + 2);
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
	int a[] = {-1,2,3};
	int n = sizeof(a)/sizeof(a[0]);

	//build segment tree
	int *st = constructST(a,n);
	int x, y;
	printf("Segment Tree Created!!\n");
	while(1){
		scanf("%d %d", &x, &y);
		if(x==-1 || y==-1)
			break;
		printf("%d\n", getSum(st, n, x, y));
	}
}