#include<iostream>
using namespace std;

class graph{
public:
	
	int x,ch,t,f;
	string names[7];
	int time[7][7];
	int fule[7][7];
	graph(){
		x = 4;
		for(int i=0;i<7;i++){
			names[i]= "ll";
		}
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				time[i][j] = 00;
				fule[i][j] = 00;
			}
		}
		
	}
	void read(){
		
		int vtx;
		cout<<"Enter how many cities : ";
		cin>>vtx;
		x = vtx;	

		for(int i=0;i<vtx;i++){
			cout<<"Enter name of city "<<i+1<<" " ;
			cin>>names[i];
		
		}
		
		for(int i=0;i<vtx;i++){
		
			for(int j=0;j<vtx;j++){
				
				cout<<"Is there any fligh available for "<<names[i]<<" and "<<names[j]<<" (0 / 1) ";	
				
				cin>>ch;
				if(ch == 1){
					cout<<"Enter time required between "<<names[i]<<" and "<<names[j]<<"  : ";
					cin>>t; 
					time[i][j] = t;
					
					cout<<"Enter fule required between "<<names[i]<<" and "<<names[j]<<"  : ";
					cin>>f;
					fule[i][j] = f;	
 					cout<<endl;
				}else{
					time[i][j] = 0;
					fule[i][j] = 0;

				}

			}

		}
	}
	void display(){
		
		cout<<"\nTIME MATRIX :\n";
		for(int i=0;i<x;i++){
			cout<<"\t"<<names[i];
		}
		cout<<endl;
		for(int i=0;i<x;i++){
			cout<<names[i]<<"\t";
			
			for(int j=0;j<x;j++){
				cout<<time[i][j]<<"\t";
			}
			cout<<endl;
		}
		
		cout<<"\nFULE MATRIX :\n";
		for(int i=0;i<x;i++){
			cout<<"\t"<<names[i];
		}
		cout<<endl;
		for(int i=0;i<x;i++){
			cout<<names[i]<<"\t";
			
			for(int j=0;j<x;j++){
				cout<<fule[i][j]<<"\t";
			}
			cout<<endl;
		}	
		
	}
	
	void search(){
		int s=0,d=0;
		cout<<"SEARCHING FOR FLIGHTS between two cities.\n";
		
		for(int i=0;i<x;i++){
			cout<<"\t"<<i+1<<".  "<<names[i];
		}
		cout<<"\nchooes first city : ";cin>>s;
		cout<<"chooes second city : ";cin>>d;
		s--;d--;
		if(s==d ){
			cout<<"SORRY, NO FLIGHTS AVAILABLE.\n";
			//finding another way to reach destination
			//check_adjescent(s,d);
		}
		else if( time[s][d]==0 || fule[s][d]==0 ){
			cout<<"SORRY, NO DIRECT FLIGHTS AVAILABLE.\n";
			//finding another way to reach destination
			check_adjescent(s,d);
		}
		else{
			cout<<"Direct flight available , time required : "<<time[s][d]<<"  and fule : "<<fule[s][d]<<endl;
		}
	}
	
	void check_adjescent(int s, int d){
		int fsource=s,fdestination=d;
		for(int i=0;i<x;i++){
			if(time[s][i] != 0 ){
				for(int j=0;j<x;j++){
					if(time[i][j] != 0){
						if( j == fdestination ){
							cout<<"\nfirst go with : "<<names[fsource]<<" to "<<names[i];
							cout<<"\nsecond go with : "<<names[i]<<" to "<<names[fdestination];
							return ;
						}
					}
				}	
			}
		}
		cout<<"SORRY , NO adjescent flight available \n\n";
		return ;
	}
	
};

int main(){	
	graph g;
	int ch=0;
	do{
	
	cout<<"\n1.Enter data \n2.Display data\n3.search flight\n4.\n5.\nEnter choice : ";
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
				
				break;
			default:
				cout<<"ENTER CORRECT CHOICE.";
				break;			
						
		}
	}while(true);
	
return 0;
}
