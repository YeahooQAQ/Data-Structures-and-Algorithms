namespace LemonCube {
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
template<typename T>
void InsertionSort(T array[], const unsigned int& num){
	for(int i = 1; i < num; i++){
		T key = array[i];
		int j = i-1;
		while(j >= 0 && key < array[j]){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = key;
	}

}

template<typename T>
void InsertionSort_Recurrence(T array[], const int index){
	if(index <= 0) return;
	InsertionSort_Recurrence(array, index-1);
	int key = array[index];
	int i = index-1;
	while(index >= 0 && key < array[i]){
		array[i+1] = array[i];
		i--;
	}
	array[i+1] = key;

}

//80 70
template<typename T>
void Merge(T array[], const int low, const int high, const int mid){
	int size = high - low + 1;
	int p = 0, p_left = low, p_right = mid+1;
	T t[size];
	while(p_left <= mid && p_right <= high){
		t[p++] = array[p_left] < array[p_right] 
			? array[p_left++] : array[p_right++];
	}
	while(p_left <= mid){
		t[p++] = array[p_left++];
	}
	while(p_right <= high){	
		t[p++] = array[p_right++];
	}
	p = low;
	for(int i = 0; i < size; i++){
		array[p++] = t[i];
	}
}

template<typename T>
void MergeSort(T array[], const int low, const int high){
	if(low < high){
		int mid = (low + high) / 2;
		MergeSort(array, low, mid);
		MergeSort(array, mid+1, high);
		Merge(array, low, high, mid);		
	}

}

//77 4800
void quickSort(int array[], int low, int high){
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
void createHeap(int arr[],int n){
	
	for(int i = 1;i <= n;i++){
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



}