#include<iostream>
using namespace std;
#define MAX 10
struct phonebook{
		string name;
		long long int phone;
};
class hash_table{
	
	public:
		phonebook hashtable[10];
		
		hash_table(){
			for(int i=0;i<MAX;i++){
				hashtable[i].phone = 0;
				hashtable[i].name = "";
			}
		}
		int hash(int key){
			return(key%MAX);
		}
		void insert(phonebook obj){
			int pos;
			pos = hash(obj.phone);
			
			if(hashtable[pos].phone == 0){
				hashtable[pos] = obj;
			}
			else{
				for(int i=(pos+1)%MAX;i !=pos;i=(i+1)%MAX){
					if(hashtable[i].phone == 0){
						hashtable[i] = obj;
						break ;
					}	
				}	
				
			}
		}
		int quadinsert(phonebook per){
			int pos;
			for(int i=0; i<MAX; i++){
				pos = (hash(per.phone)%MAX + i*i)%MAX;
				if(hashtable[pos].phone == 0){
					hashtable[pos] = per;
					return pos;
					break;
				}
			}
		}

		void display(){
			cout<<"HASH TABLE :\n";
			for(int i=0;i<MAX;i++){
			
				cout<<i<<": "<<hashtable[i].name << " - " << hashtable[i].phone<<endl;
			}
		}
};
int main(){
		hash_table ht;
		int choice,n;
		phonebook per;
		ht.display();
		for(int i=0;i<5;i++){
			cin>>per.name>> per.phone;
			ht.quadinsert(per);
			ht.display();	
		}
		/*
		do{
			cout<<"1. INSERT ELEMENT By Linear Probing"<<endl;
			cout<<"2. INSERT ELEMENT By Quadratic Probing"<<endl;
			cout<<"3. Display"<<endl;
			cout<<"4. Exit"<<endl;
			cout<<"\nEnter your choice: ";
			cin>>choice;
			switch(choice){
				case 1:
					cout << "Enter name , phone to insert:";
					cin>>per.name>> per.phone;
					ht.insert(per);
					ht.display();
					break;
				case 2:
					cout << "Enter name , phone to insert:";
					cin>>per.name>> per.phone;
					ht.quadinsert(per);
					ht.display();
					break;
				case 3:
					ht.display();
					break;
				}
		}while(choice!=4);
		
		*/
		return 0;
}




