#include<iostream>
#include<stack>
using namespace std;
class node{
	public:
	int data;
	node *leftptr;
	node *rigtptr;
	node(){
		
	}
};
class btree{
	public:
		
	node *root;
	tree(){
		root = NULL;
	}
	stack<int>st;
	
	void creat(){
		root = new node;
		cout<<"Enter root node :";
		cin>>root->data;
		
		root->leftptr = NULL;
		root->rigtptr = NULL;
		//return root;
		cout<<" Root Node is created\n";
	}
	
	void insert(){
		int x;
		char ch;
		node *p, *q;
		
		if(root == NULL){
			creat();
		}
		cout<<"Enter element to inset : ";
		cin>>x;
		p = new node;
		p->data = x;
		p->leftptr = NULL;
		p->rigtptr = NULL;
		
		q=root;
		while(q != NULL){
			cout<<"where to insert left or right of "<<q->data <<" : ";
			cin>>ch;
			if(ch== '1' || ch=='l' ){
				if(q->leftptr == NULL){
					q->leftptr = p;
					cout<<"elements is inserted";
					return ;					
				}
				else{
					q = q->leftptr;
					
				}
				
			}
			else if (ch == 'r' || ch =='2'){
				if(q->rigtptr = NULL){
					q->rigtptr = p;
					cout<<"elements is inserted";
					return ;
				}
				else{
					q = q->rigtptr;
					
				}
			}
		}
	}
	/*
	void inord_iter(node *temp){
		while(true){
			while(temp != NULL){
				st.push(temp);
				temp = temp->leftptr;
			}
			if(st.empty()){
				return;
			}
			cout<<temp->data<<" ";
			temp = temp->rigtptr;
		}
	}
	*/
	
	void prer(node *temp){
		if(temp != 	NULL){
		
			cout<<"  "<<temp->data;
			prer(temp->leftptr);
			prer(temp->rigtptr);
		}
	}
	
	void inor(node *temp){
		if(temp != 	NULL){
			inor(temp->leftptr);
			cout<<"  "<<temp->data;
			
			inor(temp->rigtptr);
		}
	}
	void post(node *temp){
		if(temp != NULL){
			post(temp->leftptr);
			post(temp->rigtptr);
			cout<<"  "<<temp->data;
		}
	}
	int nodes(node *temp){
		if(temp==NULL){
			return 0;
		}
		
		if(temp->leftptr == NULL && temp->rigtptr==NULL){
			return 1;
		}
		return nodes(temp->leftptr) + 2 + nodes(temp->rigtptr);
	}
	void display(){
		post(root);
	}
	
	void non(){
		cout<<nodes(root);
	}

};





int main(){
	btree t;
	node p;
	int chs;
	do{
	cout<<"\n1.insert\n2.display\n3.count no. of nodes\n6.To Exit\nEnter choice : ";
	cin>>chs;
	switch(chs){
		case 1 :
			t.insert();
			break;
		case 2 :
			t.display();
			
			break;
		case 3 :
			t.non();
			break;	
		case 4 :
			break;
		default :
			cout<<"Exiting.......";
			exit(0);
			break;			
	}
	}
	while(true);
	
	return 0;
}
