 #include<iostream>
using namespace std;
class node
{
    int info;
    node *next;
public:
    node();
    void ins_beg();
    void ins_end();
    void ins_pos();
    void ins_before();
    void ins_after();
    void del_beg();
    void del_item();
    void rev();
    void delalt();
    void ins_sort();
    void print();
    void Sort();
}*head;
node::node()
{

}
void node::ins_end()
{
    node *cur;
    cur=head;
    node *temp=new node;
    cout<<"\nEnter the value:\n";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
    }
}
void node::ins_beg()
{
    node *temp=new node;
    cout<<"\nEnter the value:\n";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void node::ins_pos()
{
    node *temp=new node;
    node *t,*t1;
    cout<<"\nEnter the value to be inserted\n";
    cin>>temp->info;
    temp->next=NULL;
    cout<<"\nEnter the position:\n";
    int pos;
    cin>>pos;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;
        for(int i=1;i<pos-1;i++)
            t=t->next;
        t1=t->next;
        t->next=temp;
        temp->next=t1;
    }
}
void node::print()
{
    node *h=head;
    if(h==NULL)
        cout<<"\nList is empty\n";
    while(h!=NULL)
    {
        cout<<"->"<<h->info;
        h=h->next;
    }
    cout<<endl;
}
void node::ins_before()
{
    node *temp=new node;
    node *t,*prev;
    cout<<"\nEnter the value to be inserted\n";
    cin>>temp->info;
    temp->next=NULL;
    cout<<"\nEnter the number before which the number is to be inserted :\n";
    int ele;
    cin>>ele;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;
        if(t->info==ele)
        {
            temp->next=t;
            head=temp;
        }
        else
        {
            while(t->info!=ele)
            {
                prev=t;
                t=t->next;
            }
            prev->next=temp;
            temp->next=t;
        }
    }
}
void node::ins_after()
{
     node *temp=new node;
    node *t,*t1;
    cout<<"\nEnter the value to be inserted\n";
    cin>>temp->info;
    temp->next=NULL;
    cout<<"\nEnter the number after which the number is to be inserted :\n";
    int ele;
    cin>>ele;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;
        while(t->info!=ele)
            t=t->next;
        t1=t->next;
        t->next=temp;
        temp->next=t1;
    }
}
void node::del_beg()
{
    node *temp=new node();
    temp=head;
    head=head->next;
    cout<<"\nDeleted element is: "<<temp->info<<endl;;
    delete(temp);
}
void node::del_item()
{
    node *cur,*prev,*temp;
    int data;
    if(head==NULL)
        cout<<"\nNo records to delete\n";
    else
    {
        cout<<"\nEnter the data to be deleted: \n";
        cin>>data;
        cur=head;
        while((cur!=NULL)&&(cur->info!=data))
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==head)
        {
            head=head->next;
            cout<<"Data Deleted: "<<data<<endl;
        }
        if(cur==NULL)
        {
            cout<<"Record not fount\n";
            return;
        }
        else
        {
            prev->next=cur->next;
            cout<<"Data deleted is: "<<data<<endl;
        }
        delete(cur);
    }
}
void node::rev()
{
    node *cur=head;
    node *prev;
    node *temp;
    int i=0;
    if(head==NULL)
        cout<<"\nList is empty\n";
    temp=cur->next;
    while(temp!=NULL)
    {
        prev=cur;
        i++;
        cur=temp;
        if(head!=NULL)
        temp=cur->next;
        head=cur;
        if(i==1)
            prev->next=NULL;
        cur->next=prev;
    }
}
void node::delalt()
{
    int f=0;
    node *h=head;
    node *prev;
    if(h==NULL)
        cout<<"\nList is empty\n";
    while(h!=NULL)
    {
        prev=h;
         h=h->next;
        f++;
        if(f%2==1)
        {
            prev->next=h->next;

        }
    }
}
void node::ins_sort()
{
    node *temp=new node;
    node *t,*prev;
    int f=1;
    cout<<"\nEnter the value to be inserted\n";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;
        if(temp->info<=t->info)
        {
            temp->next=t;
            head=temp;
        }
        else
        {
            while(t->info<temp->info)
            {
                prev=t;
                if(t->next==NULL)
                {
                    f=0;
                    break;
                }
                t=t->next;
            }
            if(f==0)
            {
                t->next=temp;
                temp->next=NULL;
            }
            else
            {
                prev->next=temp;
                temp->next=t;
            }
        }
    }
}
void node::Sort()
{
    node *h=head;
    node *cur=head;
    int temp;
    node *post;
    int n=0;
    while(h!=NULL)
    {
        h=h->next;
        n++;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            post=cur->next;
            if(cur->info>post->info)
            {
                temp=cur->info;
                cur->info=post->info;
                post->info=temp;
            }
            cur=cur->next;
        }
        cur=head;
    }
}
int main()
{
    node n;
    int flag=1;
    while(flag)
    {
        cout<<"1. Insert in the beginning \t 2. Insert in the end \t 3. Insert anywhere \t 4. Insert before \t 5. Insert after \t 6. Delete at the beginning \t 7. Delete an item \t 8. Print \t 9. Delete alternate \t 10. sorted insertion \t 11. reverse \t 12. sort \t 0. Exit\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1:n.ins_beg();
            break;
            case 2:n.ins_end();
            break;
            case 3:n.ins_pos();
            break;
            case 4:n.ins_before();
            break;
            case 5:n.ins_after();
            break;
            case 6:n.del_beg();
            break;
            case 7:n.del_item();
            break;
            case 8:n.print();
            break;
            case 9:n.delalt();
            break;
            case 10:n.ins_sort();
            break;
            case 11:n.rev();
            break;
            case 12:n.Sort();
            break;
            default: flag=0;
        }
    }
    return 0;
}
