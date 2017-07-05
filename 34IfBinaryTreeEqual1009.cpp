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
//�������еı���  �����ܵ��ȳ�ʼ����  �����������벻���Ĵ���
char str1[30]={0};
char str2[30]={0};//str1����һ������ǰ����������������������str2�����һ�����Ƚϵ����ı������
int size1=0,size2=0;//�ֱ��¼���Ƚ����кͱȽ����еĳ���
char *str=0;
int *size0=0;//��ָ�����ָ��sizeȥʵ��i++��Ч��������ȫ�ֱ�������ʵ�ְ����������Ľ������������

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
        //cout<<r->c;//�����Ƿ����ȷ
        size1=0;
        size0=&size1;//���ڱ�����ַ����ĸ���ָ���һ��
        str=str1;//���ڱ�����ַ���
        PreOrder(r);
        InOrder(r);
        //str1[size1]=0;//�ڵ�һ���ַ��������һ���ַ�������ַ�������ʹ���ַ������� ����Ϊ/
//��������ĺϲ�����
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
