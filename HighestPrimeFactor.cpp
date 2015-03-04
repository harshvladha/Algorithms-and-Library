#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
void primeFactor(long n)
{
  long max=0;
  while (n%2 == 0)
    {
      max=2;
      n = n/2;
    }
    long m = sqrt(n);
    for (int i = 3; i <= m; i = i+2)
      {
        while (n%i == 0)
          {
            if(i>max){
              max=i;
            }

            n = n/i;
          }
        }
        if (n > 2)
          if(n>max)
            max=n;
        cout<<max<<endl;
        }

        int main()
        {
          long t,n;
          cin>>t;
          while(t--){
            cin>>n;
            primeFactor(n);
          }

          return 0;
        }
