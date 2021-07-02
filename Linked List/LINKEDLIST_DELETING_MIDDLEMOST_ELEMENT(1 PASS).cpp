#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = NULL;

void insert_start(int n)
{
    Node *nd = new Node();
    nd->data = n;
    nd->next = NULL;
    if (head == NULL)
        head = nd;
    else
    {
        Node *temp = new Node();
        nd->next = head;
        head = nd;
    }
}

void display()
{
    if (head == NULL)
        cout << "LIST DOESNT EXIST\n";
    else
    {
        Node *temp = new Node();
        temp = head;
        cout << "LINKED LIST ELEMENTS:\n";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

void display_middle_element()
{
    Node *fast_ptr = head;
    Node *slow = head;
    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next; //FAST POINTER MOVES 2 STEPS AT A TIME
            slow = slow->next;               //SLOW POINTER MOVES 1 STEP AT A TIME
        }
        cout << "THE MIDDLE ELEMENT OF LIST IS: " << slow->data << "\n"; //WHEN FAST POINTER REACHES THE END OF LINKED LIST, SLOW POINTER REACHES IN THE MIDDLE
    }
    else
        cout << "EMPTY LINKED LIST\n";
}

void deleteMid()
{
    Node *fast_ptr = head;
    Node *slow = head;
    Node *prev=NULL;
    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next; 
            prev=slow;
            slow = slow->next;              
        }
        
        prev->next=slow->next;
        delete(slow);
        
    }
}
int main()
{
    insert_start(7);
    insert_start(6);
    insert_start(5);
    insert_start(4);
    insert_start(3);
    insert_start(2);
    insert_start(1);
    display();
    deleteMid();
    display();
    //THE OUTPUT IS
    /*
    LINKED LIST ELEMENTS:
    1->2->3->4->5->6->7->NULL
    LINKED LIST ELEMENTS:
    1->2->3->5->6->7->NULL
    */
}
