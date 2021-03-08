#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void getNext(int n,string str,int next[]){
	int j = -1;
	int i = 0;
	next[0] = -1;
	
	while(i<n){
		if(j == -1 || str[i] == str[j]){
			next[++i] = ++j;
		}
		else{
			j = next[j];
		}
	} 
	
} 

int main(){
	string str1 = "abaabe";
	string str2 = "asdawdaababeawdss";
	int len1 = str1.size();
	int len2 = str2.size();
	int next[50]={0};
	getNext(len1, str1, next);
		
	int p1 = 0;
	int p2 = 0;
	while(p2<len2){
		if(p1 == -1 || str1[p1] == str2[p2]){
			p1++;
			p2++;
		}
		else{
			p1 = next[p1];
		}
		if(p1 == len1) cout<<"yes";
	}
	



	return 0;
} 
