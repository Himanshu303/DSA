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
void removeDuplicates()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == (temp->next)->data)
        {
            Node *fwd = temp->next;
            temp->next = fwd->next; //IF DATA OF  THE NEXT NODE IS SAME AS CURRENT NODE THEN WE DELETE NEXT NODE AND STAY ON CURRENT NODE FOR NEXT ITERATION AS WELL
            delete (fwd);
            continue;
        }
        temp = temp->next;
    }
}
int main()
{
    insert_start(7);
    insert_start(7);
    insert_start(7);
    insert_start(6);
    insert_start(5);
    insert_start(5);
    insert_start(4);
    insert_start(4);
    insert_start(3);
    insert_start(2);
    insert_start(1);
    insert_start(1);
    insert_start(1);
    insert_start(1);
    insert_start(1);
    display();
    removeDuplicates();
    display();

    //THE OUTPUT OF PROGRAM IS
    /*
    LINKED LIST ELEMENTS:
    1->1->1->1->1->2->3->4->4->5->5->6->7->7->7->NULL
    LINKED LIST ELEMENTS:
    1->2->3->4->5->6->7->NULL
    */
}
