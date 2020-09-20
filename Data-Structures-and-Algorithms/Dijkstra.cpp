#include<iostream>

using namespace std;
int map[505][505][2];
int cost[505][2];
bool book[505];
int n, m, s, d;


int main(){
	cin>>n>>m>>s>>d;
	
	for(int i = 0; i < n; i++){
			cost[i][0] = 0x0fffffff;
			cost[i][1] = 0x0fffffff;		
		for(int j = 0;j < n;j++){
			map[i][j][0] = 0x0fffffff;
			map[i][j][1] = 0x0fffffff;
		}
	}
	
	for(int i = 0;i < m; i++){
		int s, d, l, spend;
		cin>>s>>d>>l>>spend;
		map[s][d][0] = l;
		map[d][s][0] = l;
		map[s][d][1] = spend;
		map[d][s][1] = spend;
	}
	cost[s][0] = 0;
	cost[s][1] = 0;

	for(int k = 0; k < n; k++){
		int minL = 0x0fffffff;
		int minS = 0x0fffffff;
		int index = 0;
		
		for(int i = 0;i < n; i++){
			if(cost[i][0] < minL && book[i] == 0){
				minL = cost[i][0];
				minS = cost[i][1];
				index = i;
			}
			else if(cost[i][0] == minL 
				&& cost[i][1] < minS
				&& book[i] == 0){
				minS = cost[i][1];
				index = i;
			}
		}
		book[index] = 1;
		
		
		for(int i = 0;i < n; i++){
			if(map[index][i][0] != 0x0fffffff){
   				if(cost[index][0] + map[index][i][0] < cost[i][0]){
					cost[i][0] = cost[index][0] + map[index][i][0];
					cost[i][1] = cost[index][1] + map[index][i][1];	
 				}
 				else if(cost[index][0] + map[index][i][0] == cost[i][0] 
 					&& cost[index][1] + map[index][i][1] < cost[i][1]){
 					cost[i][1] = cost[index][1] + map[index][i][1];	
 				}
 			}
 			
 		}
	}
	

	cout<<cost[d][0]<<" "<<cost[d][1];
	return 0;
} 