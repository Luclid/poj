#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
    double right,left;
};
node a[1010];
int ans,n,d;
bool flag;

bool cmp(node x,node y)
{
    return x.left<y.left;
}

int main()
{
    int T=0;
    scanf("%d%d",&n,&d);
    while (n!=0)
    {
        T++;
        flag=true;
        ans=0;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            if (yy>d)
            {
                flag=false;
                continue;
            }
            double dx=sqrt(d*d-yy*yy);
            a[i].left=xx-dx;
            a[i].right=xx+dx;
        }
        if (flag==false) ans=-1;
        else
        {
            sort(a+1,a+n+1,cmp);
            double last=a[1].right;
            ans=1;
            for (int i=2;i<=n;i++)
            {
                if (a[i].left>last)
                {
                    ans++;
                    last=a[i].right;
                }
                else if (a[i].right<last) last=a[i].right;
            }
        }
        printf("Case %d: %d\n",T,ans);
        scanf("%d%d",&n,&d);
    }
    return 0;
}
