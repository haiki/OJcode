#include<iostream>
#include<algorithm>
#include<vector>//��Ϊ��Ҫɾ��һ������Ԫ�أ�����������鷽��
using namespace std;
int main()
{
    vector<int> v;
    vector<int>::iterator it;//����vector
    int n,num;
    while(cin>>n)
    {
        v.clear();//��Ҫ����һ���������
        for(int i=0; i<n; i++)
        {
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(),v.begin()+n);//����Ҫע���������ʱ���±��Ǵ�ʲô��ʼ��
        cout<<v.back()<<endl;

        v.erase(v.begin()+n-1);//������һ����

        if(v.size()==0)
            cout<<"-1";
        else
        {
            for(it=v.begin(); it!=v.end(); it++)//����Ҫע��ľ�������ĸ���ʽ
                if(it==v.begin())
                {
                    cout<<*it;
                }
                else
                {
                    cout<<" "<<*it;
                }
        }
        cout<<endl;
    }

    return 0;
}
