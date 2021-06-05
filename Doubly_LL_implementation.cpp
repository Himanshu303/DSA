#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
}*head=NULL;

void insert_start(int n)
{
    Node* nd=new Node();
    nd->data=n;
    nd->prev=NULL;
    nd->next=NULL;
    if(head==NULL) head=nd;
    else
    {
        nd->next=head;          //SETTING NEXT ADDRESS OF NEW NODE
        head->prev=nd;          //SETTING PREV ADDRESS OF EARLIER HEAD NODE
        head=nd;                //SETTING NEW NODE AS HEAD NODE
    }
}

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

void insert_npos(int n,int pos)
{
    int c=1;
    Node* nd=new Node();
    nd->data=n;
    nd->next=NULL;
    nd->prev=NULL;
    if(pos==1)
    {
        nd->next=head;
        head->prev=nd;
        head=nd;
    }
    else
    {
        Node* temp=head;
        while(c!=pos-1 && temp!=NULL)
        {   
            ++c;
            temp=temp->next;                        //TRAVERSING
        }
        if(c!=pos-1 && temp==NULL) cout<<"INDEX NOT AVAILAVBLE\n";
        else
        {
            Node* nxt=new Node();
            nxt=temp->next;     
            if(nxt==NULL)                           //CHECKING IF POS IS LAST ELEMENT OF LL
            {
                temp->next=nd;                      
                nd->next=NULL;
            }
            else
            {
            nxt->prev=nd;
            temp->next=nd;
            nd->next=nxt;
            nd->prev=temp;
            }
        }
    }
}

void delete_start()
{
    Node* temp=head;
    if(head==NULL) cout<<"DELETION NOT POSSIBLE\n";
    else
    {
        head=temp->next;                        //UPDATING HEAD
        head->prev=NULL;                        
        delete(temp);
    }
}

void delete_end()
{
    Node* temp=head;
    if(head==NULL) cout<<"DELETION NOT POSSIBLE\n";
    else 
    {
        while(temp->next!=NULL) temp=temp->next;
        Node* prv=temp->prev;
        if(prv==NULL) delete(temp); //CHECKING IF IT IS 1ST ELEMENT OF LL
        else{
        prv->next=NULL;
        delete(temp);
        }
    }
}

void delete_npos(int pos)
{
    int c=1;
    if(head==NULL) cout<<"DELETION NOT POSSIBLE\n";
    else if(pos==1)
    {
        Node* temp=head;
        head=temp->next;
        head->prev=NULL;
        delete(temp);
    }
    else
    {
         Node* temp=head;
        while(c!=pos && temp!=NULL)
        {
            ++c;
            temp=temp->next;                    //TRAVERSING
        }
        if(c==pos && temp==NULL) cout<<"INDEX NOT AVAILAVBLE\n";
        else
        {
            Node* prv=temp->prev;
            Node* nxt=temp->next;
            if(nxt==NULL)                       //CHECKING IF IT IS LAST NODE OF LL
            {
                prv->next=NULL;
            }
            else
            {
            prv->next=nxt;
            nxt->prev=prv;
            }
            delete(temp);
        }
    }
}

void display()
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
    insert_start(2);
    insert_start(1);
    insert_start(0);
    insert_end(3);
    insert_end(5);
    insert_npos(4,5);
    delete_start();
    delete_end();
    delete_end();
    delete_npos(1);
    delete_npos(2);
    display();
/*
    THE FINAL OUTPUT OF THE PROGRAM IS:

    2->NULL

*/
}