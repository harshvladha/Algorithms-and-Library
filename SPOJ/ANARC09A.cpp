#include <cstdio>

using namespace std;

int main(){
	int k=1, n, open, close, i;
	char braces[2001];
	while(1){
		n = 0;
		scanf("%s", braces);
		if(braces[0]=='-')
			break;
		open = 0;
		close = 0;
		for(i=0;braces[i]!='\0';i++){
			if(braces[i]=='{'){
				open++;
			}else{
				open--;
				if(open < 0){
					open = 1;
					close++;
				}
			}
		}
		n = close + (open/2);
		printf("%d. %d\n", k, n);
		k++;
	}
	return 0;
}