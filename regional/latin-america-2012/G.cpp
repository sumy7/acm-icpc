#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <numeric>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;
#define exp 1e-8
#define inf 0x7fffffff
#define debug puts("BUG")
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)

/*2分图最大匹配,O(E*V^0.5)*/
#define maxn 2505
int headU[maxn],headV[maxn];
int du[maxn],dv[maxn];
vector<int>vec[maxn];
int uN,vN;
bool bfs()
{
    queue<int>q;
    int dis=inf;
    memset(du,0,sizeof(du));
    memset(dv,0,sizeof(dv));
    for(int i=1;i<=uN;i++)
        if(headU[i]==-1)q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(du[u]>dis)break;
        for(int i=0;i<(int)vec[u].size();i++)
            if(!dv[vec[u][i]])
            {
                dv[vec[u][i]]=du[u]+1;
                if(headV[vec[u][i]]==-1)dis=dv[vec[u][i]];
                else
                {
                    du[headV[vec[u][i]]]=dv[vec[u][i]]+1;
                    q.push(headV[vec[u][i]]);
                }
            }
    }
    return dis!=inf;
}
bool dfs(int u)
{
    for(int i=0;i<(int)vec[u].size();i++)
        if(dv[vec[u][i]]==du[u]+1)
        {
            dv[vec[u][i]]=0;
            if(headV[vec[u][i]]==-1||dfs(headV[vec[u][i]]))
            {
                headU[u]=vec[u][i];
                headV[vec[u][i]]=u;
                return 1;
            }
        }
    return 0;
}
int Hopcroft()
{
    memset(headU,-1,sizeof(headU));
    memset(headV,-1,sizeof(headV));
    int ans=0;
    while(bfs())
      for(int i=1;i<=uN;i++)
          if(headU[i]==-1&&dfs(i))ans++;
    return ans;
}
int n,m;
char ss[55][55];
void add(int x,int y)
{
    if(x-1>=0&&ss[x-1][y]=='.')vec[x*m+y+1].push_back((x-1)*m+y+1);
    if(x+1<n&&ss[x+1][y]=='.')vec[x*m+y+1].push_back((x+1)*m+y+1);
    if(y-1>=0&&ss[x][y-1]=='.')vec[x*m+y+1].push_back(x*m+y);
    if(y+1<m&&ss[x][y+1]=='.')vec[x*m+y+1].push_back(x*m+y+2);
}
int main()
{
    //read;
    while(~scanf("%d%d",&n,&m))
    {
        uN=n*m;
        for(int i=0;i<maxn;i++)vec[i].clear();
        for(int i=0;i<n;i++)
            scanf("%s",ss[i]);
        int tot=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(ss[i][j]=='.')++tot;
                if((i+j)%2&&ss[i][j]=='.')
                    add(i,j);
            }
        if(tot%2){puts("1");continue;}
        int ans=Hopcroft();
        if(ans==tot/2)puts("2");
        else puts("1");
    }
    return 0;
}
