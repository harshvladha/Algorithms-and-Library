#include <cstdio>
#include <climits>

using namespace std;

int dp[10005], w[505], c[505];
int min(int a, int b){
	return (a>b)?b:a;
}
int main(){
	int t, e, f, n, W, i, j, temp, temp1;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &e, &f);
		scanf("%d", &n);
		W = f-e;
		temp = INT_MAX;
		
		for(i=1;i<=n;i++){
			scanf("%d %d", c + i, w + i);
			temp = min(temp, w[i]);
		}
		for(i=0;i<temp;i++){
			dp[i] = 0;
		}

		
		for(i=temp;i<=W;i++){
			temp = INT_MAX;
			for(j=1;j<=n;j++){
				temp1 = 0;
				if(i >= w[j]){
					if(dp[i-w[j]] > 0 || i == w[j])
						temp1 = c[j] + dp[i-w[j]]; //assuming that more the amount in coin the greater is the weight
				}
				if(temp1 < temp && temp1!=0)
					temp = temp1;
			}

			if(temp == INT_MAX)
				dp[i] = 0;
			else
				dp[i] = temp;
		}
		if(dp[W] == 0)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);

	}
	return 0;
}