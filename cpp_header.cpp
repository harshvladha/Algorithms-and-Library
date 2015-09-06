/*
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

below #include <bits/stdc++.h> includes all the header files automatically ;)

Copy from below and use ;)
*/

#include <bits/stdc++.h>
using namespace std;

#define floop1(i, begin, end) for(__typeof(begin) i = (begin); i != (end) + 1 - 2 * ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define mem(a,x) memset(a,x,sizeof(a))

#define MAX 10000000 //10^7
#define MOD 1000000007 // 10^9+7

#define endl "\n" //faster endl..

typedef long long int ll;


ll modPow(ll n, ll p, ll mod){
	if(p<2)
		return n%mod;
	int i=2;
	ll ans = (n*n)%mod;
	while(i<p){
		ans=(ans*n)%mod;
		i++;
	}
	return ans;
}
int totalDigits(long number){
	return floor(log10(abs(number))) + 1;
}
long reverseDigits(long number){
	int length = totalDigits(number)-1;
	long reverse=0;
	long multiplier;
	while(number>0){
		multiplier = pow(10,length);
		reverse += (number%10)*multiplier;
		number = number/10;
		length--;
	}
	return reverse;

}
int main(){
	
	return 0;
}

