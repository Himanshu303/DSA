#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;   
};

class Tree
{
public:
    Node* root;
    int data;
    void createTree();
    void preOrder(){preOrder(root);}                //METHOD OVERLOADING
    void preOrder(Node* p);
    void postOrder(){postOrder(root);}
    void postOrder(Node *p);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
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

void Tree::postOrder(Node *p)
{
    if(p)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<" ";
    }
}

void Tree::inOrder(Node* p)
{
    if(p)
    {
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
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
    root->data=n;                                       //SETTING ROOT NODE AND ASSIGNING CHILDREN AS NULL
    root->left=root->right=NULL;    
    q.push(root);                                       //ENQUEUING ROOT NODES ADDRESS
    while(!q.empty())
    {
        p=q.front();                                    //TAKING ROOT NODES ADDRESS
        q.pop();
        cout<<"ENTER LEFT SUBTREE (ENTER -1 for NULL)\n";  
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();                       //CREATING NODE FOR LEFT SUBTREE
             nd->data=c;                                //ASSIGNING DATA TO NODE
             nd->right=nd->left=NULL;                   //ASSIGNING CHILDREN AS NULL
             p->left=nd;                                //ASSIGNING CURRENT NODE AS LEFT CHILD OF PARENT NODE
             q.push(nd);                                //ENQUEUING CURRENT NODE
        }
        cout<<"ENTER RIGHT SUBTREE (ENTER -1 for NULL)\n";
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();                       //CREATING NODE FOR RIGHT SUBTREE
             nd->data=c;                                //ASSIGNING DATA TO NODE
             nd->right=nd->left=NULL;                   //ASSIGNING CHILDREN AS NULL
             p->right=nd;                               //ASSIGNING CURRENT NODE AS RIGHT CHILD OF PARENT NODE
              q.push(nd);                               //ENQUEUING CURRENT NODE
        }
    }
}
int main()
{
    
    Tree* r=new Tree();
    r->createTree();
    cout<<"PREORDER TRAVERSAL IS\n";
    r->preOrder();
    cout<<"\nPOSTORDER TRAVERSAL IS\n";
    r->postOrder();
    cout<<"\nINORDER TRAVERSAL IS\n";
    r->inOrder();

/*
CONSTRUCTING TREE FOR THE BELOW REPRESENTATION

N=NULL
                                1
                               / \
                             2     3
                            / \   / \
                           4   5  6   7
                          / \ / \ / \ / \
                          N N N N N N N N

The output of the program is:
ENTER ROOT NODE OF TREE:
1
ENTER LEFT SUBTREE (ENTER -1 for NULL)
2 
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
3
ENTER LEFT SUBTREE (ENTER -1 for NULL)
4
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
5
ENTER LEFT SUBTREE (ENTER -1 for NULL)
6
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
7
ENTER LEFT SUBTREE (ENTER -1 for NULL)
-1
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
-1
ENTER LEFT SUBTREE (ENTER -1 for NULL)
-1
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
-1
ENTER LEFT SUBTREE (ENTER -1 for NULL)
-1
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
-1
ENTER LEFT SUBTREE (ENTER -1 for NULL)
-1
ENTER RIGHT SUBTREE (ENTER -1 for NULL)
-1

PREORDER TRAVERSAL IS                                                                                                   
1 2 4 5 3 6 
POSTORDER TRAVERSAL IS                                                                                                  
4 5 2 6 7 3 
INORDER TRAVERSAL IS                                                                                                    
4 2 5 1 6 3 7  
*/
}
