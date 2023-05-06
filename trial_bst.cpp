#include<iostream>
#include<stack>
using namespace std;
class node{
	public:
		string data;
		node *left;
		node *right;
		
		node(){
			this->left = NULL;
			this->right = NULL;
			this->data = "";
		}
		node(string data ){
			this->left = NULL;
			this->right = NULL;
			this->data = data;
		}
};

class bst{
	public :
	node *root;
	bst(){
		root = NULL;
	}
	
	node *creatnode(){
		node *temp;
		temp = new node;
		cout<<"enter data : ";
		cin>>temp->data;
		return temp;
	}
	
	void insert(){
		node *temp = new node;
		temp = creatnode();
		if(root == NULL){
			root = temp;
			return ;
		}
		node *q = root;
		while(q != NULL){
			
			if(q->data[0] > temp->data[0]){
				if(q->left == NULL){
					q->left = temp ;
					return ;
 				}else{
 					q = q->left;
				 }
			}
			else if(q->data[0] < temp->data[0]){
				if(q->right == NULL){
					q->right = temp ;
					return ;
 				}else{
 					q = q->right;
				}
 				
			}
			else{
				cout<<"duplicate entry not allow \n";
				return ;
			}
		}
		
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
	void min(node *temp){
		while(temp->right != NULL){
			temp = temp->right;
		}
		cout<<temp->data;
	}
	
	void mirror(node *temp){
		
		if(temp->left!=NULL){
			mirror(temp->left);
		}
		else if(temp->right!=NULL){
			mirror(temp->right);
		}
		
		node *q;
		q = temp->left;
		temp->left =temp->right;
		temp->right = q;
		
		//swap(temp->left ,temp->right);
	}
	void post(node *temp){
		if(root == NULL){
			return ;
		}
		stack<node *>st;
		stack<node *>st2;
		
		st.push(temp);
		while(!st.empty()){
			
			
			temp = st.top();st.pop();
			
			st2.push(temp);
			if(temp->left!=NULL){
				st.push(temp->left);
			}
			if(temp->right!=NULL){
				st.push(temp->right);
			}
		}
		while(!st2.empty()){
			cout << st2.top() -> data << " ";
       		st2.pop();
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
};

int main(){
	bst o;
	o.insert();
	o.insert();
	o.insert();
	o.insert();
	o.insert();
	o.inor(o.root);
	cout<<endl<<o.height(o.root)<<endl;
	//cout<<endl;o.mirror(o.root);
	o.post(o.root);
	o.search();
	return 0;
}
