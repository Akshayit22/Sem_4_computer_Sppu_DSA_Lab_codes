#include<iostream>
using namespace std;

#define size 26

class dict;

class node{
public:
	string key ;
	string value;
	node *next;
	friend class dict;

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
			head[i]=NULL;
		}
	}

	int hash(string key){
		int x;
		x = (int)key[0];
		if(x<95){x += 32;}
		return x%97;
		
	}

	void display(){
		cout<<"\nIndex\t Key\t Value";
      		for(int i=0;i<size;i++){
            		node *start=head[i];
			if(start==NULL)
                 		cout<<"\n";
			while(start!=NULL){
				cout<<"\n:"<<i
				    <<"\t"<<start->key
				    <<"\t "<<start->value;

				start=start->next;
			}
     		 }
		cout<<endl;

	}

	void insert(string word , string meaning){
	
		int index;
		index = hash(word);
		node *p = new node(word , meaning);

		if(head[index] == NULL){
			head[index] = p;
		}
		//collision condition
		else{
		
			node *temp = head[index];
			p -> next = temp-> next;
		
			temp->next = p;		
		}
		cout<<"\n word is inserted";
		
	}



	void search(string word){
		int flag = 0;

		int index ;
		index = hash(word);
		node *temp = head[index];
		

	}

	
};
int main(){

	dict xyz;
	string w,m,x,y;
	w = "apple";
	m = "a";
	x = "akshay";
	y = "aaa";

	xyz.display();

	xyz.insert(w,m);
	xyz.insert(x,y);
	//xyz.insert(a,trrt);
	xyz.display();














	
	return 0;
}


























