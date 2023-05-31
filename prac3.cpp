#include <iostream>
using namespace std;

struct node
{
    char title[20]; // name of each node 
    int node_count;
    struct node *child[10];
} * base; //point to the root of tree structure 

class book
{
public:
    book()
    {
        base = NULL; // root = null
    }

    void creat()
    {
        int chapter, section, subsection, i, j, k; //loop variable
        base = new node(); // dynamically memory allocation  for each node

        cout << "The name of book is => ";
        // cin >> base->title, it only reads a single word because >> operator stops at whitespace. To read a full line, 
        cin.getline(base->title,20);

        cout << "Enter the number of chapter => ";
        cin >> chapter;
        base->node_count = chapter; //enter the number of chapters and stores it in base->node_count

        for (i = 0; i < chapter; i++)
        {
            base->child[i] = new node; //dynamically memory allocate for chapter

            cout << "Enter the name of chapter " << i + 1 << " => ";
            cin >> base->child[i]->title;

            cout << "Enter the number of section => ";
            cin >> section;
            base->child[i]->node_count = section;

            for (j = 0; j < section; j++)
            {
                base->child[i]->child[j] = new node; // enter the name of the section and stores it in base->child[i]->child[j]->title.

                cout << "Enter the name of section " << j + 1 << "=> ";
                cin >> base->child[i]->child[j]->title;

                cout << "Enter the number of sub-section => ";
                cin >> subsection;
                base->child[i]->child[j]->node_count = subsection;//asks the user to enter the number of subsections in the current section and stores it in base->child[i]->child[j]->node_count.



                for (k = 0; k < subsection; k++)
                {
                    base->child[i]->child[j]->child[k] = new node;

                    cout << "Enter the name of sub-section " << k + 1 << "=> ";
                    cin >> base->child[i]->child[j]->child[k]->title;
                }
            }
            
        }
    }

    void print(node *r) //takes a pointer to a input node 
    {
        int i, j, k, chapter;
        if (r != NULL)
        {
            cout << "\nThe book name is " << r->title << endl;

            chapter = r->node_count; //assigns the value

            for (i = 0; i < chapter; i++)
            {
                cout << "\nChapter " << i + 1 << endl;
                cout << "  " << r->child[i]->title;
                cout << "\n\tSection";
                for (j = 0; j < r->child[i]->node_count; j++)
                {
                    cout << "\n\t  " << r->child[i]->child[j]->title;
                    cout << "\n\t\tsubsection";
                    for (k = 0; k < r->child[i]->child[j]->node_count; k++)
                    {
                        cout << "\n\t\t   " << r->child[i]->child[j]->child[k]->title;
                    }
                }
            }
        }
    }
};

int main()
{
    book obj; // instance of book 
    obj.creat();

    cout << "---------------------" << endl;
    obj.print(base);
}
