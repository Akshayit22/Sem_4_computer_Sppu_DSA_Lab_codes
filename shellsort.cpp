#include<iostream>
using namespace std;

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

void shellsort(int arr[] , int n){
	
	
	int gap = n/2;
	for(gap ; gap>=1 ; gap /= 2){
		
		
		for(int j = gap ; j<n ; j++){
			
			
			for(int i=j-gap;i>=0;i -= gap){
				
				display(arr,n);
				
				if(arr[i+gap] > arr[i]){
					break;
				}else{
					swap(arr[i+gap] , arr[i]);
				}
				
			}
			
		}
		
	}
	
}

int main(){
	int arr[10] = {90,76,32,1,54,34,21,22};
	int n = 8;
	display(arr,n);
	shellsort(arr,n);
	display(arr,n);
	return 0;
}
