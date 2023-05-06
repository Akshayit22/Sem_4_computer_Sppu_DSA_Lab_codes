#include<iostream>
#include<stack>
using namespace std;
class node{
	public:
	int data;
	node *left;
	node(){
		data=0;
		left=NULL;
	}
	
}; 
class graphll{
	public:
		node *head[10];
		int visited[10];
		int vtx,edge;
		stack <int> st;
		int fr,rr;
		int q[30];
		graphll(int v){
			vtx = v;
			for(int i=0;i<v;i++){
				head[i] = new node;
				head[i]->data = i;
				head[i]->left = NULL;
			}
			for(int i=0;i<10;i++){
				visited[i] = 0;
			}
		}
		void get_edges(){
			int sv,ev;
			node *newnode,*temp;
			cout<<"Enter no. of edges of graph : ";
			cin>>edge;
			cout<<"Enter starting vertex then ending vtx ex.(0 1) : ";
			for(int i=0;i<edge;i++){
				
				cin>>sv>>ev;
				sv--;ev--;
				newnode=new node;
				newnode->data=ev;
				for(temp=head[sv];temp->left!=NULL;temp=temp->left);
					temp->left=newnode;
				
			}
		}
		void display(){
				node *temp;
				for(int i=0;i<vtx;i++){
					cout<<endl;
					for(temp=head[i];temp!=NULL;temp=temp->left)
						cout<<temp->data<<" ->  ";
				}cout<<endl;
		}
		void dfsr(int s){
			visited[s] = 1;
			cout<<s<<" ";
			node *temp;
			for(temp=head[s];temp!=NULL;temp=temp->left){
				if(visited[temp->data] == 0){
					dfs(temp->data);
				}
			}
						
		}
	
		void dfs(int s){
			int v;node *temp;
			st.push(s);
			while(st.empty() != 1){
				v = st.top();st.pop();
				if(visited[v]==0){
					visited[v] = 1;
					cout<<v<<" ";
					for(temp=head[s];temp!=NULL;temp=temp->left){
						st.push(temp->data);
					}
				}
			}
		}
		void bfs(int x){
			int v=0;node *temp;
			visited[x] = 1;	
			fr = rr = -1;
			q[rr++] = x;
			while(fr != rr){
				v = q[fr++];
				cout<<" "<<v;
				
				for(temp=head[v];temp!=NULL;temp=temp->left){
						if(visited[temp->data] != 1){
							q[rr++] = temp->data;
							visited[temp->data] = 1;	
						}
				}

			}
		}
};
int main(){
	int y;
	cout<<"Enter no. of vertex of graph : ";
	cin>>y;
	graphll g(y);
	g.get_edges();
	g.display();
	cout<<endl;
	//g.dfsr(0);
	g.bfs(0);
	return 0;
}
