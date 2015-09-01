#include <cstdio>
#include <cstring>
int min(int a, int b){
	return (a<=b?a:b);
}
int main(){
	int i, j, a[26], b[26];
	char sa[1001], sb[1001];
	while(scanf("%s%s", sa, sb)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<strlen(sa);i++)
			a[sa[i]-'a']++;
		for(i=0;i<strlen(sb);i++)
			b[sb[i]-'a']++;

		for(i=0;i<26;i++){
			if(a[i] > 0 && b[i] > 0){
				for(j=0;j<min(a[i], b[i]);j++)
					printf("%c", i+'a');
			}
		}
		printf("\n");
	}
	return 0;
}