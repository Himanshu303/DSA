#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
} *head=NULL;

void insert_end(int n)
{
    Node* nd=new Node();
    nd->data=n;
    nd->next=NULL;
    if(head==NULL) head=nd;
    else
    {
        Node* temp=new Node();
        temp=head;
        while(temp->next!=NULL)     temp=temp->next;
        temp->next=nd;
    }
}

//THIS IS RECURSIVE VERSION OF REVERSING A LINKED LIST
void recur_reverse(Node* p)      
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    recur_reverse(p->next);           //Tail recursion
    Node* q=p->next;            //Getting address of last node
    q->next=p;                  //setting last nodes next as second last node
    p->next=NULL;               //setting second last nodes next as NULL which will be updated in next stack

    
}   
void display()
{
    if(head==NULL) cout<<"LIST DOESNT EXIST\n";
    else
    {
        Node* temp=new Node();
        temp=head;
       
        while(temp!=NULL)                                           //TRAVERSING TO THE END
        {   
            cout<<temp->data<<"->";                                  //PRINING CURRENT DATA
            temp=temp->next;                                        //MOVING FORWARD IN LINKED LIST
        }       
        cout<<"NULL\n";
    }
}

int main()
{
    
    insert_end(15);
    insert_end(79);
    insert_end(105);
    insert_end(56);
    cout<<"ORIGINAL LINKED LIST IS\n";
    display();
    recur_reverse(head);                                              //Passing head as reference
    cout<<"NEW LINKED LIST IS\n";
    display();

    //THE OUTPUT OF THE PROGRAM IS
 /* ORIGINAL LINKED LIST IS
    15->79->105->56->NULL
    NEW LINKED LIST IS
    6->105->79->15->NULL
*/
}
