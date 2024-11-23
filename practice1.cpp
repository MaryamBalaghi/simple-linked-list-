#include <iostream>
#include <string.h>
using namespace std;
class node
{
    friend class hohochichi;
    private:
    char name[40];
    node *next;
};
class hohochichi
{
    node *first, *last;
    public:
    hohochichi();
    ~hohochichi();
    void addnode();
    void delnode();
    bool searchnode();
    void display();
    void delnode_2();
};
hohochichi::hohochichi()
{
    first=last=NULL;
}
hohochichi::~hohochichi()
{
    node *curptr, *temp;
    curptr=first;
    while (curptr!=NULL)
    {
        temp=curptr;
        curptr=curptr->next;
        delete temp;
    }  
}
void hohochichi::addnode()
{
    node *newstudent;
    newstudent =new node;
    cout<<"Enter the student`s name:";
    cin>>newstudent->name;
    if(first==NULL)               // list is empty
    {
        first=newstudent;
    }
    else
    {
        last->next=newstudent;
    }
    last=newstudent;
    newstudent->next=NULL;
}
void hohochichi::display()
{
    if(first==NULL)
    {
        cout<<"The list is empty";
    }
    else
    {node *curptr=first;
    while (curptr)
    {
        cout<<curptr->name<<"\n";
        curptr=curptr->next;
    }}
}
void hohochichi::delnode()
{
    if(first==NULL)
    {
        cout<<"The list is empty.";
    }
    else 
    {
        node *predel=NULL, *temp, *del=first;
        char nam[50];
        cout<<"Enter his/her name for delete: ";
        cin>>nam;
        if(strcmp(nam,first->name)==0)
        {
            temp=first;
            first=first->next;
            delete temp;
            if(first==NULL)
            {
                last=NULL;
            }
            cout<<"Student deleted successfully."<<"\n";
            return;
        }
        while(del!=NULL)
        {
            if(strcmp(nam,last->name)==0 &&del->next==NULL)
            {
                predel->next=NULL;
                last=predel;
                delete del;
                cout << "Student deleted successfully." << endl;
                return;
            }
            predel = del;
            del = del->next;
        }
        cout<<"You can not delete."<<"\n";
    }
}
bool hohochichi::searchnode()
{
    if(first==NULL)
    {
        cout<<"The list is empty.";
        return false;
    }
    else
    {
        char nam[50];
        node *curstudent=first;
        cout<<"Enter his/her name for find: ";
        cin>>nam;
        while (curstudent!=NULL)
        {
            if(strcmp(curstudent->name,nam)==0)
            {
                cout<<"Student found"<<"\n";
                return true;
            }
            curstudent=curstudent->next;
        }
        cout<<"Student not found"<<"\n";
        return false;
    }
}
void hohochichi::delnode_2()
{
    int position=1;   
    if(first==NULL)
    {
        cout<<"The list is empty.";
    }
    else
    {
        node *ptr=first,*preptr=NULL ;
        while(ptr)
        {
            if(position%2!=0)
            {   node *temp;
                temp=ptr;
                if(first==ptr)
                {
                    first=first->next;
                    if(first==NULL)
                    {
                        last=NULL;
                    }  
                    ptr=first ;
                }
                else
                {
                preptr->next=ptr->next;
                if(ptr==last)
                {
                    last=preptr;
                } 
                ptr=ptr->next;
                }
                delete temp;
            }
            else
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            position++;
        }
        cout << "Odd nodes have been removed successfully." << endl;
    }
}
int main()
{
    hohochichi hoho;
    int choise;
    char n;
    bool Continue=true;
    cout<<"Guide list:"<<"\n";
    cout<<"1 is Add new student."<<"\n"<<"2 is delete a student from first or last."<<"\n"
    <<"3 is search an student."<<"\n"<<"4 show all of students."<<"\n"
    <<"5 is delete odd-positioned students."<<"\n"<<"6 is Exit."<<"\n"<<"***"<<"\n";
    
    while (Continue)
    {

    cout<<"Enter your choise: ";
    cin>>choise;
    switch (choise)
    {
    case 1:
        hoho.addnode();
        break;
    case 2:
        hoho.delnode();
        break;
    case 3:
        hoho.searchnode();
        break;
    case 4:
        hoho.display();
        break;
    case 5:
        hoho.delnode_2();
        break;
    case 6:
        break;
    default:
        cout<<"Your choise was not defind. please try again.";
    }
    do
    {
    cout<<"Do you want continue? (please answer whit only by y/n)";
        cin>>n;
    } while (n != 'y' && n != 'n');
    if(n=='n')
    {
        Continue=false;
    }
    else if(n=='y')
    {
        Continue=true;
    }
    }
}