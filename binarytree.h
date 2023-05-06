#include <iostream>
#include "stack.h"
using namespace std;
class node{
	int data;
	node *leftNode,*rightNode
};

class btree
{
        Node *root;
        public:
        Node* createNode();
        void insertNode();
        bool checkRoot();
        void display();
        void innerorder(Node*);
        void innerorder();
        void postorder(Node*);
        void postorder();
        void preorder(Node*);
        void preorder();
        bool searchNode(int);//For User Passed Value
        void searchNode();
        void deleteNode();
        btree()
        {
                root = NULL;
        }
        
};
Node *btree :: createNode()
{
    Node *temp = new Node;
    int value;
    cout << "Enter the value to be inserted to Node:";
    cin >> value;
    if (temp == NULL)
    {
        cout << "Memory not allocated" << endl;
        return 0;
    }
    else
    {
        temp->data = value;
        temp->leftNode = NULL;
        temp->rightNode = NULL;
        return temp;
    }
}
bool btree :: checkRoot()
{
        if(root!=NULL)
                return true;
        return false;
}
void btree :: insertNode()
{
        Node *temp;
        temp = createNode();
        if(!checkRoot())
        {
                root=temp;
                cout<<"Insert "<<temp->data<<" At Root Node"<<endl;
                return;
        }
        else
        {
                char ch;
                Node *q;
                q=root;
                while(q!=NULL)
                {
                        if(q->data==temp->data)
                        {
                                cout<<"Duplication not allowed"<<endl;
                                return;
                        }
                        else if(q->data>temp->data)
                                if(q->leftNode==NULL)
                                {
                                       q->leftNode = temp;
                                       cout<<"Insert "<<temp->data<<" At Left Node"<<endl;
                                       return ;
                                }
                                else
                                       q = q->leftNode;
                        else if(q->data<temp->data)
                                if(q->rightNode==NULL)
                                {
                                        q->rightNode = temp;
                                        cout<<"Insert "<<temp->data<<" At Right Node"<<endl;
                                        return;
                                }
                                else
                                        q = q->rightNode;
                        else
                                cout<<"Invalid Choice:"<<endl;
                }
        }
}
void btree :: display()
{
    char ch;
    bool loop=true;
    while(loop)
    {
            cout<<"Menu:"<<endl;
            cout<<"1.Inorder"<<endl;
            cout<<"2.Preorder"<<endl;
            cout<<"3.Postorder"<<endl;
            cout<<"4.Exit"<<endl;
            cout<<"Enter the choice:";
            cin>>ch;
            switch(ch)
            {
                case '1':
                        cout<<"Inorder of Tree:";
                        innerorder(root);
                        cout<<endl;
                        break;
                case '2':
                        cout<<"Preorder of Tree:";
                        preorder(root);
                        cout<<endl;
                break;
                case '3':
                        cout<<"Postorder of Tree:";
                        postorder(root);
                        cout<<endl;
                break;
                case '4':
                        loop = false;
                        break;
                default:
                        cout<<"Enter a valid choice"<<endl;
                break;      
            }
               
    }     
}
void btree::innerorder(Node* temp)
{
        if(temp!=NULL)
        {
                innerorder(temp->leftNode);
                cout<<temp->data<<" ";
                innerorder(temp->rightNode);
        }
        return;     
}
void btree::preorder(Node* temp)
{
        if(temp!=NULL)
        {
                cout<<temp->data<<" ";
                preorder(temp->leftNode);
                preorder(temp->rightNode);
        }
        return;     
}
void btree::postorder(Node* temp)
{
        if(temp!=NULL)
        {
                postorder(temp->leftNode);
                postorder(temp->rightNode);
                cout<<temp->data<<" ";
        }
        return;     
}
bool btree:: searchNode(int searchNodeValue)
{
        Node *q;
        if(checkRoot())
        {
                q=root;
                while(q!=NULL)
                {
                        if(q->data==searchNodeValue)
                                return true;
                        else if(q->data>searchNodeValue)
                                q = q->leftNode;
                        else
                                q = q->rightNode;
                }
        }
        else
        cout<<"The Binary Search Tree is empty."<<endl;
        return false;
}
void btree::searchNode()
{
        int nodeToSearch;
        cout<<"Enter Search Node:";
        cin>>nodeToSearch;
        if(searchNode(nodeToSearch))
                cout<<nodeToSearch<<" found successfully"<<endl;       
        else
                cout<<nodeToSearch<<" Node not found";
        return;
}
void btree::deleteNode()
{
        int nodeToDelete;
        cout<<"Enter the number to delete:";
        cin>>nodeToDelete;
        if(searchNode(nodeToDelete))
        {

        }
        cout<<"Node not present";
        return;
}
