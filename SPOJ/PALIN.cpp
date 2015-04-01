#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    char a[1000002];
    cin>>a;
    int len = strlen(a);
    int flag=0;
    for(int i=0;i<len;i++){
      if(a[i]!='9'){
        flag=1;
        break;
      }
    }
    if(flag==0){
      a[0]='1';
      for(int i=1;i<len;i++){
        a[i]='0';
      }
      a[len]='1';
      a[len+1]='\0';
    }else{
      flag=0;
      for(int i=1;i<len/2;i++){
        if(a[i]<a[len-i-1])
          flag=-1;
        if(a[i]>a[len-i-1])
          flag=1;
        a[len-i-1]=a[i];
      }
      int t,tmp1;
      if(flag == -1 || flag==0){
        t = 0;
        if(len%2 == 0)
          tmp1 = len/2-1;
        else
          tmp1 = len/2;
        while(a[tmp1-t] == '9'){
          a[tmp1-t] = '0';
          a[len-1-tmp1+t] = '0';
          t++;
        }
        a[tmp1-t] ++;
        a[len-1-tmp1+t] = a[tmp1-t];
      }
    }
    cout<<a<<endl;
  }
  return 0;
}
