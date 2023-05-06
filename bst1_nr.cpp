#include<iostream>
using namespace std;
#include<stack>
class Node
{
public :
int data;
Node * left,*right;
};

class btree
{
public :
Node * root;
btree()
{
root = NULL;
}

void creat();
void insert();
void minimum( Node *);
void maximum( Node *);
void search( Node *);
void in_non_rec(Node *);
void pre_non_rec(Node *);
void post_non_rec(Node * temp) ;

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
int  x;
char ch;
Node * p, *q;
if (root == NULL)
{ //creat();
root = new Node;
cout << " \n enter root node";
cin>> root-> data;
root -> left = NULL;
root -> right = NULL;
cout << " tree is created ";
return;
}
cout<<"\n Enter the data";
cin >> x;
p = new Node ;
p -> data = x;
p-> left = NULL;
p -> right = NULL;
q = root;
while (q != NULL)
{
if (q->data > p -> data)
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
else if ( q -> data < p -> data)
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



void btree :: minimum( Node * temp)
{
//temp = root;
while( temp-> left !=  NULL)
{
temp = temp -> left ;
}
cout << " minimum number is " << temp -> data ;
}

void btree :: maximum( Node * temp)
{
//temp = root;
while( temp-> right !=  NULL)
{
temp = temp -> right ;
}
cout << " maximum number is " << temp -> data ;
}

 void btree :: search (Node *temp)
 {
  int val;
cout <<"enter the value to be search"<<endl;
cin>>val;

Node *q;


q = temp;
while (q != NULL)
{
if ( q -> data == val)
{cout <<" value is found  "<<endl;
return;}
if (q->data > val)
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
else if ( q -> data < val)
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


void btree :: in_non_rec(Node * temp)
{
	stack <Node *> s;
	
	while(1)
	{
		while( temp != NULL)
		{
			s.push(temp);
			temp= temp -> left;
			
		}
		if (s.empty())
		return;
		temp = s.top();
		s.pop();
		cout<< temp -> data<<" ";
		temp = temp-> right;
	}

}

void btree :: pre_non_rec(Node * temp)
{
	
	stack <Node *> s;
	while(1)
	{
		while(temp != NULL)
		{
			cout << temp -> data<<" ";
			s.push(temp);
			temp = temp -> left;
		}
		if( s.empty())
		return;
		temp = s.top();
		s.pop();
		temp = temp -> right;
	}
}

void btree :: post_non_rec(Node * temp)
 {

    if (root == NULL) return;
    stack <Node *> s1,s2;

    s1.push(temp);
 
    while (!s1.empty()) {
        temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp -> left != NULL) s1.push(temp -> left);

        if (temp -> right != NULL) s1.push(temp -> right);
    }
    // Print the second stack
    while(!s2.empty()) {
        cout << s2.top() -> data << " ";
        s2.pop();
    }
    cout << endl;
}
int main()
{
btree b;


int ch;
do
{
cout<<"   \n  ********MENU********"<<endl;
cout<<"\n enter 1 for insert \n enter 2 for preorder \n enter 3 for inoreder \n enter 4 for postorder \n";
cout << " enter 5 for minimum \n enter 6 maximum \n enter 7 for search \nenter 8 exit\n "<< endl;
cout <<"\n enter ther choice"<< endl;
cin>> ch;
switch (ch)
{
case 1 :
//b.creat();
b.insert();
break;
case 2 :
cout << " \n preorder traversal is "<<endl;
b.pre_non_rec(b.root);

cout<<endl;
break;

case 3 :
cout << " \n inorder  traversal is "<< endl;
b.in_non_rec(b.root);
cout<<endl;
break;
case 4 :
cout <<"\n postorder traversal is "<< endl;
b.post_non_rec(b.root);
cout<<endl;
break;
case 5 :
cout << "minimum value is ";
b.minimum(b.root);
break;
case 6 :
cout << "maximum  value is ";
b.maximum(b.root);
break;
case 7:

b.search(b.root);
break;
case 8 :
cout << " \n EXITING ...."<<endl;
break;
default :
cout<< " invalid input "<<endl;


}
}while ( ch != 8);


}
