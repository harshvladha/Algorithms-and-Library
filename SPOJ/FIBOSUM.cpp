#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

//matrix multiplication A*B
matrix multiply(matrix A, matrix B){
	matrix C(K+1, vector<ll>(K+1));

	for(int i=1;i<=K;i++)
		for(int j=1;j<=K;j++)
			for(int k=1;k<=K;k++)
				C[i][j] = (C[i][j] + A[i][k]*B[k][j])%MOD;

	return C;
}
//calculate power A^p
matrix pow(matrix A, int p){
	if(p==1)
		return A;
	if(p%2)
		return multiply(A, pow(A, p-1));
	
	matrix X = pow(A, p/2);
	return multiply(X,X);
}

ll fibonacci(ll N){
	//create vector F1
	vector<ll> F1(K+1);
	F1[1] = 0;
	F1[2] = 1;

	//create matrix T (transformation matrix)
	matrix T(K+1, vector<ll>(K+1));
	T[1][1] = 0; 
	T[1][2] = 1;
	T[2][1] = 1;
	T[2][2] = 1;

	//raise T to to the (N-1)th power
	if(N==0)
		return 0;
	if(N==1)
		return 1;
	T = pow(T, N);

	//the answer is the first row of T.F1

	ll ans = 0;
	for(int i=1;i<=K;i++)
		ans = (ans + T[1][i]*F1[i])%MOD;

	return ans;
}

int main(){
	int t;
	ll n, m;
	ios::sync_with_stdio(false);

	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<(fibonacci(m+2) - fibonacci(n+1) + MOD)%MOD<<"\n";
	}
	return 0;
}