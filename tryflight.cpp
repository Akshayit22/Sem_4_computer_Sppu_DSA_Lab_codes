#include<iostream>
using namespace std;
class node{
public:	
	int data;
	string name;
	node *left;
	
	node(){
		this->left = NULL;
	}
	node(int x,string str){
		this->data = x;
		this->name = str;
		this->left = NULL;
	}
};
class flight{
public:
	int vtx,e;
	node *head[10];
	string names[10];
	
	flight(){
		int v;
		cout<<"Enter No. of cities : ";
		cin>>v;
		vtx = v;	
		for(int i=0;i<v;i++){
			head[i] = new node;
			cout<<"Enter name of city "<<i+1<<" : ";
			cin>>names[i];
			head[i]->name = names[i];
			//cout<<"Enter a data : ";
			//cin>>head[i]->data;
			head[i]->data = 0;
		}
	}
	
	void get_data(){
		int edge,sv,ev,d;
		node *newnode,*temp;
		cout<<"Enter how many flight connections are there : ";
		cin>>edge; e = edge; cout<<"\t";
		for(int i=0;i<vtx;i++){
			cout<<i+1<<". "<<names[i]<<"\t";
		}
		cout<<"\nEnter connections ex.[1 2]  : ";
		for(int i=0;i<edge;i++){
			cin>>sv>>ev;
			sv--;ev--;
			cout<<"Enter data for it : ";cin>>d;
			newnode = new node;
			newnode->name = names[ev];
			newnode->data = d;
			newnode->left = NULL;
			
			for(temp=head[sv];temp->left!=NULL;temp=temp->left);
					temp->left=newnode;
			
		}
	}
	void display(){
		node *temp;
		for(int i=0;i<vtx;i++){
			for(temp=head[i];temp != NULL;temp = temp->left){
				cout<<temp->name<<" : "<<temp->data<<"\t-> ";
			}
			cout<<endl;
		}
	}
	
};

int main(){
	flight x;
	x.get_data();
	x.display();
	return 0;
}
