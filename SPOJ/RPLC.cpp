#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){
	int t,i = 1, x, n;
	ll energy, min_energy;
	scanf("%d", &t);
	while(i <= t){
		scanf("%d", &n);
		energy = 0;
		min_energy = 1;
		while(n--){
			scanf("%d", &x);
			energy += x;

			if(energy < 0){
				min_energy += abs(energy);
				energy = 0;
			}
		}
		printf("Scenario #%d: %lld\n", i++, min_energy);
	}
	return 0;
}