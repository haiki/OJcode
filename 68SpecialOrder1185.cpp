#include<iostream>
#include<algorithm>
#include<vector>//因为需要删除一个最大的元素，用这个比数组方便
using namespace std;
int main()
{
    vector<int> v;
    vector<int>::iterator it;//遍历vector
    int n,num;
    while(cin>>n)
    {
        v.clear();//需要把上一组数据清除
        for(int i=0; i<n; i++)
        {
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(),v.begin()+n);//排序要注意你输入的时候下标是从什么开始的
        cout<<v.back()<<endl;

        v.erase(v.begin()+n-1);//清除最后一个数

        if(v.size()==0)
            cout<<"-1";
        else
        {
            for(it=v.begin(); it!=v.end(); it++)//这里要注意的就是输出的个格式
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
