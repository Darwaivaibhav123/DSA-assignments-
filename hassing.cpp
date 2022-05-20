#include <iostream>
#include <cstring>
using namespace std;
class telephone
{
    unsigned long long key;
    unsigned long long mobile[50];
    string name[50];
    int  address ;
    int num ,ch ; 
    public:
        telephone()
        {
            for (int i=0 ; i <10 ; i++)
            {
                mobile[i]=0;
            }
            for (int i=0 ;i<10 ; i++)
            {
                name[i]="-";
            }
        
        }
        int  hashfunction(unsigned long long key)
        {
            return key%10;
            
        }
        void insert ()
        {
            cout<<"\nenter how many record do you want to insert = ";
            cin>>num;
            cout<<"\nenter which methord you want to perfome \n 1. linear probling \n 2. Quadratic probing"<<endl; 
            cin>>ch;
            for (int i =0 ; i<num ; i++)
            {
               cout<<"enter the mobile no = ";
               cin>>key;
               address=hashfunction(key);
            
                if (mobile[address]==0)
                {
                   mobile[address]=key;
                   cout<<"enter the name =";
                   cin>>name[address];
                }
                else
                {
                    if (ch==1)
                    {
                        linear_probing (mobile , name , key);
                    }
                    else if (ch ==2)
                    {
                        Quadratic_probing(mobile , name , key);
                    }
                    
                }
            }
        }
        void linear_probing (unsigned long long mobile[],string name[],unsigned long long key)
        {
            while(mobile[address]!=0)
            {
                address++;
            }
            mobile[address]=key;
            cout<<"enter the name =";
            cin>>name[address];
        }
        void Quadratic_probing (unsigned long long mobile[],string name[],unsigned long long key)
        {
            int i=1;
            while(mobile[address]!=0)
            {
                address+=(i*i);
                i++;
            }
            mobile[address]=key;
            cout<<"enter the name =";
            cin>>name[address];
        }
        void display()
        {
            cout<<"\t index \t name \t moblie " ;
            for (int i =0 ; i<10; i++)
            {
                cout<<i<<"\t"<<name[i]<<"\t"<<mobile[i]<<endl;
            }
        }
};
int main ()
{
    telephone t;
    int choice ;
    int flag =1 ;
    while (flag ==1)
    {
        cout<<" \n----Telephone Directory-----"<<endl;
        cout<<"1. Insert record"<<endl;
        cout<<"2. Display record"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";  
        cin>>choice ;
        switch( choice)
        {
            case 1:
            t.insert();
            break;
            case 2 :
            t.display();
            break;
            case 3:
            cout <<"exit"<<endl;
        }
        
    }
    
}       
