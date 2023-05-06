#include<iostream>
using namespace std;
class node{
	public:
		int data,ht;
		node *left;
		node *right;
		node(){
			this->left = NULL;
			this->right = NULL;
		}
		node(int x){
			this->data = x;
			this->left = NULL;
			this->right = NULL;
		}
};

class avltree{
	public:
		node *root;
		
		avltree(){
			root = NULL;	
		}
		
		void inor(node *temp){
			if(temp != NULL){	
				inor(temp->left);
				cout << temp->data << " ";
				inor(temp->right);
			}
		}
		
		node* rotate_right(node *x){
			node *y;
			
			y = x->left;
			x->left = y->right;
			y->right = x;
			
			x->ht = height(x);
			y->ht = height(y);
			cout<<"r_r\n";
			return y;
			
		}
	
		node* rotate_left(node *x){
			node *y;
			
			y = x->right;
			x->right = y->left;
			y->left = x;
			
			x->ht = height(x);
			y->ht = height(y);
			cout<<"r_l\n";
			return y;
		}
		
		int height(node *t){
			int lh,rh;
			if(t == NULL){ return 0; }
			if(t->left == NULL && t->right == NULL){ return 0; }
			
			lh = height(t->left);
			rh = height(t->right);
			
			if(lh < rh){ return rh+1; }
			else { return lh+1; }
		}
		
		int bf(node *t){
			int lh,rh;
			if(t==NULL){ return 0;}
			else{
				
				if(t->left == NULL ){ lh = 0;}
				else{
					lh = 1+ t->left->ht;
				}
				
				if(t->right == NULL ){ lh = 0;}
				else{
					lh = 1+ t->right->ht;
				}
			}
			
			return (lh-rh);
		}
		
		node* ll(node *t){
			cout<<"\n ll rotation done...\n";
			
			t = rotate_right(t);
			
			return t;
		}
		
		node* rr(node *t){
			cout<<"\n rr rotation done...\n";
			
			t = rotate_left(t);
			
			return t;
		}
		
		node* rl(node *t){
			cout<<"\n rl rotation done...\n";
			
			t->right = rotate_right(t->right);
			t = rotate_left(t);
			
			return t;
		}
		
		node* lr(node *t){
			cout<<"\n lr rotation done...\n";
			
			t->left = rotate_left(t->left);
			t = rotate_right(t);
			
			return t;
		}
		
		node* insert(node *root,int key){
			node *temp,*tempx;
			//tempx = root;
			root = new node(100);	
			int lh,rh;
			/*
			if(root == NULL){
				temp = new node(key);
				temp->ht = 0;
				root = temp;
				cout<<"NODE IS CREADED .. \n";
			}
			*/
			
			
				if(root->data > key){
					root->left = insert(root->left , key);
					if(bf(root) == 2){
						if(root->left->data > key){
							root = ll(root);
						}
						else{
							root = lr(root);
						}
					}
				}
				else{
					if(root->data < key){
						root->right = insert(root->right , key);
						
						if(bf(root) == -2){
							if(root->right->data < key){
								root = rr(root);
							}
							else{
								root = rl(root);
							}	
						}
					}
					else{cout<<"duplicate...\n";}
				}
			
			root->ht = height(root);
			return root;
		}
		void dis(){
			//node *root;
			//root = new node(100);	
			root = insert(root, 88);
			root = insert(root, 85);
			root = insert(root, 77);
			root = insert(root, 40);
			root = insert(root, 50);
			root = insert(root, 25);
			cout<<endl;
			inor(root);
		}
};

int main(){
	avltree obj;
	//node *root ;
	obj.dis();
	return 0;
}
