#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

struct line{
	int x, y;
	int length;
};

int find(int x,int * p){
	return p[x] == x?x:p[x] = find(p[x],p);
}

bool cmp(line a, line b){
	return a.length < b.length;
}

int main(){
	int n, m;
	cin>>n>>m;
	int p[n+1];
	line arr[m];
	int num = 0;
	int ans = 0;
	
	for(int i = 0;i <= n;i++){
		p[i] = i;
 	}
	for(int i = 0;i < m;i++){
		cin>>arr[i].x>>arr[i].y>>arr[i].length;
	}
	sort(arr,arr+m,cmp);
	
	for(int i = 0;i < m;i++){
		if(num == n)break; 

		int x = find(arr[i].x,p);
		int y = find(arr[i].y,p);
		
		if(x != y){
			num++;			
			ans += arr[i].length;
			p[x] = y;
		}		
		
	}
	if(n-num-1){
		cout<<"Impossible";
	}
	else{
		cout<<ans;
	}
	return 0;
} 
