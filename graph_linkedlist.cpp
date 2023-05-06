#include<iostream>
using namespace std;

class node{
	public:
		string name;
		int data;
		int id;
		node *left;
		node(){
			name = "null";
			data = 0;
			id = -1;
			left = NULL;
		}		
};

class graph{
	public:
		int x;
		node* head[10];
		graph(){

			int vtx;
			cout<<"Enter how many cities : ";
			cin>>vtx;
			x = vtx;
			
			for(int i=0;i<x;i++){
				head[i] = new node;
				cout<<"Enter name of city "<<i+1<<" :";
				cin>>head[i]->name;
				head[i]->id = i;
			}
		}
		
		void creat();
		void read();
		void display();
		void search();
		
		//void DFS()
};




void graph :: display(){
	node *temp;
	for(int i=0;i<x;i++){
		cout<<endl;
		for(temp=head[i];temp!=NULL;temp=temp->left)
			//cout<<temp->id+1<<"\t";
			cout<<temp->name<<" :"<<temp->data<<" ->  ";
	}cout<<endl;
			
}
void graph :: read(){
	int ch=0;
	node *newnode,*temp;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){

			cout<<"is there any link/edge between "<<head[i]->name<<" and "<<head[j]->name<<" (1/0) : ";
			cin>>ch;
			if(ch == 1){
				cout<<"Enter time required to :";
				newnode = new node();
				newnode->name = head[j]->name;
				cin>>newnode->data;
				newnode->id = j;
				newnode->left = NULL;
				
				for( temp=head[i]; temp->left != NULL ; temp=temp->left);
					temp->left=newnode;
				
			}
		}
	}
}

void graph :: search(){
	int s=0,d=0;
		cout<<"SEARCHING FOR FLIGHTS between two cities.\n";
		
		for(int i=0;i<x;i++){
			cout<<"\t"<<i+1<<".  "<<head[i]->name;
		}
		cout<<"\nchooes first city : ";cin>>s;
		cout<<"chooes second city : ";cin>>d;
		s--;d--;
		//cout<<s<<" "<<d;
		if(s==d || s>x || d>x){
			cout<<"\n\tCAN'T FIND FLIGHT FOR THE SAME\n";
		}
		else{
			int ts=0;
			node *temp,*temp2;
			for(temp=head[s];temp!=NULL;temp=temp->left){
				if(temp->id == d){
					cout<<"Direct flight available , time required : "<<temp->data<<endl;
					return ;
				}else{
					ts = temp->id;
					for(temp2=head[ts];temp2!=NULL;temp2=temp2->left){
						if(temp2->id == d){
							cout<<"\nfirst go with : "<<head[s]->name<<" to "<<head[ts]->name;
							cout<<"\nsecond go with : "<<head[ts]->name<<" to "<<head[d]->name;
						return ;
						}
					}
				}
			}
			
			
		}
}
int main(){
	graph g;
	int ch=0;
	do{
	
	cout<<"\n1.Enter data \n2.Display data\n3.search flight\n4.\n5.EXIT\nEnter choice : ";
	cin>>ch;
		switch(ch){
			case 1:
					g.read();
				break;
			case 2:
					g.display();
				break;
			case 3:
					g.search();
				break;
			case 4:
					
				break;
			case 5:
					exit(0);
				break;
			default:
				cout<<"ENTER CORRECT CHOICE.";
				break;			
						
		}
	}while(true);
	
	return 0;
}
/*
				else{
					ts = temp->id;
					for(temp2=head[ts];temp2!=NULL;temp2=temp2->left){
						if(temp2->id == d){
							cout<<"\nfirst go with : "<<head[s]->name<<" to "<<head[ts]->name;
							cout<<"\nsecond go with : "<<head[ts]->name<<" to "<<head[d]->name;
						return ;
						}
					}
				}
*/
