#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
}*head=NULL;

void insert_end(int n)
{
    Node* temp=new Node();
    Node* nd=new Node();
    nd->data=n;
    nd->prev=NULL;
    nd->next=NULL;
    if(head==NULL) head=nd;
    else
    {
        temp=head;
        while(temp->next!=NULL) temp=temp->next;    //TRAVERSING
        temp->next=nd;                              
        nd->prev=temp;                              //SETTING PREV ADDRESS OF NEW NODE
    }
}

Node* reverse_recur(Node* head)
{
    Node* temp=new Node();

    if(head==NULL)  return NULL;

    temp=head->next;
    head->next=head->prev;
    head->prev=temp;

    if(head->prev==NULL)    return head;
    
    return reverse_recur(head->prev);
}

void display(Node *head)
{
    Node* temp=new Node();
    temp=head;
    if(head==NULL) cout<<"EMPTY LL\n";
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
int main()
{
    insert_end(15);
    insert_end(27);
    insert_end(61);
    insert_end(82);
    insert_end(101);
    insert_end(29);
    insert_end(41);
    insert_end(52);
    cout<<"ORIGINAL LL IS:\n";
    display(head);
    cout<<"REVERSED LL IS\n";
    Node* newh= reverse_recur(head);
    display(newh);
    /*
    OUTPUT:
    ORIGINAL LL IS:
    15->27->61->82->101->29->41->52->NULL
    REVERSED LL IS
    52->41->29->101->82->61->27->15->NULL
    */
}
