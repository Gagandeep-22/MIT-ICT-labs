#include<iostream>
using namespace std;
int main()
{
    char str1[50], str2[50];
    int i=0,j=0;
    cout<<"\nEnter first string : ";
    cin>>str1;
    cout<<"\nEnter second string : ";
    cin>>str2;
    while(str1[i]!='\0')
        i++;
    while(str2[j]!='\0')
    {
        str1[i]=str2[j];
        j++;
        i++;
    }
    str1[i]='\0';
    cout<<"\nConcatenated String is "<<str1;
    return 0;
}
