#include<iostream>
using namespace std;
#define size 26
class node{
public:
	
	string key ;
	string value;
	node *next;
	
	friend class hashing;
	
	node(){
		next =  NULL;
	}
	
	node(string key , string value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	
}; 

class dict{
public:
	
	node *head[size];
	
	dict(){
		for(int i=0;i<size;i++){
			head[i] == NULL;
		}
	}
	
	int hash(string key){
		int x;
		x = (int)key[0];
		if(x<95){x += 32;}
		return x%97;
	}
	
	void display(){
		cout<<endl;
		cout<<"index \t word \t meaning";
		
		for(int i=0;i<=size;i++){
			
			node *temp = head[i];
			
            if(temp==NULL){
   		        cout<<endl;
			}
			
            while(temp != NULL)
            {
                  cout<<"\n:"<<i<<"\t"<<temp->key <<"\t "<<temp->value;
                  temp = temp->next;
            }
		}
	}
	
	void insert(string word,string meaning){
		int pos;
		pos = hash(word);
		node *p = new node(word,meaning);
		
		if(head[pos] == NULL){
			head[pos] = p;
		}
		else{
			node *temp=head[pos];
			
            p->next = temp->next;
			temp->next=p;
		}
		cout<<endl<<word<<" inserted into dictionary at index"<<pos;
	}
	
	void search(string word){
		string s = word;
		int inx = hash(s);
		int flg = 0;
		
		node *temp = head[inx];
		
			while(temp != NULL){
				
				if(temp->key == s){
					flg = 1;
					cout<<"Word is present and it's meaning is : ";
					cout<<temp->value;
					break;
				}
				temp = temp->next;
			}
		
			if(flg==1){
				cout<<" .";
			}
			else{
					cout<<" word is not present in dictionary.";
			}
	}
	
	
	bool delit(string word){
		string s = word;
		int inx = hash(s);
		
		node *temp = head[inx];
		node *p = head[inx];
		
		
		
	}
	
};
int main(){
	dict d;
	string a="a";
	d.display();
	d.search(a);
	d.display();
	string s,ss;
	
	
	return 0;
}
