#include<iostream>
#include<cstring>
using namespace std;
class Node
{
public:
    Node* lchild;
    Node* rchild;
    int c;
    Node(int n)
    {
        c=n;
        lchild=rchild=NULL;
    }
};
//对于所有的变量  尽可能的先初始化好  否则会出现意想不到的错误
char str1[30]={0};
char str2[30]={0};//str1：第一颗树的前序中序遍历结果连接起来；str2：与第一颗树比较的树的遍历结果
int size1=0,size2=0;//分别记录被比较序列和比较序列的长度
char *str=0;
int *size0=0;//用指针变量指向size去实现i++的效果，并且全局变量可以实现把两个遍历的结果连接起来。

void PreOrder(Node *root)
{
    str[(*size0)++]=root->c+'0';
    if(root->lchild!=NULL)
        PreOrder(root->lchild);
    if(root->rchild!=NULL)
        PreOrder(root->rchild);
}
void InOrder(Node *root)
{
    if(root->lchild!=NULL)
        InOrder(root->lchild);
    str[(*size0)++]=root->c+'0';
    if(root->rchild!=NULL)
        InOrder(root->rchild);
}

Node* Insert(Node *root,int num)
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
    while(cin>>n&&n!=0)
    {
        char tmp[12];
        cin>>tmp;

        Node *r=NULL;
        for(int i=0; tmp[i]!='\0'; i++)
        {
            r=Insert(r,tmp[i]-'0');
        }
        //cout<<r->c;//测试是否根正确
        size1=0;
        size0=&size1;//正在保存的字符串的个数指向第一个
        str=str1;//正在保存的字符串
        PreOrder(r);
        InOrder(r);
        //str1[size1]=0;//在第一个字符串的最后一个字符后添加字符，方便使用字符串函数 否则为/
//测试输出的合并序列
       /* for(int i=0; i<=size1; i++)
            cout<<str1[i];
        cout<<endl;*/
        while(n--!=0)
        {
            cin>>tmp;
            Node *ro=NULL;
            for(int j=0; tmp[j]!='\0'; j++)
            {
                ro=Insert(ro,tmp[j]-'0');
            }
            //cout<<ro->c;
            size2=0;
            size0=&size2;
            str=str2;
            PreOrder(ro);
            InOrder(ro);
            //str2[size2]=0;
            /*for(int i=0; i<=size2; i++)
                cout<<str2[i];
            cout<<endl;*/
            if(strcmp(str1,str2)==0)
               cout<<"YES"<<endl;
            else
               cout<<"NO"<<endl;
        }

    }
    return 0;
}
