#include<iostream>

using namespace std;
//4 8 6

//overtime 5000 
void BubbleSort(int array[], int num){
	
	for(int i = num; i > 0;i--){
		for(int j = 1;j < i;j++){
			if(array[j-1] > array[j]){
				array[j] ^= array[j-1];
				array[j-1] ^= array[j];
				array[j] ^= array[j-1];				
			}
		}
	}
	
} 

//5000ms 2500ms 
void insertSort(int array[], int num){
	
	for(int i = 1;i < num; i++){
		int t = array[i];		
		int j = i-1;
		while(array[j] > t && j >= 0){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = t;		
	}
	
}
//80 70
void merge(int array[],int low,int high,int mid){
	int t[high-low+1];
	int i = low;
	int j = mid+1;
	int num = 0;
	
	while(i <= mid && j <= high){
		if(array[i] < array[j]){
			t[num++] = array[i++];
		}
		else{
			t[num++] = array[j++];
		}
		
	}
	
	while(i <= mid){
		t[num++] = array[i++];
	} 
	while(j <= high){
		t[num++] = array[j++];
	}
	
	for(int index = 0; index < num; index++){
		array[low++] = t[index];
	}
	
}

void mergeSort(int array[], int low, int high){
	if(low < high){
		int mid = (low + high)/2;
		mergeSort(array, low, mid);
		mergeSort(array, mid+1,high);
		merge(array, low, high, mid);	
	} 
}

//77 4800
void quickSort(int array[],int low, int high){
	if(low >= high){
		return;	
	} 
	
	int i = low;
	int j = high;
	int pivot = array[low];
	while(i < j){
		while(array[j] >= pivot && i < j){
			j--;
		}
		while(array[i] <= pivot && i < j){
			i++;
		}
		if(i < j){
			array[i] ^= array[j];
			array[j] ^= array[i];
			array[i] ^= array[j];
		}
	}
	
	array[low] = array[i];
	array[i] = pivot;
	
	quickSort(array,low,i-1);
	quickSort(array,i+1,high);
}

//90 80 
void ShellSort(int array[], int num){
	
	for(int gap = num / 2; gap > 0; gap /= 2){
		for(int i = gap; i < num; i++){
			int t = array[i];
			int j = i-gap;
			while(j >= 0 && array[j] > t ){
				array[j+gap] = array[j];
				j -= gap;
			}
			array[j+gap] = t;	
		}
	}
	
}


int main(){
	int n;
	cin>>n;
	int array[n];
	for(int i = 0;i < n;i++){
		cin>>array[i];
	}
	
	mergeSort(array, 0, n-1);
	
	for(int i = 0;i < n;i++){
		if(i != 0){
			cout<<" ";
		}
		cout<<array[i];
	}
	
	return 0;
} 
