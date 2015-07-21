#include<cstdio>
#include<cstring>
using namespace std;
int mmax,sum;
char s[10];
bool v[10],way[10];
bool rejected;
void dfs(int dep,int value,int before)
{
    int now=0;
    for (int i=before;i<dep;i++)
    {
        now=now*10;
        now=now+s[i]-'0';
    }
    if (dep==strlen(s))
    {
        int ans=value+now;
        if (ans>mmax) return;
        if (ans==sum)
        {
            rejected=true;
            return;
        }
        else if (ans>sum)
        {
            sum=ans;
            rejected=false;
            for (int i=0;i<strlen(s);i++) way[i]=v[i];
            return;
        }
        return;
    }
    if (value>mmax) return;
    v[dep]=1;
    dfs(dep+1,value+now,dep);
    v[dep]=0;
    dfs(dep+1,value,before);

}
int main()
{
    scanf("%d%s",&mmax,s);
    while (mmax!=0)
    {
        memset(v,0,sizeof(v));
        sum=0;
        v[0]=1;
        rejected=false;
        dfs(1,0,0);
        if (rejected==true) printf("rejected\n");
        else if (sum==0) printf("error\n");
        else
        {
            printf("%d",sum);
            for (int i=0;i<strlen(s);i++)
            {
                if (way[i]==1) printf(" ");
                printf("%c",s[i]);
            }
            printf("\n");
        }
        scanf("%d%s",&mmax,s);
    }
    return 0;
}
