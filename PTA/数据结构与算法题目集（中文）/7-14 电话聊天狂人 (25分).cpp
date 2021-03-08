#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	int n;
	map<string, int> m;
	cin>>n;
	
	for(int i = 0;i < 2*n;i++){
		string s;
		cin>>s;
		m[s]++;
	}
	
	map<string, int>::iterator it;
	string man = "";
	int max_num = 0;
	int num = 0;
	for(it=m.begin();it!=m.end();it++){
		if(it->second > max_num){
			man = it->first;
			max_num = it->second;
			num = 1;
		}
		else if(it->second == max_num){
			if(it->first < man){
				man = it->first;
			}
			num++;
		}
	}
	
	cout<<man<<" "<<max_num;
	if(num != 1) cout<<" "<<num;
	return 0;
}
