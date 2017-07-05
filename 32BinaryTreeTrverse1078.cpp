#include<iostream>
#include<cstring>
using namespace std;
class Node{
public:

    Node *lchild;
    Node *rchild;
    char c;
    Node(){lchild=rchild=NULL;}

};
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
char str1[30],str2[30];//save preorder and inorder result

void PostOrder(Node *root)//后序遍历
{
    if(root->lchild!=NULL)
        PostOrder(root->lchild);
    if(root->rchild!=NULL)
        PostOrder(root->rchild);
    cout<<root->c;
}
//还原二叉树
Node *Build(int s1,int e1,int s2,int e2)//s1:前序遍历的开始，结束。s2：中序遍历的开始位置和结束位置。
{
    Node *ret=new Node();
    ret->c=str1[s1];//根节点
    int rootIndex;
    for(int i=s2;i<=e2;i++)
    {
        if(str1[s1]==str2[i])
        {
            rootIndex=i;//查找中序遍历中的根节点的位置
            break;
        }
    }
    if(rootIndex!=s2)//如果中序遍历的左子树不为空
        ret->lchild=Build(s1+1,s1+(rootIndex-s2),s2,rootIndex-1);//it's important to identify the boundary
    if(rootIndex!=e2)//如果右子树不为空
        ret->rchild=Build(s1+(rootIndex-s2)+1,e1,rootIndex+1,e2);
    return ret;
}

int main()
{
    while(cin>>str1)
    {
        cin>>str2;
        int len1=strlen(str1);
        int len2=strlen(str2);
        Node *root=new Node();
        root=Build(0,len1-1,0,len2-1);
        PostOrder(root);
        cout<<endl;
        clear(root);
    }

    return 0;
}
