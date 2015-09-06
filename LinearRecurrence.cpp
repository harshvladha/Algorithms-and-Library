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

ll fibonacci(int N){
	//create vector F1
	vector<ll> F1(K+1);
	F1[1] = 1;
	F1[2] = 1;

	//create matrix T (transformation matrix)
	matrix T(K+1, vector<ll>(K+1));
	T[1][1] = 0; 
	T[1][2] = 1;
	T[2][1] = 1; //coefficient of kth
	T[2][2] = 1; //coefficient of (k-1)th

	//raise T to to the (N-1)th power
	if(N==1)
		return 1;
	T = pow(T, N-1);

	//the answer is the first row of T.F1

	ll ans = 0;
	for(int i=1;i<=K;i++)
		ans = (ans + T[1][i]*F1[i])%MOD;

	return ans;
}

int main(){
	int N;
	cin>>N;
	cout<<fibonacci(N)<<endl;
	return 0;
}
