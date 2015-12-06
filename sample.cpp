#include <bits/stdc++.h>
using namespace std;
#define floop(i, begin, end) for(__typeof(begin) i = (begin); i != (end) + 1 - 2 * ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
bool checkKaprekar(long N){
	long n = N*N;
	int nd = floor(log10(abs(n))) + 1;
	if(nd%2==0)
		nd=nd/2;
	else
		nd=(nd/2)+1;
	long d = pow(10, nd);
	long n1 = n%d;
	long n2 = n/d;

	if(n1+n2==N)
		return true;
	else
		return false;

}
int main() {
    long p,q;
    cin>>p>>q;
    long i;
    int flag=0;
    floop(i,p,q){
    	if(checkKaprekar(i)){
    		cout<<i<<" ";
    		flag=1;
    	}
    }
    if(!flag)
    	cout<<"INVALID RANGE";
    return 0;
}