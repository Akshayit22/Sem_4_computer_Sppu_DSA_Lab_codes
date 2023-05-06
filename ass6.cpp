#include<iostream>
using namespace std;

class Node
{
	public :
		char   meaning[10];
		char  keyword[10];
		Node * left,*right;
};

class btree
{
	public :
		Node * root;
		btree(){
			root = NULL;
		}
		
		void creat();
		void insert();
		void inorder(Node *);
		void preorder(Node  *);
		void postorder(Node *);
		void minimum( Node *);
		void maximum( Node *);
		void search( Node *);
		int longpath( Node *);


};

/*void btree :: creat()
{
root = new Node;
cout << " \n enter root node";
cin>> root-> data;
root -> left = NULL;
root -> right = NULL;
cout << " tree is created ";
}
*/
void btree :: insert ()
{
	char  x[10],y[10];
	char ch;
	Node * p, *q;
	if (root == NULL)
	{ //creat();
		root = new Node;
		cout << " \n enter the keyword ";
		cin>> root-> keyword;
		cout << " \n enter  its meaning ";
		cin>> root-> meaning;
		root -> left = NULL;
		root -> right = NULL;
		cout << " key  and its meaning inserted";
	return;
	}
	cout<<"\n Enter the keyword";
	cin >> p -> keyword;
	p = new Node ;
	//p -> keyword;
	cout << " \n enter  its meaning ";
	cin>>p-> meaning ;
	//p-> meaning;
	
	p-> left = NULL;
	p -> right = NULL;
	q = root;
	while (q != NULL)
	{
		if (q->keyword > p -> keyword)
		{
			if ( q-> left == NULL )
			{
				q->left = p ;
				return;
			}
			else
			{
				q = q-> left;
			}
		}
		else if ( q -> keyword < p -> keyword)
		{
			if( q -> right == NULL )
			{
				q -> right = p ;
				return ;
			}
			else
			{
				q = q-> right;
			}
		}


	}
}

void btree :: preorder( Node * temp)
{
	if ( temp != NULL )
	{
		cout << " " << temp -> keyword;
		preorder(temp->left);
		preorder( temp -> right);
	}
}

void btree :: inorder( Node * temp)
{

	if (temp == NULL)
        	return;
 
   	 
    	inorder(temp->left);
 
    	cout << temp->keyword << " ";

    	inorder(temp->right);
}

void btree :: postorder( Node * temp)
{
	if ( temp != NULL)
	{
		postorder( temp -> left);
		postorder ( temp -> right);
		cout << " " << temp -> keyword;
	}
}


void btree :: search (Node *temp)
{
	char val[10];
	cout <<"enter the value to be search"<<endl;
	cin>>val;

	Node *q;


	q = temp;
	while (q != NULL)
	{
		if ( q -> keyword == val)
		{	cout <<" value is found  "<<endl;
			return;}
		if (q->keyword > val)
		{
			if ( q-> left == NULL )
			{
				//q->left = p ;
				cout <<"value not found"<<endl;
				return;
			}
			else
			{
				q = q-> left;
			}
		}
		else if ( q -> keyword < val)
		{
			if( q -> right == NULL )
			{
				//q -> right = p ;
				cout <<"value not found"<<endl;
				return ;
			}
			else
			{
				q = q-> right;
			}
		}

	}
 }

int main()
{
	btree b;


	int ch;
	do
	{
	cout<<"   \n  ********MENU********"<<endl;
	cout<<"\n enter 1 for insert \n enter 2 for preorder \n enter 3 for inoreder \n enter 4 for postorder \n";
	cout << " enter 5 for minimum \n enter 6 maximum \n enter 5 for search \n enter  8 for finding number of node  in longest path \nenter 9 exit\n "<< endl;
	cout <<"\n enter ther choice"<< endl;
	
	cin>> ch;
	char inp;
	
	switch (ch)
	{
		case 1 :
			//b.creat();
			//cout<<"enter the number of datas you want to insert"<<endl;
			//int k;
			//cin>>k;
			//for( int i=0;i<k;i++){
				b.insert();
			//}
			break;
		case 2 :
			cout << " \n preorder traversal is "<<endl;
			b.preorder(b.root);
			cout<<endl;
			break;

		case 3 :
			cout << " \n inorder  traversal is "<< endl;
			b.inorder(b.root);
			cout<<endl;
			break;
		case 4 :
			cout <<"\n postorder traversal is "<< endl;
			b.postorder(b.root);
			cout<<endl;
			break;
		
		case 5:

			b.search(b.root);
			break;
		
		case 6 :
			cout << " \n EXITING ...."<<endl;
			break;
		default :
			cout<< " invalid input "<<endl;
			break;


	}
	
	}while ( ch != 9);


}
