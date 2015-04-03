#include <bits/stdc++>

using namespace std;
void primeFactors(long n)
{
  long max=0;
  while (n%2 == 0)
    {
      max=2;
      n = n/2;
    }
    long m = sqrt(n);
    for (int i = 3; i <= m; i = i+2){
        while (n%i == 0){
            cout<<i<<" ";
            n = n/i;
        }
    }
    if (n > 2)
      cout<<n<<endl;
}

int main()
{
  long t,n;
  cin>>t;
  while(t--){
    cin>>n;
    primeFactors(n);
  }

  return 0;
}
