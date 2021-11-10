#include<iostream>
#define Size 50
using namespace std;
class Queue
{
    private: int item, i, q[Size],Front, Rear;
    public:
        Queue()
        {
            Front=-1;
            Rear=-1;
        }
        void Insert()
        {
            if(Rear==Size)
            {
                cout<<"Queue is full";
                return;
            }
            cin>>item;
            Rear=Rear+1;
            q[Rear]=item;
        }

        void delet()
        {
            if(Front==Rear)
            {
                cout<<"queue is empty";
                return;
            }
            if(Front==-1)
            {
                cout<<"item deleted is"<<q[Front+1]<<"\n";
                Front=Front+2;
                return;
            }
            cout<<"item deleted is"<<q[Front]<<"\n";
            Front=Front+1;
        }
        void display()
        {
            for(i=Front;i<=Rear;i++)
                cout<<q[i]<<"\n";
        }
};
int main()
{
    Queue q;
    q.Insert();
    q.Insert();
    q.Insert();
    q.delet();
    q.display();
    q.delet();
    q.display();
    return 0;
}
