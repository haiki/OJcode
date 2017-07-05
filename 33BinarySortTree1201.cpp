#include<iostream>
using namespace std;
class Node
{
public:
    Node* lchild;
    Node* rchild;
    int c;
    Node(int ch)
    {
        c=ch;
        lchild=rchild=NULL;
    }
} ;
void PreOrder(Node *root)
{
    cout<<root->c<<" ";
    if(root->lchild!=NULL)
        PreOrder(root->lchild);
    if(root->rchild!=NULL)
        PreOrder(root->rchild);
}
void InOrder(Node *root)
{
    if(root->lchild!=NULL)
        InOrder(root->lchild);
    cout<<root->c<<" ";
    if(root->rchild!=NULL)
        InOrder(root->rchild);
}
void PostOrder(Node *root)
{
    if(root->lchild!=NULL)
        PostOrder(root->lchild);

    if(root->rchild!=NULL)
        PostOrder(root->rchild);
    cout<<root->c<<" ";

}
Node *Insert(Node *root,int num)
{
    if(root==NULL)
    {
        root=new Node(num);
    }
    else if(num>root->c)
    {
        root->rchild=Insert(root->rchild,num);
    }
    else if(num<root->c)
    {
        root->lchild=Insert(root->lchild,num);
    }
    return root;
}
int main()
{
    int n;


    while(cin>>n&&n>0&&n<=100)
    {
        Node *r=NULL;
        for(int i=0; i<n; i++)
        {
            int m;
            cin>>m;
            r=Insert(r,m);
        }
        PreOrder(r);
        cout<<endl;
        InOrder(r);
        cout<<endl;
        PostOrder(r);
        cout<<endl;
    }

    return 0;
}
