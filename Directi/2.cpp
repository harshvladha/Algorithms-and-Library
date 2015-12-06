#include <cstdio>
#include <climits>
#include <cstring>
#define MAX 105

int min(int a, int b){
	return (a>b)?b:a;
}
int t,n,i,j,x,y,a[MAX][MAX],b[MAX][MAX];


int solvedp(){

	int dp[MAX][MAX];
	int l=0,t=0, tmp = 0;
	a[1][2] = a[1][1] + a[1][2];
	for(i=1;i<=n+1;i++){
		for(j=i+1;j<=n;j++){
			tmp = INT_MAX;
			if(j != i + 1){
				tmp = min(tmp, a[i][j] + a[i][j-1]);
			}
			if(i != 1){
				tmp = min(tmp, a[i][j] + a[i-1][j]);	
			}
			if(tmp!=INT_MAX){
				a[i][j] = tmp;
			}
		}
	}
	a[n][n] = a[n][n]+a[n-1][n];
	/*
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	*/
	for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            b[i][j]=a[n-i+1][n-j+1];
            //printf("%d ", b[i][j]);
        }
        //printf("\n");
    }
	
	i=1;j=1;
    b[1][2]=b[1][1]+b[1][2];
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            tmp = INT_MAX;
            if(j != i+1)
                tmp = min(tmp,b[i][j]+b[i][j-1]);
            if(i != 1)
                tmp = min(tmp,b[i][j]+b[i-1][j]);
            if(tmp != INT_MAX)
            	b[i][j] = tmp;
           }
        }
    b[n][n]=b[n][n]+b[n-1][n];
    
    return b[n][n];
}


int main(){
	scanf("%d", &t);
	while(t--){
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d", &a[i][j]);
			}
		}

		for(i=0;i<=n+1;i++){
			a[i][0] = a[i][n+1] = INT_MAX;
		}
		printf("%d\n", solvedp());
	}
	
	return 0;
}