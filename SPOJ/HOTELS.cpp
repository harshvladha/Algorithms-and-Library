#include <cstdio>

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d", a+i);
	}
	int current_sum = 0, best_sum = 0, temp;
	for(i=j=0;i<n;i++){
		if(current_sum + a[i] < m){
			current_sum = current_sum + a[i];
		}else if(current_sum + a[i] == m){
			current_sum = current_sum + a[i];
			best_sum = current_sum;
			break;
		}else{
			temp = current_sum;
			while(temp + a[i] > m){
				current_sum = current_sum - a[j];
				temp = current_sum;

				if(current_sum + a[i] < m){
					current_sum = current_sum + a[i];
				}
				else if(current_sum + a[i] == m){
					current_sum = current_sum + a[i];
					best_sum = current_sum;
					break;
				}
				j++;
			}
		}

		if(current_sum > best_sum)
			best_sum = current_sum;
	}
	printf("%d\n", best_sum);

	return 0;
}