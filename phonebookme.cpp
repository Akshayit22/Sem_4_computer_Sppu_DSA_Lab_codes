#include<iostream>
#include<string.h>
using namespace std;
class phonebook{
	public:
		unsigned long long int no[13];
		string name[13];
		phonebook(){
			for(int i=0;i<13;i++){
				no[i]=0;
				name[i]="none";
			}
		}
		int getno(){
		
		unsigned long long int number;
			//cout<<"Enter phone number : "	;
			cin>>number;
			return number;
				
		}
		
		string getname(){
				string s;
			//	cout<<"Enter contact name and number : ";
				getline(cin,s);	
				return s;	
		}
		
		int ascii(string ss){
			string s = ss;
			int sum=0;

			for(int i=0;i<s.length();i++){
				int x = (int)s[i];
				sum += x;
			}
			return sum;
		}
		
		int hash(string s){
			int key;
			string namexx = s;
			key = ascii(namexx);
			return key%13;
			
		}
		
		void insert(unsigned long long int number,string namex){
		//	long mno= number;	
			int pos = hash(namex);
			if(no[pos] == 0){
				no[pos] = number;
				name[pos]=namex;
				return ;
			}
			
			else{
				for(int i=(pos+1)%10;i != pos; i=(i+1)%10){
					if(no[i] == 0){
						no[i] = number;
						name[pos]=namex;
						return ;
					}
				}
				cout<<"element not inserted "<<endl;
			}
			
		}
		
		void display(){
			for(int i=0;i<13;i++){
				cout<<i<<"\t"<<name[i]<<"-----> "<<no[i]<<endl;
			}
			
		}
		
		
};

int main(){

	phonebook ph;
	ph.display();

	
	
	

	//int x;
	do{
	cout<<"1. to insert contact\n2. to search element\n3. to delete element\n4. to display table\n5. to exit\n";
	cout<<"enter choice : ";
	int ch;
	cin>>ch;
	cout<<endl;
	
	switch(ch){
		case(1):
			string sx;
			cout<<"Enter contact name : ";
			getline(cin,s);	
			
			unsigned long long int number;
			cout<<"Enter phone number : "	;
			cin>>number;
			
			ph.insert(number,sx);
			cout<<endl;
			break;
		
		case(4):
			ph.display();
			cout<<endl;
			break;
		case(5):
			exit(0);

	}
	}while(true);
	
	return 0;
}
