/*
Author: Sanika Dalal
PROBLEM STATEMENT:
	You have a business with several offices; you want to lease phone lines to connect them up
	with each other; and the phone company charges different amounts of money to connect
	different pairs of cities. You want a set of lines that connects all your offices with 		minimum total cost.
	Solve the problem by suggesting appropriate data structures.
*/

#include<iostream>
using namespace std;

class tree
{
	int a[20][20],l,u,w,i,j,v,e,visited[20];
public:
	void input(); //functions
	void display();
	void minimum();
};

void tree::input() //regarding branches connection
{
	cout<<"Enter the no. of branches: "; //vertices
	cin>>v;

	for(i=0;i<v;i++) //row for matrix representation
	{
		visited[i]=0;
		for(j=0;j<v;j++) //column 
		{
			a[i][j]= 0; //999;
		}
	}

	cout<<"\nEnter the no. of connections: "; //no of edges
	cin>>e;

	for(i=0;i<e;i++)
	{
		cout<<"Enter the end branches of connections:  "<<endl;
		cin>>l>>u;
		cout<<"Enter the phone company charges for this connection:  ";
		cin>>w;
		a[l-1][u-1]=a[u-1][l-1]=w; // undirected graph symmetric representation
		
		//as array is started from 0 if there are 5 conn
	}  
}

void tree::display()
{
	cout<<"\nAdjacency matrix:";
	for(i=0;i<v;i++)
	{
		cout<<endl;
		for(j=0;j<v;j++)
		{
			cout<<a[i][j]<<"   "; //roe by row printed
		}
		cout<<endl;
	}
}

void tree::minimum() //prims algoritham
{
	int p=0,q=0,total=0,min;
	
	visited[0]=1;  //visited first city
	
	for(int count=0;count<(v-1);count++)
	{
		min=999;
		for(i=0;i<v;i++)
		{
			if(visited[i]==1) // source vertex
			{
				for(j=0;j<v;j++)
				{
					if(visited[j]!=1) // destination vertex
					{
						if(min > a[i][j])
						{
							min=a[i][j];// put that wait with min
							p=i; //update min i p 
							q=j;
						}
					}
				}
			}
		}
		visited[p]=1;
		visited[q]=1;
		total=total+min;
		cout<<"Minimum cost connection is"<<(p+1)<<" -> "<<(q+1)<<"  with charge : "<<min<< endl;//in matris 3 is present as 2 as array
		
	}
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}

int main()
{
	int ch;
	tree t;
	do
	{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
	
	switch(ch)
	{	
	case 1: cout<<"**INPUT YOUR VALUES**"<<endl;	
		t.input();//call input using obj of tree
		break;

	case 2: cout<<"**DISPLAY THE CONTENTS***"<<endl;
		t.display();
		break;

	case 3: cout<<"****MINIMUM*****"<<endl;
		t.minimum();
		break;
	}
	
	}while(ch!=4);
	return 0;
}
