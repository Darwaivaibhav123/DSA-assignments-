#include<iostream>
using namespace std;


struct node
{
    char label[50];  
    int chcount;  
    node *child[50];
}*root;  // For storing the address of the root node.

class tree
{
    public:
    tree()
    {
        root=NULL;
    }
    
    void insert();      
    void display();
};

void tree::insert() 
{
    root=new node();  
    cout<<"Enter the name of the book: "<<endl;
    cin>>root->label;
    cout<<"Enter the number of chapter in the book: "<<endl;
    cin>>root->chcount;

    for (int i=0;i<root->chcount;i++)  // i=no. of chapters.
    {
        root->child[i]=new node();
        cout<<"Enter the name of the chapter: "<<endl;
        cin>>root->child[i]->label;
        cout<<"Enter the number of sections in the chapter: "<<endl;
        cin>>root->child[i]->chcount;

        for (int j=0;j<root->child[i]->chcount;j++)   // j=no. of sections.
        {
            root->child[i]->child[j]=new node();
            cout<<"Enter the name of the section: "<<endl;
            cin>>root->child[i]->child[j]->label;
            cout<<"Enter the number of sub-sections in the section: "<<endl;
            cin>>root->child[i]->child[j]->chcount;

            for (int k=0;k<root->child[i]->child[j]->chcount;k++)   // k=no. of sub-sections.
            {
                root->child[i]->child[j]->child[k]=new node();
                cout<<"Enter the name of the sub-section :"<<endl;
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}


void tree::display()
{
    if (root!=NULL)
    {
        cout<<"------------------------------"<<endl;
        cout<<"      BOOK HIERARCHY"<<endl;
        cout<<"------------------------------"<<endl;

        cout<<"Book name:"<<root->label<<endl;
        for(int i=0;i<root->chcount;i++)
        {
            cout<<"-->"<<root->child[i]->label<<endl;
            for(int j=0;j<root->child[i]->chcount;j++)
            {
                cout<<"---->"<<root->child[i]->child[j]->label<<endl;
                for (int k=0;k<root->child[i]->child[j]->chcount;k++)
                {
                    cout<<"------>"<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }
    }
}

int main()
{
   tree t;    
   int ch;  
   int f=1;
   while(f==1)
   {
       cout<<"\n----- General Tree :: Menu -----"<<endl;
       cout<<"1.Insert \n2.Display \n3.Exit"<<endl;
       cout<<"Enter your choice: ";
       cin>>ch;
       switch(ch)
       {
           case 1:
                t.insert();
                break;

            case 2:
                t.display();
                break;

            case 3:
                exit(1);

            default:
                cout<<"Invalid input!!"<<endl;
       }
   }
return 0;
}
