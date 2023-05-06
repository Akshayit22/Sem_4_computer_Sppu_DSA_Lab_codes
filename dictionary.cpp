#include<iostream>
using namespace std;
#define size 13
struct dict{
	string key ;
	string value;
}; 
class hashing{
	public:
	dict hashtable[10];
	hashing(){
		for(int i=0;i<10;i++){
			hashtable[i].key = "";
			hashtable[i].value = "";
		}
	}
	int hash(string key){
		int x,y;
		x = (int)key[0];
		//cout<<x;
		if(x<95){
			x += 32;
		}
		y = x-97;
		return y;
		//cout<<"--"<<x<<"--"<<y<<endl;
	}
	void display(){
		for(int i=0;i<10;i++){
			cout<<hashtable[i].key<<"-->"
				<<hashtable[i].value<<endl;
		}
	}
	void insert(dict d){
		int pos;
		pos = hash(d.key);
		if(hashtable[pos].key==""){
			hashtable[pos] = d;
		}
		//collision condition
		else{
			
		}
		
	}
};
int main(){
	hashing h;
	h.display();
	dict d;
	
	string s,ss;
	cin>>d.key>>d.value;
	h.insert(d);
	h.display();
	
	return 0;
}
