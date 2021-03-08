#include<iostream>
#include<cstring>
using namespace std;

void createHeap(int arr[],int n){
	
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
		int l = i;
		while(l > 1){
			if(arr[l/2] < arr[l]){
				arr[l] ^= arr[l/2];
				arr[l/2] ^= arr[l];			
				arr[l] ^= arr[l/2];
				l /= 2;			
			}
			else{
				break;
			} 
		}
	}
	
}

void heapSort(int arr[],int n){
	
	while(n > 1){
		
		arr[1] ^= arr[n];
		arr[n] ^= arr[1];
		arr[1] ^= arr[n];
		n--;

		int t = 1;
		while(2*t <= n){
			int max = 2*t;
			
			if(max+1 <= n && arr[max] < arr[max+1]){
				max++;
			}
			if(arr[t] > arr[max]){
				break;
			}
			else{
				arr[max] ^= arr[t];
				arr[t] ^= arr[max];
				arr[max] ^= arr[t];
			}

			t = max;
		}
	}
}

int main(){
	int n, len = 0;
	cin>>n;	
	int arr[n+1];

	createHeap(arr, n);
	heapSort(arr, n);

	for(int i = 1;i <= n;i++){
		if(i != 1) cout<<" ";
		cout<<arr[i];		
	} 
	return 0; 
} 