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
    int height_tree(Node *p);
    void preOrder(){preOrder(root);}
    void preOrder(Node* p);

};
void Tree::preOrder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }
}


int Tree::height_tree(Node* p)
{
    if(p==NULL) return 0;
    else return max(height_tree(p->left),height_tree(p->right))+1;
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
             nd->right=NULL;
             nd->left=NULL;
             p->left=nd;
             q.push(nd);
        }
        cout<<"ENTER RIGHT CHILD NODE OF "<<p->data<<" (ENTER -1 for NULL)\n";
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();
             nd->data=c;
             nd->right=NULL;
             nd->left=NULL;
             p->right=nd;
             q.push(nd);
        }
    }
}
int main()
{
    
    Tree* r=new Tree();
    r->createTree();
    cout<<"TOTAL LEVELS OF THE TREE IS: ";
    cout<<r->height_tree(root)<<"\n";
    cout<<"HEIGHT OF THE TREE IS: ";
    cout<<r->height_tree(root)-1<<"\n";


    /*
    N=NULL
    TOTAL LEVELS OF BINARY TREE
     1ST                   1
                          /  \
     2ND                2      3
                       / \     / \
     3RD              4   5    6  7
                     /  \ / \   / \
                    N  N  N  N  N   N
       
             
    */
   //THE OUTPUT OF THE CODE IS

/*
   ENTER ROOT NODE OF TREE:
    1
    ENTER LEFT CHILD NODE OF 1 (ENTER -1 for NULL)
    2
    ENTER RIGHT CHILD NODE OF 1 (ENTER -1 for NULL)
    3
    ENTER LEFT CHILD NODE OF 2 (ENTER -1 for NULL)
    4
    ENTER RIGHT CHILD NODE OF 2 (ENTER -1 for NULL)
    5
    ENTER LEFT CHILD NODE OF 3 (ENTER -1 for NULL)
    6
    ENTER RIGHT CHILD NODE OF 3 (ENTER -1 for NULL)
    7
    ENTER LEFT CHILD NODE OF 4 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 4 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 5 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 5 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 6 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 6 (ENTER -1 for NULL)
    -1
    ENTER LEFT CHILD NODE OF 7 (ENTER -1 for NULL)
    -1
    ENTER RIGHT CHILD NODE OF 7 (ENTER -1 for NULL)
    -1
    TOTAL LEVELS OF THE TREE IS: 3
    HEIGHT OF THE TREE IS: 2
    */

}

