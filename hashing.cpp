#include<iostream>
using namespace std;
//#define hash(x) x%10
#define size 10
class hashing{
	public:
 
		int arr [size];
		
		hashing(){
			for(int i=0;i<size;i++){
				arr[i] = 0;
			}
		}
		
		int hash(int key){
			return (key%10);
		}
		/*
		//linear probing 
		void insert(int key){
			int pos = hash(key);
			if(arr[pos] == 0){
				arr[pos] = key;
				return ;
			}
			
			else{
				for(int i=(pos+1)%10;i != pos; i=(i+1)%10){
					if(arr[i] == 0){
						arr[i] = key;
						return ;
					}
				}
				cout<<"element not inserted "<<endl;
			}
			
		}
		
		//quadratic probing 
		void insert(int key){
			int pos = hash(key);
			if(arr[pos] == 0){
				arr[pos] = key;
				return ;
			}
			
			else{
				for(int i=(pos+(i*i))%10;i != pos; i=((i*i)+pos)%10){
				//for(int i=(pos+1); i !=pos; i = (((i*i)+pos)%10)){
			
					if(arr[i] == 0){
						arr[i] = key;
						return ;
					}
				}
				cout<<"element can no inserted "<<endl;
			}
			
		}
		
		//for referanc of quadratic probing
		int Hash_table :: add(phonebook per)
			{
			int pos;
			for(int i=0; i<MAX; i++)
			{
			
			
			pos = (hash(per.phone)%MAX + i*i)%MAX;
			if(hashtable[pos].phone == 0)
			{
			hashtable[pos] = per;
			return pos;
			break;
			}
			}
			}
		
		*/
		void insert(int key){
			int pos;
			for(int i=0; i<size; i++){
				pos = (hash(key)%size + i*i)%size;
			
				if(arr[pos] == 0){
					arr[pos] = key;
					//return pos;
					break;
				}
			}
		}
			
			
		
		void display(){
			for(int i=0;i<10;i++){
				cout<<i<<"    "<<arr[i]<<endl;
			}
		
		}
		
		int search(int key){
			int pos = hash(key);
			int count =1;
			if(arr[pos] == key){
				cout<<"element found at index : "<<pos<<endl;
				cout<<"No. of camparision done: "<<count<<endl;
				return pos;
			}
			
			else{
				for(int i=(pos+1)%10;i != pos; i=(i+1)%10){
					if(arr[i] == key){
						count++;
						cout<<"element found at index : "<<i<<endl;
						cout<<"No. of camparision done : "<<count<<endl;
						return pos ;
					}
					else{count++;}
				}
				cout<<"element not found "<<endl;
				return -1;
			}
		}
		
		int deletefunction(int key){
			int pos = hash(key);
			
			if(arr[pos] == key){
				
				return pos;
			}
			
			else{
				for(int i=(pos+1)%10;i != pos; i=(i+1)%10){
					if(arr[i] == key){
						
						return i ;
					}
					
				}
				
				return -1;
			}


		}
		void deletex(int key){
			int index ;
			 index = deletefunction(key);
			if(index >= 0 ){
				arr[index] = 0;
			}
			else{
				cout<<"element not found "<<endl;
				return;
			}
			cout<<"After Deleting "<<endl;
			display();
		}
	
};


int main(){
	hashing h;
	int x;
	do{
	cout<<"1. to insert element\n2. to search element\n3. to delete element\n4. to display table\n5. to exit\n";
	cout<<"enter choice : ";
	int ch;
	cin>>ch;
	cout<<endl;
	
	switch(ch){
		case(1):
			cout<<"enter element to insert : ";
			cin>>x;
			//h.insert(x);
			cout<<endl;
			break;
		case(2):
			cout<<"enter element to search : ";
			cin>>x;
			h.search(x);
			cout<<endl;
			break;
		case(3):
			cout<<"enter element to delete : ";
			cin>>x;
			h.deletex(x);
			cout<<endl;
			break;
		case(4):
			h.display();
			cout<<endl;
			break;
		case(5):
			exit(0);

	}
	}while(true);
	return 0;
}
