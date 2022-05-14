#include <iostream>
#include <fstream>
using namespace std;
class employee 
{
  public:
  int employeeid;
  char name[40];
  int salary;

  void setup ()
  {
    cout << "\nenter the name of employee =";
    cin >> name;
    cout << " \nenter the employee id=";
    cin >> employeeid;
    cout << " \nenter the employee salary =";
    cin >> salary;
  }
  void showdata ()
  {
    cout << "\nname of employee is =" << name;
    cout << "\n employee id is =" << employeeid;
    cout << "\n the employee salary is  ="<<salary;
  }
  int adddata()
  {
      return employeeid ;
  }
};
void write()
{
    ofstream outFile;
    outFile.open("employee.dat", ios::binary | ios::app);

    employee obj;
    obj.setup();
    outFile.write((char*)&obj, sizeof(obj)); 
    outFile.close();
}
void display()
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);
    employee obj;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showdata();
    }
}
void search (int n)
{
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);
    int flag=0;
    employee obj;
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
    if(obj.adddata () == n)
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

void delete_record(int n)
{
    employee obj;
    ifstream inFile;
    inFile.open("employee.dat", ios::binary);

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while(inFile.read((char*)&obj, sizeof(obj)))
    {
    if(obj.adddata() != n)
    {
    outFile.write((char*)&obj, sizeof(obj));
    }
    }
    inFile.close();
    outFile.close();
    remove("employee.dat");
    rename("temp.dat", "employee.dat");
}
int main()
{
int ch;
do{
cout<<"\n\n\n********Fileoperations*********";
cout<<"\n1.write\n2.display\n3.search\n4.delete\n5.exit";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){

case 1: cout<<"Enter number of records: ";
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
cout<<"Enter Student employee id : ";
int s;
cin>>s;
search(s);
break;

case 4:
cout<<"Enter employee id  to be deleted: ";
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


