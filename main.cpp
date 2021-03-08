#include<iostream>
#include"include/sort.hpp"
using namespace LemonCube;
using namespace std;

int main(){
	int array[] = {3,41,52,26,38,57,9,49};
	InsertionSort_Recurrence(array, sizeof(array)/sizeof(int)-1);
	for(auto num : array){
		cout<<num<<" ";
	}
	return 0; 
} 