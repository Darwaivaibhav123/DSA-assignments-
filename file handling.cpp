#include <iostream>
#include <fstream>
using namespace std;
class student
{
    public :
    int rollno;
    char name[50];
    char division[5];
    char add[50];
    
    void setup()
    {
        cout<<"enter the roll number of student= " <<endl;
        cin >>rollno;
        cout<< "enter the name of student ="<<endl;
        cin>>name[50];
        cout<<"enter the division of student ="<<endl;
        cin>>division[5];
        cout<<"enter the address of student ="<< endl;
        cin>>add[50];
    }
        
    void showdata()
    {
        cout<<"\n**** disply the informtion of student ****";
        cout<<"\n student roll no =  "<<rollno;
        cout<<"\n student name = "<<name[50];
        cout<<"\n student division= "<<division[5];
        cout<<"\n student address =  "<<add[50];
    }
    int studentid()
    {
        return rollno ;

    }

    
  
};
void write()
{
    fstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);

    student obj;
    obj.setup();
    outFile.write((char*)&obj, sizeof(obj));
    outFile.close();
}
void display()
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    student obj;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showdata();
    }
   
    inFile.close();
}
void search(int n)
{
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    int flag=0;
    student obj;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
    if(obj.studentid() == n)
    {
    obj.showdata();
    flag=1;
    break;
    }
    }
    if(flag==0)
    cout<<"\n\n Record Not Found";
    inFile.close();
    
}

void delete_record (int n)
{
    
    student obj;
    ifstream inFile;
    inFile.open("student.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
    if(obj.studentid() != n)
    {
    outFile.write((char*)&obj, sizeof(obj));
    }
    }
    inFile.close();
    outFile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
}
int main()
{
   int ch ;
   do{
     cout<<"\n\n\n********Fileoperations*********";
cout<<"\n1.write\n2.display\n3.search\n4.delete\n5.exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){

case 1: 
cout<<"Enter number of records: ";
int n;
cin>>n;
for(int i = 0; i <n; i++)
write();
break;

case 2:
cout << "\n---List of records---";
display();
break;

case 3:
cout<<"Enter Student Roll No: ";
int s;
cin>>s;
search(s);
break;

case 4:
cout<<"Enter Roll No. to be deleted: ";
int d;
cin>>d;
delete_record(d);
cout << "\nRecord Deleted";
break;

case 5:
return 0;

}
}while(ch!=5);
}
