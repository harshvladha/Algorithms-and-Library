#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 300
using namespace std;

int main(){
	char a[MAX], b[MAX];
	int i, j, len, flag = 0;
	while(scanf("%s", a)==1){
		len = strlen(a);
		if(a[0]=='_' || a[0]<'a'){
			printf("Error!\n");
		}else{
			flag=j=0;
			for(int i=0;i<len;i++){
				if(!flag && a[i]=='_')
					flag=1; //cpp
				if(!flag && isupper(a[i]))
					flag=2; //java
				if((flag==2 && a[i]=='_') || (flag==1 && isupper(a[i]))){
					flag=3; //error
					break;
				}else if(flag==1 && a[i]=='_'){
					if(!islower(a[i+1])){
						flag=3;
						break;
					}
					b[j++]=a[++i]-32;
				}else if(flag==2 && isupper(a[i])){
					b[j++] = '_';
					b[j++] = a[i]+32;
				}else{
					b[j++] = a[i];
				}
			}
			b[j] = '\0';
			if(flag==3)
				printf("Error!\n");
			else
				printf("%s\n",b);
		}
	}
	return 0;
}



