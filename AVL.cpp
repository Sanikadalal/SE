/* A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
deleting keywords, updating values of any entry. Provide facility to display whole data 
sorted in ascending/ Descending order. Also find how many maximum comparisons may 
require for finding any keyword. Use Height balance tree and find the complexity for 
finding a keyword.*/


#include<iostream>
using namespace std;

class node
{
public:
	string key;
	string meaning;   // Declare variable 
	node *left;
	node *right;
};

class AVL
{
	node *root;
        public:
            	AVL()
            	{
            		root=NULL;
            	}
            	
	            void create();
	            node* insert(node *cur,node *temp);
            	node* balance(node *temp);  
            	int dif(node *temp);
            	int height(node *temp);
            	int maximum(int a,int b);
            	
            	node* LL(node *par);
            	node* RR(node *par);
            	node* LR(node *par);
            	node* RL(node *par);
            	
            	void ascending(node *temp);
            	node* delete_n(node *root,string key1);
            	void deleten();
            	
            	node* extractmin(node *t);
                void descending(node *temp);
                void display();
                bool search(node *cur,string key1);
                void search_value();
};

void AVL::create()
{
	char answer;
	node *temp;
	do
	{
		temp=new node(); //dymamic memory allocation
		cout<<"\n Enter the keyword:";
		cin>>temp->key;
		cout<<"\n Enter the meaning:";
		cin>>temp->meaning;
		temp->left=temp->right=NULL;  // node is created with 4 field

			root=insert(root,temp);  // call insert function for inserting created node

		cout<<"\n Do you want to add another word?(y/n)";
		cin>>answer;
	}
	while(answer=='y'||answer=='Y');
}


node* AVL::insert(node *cur,node *temp) // temp wants to insert
{
	if(cur==NULL)
	{
		return temp; //temp = root;
		
	}
	if(temp->key<cur->key)
	{
		cur->left=insert(cur->left,temp);
		cur=balance(cur); // call the balance function for cur node as avl
	}
	else if(temp->key>cur->key)
	{
		cur->right=insert(cur->right,temp);
		cur=balance(cur);
	}
	return cur;
}

node* AVL::balance(node *temp)
{
	int bal;
	bal=dif(temp);  // calculate balance factor by calling diff function
	
	if(bal>=2)  // +ve 2 means left
	
	 // we need to balance tree as 1 0 -1 is bal tree
	{
		if(dif(temp->left)<0) // -1< 0  
			temp=LR(temp);  
		else
			temp=LL(temp);  // 1 > 0
	}
	else if(bal<=-2) // -2 right 
	{
		if(dif(temp->right)<0)
			temp=RR(temp);
		else
			temp=RL(temp);
	}
	return temp;
}


int AVL::dif(node *temp) 
{
	int l,r;
	l=height(temp->left);
	r=height(temp->right);
	return(l-r); //height of temp
}

int AVL::height(node *temp) //calculate height of left and righr sub tree
{
	if(temp==NULL)
		return(-1);
	else
		return(max(height(temp->left),height(temp->right))+1); //recursively call height and consider max and add 1 for root node
}

int AVL::maximum(int a,int b)  // to calculate max value-
{
	if(a>b)
		return a;
	else
		return b;
}

node* AVL::LL(node *par)
{
	node *temp,*temp1;
	temp=par->left;
	temp1=temp->right;
	temp->right=par;
	par->left=temp1;
	return temp;
}

node* AVL::RR(node *par)
{
	node *temp,*temp1;
	temp=par->right;
	temp1=temp->left;
	temp->left=par;
	par->right=temp1;
	return temp;
}

node* AVL::LR(node *par)
{
	par->left=RR(par->left);
	return(LL(par));
}

node* AVL::RL(node *par)
{
	par->right=LL(par->right);
	return(RR(par));
}

void AVL::ascending(node *temp)
{
        if(temp!=NULL)
        {
                ascending(temp->left);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                ascending(temp->right);
        }
}

void AVL::descending(node *temp)
{
        if(temp!=NULL)
        {
                descending(temp->right);
                cout<<"\n\t"<<temp->key<<" : "<<temp->meaning;
                descending(temp->left);
        }
}


void AVL::display()
{
        cout<<"\n The keywords in ascending order are : \n";
        ascending(root);
        cout<<"\n The keywords in descending order are : \n";
        descending(root);
}

bool AVL::search(node *cur,string key1)  // key 1 wants to search
{
	if(cur)
	{
		if(cur->key==key1)
			return true;
		if(cur->key>key1)
			return search(cur->left,key1);
		else
			return search(cur->right,key1);
	}
	return false; //element not found
}

void AVL::search_value()
{
	string key2;
        cout<<"\n Enter the keyword you wish to search : ";
        cin>>key2;
        if(search(root,key2)) // search operation  of taking key from user
                cout<<"\n The entered keyword is present in the AVL tree";
        else
                cout<<"\n The entered keyword is not present in the AVL tree";
}


node* AVL::delete_n(node* cur,string key1)
{
    if ( !cur)  //cur=0 return it
    	return cur;
    if ( key1 < cur->key )
        cur->left = delete_n(cur->left, key1);

    else if( key1 > cur->key )
        cur->right = delete_n(cur->right, key1);

    else //key is root 
    {
        node *l = cur->left;
        node *r = cur->right;
        delete cur;
        if ( !r )  //r==0
        	return l;
        node *m=r; //m is right node
        
        while(m->left) //move on m left to find min of r
        	m=m->left;
        m->right = extractmin(r);
        m->left = l;
        return balance(m);
    }
    return balance(cur);
}

    node* AVL::extractmin(node *t)
    {
        if ( !t->left ) 
        return t->right;
        t->left = extractmin(t->left);
        return balance(t);
    }

void AVL::deleten() //
{
	string key;
	cout<<"\n Enter the keyword to be deleted : ";
	cin>>key;
	root=delete_n(root,key);
}

int main()
{
  char c;
  int ch;
  AVL a;
  do
  {
      cout<<"*********************************";
	  cout<<"\n 1.Insert a keyword in AVL tree.";
	  cout<<"\n 2.Display the AVL tree.";
	  cout<<"\n 3.Search a keyword";
	  cout<<"\n 4.Delete a keyword.";
	  cout<<"\n Enter your choice : ";
	  cin>>ch;
	  switch(ch)
	  {
      	  case 1 : a.create();
               break;
      	  case 2 : a.display();
               break;
      	  case 3 : a.search_value();
               break;
      	  case 4 : a.deleten();
               break;
      	  default : cout<<"\n Wrong choice ! ";
	  }
	  cout<<"\n Do you want to continue? (y/n): ";
	  cin>>c;
  	  }
  	  while(c=='y'||c=='Y');
  return 0;
}
