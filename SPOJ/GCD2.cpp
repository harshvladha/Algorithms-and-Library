#include <cstdio>
#include <cstring>

using namespace std;

char b[252];

int gcd(int a, int b)
{
	int k;
	while(b)
	{
		a %= b;
		k = a;
		a = b;
		b = k;
	}
	return a;
}
int main(){
	int t, a, mod, l, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		scanf("%s", b);
		mod = 0;
		if(!a){
			printf("%s\n",b);
			continue;
		}
		l = strlen(b);
		for(i=0;i<l;i++){
			mod = (mod*10 + (b[i]-'0'))%a;
		}
		mod = gcd(a, mod);
		printf("%d\n", mod);
	}
	return 0;
}

/* python code was rejected code these big lines :( */