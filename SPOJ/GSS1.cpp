#include <cstdio>
#define MAX 50000
using namespace std;

struct node{
	int l, r, max;
};
int Max(int m, int n){
	return (m>n)?m:n;
}
int a[MAX + 1], sums[MAX + 1];
node seg_tree[4*MAX + 1];

void constructST(int n, int i, int j){
	if(i==j){
		node temp;
		temp.l = a[i];
		temp.r = a[i];
		temp.max = a[i];
		seg_tree[n] = temp;
	}else{
		constructST(n*2, i, (i+j)/2);
		constructST(n*2 + 1, (i+j)/2 + 1, j);
		
		node left = seg_tree[n*2];
		node right = seg_tree[n*2 + 1];

		seg_tree[n].l = Max(left.l, sums[(i+j)/2] - sums[i-1] + right.l);
		seg_tree[n].r = Max(right.r, sums[j] - sums[(i+j)/2] + left.r);
		seg_tree[n].max = Max(left.max, Max(right.max, left.r + right.l));
	}
}
node ans(int n, int a, int b, int i, int j){
	if(a==i && b==j){
		return seg_tree[n];
	}else if(j <= (a + b)/2){
		return ans(n*2, a, (a+b)/2, i, j);
	}
	if(i > (a + b)/2){
		return ans(n*2 + 1, (a+b)/2 + 1, b, i, j);
	}
	node left = ans(n*2, a, (a + b)/2, i, (a + b)/2);
    node right = ans(n*2 + 1, (a + b)/2 + 1, b, (a + b)/2 + 1, j);

    node temp;
    temp.l = Max(left.l, sums[(a+b)/2]-sums[i-1] + right.l);
    temp.r = Max(right.r, sums[b]-sums[(a+b)/2] + left.r);
    temp.max = Max(left.max, Max(right.max, left.r + right.l));
    return temp;
}
int main(){
	int n,m,i,x,y;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", a + i);
		if(i==0)
			sums[i] = a[i];
		else
			sums[i] = sums[i-1] + a[i];
	}
	constructST(1,0,n-1);
	scanf("%d", &m);
	for(i=0;i<m;i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", ans(1, 0, n-1, x-1, y-1).max);
	}
}