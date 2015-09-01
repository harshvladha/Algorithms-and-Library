#include <cstdio>

struct node{
	int x, y;
	void pode(int _x, int _y){
		x = _x;
		y = _y;
	}
};

int main(){
	int a=5, b=6;
	node c;
	c.pode(a,b);
	printf("%d\n", c.x);
}