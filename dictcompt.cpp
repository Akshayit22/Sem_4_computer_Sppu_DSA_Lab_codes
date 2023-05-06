#include <iostream>
using namespace std;

const int MAX=26;
class dictionary;
class node
{
	      string key,value;
	      node *next;
	public:
	      friend class dictionary;
		    node()
		    {
		       next=NULL;
	      	}
		    node(string key,string value)
		    {
		            this->key=key;
		            this->value=value;
		            next=NULL;
		    }
};

class dictionary
{
    node *head[MAX];
public:
    	dictionary()
		{
            for(int i=0;i<MAX;i++)
                  head[i]=NULL;
		}
	    int hashf(string word);
	    void insert(string,string);
	    void find(string word);
	    bool deleteWord(string word);
	    void display();
};


int dictionary::hashf(string word)
{
      int ascii=0;
      ascii = word[0];
      if(ascii < 95){ ascii += 32; }
      return (ascii%97);
}

void dictionary::insert(string word,string meaning)
{
      int index=hashf(word);
      node *p=new node(word,meaning);

      if(head[index]==NULL)
      {
            head[index]=p;
      }
      else
      {
            node *start=head[index];//creating new pointer at arr index where collision occurce
            p->next = start->next;

            start->next=p;
      }

      cout<<endl<<word<<" inserted into dictionary at index"<<index;
}


void dictionary::find(string word)
{
      int index=hashf(word);
      int flag=0;
      node *start=head[index];
      while(start!=NULL)
      {

            if(start->key==word)
            {
                  flag=1;
		  cout<<"Word Is  present.\n";
		  cout<<"Meaning is "<<start->value;
                  break;
            }
            start=start->next;
      }
      if(flag==1)
            cout<<".";
            
      else
            cout<<"Word Is not present.";
}




bool dictionary::deleteWord(string word)
{
      int index=hashf(word);
      node *tmp=head[index];
      node *par=head[index];
      if(tmp==NULL) //if no word is present at that index
      {
            return false;
      }
      if(tmp->key==word && tmp->next==NULL)//only one word is present
      {
            head[index]=NULL;
            delete tmp;
            return true;
      }
      //tmp=tmp->next;
      while(tmp->key!=word && tmp->next!=NULL)//more than one word is present
      {
            par=tmp;
            tmp=tmp->next;
      }
      if(tmp->key==word && tmp->next!=NULL)
      {
          if(par->key==tmp->key)
          {
              head[index]=tmp->next;
          }
          else
          {
            par->next=tmp->next;
            tmp->next=NULL;
          }
            delete tmp;
            return true;
      }
      else //delete at end
      {
            par->next=NULL;
            tmp->next=NULL;
            delete tmp;
            return true;
      }
      return false;
}

void dictionary:: display()
{
      cout<<"\nIndex  \t Key \t Value";
      for(int i=0;i<26;i++)
      {
            node *start=head[i];
            if(start==NULL)
                  cout<<"\n";
            while(start!=NULL)
            {
                  cout<<"\n:"<<i<<"\t"<<start->key <<"\t "<<start->value;
                  start=start->next;
            }
      }
}



int main() {
      dictionary oxford;
      int choice;
      string word , meaning;
     
      do
      {
            cout<<"\n**** MENU ****\n"
                        <<"1.Insert Word\n"
                        <<"2.Find Word\n"
                        <<"3.Delete Word\n"
                        <<"4.Display\n"
                        <<"Enter Your Choice :";
            cin>>choice;
            switch(choice)
            {
            case 1:
                  cout<<"Enter Word: ";
                  cin>>word;
                  cout<<"Enter Meaning: ";
                  cin>> meaning;
                  oxford.insert(word,meaning);

                  break;
            case 2:
                  cout<<"Enter Word to Search: ";
                  cin>>word;
                  oxford.find(word);

                  break;
            case 3:
                  cout<<"Enter Word to Delete: ";
                  cin>>word;
                  if(oxford.deleteWord(word))
                        cout<<" Word is deleted.";
                  else
                  {
                        cout<<"\nFailed to delete "<<word;
                  }
                  break;

            case 4:
                  cout<<"***DISPLAYING***";
                  oxford.display();
                  break;
            default:
                  cout<<"\nWrong Choice.";
                  break;
            }

      }while(choice!=0);

      return 0;}

