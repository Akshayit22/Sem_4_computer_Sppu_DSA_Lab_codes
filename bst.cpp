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
		cout<<"\n1.pre-order\n2.in-order\n3.post-order\nenter choice : ";
		cin>>d;
		if(d==1){
			prer(root);		
		}else if(d==2){
			inor(root);
		}else{
			post(root);
		}
	
	}

	int nodes(node *temp){
		if(temp == NULL){
			return 0;
		}
		
		return (nodes(temp->lptr)+nodes(temp->rptr)+1);	

	}

	
	
};

/*
//non recursive in-order traversal
void btree :: in_non_rec(Node * temp)
{
	stack <Node *> s;
	
	while(1)
	{
		while( temp != NULL)
		{
			s.push(temp);
			temp= temp -> left;
			
		}
		if (s.empty())
		return;
		temp = s.top();
		s.pop();
		cout<< temp -> data<<" ";
		temp = temp-> right;
	}

}
*/




int main(){
	int ch;
	bst b;
	do{
		cout<<"\n1.insert\n2.display\n3.count nodes\n4.Height of BST\nEnter choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				b.insert();
				break;
			case 2:
				b.display();
				
				break;
			case 3:
				cout<<"No. of nodes of tree :"<<b.nodes(b.root);
				break;
			case 4:
				cout<<"Height of BST : "<<b.height(b.root);
				break;
			default:
				cout<<"enter correct choice :";
				break;
			
		}
	}while(true);



	return 0;
}














