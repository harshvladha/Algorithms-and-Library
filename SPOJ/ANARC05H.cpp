#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 30
char digits[MAX];
int dp[MAX][10*MAX];
int l;
//top-down approach of Dynamic Programming
int subgroups(int pointer, int previous){
	if(pointer == l)
		return 1;
	
	if(dp[pointer][previous] != -1)
		return dp[pointer][previous];
	
	dp[pointer][previous] = 0;
	int sum = 0;
	for(int i=pointer;i<l;i++){
		sum += digits[i] - '0';
		if(sum >= previous)
			dp[pointer][previous] += subgroups(i+1, sum);
	}

	return dp[pointer][previous];
}
int main(){
	int t = 1, answer;
	while(1){
		scanf("%s", digits);
		if(!isdigit(digits[0]))
			break;
		memset(dp, -1, sizeof(dp));
		l = strlen(digits);
		answer = subgroups(0, 0);
		printf("%d. %d\n", t++, answer);
	}
	return 0;
}