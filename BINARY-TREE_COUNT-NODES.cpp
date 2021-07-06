#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;   
}*root=NULL;

class Tree
{
public:
   
    int data;
    void createTree();
  
    int count_nodes(Node *p);

};

int Tree::count_nodes(Node* p)
{
    if(p)
    {
        return count_nodes(p->left)+count_nodes(p->right)+1;
    }
    else return 0;

}

void Tree::createTree()
{
    int n;
    Node *p=NULL;
    int c;
    queue<Node *> q;
    cout<<"ENTER ROOT NODE OF TREE:\n";
    cin>>n;
    root=new Node();
    root->data=n;
    root->left=root->right=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"ENTER LEFT CHILD NODE OF "<<p->data<<" (ENTER -1 for NULL)\n";
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();
             nd->data=c;
             nd->right=nd->left=NULL;
             p->left=nd;
             q.push(nd);
        }
        cout<<"ENTER RIGHT CHILD NODE OF "<<p->data<<" (ENTER -1 for NULL)\n";
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();
             nd->data=c;
             nd->right=nd->left=NULL;
             p->right=nd;
              q.push(nd);
        }
    }
}
int main()
{
    
    Tree* r=new Tree();
    r->createTree();
    cout<<"NUMBER OF NODES IN TREE IS: ";
    cout<<r->count_nodes(root)<<"\n";


    /*
    N=NULL
    Lets count number of nodes of following binary tree
                        1
                       /  \
                     2      6
                    / \     / \
                  3    4    N  N
                /  \   / \ 
               5   N   N  N
              / \
             N   N
    */
   //THE OUTPUT OF THE CODE IS

/*
   ENTER ROOT NODE OF TREE:
    1
    ENTER LEFT CHILD NODE OF 1 (ENTER -1 for NULL)
    2
    ENTER RIGHT CHILD NODE OF 1 (ENTER -1 for NULL)
    6
    ENTER LEFT CHILD NODE OF 2 (ENTER -1 for NULL)
    3
    ENTER RIGHT CHILD NODE OF 2 (ENTER -1 for NULL)
    4
    ENTER LEFT CHILD NODE OF 6 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 6 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 3 (ENTER -1 for NULL)
    5
    ENTER RIGHT CHILD NODE OF 3 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 4 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 4 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 5 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 5 (ENTER -1 for NULL)
    -1
    NUMBER OF NODES IN TREE IS: 6
    */

}

