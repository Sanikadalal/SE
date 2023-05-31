#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{  
	int a;
	node *left,*right;// pointer to the left child node.
};
 
class Bt
{ 	 
    public:
     node *root=NULL,*temp=NULL,*t1=NULL,*s=NULL, *t=NULL;// temporary node pointers used in different operations.

     int count;     //storing height of tree
     Bt()
     {  
     count=0;    //count variable is to 0
     }
     
     node *create();//member function
     void insert();
     void find();
     void search();
     void swap(node*);//get mirror image
     int height(node*,int);
     void disp(node*);   
};

node *Bt::create()
{  
    node *p=new(struct node);//new node dynamically allocatin memory
    p->left=NULL;
    p->right=NULL;
    cout<<"\n Enter the data : ";
    cin>>p->a;
    return p;
}

void Bt::insert()
{  
    temp=create();//create() function to create a new node and assigns the returned pointer to the temp
    if(root==NULL)      
        root=temp;          
    else
    {    
      t1=root;
      while(t1!=NULL)
      {      
        s=t1;
        if((temp->a)>(t1->a)) //temp is greater than the current node's data value
            t1=t1->right;    
        else
            t1=t1->left;    
      }
      if((temp->a)>(s->a))  // value of temp is greater than the current node's data value, 
          s->right=temp;    
      else   
          s->left=temp;       
    }             
}

void Bt::find()
{ 
    if(root==NULL)
    {    
      cout<<"\n Tree not exist !!";  
    }
    else
    {
      t1=root;   //if tree is not empty t1 pointer to the root.
      while(t1->left!=NULL)
      {      
        t1=t1->left;
      }           
      cout<<"\n Minimum Value = "<<t1->a;

      t1=root;  
      while(t1->right!=NULL)
      {       
        t1=t1->right;       
      }        
      cout<<"\n Maximum Value = "<<t1->a; //store it in a member variable 
    }
} 

void Bt::search()
{   
    int m,f=0;//m data value to be searched, and f is used as a flag variable to indicate whether the data is found.
    if(root==NULL)
        cout<<"\n Tree not exist !!";
    else
    {
     cout<<"\n Enter data to be searched : ";
     cin>>m;
     if(root->a==m)   
         cout<<" Data found in Tree !!";  
     else
     {    
        t1=root;
        while(t1->a!=m)
        {
          if((m)>(t1->a))    
              t1=t1->right;  
          else   
              t1=t1->left; 

          if(t1==NULL)
          {   
            cout<<" Data not found in Tree !!";     
            f=1; 
            break;
          }
        }
        if(f==0)
        {   cout<<" Data found in Tree !!";    }
     }
    }  
} 


void Bt::swap(node *q)
{
	if (q==NULL)
		return;
   	if(q->left!=NULL)
   		swap(q->left);
   	if(q->right!=NULL)
	   	swap(q->right);
	   	t=q->left;
	   	q->left=q->right;
	   	q->right=t;
}    

int Bt::height(node *q,int c)  
{  
    c++;
    if(q->left!=NULL)      
        height(q->left,c);    
    if(q->right!=NULL) 
        height(q->right,c);
    if(count<c)
        count=c;  
    return 0;
}
                       
void Bt::disp(node *q) 
{ 	
	if (q == NULL)
		return;
	disp(q->left);
    cout<<" -> "<<q->a;
    disp(q->right);       
}

int main()
{ 
   Bt b; 
   int ch;
   while(1)
   {
    cout<<"\n\n *******   MENU   *******";
    cout<<"\n 1.Insert";
    cout<<"\n 2.Smallest & Greatest Value";
    cout<<"\n 3.Search";
    cout<<"\n 4.Mirror";
    cout<<"\n 5.Height";
    cout<<"\n 6.Display";
    cout<<"\n 7.Exit";
    cout<<"\n\n Enter your choice : ";
    cin>>ch;
    
    switch(ch)
    {     
    case 1: 
        b.insert();
        cout<<" Tree After Inserting :\n";
        b.disp(b.root);
        break;

    case 2: 
        b.find();
        break;

    case 3: 
        b.search();
        break;
            
    case 4: 
        if(b.root==NULL)  
            cout<<"\n Tree not exist.\n";
        else
        {
            b.swap(b.root);
            cout<<"Tree After Mirroring :\n";
            b.disp(b.root);
        }
        break;
            
    case 5: 
        b.count=0;
        if(b.root==NULL) 
            cout<<"\n Tree not exist.\n";
        else
        {
            b.height(b.root,0); 
            cout<<"\n Height of the tree is : "<<b.count;    
        }
        break;
            
    case 6: 
        if(b.root==NULL) 
            cout<<"\n Tree not exist.\n";
        else
            b.disp(b.root);     
        break;

    case 7:
        cout<<" Thanks for using this Program !!";
        exit(0);
    }                
   }         
   return 0;
}