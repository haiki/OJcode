#include<iostream>
#include<cmath>
using namespace std;
 //感觉如果是两个相同类型的数相运算后由大类型到小类型就不用强制转换了，如double到int
//但是一个double和int运算得到一个int则需要强制转换
int main()
{
    int n,m;
    int left,right;
    int n_d,m_d,diff;
    int ans=0;
    while(cin>>m>>n)//看清楚题目要求是哪个在前哪个在后
    {
        if(n==0&&m==0)
            break;

        left=right=m;

        n_d=log(n)/log(2)+1;//求出有n个节点的时候其深度，相当于第n个节点在第几层；这只是针对完全二叉树说的
        m_d=log(m)/log(2)+1;//这里相当于下取整


        diff=n_d-m_d;//求出以m为根节点树除了叶节点的高度

        for(int i=0;i<diff;i++)
        {
            left=2*left;
            right=right*2+1;//一直走到叶节点那一层,而且这个是以根节点开始，一路向左，一路向右到最底层。
        }

        ans=pow(2,diff)-1;//求出满的那些层一共有多少节点
        if(right<=n)
            ans+=right-left+1;
        else if(left<=n)
            ans+=n-left+1;
        cout<<ans<<endl;

    }

    return 0;
}
