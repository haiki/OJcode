#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node
{
public:

    int data;
    Node *lchild;
    Node *rchild;
    Node(int da=0):data(da)
    {
        lchild=rchild=0;
    }
    Node(int da,Node *l,Node *r)
    {
        data=da;
        lchild=l;
        rchild=r;
    }
};
class BinSearTree
{
public:
    Node *root;
    void clear(Node *root)
    {
        if(root!=NULL)
        {
            clear(root->lchild);
            clear(root->rchild);
            root->lchild=NULL;
            root->rchild=NULL;
            delete root;
            root=NULL;
        }
    }
    BinSearTree()
    {
        root=0;
    }
    BinSearTree(int da)
    {
        root=new Node(da);
    }
    void InsertNode(int da)
    {
        Node *p=root,*pre=NULL;
        while(p)
        {
            pre=p;
            if(da<(p->data))
                p=p->lchild;
            else
                p=p->rchild;
        }
        if(root==NULL)
            root=new Node(da);
        else if(da<(pre->data))
            pre->lchild=new Node(da);
        else
            pre->rchild=new Node(da);
    }
    int visit(Node *n)
    {
        return n->data;
    }
    string Inorder(Node *root)
    {
        string str;
        if(root!=NULL)
        {
            str+=Inorder(root->lchild);
            str+=visit(root)+'0';
            str+=Inorder(root->rchild);
        }
        return str;
    }
    string Preorder(Node *root)
    {
        string str;
        if(root!=NULL)
        {
            str+=visit(root)+'0';
            str+=Preorder(root->lchild);
            str+=Preorder(root->rchild);
        }
        return str;
    }
    Node *getRoot()
    {
        return root;
    }
};
int main()
{
    vector<string> ve;
    vector<string> ve1;
    BinSearTree bt;
    string num;//要输入的数
    int n;//输入几组数与原来的比较
    char c;
    while(cin>>n&&n!=0)
    {
        cin.get(c);
        ve.resize(n+1);
        ve1.resize(n+1);

        getline(cin,num);

        for(int i=0; i<num.size(); i++)
        {
            bt.InsertNode(num[i]-'0');
        }
        Node *no=bt.getRoot();
        ve[0]=bt.Inorder(no);
        ve1[0]=bt.Preorder(no);
        for(int j=1; j<=n; j++)
        {
            getline(cin,ve[j]);
            BinSearTree bt1;
            for(int i=0; i<ve[j].size(); i++)
            {
                bt1.InsertNode(ve[j][i]-'0');
            }
            no=bt1.getRoot();
            ve[j]=bt1.Inorder(no);
            ve1[j]=bt1.Preorder(no);
        }
    }
    for(int i=1; i<ve.size(); i++)
    {
        if(ve[i]==ve[0]&&ve1[i]==ve1[0])
            cout<<"YES";
        else
            cout<<"NO";
        if(i<ve.size()-1)
            cout<<endl;
    }
}
