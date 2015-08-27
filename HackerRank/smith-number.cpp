#include <bits/stdc++.h>
using namespace std;
long getsum(long n){
	long ans = 0;
	while(n!=0){
		ans += n%10;
		n = n/10;
	}
	return ans;
}
long primeFactors(long n)
{
  long ans=0;
  while (n%2 == 0)
    {
      n = n/2;
      ans+=2;
    }
    long m = sqrt(n);
    for (int i = 3; i <= m; i = i+2){
        while (n%i == 0){
        	ans+=getsum(i);
            n = n/i;
        }
    }
    if (n > 2){
    	cout<<n<<endl;
      ans+=getsum(n);
    }
    return ans;
}
int main() {
    long n;
    cin>>n;
    long ans1 = primeFactors(n);
    long ans2 = getsum(n);
    if(ans1==ans2)
    	cout<<1<<endl;
    else
    	cout<<0<<endl;
    return 0;
}