#include<iostream>
#include<string>
#include<stack>
using namespace std;

class node{
	public:
	char data;
	node *left;
	node *rgt;
	node(){
		
	}
	node(char x){
		data = x;
		left = NULL;
		rgt = NULL;
	}
};
class exptree{
	public:
	
	
	string read(){
		string e;
		cout<<"Enter post-fix expresion :";
		cin>>e;
		return e;
	}
	
	void inor(node *xyz){
		
		if(xyz != 	NULL){
			
			inor(xyz->left);
			
			cout<<"  "<<xyz->data;
			
			inor(xyz->rgt);
		}
	}
	
	void creat_exp_tree(){
		stack<node*>st;
		node *temp,*temp_op,*result;
		
		string exp = read();
		
		for(int i=0;i<exp.length();i++){
		
			if(isalpha(exp[i])){
				
				temp = new node(exp[i]);
				st.push(temp); 
			}
			else{
				temp_op = new node(exp[i]);
				
				node *temp_r = st.top();st.pop();
				node *temp_l = st.top();st.pop();
				
				temp_op->rgt = temp_r;
				temp_op->left = temp_l;
				st.push(temp_op);
			}
		}
		
		inor(temp_op);
		cout<<"\n";
		deletetree(temp_op);
		cout<<"tree after deletion : ";
		
	}
	

	
	void deletetree(node *temp){
		if (temp == NULL){
			return;
		}
		deletetree(temp->left);
		deletetree(temp->rgt);
		cout<<"node  "<<temp->data<<"  is deleted.\n";
		
		delete temp;
	}
		
	
};
int main(){
	exptree x;
	
	x.creat_exp_tree();
	/*
	int ch;
	do{
		cout<<"\n1.Delete\n2.Display\n3.Delete\nEnter choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				x.del();
				break;
			case 2:
				x.display();
				
				break;
			case 3:
				//b.deletetreef();
				break;
			case 4:
				
				break;
			default:
				cout<<"enter correct choice :";
				break;
			
		}
	}while(true);
	*/
	return 0;
}

//binary_tree//exp//avl_both//dict_bst
