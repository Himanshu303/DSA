#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

//CREATING CLASS FOR STACK USING ARRAY HAVING MAX SIZE 100
class Stack_array
{
    public:

    int top;
    int stack[MAX];

    Stack_array() 
    {
        top=-1;                 //USING CONSTRUCTOR TO DEFINE TOP
    }
    void push(int x);
    void pop();
    void isEmpty();
    void display();
    void peek();
};

void Stack_array::push(int x)           //PUSHING ELEMENT IN STACK
    {
        if(top<=MAX)
        {
            stack[++top]=x;
            cout<<"Element "<<x<<" inserted successfully\n";
        }
        else cout<<"STACK OVERFLOW !\n";
    }

    void Stack_array::pop()             //POPPING AN ELEMENT FROM STACK
    {
        if(top==-1) cout<<"\nUNDERFLOW\n";
        else 
        {   
            cout<<"Element "<<stack[top]<<" popped\n";
            --top;
        }
    }

    void Stack_array::isEmpty()         //CHECKING WHETHER A STACK IS EMPTY
    {   
        if(top<0) cout<<"True\n";
        else cout<<"False\n";
    }

    void Stack_array::display()         //DISPLAYING ALL ELEMENTS OF STACK
    {
        cout<<"STACK ELEMENTS:\n";
        for(int i=top;i>=0;i--) cout<<stack[i]<<"\n";  
    }

    void Stack_array::peek()            //DISPLAYING TOPMOST ELEMENT OF STACK
    {
        cout<<"Peek: "<<stack[top]<<"\n";
    }

struct node{
    int data;
    node* next;
};

//CREATING CLASS FOR DYNAMIC STACK USING LINKED LIST
class Stack_linked
{
    private:
        node *head;
    public:
    Stack_linked()
    {
        head=NULL;
    }
     void push(int x);
    void pop();
    void isEmpty();
    void display();
    void peek(); 
};

  void Stack_linked::push(int x)        //PUSHING ELEMENT IN STACK
    {
        node* n=new node();
        n->data=x;
        n->next=NULL;
        if(head==NULL) head=n;
        else
        {
            n->next=head;
            head=n;
        }
        cout<<"Element "<<n->data<<" inserted successfully\n";
    }

    void Stack_linked::pop()             //POPPING AN ELEMENT FROM STACK
    {
        if(head==NULL) cout<<"UNDERFLOW!\n";
        else
        {
          node* temp=head;
          head=head->next;
          cout<<"Element "<<temp->data<<" popped successfully\n";
        }
    }

    void Stack_linked::isEmpty()         //CHECKING WHETHER A STACK IS EMPTY
    {
        if(head==NULL) cout<<"True\n";
        else cout<<"False\n";
    }

    void Stack_linked::display()         //DISPLAYING ALL ELEMENTS OF STACK
    {
        cout<<"STACK ELEMETNS:\n";
        node* temp=new node();
        temp=head;
        while(temp!=NULL) 
        { 
            cout<<temp->data<<"\n";
            temp=temp->next;
        }
    }

    void Stack_linked::peek()               //DISPLAYING TOPMOST ELEMENT OF STACK
    {
        cout<<"Peek: "<<head->data<<"\n";
    }

int main()
{
    cout<<"----------ARRAY IMPLEMENTATION OF STACK----------\n";
    Stack_array s;
    s.isEmpty();
    s.push(1);
    s.push(2);
    s.isEmpty();
    s.push(3);
    s.peek();
    s.pop();
    s.display();
    cout<<"----------LINKED LIST IMPLEMENTATION OF STACK----------\n";
    Stack_linked st;
    st.isEmpty();
    st.push(3);
    st.push(2);
    st.push(1);
    st.isEmpty();
    st.peek();
    st.pop();
    st.display(); 

    //OUTPUT

/*  

  ----------ARRAY IMPLEMENTATION OF STACK----------
True                                                          //CHECKING WHETHER STACK IS EMPTY
Element 1 inserted successfully
Element 2 inserted successfully
False                                                         //CHECKING WHETHER STACK IS EMPTY
Element 3 inserted successfully
Peek: 3
Element 3 popped
STACK ELEMENTS:
2
1
----------LINKED LIST IMPLEMENTATION OF STACK----------
True                                                          //CHECKING WHETHER STACK IS EMPTY
Element 3 inserted successfully
Element 2 inserted successfully
Element 1 inserted successfully
False                                                         //CHECKING WHETHER STACK IS EMPTY
Peek: 1
Element 1 popped successfully
STACK ELEMETNS:
2
3


*/
}
