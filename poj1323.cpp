#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,lose,x;
bool flag[1010],v[1010];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    scanf("%d%d",&m,&n);
    int t=0;
    while (m!=0)
    {
        t++;
        memset(v,0,sizeof(v));
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            flag[x]=1;
        }
        lose=0;
        for (int i=m*n;i>1;i--)
            if (flag[i]==0)
                for (int j=i-1;j>=1;j--)
                    if (flag[j]==1 && v[j]==0)
                    {
                        lose++;
                        v[j]=1;
                        break;
                    }
        printf("Case %d: %d\n",t,n-lose);
        scanf("%d%d",&m,&n);
    }
    return 0;
}
