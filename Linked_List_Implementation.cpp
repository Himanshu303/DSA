#include<bits/stdc++.h>
using namespace std;

//CREATES A NODE STRUCTURE CONTAINING DATA OF CURRENT NODE AND ADDRESS OF NEXT NODE
struct Node
{
    int data;
    Node* next;
} *head=NULL;                                       //WE USE HEAD TO DENOTE 1ST ELEMENT OF LINKED LIST

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
        while(temp->next!=NULL)     temp=temp->next; // TRAVERSING TO THE LAST ELEMENT
        temp->next=nd;                               // ADDING NEW NODE AT THE END
    }
}

void insert_start(int n)
{
    Node* nd=new Node();
    nd->data=n;
    nd->next=NULL;
    if(head==NULL) head=nd;         
    else
    {
        Node* temp=new Node();
        nd->next=head;                              //SET NEW NODE ADDRESS TO POINT TOWARDS HEAD
        head=nd;                                    //SET NEW NODE AS HEAD
    }
}

void delete_start()
{
    if(head==NULL) cout<<"DELETION NOT POSSIBLE\n";
    else
    {
        Node* temp=new Node();
        temp=head;
        head=head->next;                            //SETTING NEXT ELEMENT OF HEAD AS NEW HEAD
        delete(temp);                               //DELETING PREVIOUS HEAD
    }
}

void delete_end()
{
    if(head==NULL) cout<<"DELETION NOT POSSIBLE\n";
    else
    {
        Node* temp=new Node();
        temp=head;
        Node* prev=new Node();
        while((temp->next)->next!=NULL)      temp=temp->next;       //TRAVERSING TO THE END
        delete(temp->next);                                         //DELETING LAST NODE
        temp->next=NULL;                                            //SETTING NEXT ADDRESS TO 2ND LAST ELEMENT AS NULL
    }
}

void display()
{
    if(head==NULL) cout<<"LIST DOESNT EXIST\n";
    else
    {
        Node* temp=new Node();
        temp=head;
        cout<<"LINKED LIST ELEMENTS:\n";
        while(temp!=NULL)                                           //TRAVERSING TO THE END
        {   
            cout<<temp->data<<"->";                                  //PRINING CURRENT DATA
            temp=temp->next;                                        //MOVING FORWARD IN LINKED LIST
        }       
        cout<<"NULL";
    }
}

void insert_npos(int n,int pos)
{    
    int c=1;
    Node* nd=new Node();
    nd->data=n;
    if(pos==1)
    {
        nd->next=head;
        head=nd;
    }
    else
    {
        Node* temp=head;
        while(c!=pos-1 && temp!=NULL)
        {   
            temp=temp->next;
            ++c;                                                       //TRAVERSING TILL WE REACH DESTINATION INDEX
        }
        if(c!=pos-1 && temp==NULL) cout<<"INDEX NOT AVAILABLE\n";      //CHECKING IF LINKED LIST ENDS BEFORE WE REACH DESTINATION
        else    
        {
            nd->next=temp->next;                                        //ADDING NODE IN BETWEEN               
            temp->next=nd;
        }
    }
}

void delete_npos(int pos)
{
    Node* temp=head;
    if(pos==1)
    {
        head=temp->next;
        delete(temp);
    }

    else 
    {
        int c=1;

        while(c<pos-1 && temp!=NULL)
        {
            ++c;                                                            //TRAVERSING TILL WE REACH DESTINATION INDEX
            temp=temp->next;
        }

        if(c!=pos-1 && head==NULL) cout<<"DELETION NOT POSSIBLE\n";          //CHECKING IF LINKED LIST ENDS BEFORE WE REACH DESTINATION

        else
        {
            Node* nextP=temp->next;
            temp->next=nextP->next;                                             
            delete(nextP);                                                     //DELETING NODE IN BETWEEN 

        }
    }
}

int main()
{
    
    insert_start(4);
    insert_start(3);
    insert_start(2);
    insert_start(1);
    insert_end(5);
    insert_npos(8,2);
    delete_npos(5);
    delete_end();
    display(); 

    //THE OUTPUT OF THIS PROGRAM IS
    //1->8->2->3->NULL
}
