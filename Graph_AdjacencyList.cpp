#include<iostream>
using namespace std;

class Node
{
	int data;
	//int weight;
	Node *next;
public:
	Node()
	{
		data=0;
		next=NULL;
	}
	friend class GraphALL;
};
class GraphALL
{
	Node* da[10];
	int vertex,edges;  
	int visit[10];
	public:
		GraphALL(int v,int e)
		{
			vertex=v;
			edges=e;
			
			for(int i=0;i<vertex;i++)
			{
				da[i]=new Node;
				da[i]->data=i;
				
			}
		}
			void initvisit()
		{
			for(int i=0;i<vertex;i++)
			{
				visit[i]=0;
			}
		}
		void create()
		{
			int sv,ev;
			Node *newnode,*temp;
			for(int i=0;i<edges;i++)
			{
				cout<<"\nEnter start vertex & end vertex";
				cin>>sv>>ev;
				newnode=new Node;
				newnode->data=ev;
				for(temp=da[sv];temp->next!=NULL;temp=temp->next);
					temp->next=newnode;
				
				
			}
		}
		void display()
		{
			Node *temp;
			for(int i=0;i<vertex;i++)
			{
				cout<<endl;
				for(temp=da[i];temp!=NULL;temp=temp->next)
					cout<<temp->data<<"->";
			}cout<<endl;
		}
		void DFS(int v)
		{
			
			if(visit[v]==0)
			{
				cout<<v<<"\t";
				visit[v]=1;
				for(Node *temp=da[v];temp!=NULL;temp=temp->next)
				   		DFS(temp->data);
			}
		}
		
	
};
main()
{
	int v,e;
	cout<<"\nEnter a Number of vertex";
	cin>>v;
	cout<<"\nEnter a Number of edges";
	cin>>e;
	GraphALL g1(v,e);
	g1.create();
	g1.display();
	g1.initvisit();
	g1.DFS(0);
	
}

/*
//code by me

#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left;
		node(){
			data = 0;
			left = NULL;
		}
		node(int x){
			data = x;
			left = NULL;
		}
};

class graph{
	public:
		int x;
		node* head[10];
		graph(){
			int vtx;
			cout<<"Enter how many vertices graph have : ";
			cin>>vtx;
			//vtx = x;
			x = vtx;
			//node *head[x];
			for(int i=0;i<vtx;i++){
				head[i] = new node;
				head[i]->data = i+1;
				head[i]->left = NULL;
			}
		}
		
		void creat();
		void read();
		void display();
		//void DFS()
};




void graph :: display(){
	node *temp;
			for(int i=0;i<x;i++){
				cout<<endl;
				for(temp=head[i];temp!=NULL;temp=temp->left)
					cout<<temp->data<<"->";
			}cout<<endl;
			
}
void graph :: read(){
	int ch=0;
	node *newnode,*temp;
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			cout<<"is there any link/edge between "<<i+1<<" and "<<j+1<<" (1/0) : ";
			cin>>ch;
			if(ch == 1){
				newnode = new node();
				newnode->data = j+1;
				newnode->left = NULL;
				
				for( temp=head[i]; temp->left != NULL ; temp=temp->left);
					temp->left=newnode;
				
			}
		}
	}
}

int main(){
	//int v;
	//cin>>v;
	graph g;
	g.display();
	g.read();
	g.display();
	return 0;
}




*/
