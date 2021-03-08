#include<iostream>
#include<cstdio>
#include<string>
using namespace std; 
int n;
int sum = 0;
struct tree{
	string name;
	float num;
	tree* l;
	tree* r;	
};

void insert(tree* & T,string s){
	if(T == NULL){
		T = new tree;
		T->name = s;
		T->l = NULL;
		T->r = NULL;
		T->num = 1;
	}
	else if(T->name == s){
		T->num++;
	}
	else if(T->name > s){
		insert(T->l,s);
	}
	else{
		insert(T->r,s);
	}
}

void mid(tree* T){
	if(T->l){
		mid(T->l);
	}
	if(sum) cout<<endl;	
	cout<<T->name;
	printf(" %.4f%%",T->num/n*100);
	sum++;
	if(T->r){
		mid(T->r);
	}
}

int main(){
	tree *T = NULL;
	cin>>n;
	cin.get();
	for(int i = 0;i < n;i++){
		string s;
		getline(cin,s);
		insert(T,s);
	}
	
	mid(T);
	
	return 0;
} 
