#include<iostream>
#include<String.h>
using namespace std;
class student
{
    public:
    int rollno;
    char name[20];
    int grade;
public:
    void read();
    void display();
};
void student::read()
{
    cout<<"Enter the roll no: ";
    cin>>rollno;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter the grade: ";
    cin>>grade;
}
void student::display()
{
    cout<<"rollno: "<<rollno;
    cout<<"\nname: "<<name<<"\n";
}
int main()
{
    student s[10],temp;
    int n,i,j;
    cout<<"Enter the number of students\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        s[i].read();
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].rollno>s[j+1].rollno)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        s[i].display();
    }
    return 0;
}
