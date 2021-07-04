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
    void preOrder(){preOrder(root);}
    void preOrder(Node* p);
    void postOrder(){postOrder(root);}
    void postOrder(Node *p);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
    void levelOrder(){levelOrder(root);}
    void levelOrder(Node* p);

};
void Tree::levelOrder(Node *p)
{
    queue<Node*> q;
    
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty())
    {
        Node* r=q.front();
        q.pop();
        if(r->left)
        {
            cout<<r->left->data<<" ";
            q.push(r->left);
        }
        if(r->right)
        {
            cout<<r->right->data<<" ";
            q.push(r->right);
        }

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
    root->data=n;
    root->left=root->right=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"ENTER LEFT SUBTREE (ENTER -1 for NULL)\n";
        cin>>c;
        if(c!=-1)
        {
             Node* nd=new Node();
             nd->data=c;
             nd->right=nd->left=NULL;
             p->left=nd;
             q.push(nd);
        }
        cout<<"ENTER RIGHT SUBTREE (ENTER -1 for NULL)\n";
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
    cout<<"THE LEVEL ORDER OF TREE IS:\n";
    r->levelOrder();

/*
    N=NULL
    CONSTRUCTING FOLLOWING TREE:
  
                                1
                               / \
                             2      4
                            /  \    /\
                          3     N   N  5
                         / \           / \
                        N   N         N   N
*/
    //THE OUTPUT OF PROGRAM IS
    /*

    ENTER ROOT NODE OF TREE:
    1
    ENTER LEFT SUBTREE (ENTER -1 for NULL)
    2
    ENTER RIGHT SUBTREE (ENTER -1 for NULL)
    4
    ENTER LEFT SUBTREE (ENTER -1 for NULL)
    3
    ENTER RIGHT SUBTREE (ENTER -1 for NULL)
    -1
    ENTER LEFT SUBTREE (ENTER -1 for NULL)
    -1
    ENTER RIGHT SUBTREE (ENTER -1 for NULL)
    5
    ENTER LEFT SUBTREE (ENTER -1 for NULL)
    -1
    ENTER RIGHT SUBTREE (ENTER -1 for NULL)
    -1
    ENTER LEFT SUBTREE (ENTER -1 for NULL)
    -1
    ENTER RIGHT SUBTREE (ENTER -1 for NULL)
    -1
    THE LEVEL ORDER OF TREE IS:
    1 2 4 3 5 
    
    */

}

