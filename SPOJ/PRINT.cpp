#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
/**
Sieve of Eratosthenes : SEGMENTED Version
Use to find all prime numbers efficiently for numbers upto 10million = 10000000
*/

void markMultiples(bool a[], long start, long size){
  long i=2, j;
  while((j=i*start)<=size){
    a[j-1]=1; //not prime mark it as true
    i++;
  }
}
void Sieve(vector<long>* temp, long n){
  if(n >= 2){
    bool a[n], j=0;
    memset(a, 0, sizeof(a)); //set all false initially which implies all are prime
    for(long i=1; i<n ; i++){
      if(!a[i]){
        temp->push_back(i+1);
        markMultiples(a, i+1, n); //mark multiples as true as they are not prime
      }
    }
  }
}
void Segment(long m, long n){
  if(n >= 2 && n>m){
    bool a[n-m+1];
    memset(a, 0, sizeof(a)); //set all false initially which implies all are prime
    if(m<2){
      a[0]=1;
    }
    long b = sqrt(n);
    vector<long> pri;

    Sieve(&pri, b);

    for(long i=0; i<pri.size(); i++){
      long temp;
      if(pri[i]>=m){
        temp = 2*pri[i];
      }else
        temp = (m/pri[i])*pri[i];
      if(temp<m){
        temp+=pri[i];
      }
      while(temp<=n){
        a[temp-m]=1;
        temp+=pri[i];
      }
    }
    for(long i=0; i<=n-m;i++){
      if(!a[i]){
        //cout<<m+i<<endl;
        printf("%ld\n", m+i);
      }
    }
  }
}
int main(){
  long t,m,n;
  scanf("%ld", &t);
  while(t--){
    //cin>>m>>n;
    scanf("%ld %ld", &m, &n);
    Segment(m,n);
  }
  return 0;
}