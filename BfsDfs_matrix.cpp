#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class graph{
	public:
	int j,vtx;
	int arr[10][10];
	int visited[10];
	int fr,rr;
	int q[10];
	stack<int>st;
	//queue<int>q; 
	graph(){
		for(int i=0;i<10;i++){
			visited[i]= 0;
			
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				arr[i][j] = 0;
			}
		}
		cout<<"Enter NO. of vertice of graph : ";
		cin>>vtx;
	}
	
	void display(){

		cout<<"\n MATRIX :\n";
		for(int i=0;i<vtx;i++){
			for(int j=0;j<vtx;j++){
				cout<<arr[i][j]<<"   ";
			}
			cout<<endl;
		}
	}
	
	void get_edges(){
		int f,e,v;
		cout<<"enter how many edges want to insert : ";
		cin>>f;
		cout<<"\n Enter starting edge and ending edge ( greter than 0)\n";
		cout<<"ex.[1 3] :  ";
		for(int i=0;i<f;i++){
			cin>>e>>v;
			e--;v--;
			arr[e][v] = 1;
			arr[v][e] = 1;
			cout<<"  Next   :  ";
		}
	}
	void dfs(int x){
		int v;
		st.push(x);
		while(st.empty() != 1){
			v = st.top();
			st.pop();
			if(visited[v] == 0 ){
				cout<<(v+1)<<" ";
				visited[v] = 1;
				for(int i=0;i<vtx;i++){
					if(arr[v][i] != 0){
						st.push(i);
					}
				}
			} 
		}
	}
	//reccursive
	void dfsr(int x){
		cout<<(x+1)<<" ";
		visited[x] = 1;
		for(int i=0;i<vtx;i++){
			if(arr[x][i] != 0 && visited[i]==0 ){
				dfsr(i);
			}
		}
	}
	
	void bfs(int x){
		int v=0;
		visited[x] = 1;	
		fr = rr = -1;
		q[rr++] = x;
		while(fr != rr){
			v = q[fr++];
			cout<<" "<<v;
			for(int i=0;i<vtx;i++){
				if(arr[x][i] != 0 && visited[i] == 0){
					q[rr++] = v;
					visited[v] = 1;	
				}
			}
		}
	}
};

int main(){
	graph g;
	g.get_edges();
	g.display();
	g.bfs(0);
	return 0;
}
