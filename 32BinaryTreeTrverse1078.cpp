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

void PostOrder(Node *root)//�������
{
    if(root->lchild!=NULL)
        PostOrder(root->lchild);
    if(root->rchild!=NULL)
        PostOrder(root->rchild);
    cout<<root->c;
}
//��ԭ������
Node *Build(int s1,int e1,int s2,int e2)//s1:ǰ������Ŀ�ʼ��������s2����������Ŀ�ʼλ�úͽ���λ�á�
{
    Node *ret=new Node();
    ret->c=str1[s1];//���ڵ�
    int rootIndex;
    for(int i=s2;i<=e2;i++)
    {
        if(str1[s1]==str2[i])
        {
            rootIndex=i;//������������еĸ��ڵ��λ��
            break;
        }
    }
    if(rootIndex!=s2)//��������������������Ϊ��
        ret->lchild=Build(s1+1,s1+(rootIndex-s2),s2,rootIndex-1);//it's important to identify the boundary
    if(rootIndex!=e2)//�����������Ϊ��
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
