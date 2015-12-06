/**
	@package Worksap
	@name Exam1
	@description NP Problem, Solution in O(m.n.n) time complexity
	@author Harsh Vardhan Ladha, 12-1-5-003
	@email harsh.ladha@gmail.com
*/
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

#define MAX 501
#define endl "\n"

using namespace std;

int grid[MAX][MAX]; //input grid
long up[MAX][MAX]; //tabulation array in upward direction
long down[MAX][MAX]; //tabulation array in downward direction
long column[MAX]; //max values from up and down tabulation
bool entry_from[MAX]; //column-wise entry checker
int n, m; //n rows and m column
int i, j, k; //iterator variables

int playGame(){
	long upa=0, dna=0, last_sum_up = 0, last_sum_dn = 0; //upa => upward access row, dna => downward access row
	long ans = 0, current_maximum = 0, sum_col = 0;
	bool flag = false, block_up_flag = false, block_dn_flag = false;
	bool teleport_up_flag = false, teleport_dn_flag = false;
	
	//initialize column matrix to 0s
	memset(column, 0, sizeof(column));

	//marking all cells in a row of single to be true for entry to another column
	memset(entry_from, 1, sizeof(entry_from)); 

	for(j=1;j<=m;j++){ //iterate through columns
		
		sum_col = 0;

		for(i=1;i<=n;i++){
			flag = false; //if the current cell is -1
			block_dn_flag = false; //while traversing down if we get -1
			block_up_flag = false; //while traversing up if we get -1
			teleport_up_flag = false; //to check whether we have teleported, to maintain last_sum_up
			teleport_dn_flag = false; //to check whether we have teleported, to maintain last_sum_dn
			

			//if whole column is blocked we cannot traverse further
			//i.e., if sum_col = number of rows = n then answer should be 0
			if(entry_from[i] == false || grid[i][j] == -1)
				sum_col += 1;

			if(sum_col == n){
				return -1; //fixed earlier returned 0;
			}

			//current element is -1, don't traverse up and down, mark flag
			if(grid[i][j] == -1){
				flag = true;
			}
			
			if(!flag){
				//initialise the movement, column-wise
				k = 1;
				//if we can enter this column from i(th) row, checked from entry_from[] column matrix
				if(entry_from[i]){
					//adding last column entries(score) to this column items
					up[i][i] = column[i]+grid[i][j];
					down[i][i] = column[i]+grid[i][j];
					//update last_sums to store last column's score and this column cells sum
					last_sum_up = column[i]+grid[i][j];
					last_sum_dn = column[i]+grid[i][j];	
				
					//traverse up and down together in that column
					//total number of movements can be n-1
					while(k < n){

						//upward access row num
						upa = i - k; 
						
						if(upa <= 0){ //teleporting case while moving up
							upa += n;
							//check if we already have teleported
							//if already teleported don't reset last_sum
							if(teleport_up_flag == false){
								last_sum_up = 0;
								teleport_up_flag = true;
							}
						}

						//if next cell is not blocked with -1, add the value to last_sum
						if(grid[upa][j] != -1 && block_up_flag == false)
							last_sum_up += grid[upa][j];
						else{
							last_sum_up = 0;
							block_up_flag = true;
						}
						if(block_up_flag == false)
							up[upa][i] = last_sum_up;

						//downward access row num
						dna = i + k; 
						
						if(dna > n){ //teleporting case while moving down
							dna -= n;
							//check if we already have teleported
							//if already teleported don't reset last_sum
							if(teleport_dn_flag == false){
								last_sum_dn = 0;
								teleport_dn_flag = true;
							}
						}

						//if next cell is not blocked with -1, add the value to last_sum
						if(grid[dna][j] != -1 && block_dn_flag == false)
							last_sum_dn += grid[dna][j];
						else{
							last_sum_dn = 0;
							block_dn_flag = true;
						}
						if(block_dn_flag == false)
							down[dna][i] = last_sum_dn;


						k++;
					} 
				}
			}
		}

		/* printing the upward and downward tabulations up & down [debug]
		for(int l=1;l<=n;l++){
			for(int o=1;o<=n;o++){
				cout<<up[l][o]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int l=1;l<=n;l++){
			for(int o=1;o<=n;o++){
				cout<<down[l][o]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/

		//evaluation for columnar matrix
		//finding the maximum value in a same row for up and down matrix
		for(i=1;i<=n;i++){
			current_maximum = 0;
			for(k=1;k<=n;k++){
				if(up[i][k] > down[i][k]){
					if(current_maximum < up[i][k]){
						current_maximum = up[i][k];
					}
				}else{
					if(current_maximum < down[i][k]){
						current_maximum = down[i][k];
					}
				}
				up[i][k] = 0;
				down[i][k] = 0;
			}
			column[i] = current_maximum;
			
		}
		
		//blocking the entry to next column from row if the cell is -1 
		//cout<<"entry"<<endl;
		for(i=1;i<=n;i++){
			if(grid[i][j] == -1){
				entry_from[i] = false;
			}else if(entry_from[i] == false){
				if(i >= 2 && i < n){
					if(grid[i-1][j]==-1 && grid[i+1][j]==-1){
						entry_from[i] = false;
					}else{
						entry_from[i] = true;
					}
				}else{
					entry_from[i] = true;
				}
				
			}else{
				entry_from[i] = true;
			}
			//cout<<entry_from[i]<<endl;
		}
		
	}

	//find maximum in columnar matrix
	for(i=1;i<=n;i++){
		if(column[i] > ans)
			ans = column[i];
	}

	return ans;
}

int main(){
	//initialize grid with all 0s
	memset(grid, 0, sizeof(grid));
	
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>grid[i][j];

	//lets play game
	cout<<playGame()<<endl;
	return 0;
}