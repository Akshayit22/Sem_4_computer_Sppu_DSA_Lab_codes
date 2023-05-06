#include<iostream>
using namespace std;


class node{
public:
	string key;
	string word;
	node *lptr;
	node *rptr;
	node(){

	}
};

class bst{
public:
	node *root;
	bst(){
		root = NULL;
	}

	void creat(){
		string key1,word1;
		root = new node;
		cout<<"Enter for ROOT:\nEnter word : ";
		cin>>key1;
		cout<<"Enter it's meaning : ";
		cin>>word1;
		root->key = key1;
		root->word = word1;
		root->lptr = NULL;
		root->rptr = NULL;
	}

	void insert(){
		string key1,word1;
		node *p,*q;
		if(root == NULL){
			creat();
		}		
		p=new node;
		cout<<"\nEnter word : ";
		cin>>key1;
		cout<<"Enter it's meaning : ";
		cin>>word1;
		p->key = key1;
		p->word = word1;
		p->lptr = NULL;
		p->rptr = NULL;
		q=root;
		
		while(q != NULL){
			if(q->key > p->key){
				if ( q->lptr == NULL){
					q->lptr = p ;
					cout<<"Element inserted ";
					return;
				}else{
					q = q-> lptr;
				}

			}
			else if(p->key > q->key){
				if( q ->rptr == NULL){
					q ->rptr = p ;
					cout<<"Element inserted ";
					return ;
				}else{
					q = q->rptr;
				}
			}
		}
	}

	void prer(node *temp){
		if(temp == NULL){
			return ; 
		}
			cout<<"\n"<<temp->key<<"--->"<<temp->word;
			prer(temp->lptr);
			prer(temp->rptr);
		
	}
	void inor(node *temp){
		if(temp != NULL){
			
			prer(temp->lptr);
			cout<<"\n"<<temp->key<<"--->"<<temp->word;
			prer(temp->rptr);
		}
	}
	void post(node *temp){
		if(temp != NULL){
			
			prer(temp->lptr);
			prer(temp->rptr);
			cout<<"\n"<<temp->key<<"--->"<<temp->word;
		}
	}




	void display(){
		int d;
		cout<<"\n1.Pre-order\n2.In-order(Sorted manner)\n3.Post-order\nEnter choice : ";
		cin>>d;
		if(root == NULL){
			cout<<"TREE IS EMPTY.\n";
		}
		if(d==1){
			prer(root);	
		}else if(d==2){
			inor(root);
		}else{
			post(root);
		}
		cout<<endl;	
	}
	
	int nodes(node *temp){
		if(temp == NULL){
			return 0;
		}
		
		return (nodes(temp->lptr)+nodes(temp->rptr)+1);	

	}

	void search(){
		node *q;q = new node;
		q=root;
		if(q == NULL){
			cout<<"DICTIONARY ID EMPTY/NO RECORD STORED";
		}
		string searchkey;
		cout<<"Enter word to search :";
		cin>>searchkey;
		while(q != NULL){
			
			if(q->key[0] > searchkey[0]){
				if ( q->key == searchkey){
					
					cout<<"Element found !\t It's meaning is :"<<q->word;
					return;
				}else{
					q = q-> lptr;
				}

			}
			else if(q->key[0] < searchkey[0]){
				if( q->key == searchkey){
					
					cout<<"Element found !\t It's meaning is :"<<q->word;
					return ;
				}else{
					q = q->rptr;
				}
			}
		}
	}
	
	
	
};





int main(){
	int ch;
	bst b;
	do{
		cout<<"\n1.insert\n2.display\n3.Count No. record stored\n4.Search in records\n0/9 to exit\nEnter choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				b.insert();
				break;
			case 2:
				b.display();
				
				break;
			case 3:
				//cout<<"No. of record stored in BST is :"<<b.nodes(b.root);
				b.mirror(b.root);
				break;
			case 4:
				b.search();
				
				break;
			case 0:
				exit(0);	
				break;
			case 9:
				exit(0);	
				break;		
			default:
				cout<<"enter correct choice :";
				break;
			
		}
	}while(true);



	return 0;
}














