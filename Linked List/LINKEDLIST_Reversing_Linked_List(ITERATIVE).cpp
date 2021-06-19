
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

//THIS IS ITERATIVE VERSION OF REVERSING A LINKED LIST
void reverse()      
{
    
    cout<<"\n";
    Node *current=new Node();           //IT WILL HOLD CURRENT NODE
    Node *previous=new Node();          //IT WILL HOLD PREVOUS NODE OF CURRENT NODE
    Node *forward=new Node();           //IT WILL HOLD NEXT ELEMENT OF CURRENT NODE
    current=head;
    previous=NULL;
    while(current!=NULL)
    {
        forward=current->next;          //SETTING FORWARD NODE ADDRESS SO THAT IT DOESN'T GETS LOST
        current->next=previous;         //SETTING NEXT ELEMENT OF CURRENT NODE AS PREVIOUS NODE
        previous=current;               //UPDATING NEW PREVIOUS
        current=forward;                //TRAVERSING TO NEXT ELEMENT
    }
    head=previous;                      //AFTER THE ITERATION THE LATEST PREVIOUS NODE WILL BE THE HEAD NODE
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
        cout<<"NULL";
    }
}

int main()
{
    
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    cout<<"ORIGINAL LINKED LIST IS\n";
    display();
    reverse();
    cout<<"NEW LINKED LIST IS\n";
    display();

    //THE OUTPUT OF THE PROGRAM IS
 /*   ORIGINAL LINKED LIST IS
    1->2->3->4->NULL
    NEW LINKED LIST IS
    4->3->2->1->NULL
*/
}
