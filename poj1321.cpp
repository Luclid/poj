#include<cstdio>
using namespace std;
int n,k;
bool v[10];
char a[10][10];
long long ans;
void dfs(int now,int sum)
{
    if (sum==k)
    {
        ans++;
        return;
    }
    for (int i=0;i<n;i++)
        if (a[now][i]=='#' && !v[i])
        {
            v[i]=true;
            dfs(now+1,sum+1);
            v[i]=false;
        }
    if (now+1<n) dfs(now+1,sum);
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    while (n!=-1)
    {
        for (int i=0;i<n;i++) scanf("%s",a[i]);
        for (int i=0;i<n;i++) v[i]=false;
        ans=0;
        dfs(0,0);
        printf("%lld\n",ans);
        scanf("%d%d",&n,&k);
    }
    return 0;
}
