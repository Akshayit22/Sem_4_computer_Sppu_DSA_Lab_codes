#include<iostream>
using namespace std;

class node{
	public:
		string data;
		node *left;
		node *right;
		int ht;
		node(){
			this->left = NULL;
			this->right = NULL;
			this->data = "";
			this->ht = 0;
		}
		node(string data ){
			this->left = NULL;
			this->right = NULL;
			this->data = data;
			this->ht = 0;
		}
};
class avl{
	node *root;
	avl(){
		root = NULL;
	}
	
	node *creatnode(){
		node *temp;
		temp = new node;
		cout<<"enter data : ";
		cin>>temp->data;
		return temp;
	}
	void inor(node *temp){
		if(temp != NULL){
			inor(temp->left);
			cout<<"  "<<temp->data;
			inor(temp->right);
		}
	}
	int height(node *temp){
		int lh,rh;
		if(temp == NULL){
			return 0;
		}
		if(temp->left == NULL && temp->right == NULL){
			return 0;
		}
		lh = height(temp->left);
		rh = height(temp->right);
		
		if(lh > rh){
			return lh+1;
		}else{
			return rh+1;
		}
	}
	
	void search(){
		node *temp ;
		temp = root;
		string x;
		cout<<"\nenter key to search : ";cin>>x;
		while(temp != NULL){
			if(temp->data[0] == x[0] ){
				cout<<"key found\n";
				return ;
			}
			if(temp->data[0] > x[0]){
				temp = temp->left;
			}
			else if(temp->data[0] < x[0] ){
				temp = temp->right;
			}
		}
	}
	
	
	
	
	int bf(node *temp){
		int lh,rh;
		if(root == NULL){
			return 0;
		}
		if(temp->left == NULL){
			lh = 0;
		}else{
			lh = 1 + temp->left->ht;
		}
		
		if(temp->right == NULL){
			rh = 0;
		}else{
			rh = 1 + temp->right->ht;
		}
		
		return (lh-rh);
	}
	
	node *rotate_right(node *x){
		node *y;
		
		y = x->left;
		x->left = y->right;
		y->right = x;
		
		x->ht = height(x);
		y->ht = height(y);
		
		return y;
	}
	node *rotate_left(node *x){
		node *y;
		
		y = x->right;
		x->right = y->left;
		y->left = x;
		
		x->ht = height(x);
		y->ht = height(y);
		
		return y;
	}
	
};


int main(){
	
	return 0;
}
