
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2; 

	
	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i) {
		swap(arr[i], arr[largest]);

	
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	
	for (int i = n - 1; i > 0; i--) {
	
		swap(arr[0], arr[i]);

		
		heapify(arr, i, 0);
	}
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver code
int main()
{	int arr[10];
	//int arr[] = { 12, 11, 13, 5, 6, 7 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);
}


/*


#include<iostream>
using namespace std;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void heapify(int arr[] , int n , int root){
	int largest , l , r ;
	largest = root;
	l = root * 2 + 1;
	r = root * 2 + 2;
	
	if(n > l && arr[l] > arr[largest]){
		largest = l;
	}
	if(n > r && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != root){
		swap(arr[largest],arr[root]);
		//display(arr,n);
		heapify(arr , n , largest);
		
	}
}

void heapsort(int arr[] , int n){
	for(int i=n/2 -1;i>=0;i--){
		heapify(arr,n,i);
		display(arr,n);
	}
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		
		heapify(arr,i,0);
	}
}

int main(){
	int arr[10] = {90,76,32,1,54,34,21,22};
	int n = 8;
	heapsort(arr , n);
	display(arr,n);
	return 0;
}



*/

