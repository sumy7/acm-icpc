#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <deque>
#include <assert.h>

using namespace std;
#define BUG1 puts("BUG11\n")
#define BUG2 puts("BUG22\n")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rp(i,a) for(int i=0;i<a;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define STOP  system("pause")
#define PP printf(" ")
#define mem(x,y) memset(x,y,sizeof(x))
#define LN printf("\n");
#define du freopen("in.txt","r",stdin)
#define chu freopen("out.txt","w",stdout)
#define EPS 1e-8
#define FI first
#define SE second
#define PB push_back
#define MP make_pair


typedef long long LL;
inline bool insize(int c,int l,int r){if (c>=l&&c<=r) return true; return false;}
template<class T> inline void checkmin(T &a,T b){if(a == -1 || a > b)a = b;}
template<class T> inline void checkmax(T &a,T b){if(a < b)    a = b;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int ,int> II;

int dx[] = {0,1,0,-1};//up Right down Left
int dy[] = {1,0,-1,0};
template<class T> inline void sf(T& x)
{
    char c;
    int mul = 1;
    while((c = getchar()) != EOF)
    {
        if(c == '-')mul = -1;
        if(c >= '0' && c <= '9')
        {
            x = c-'0';
            break;
        }
    }
    if(c == EOF){x = EOF;return;}
    while((c = getchar()))
    {
        if(c >= '0' && c <= '9')
        {
            x = (x<<1)+(x<<3)+(c-'0');
        }
        else break;
    }
    x *= mul;
}

const int N=20000;       // 点数
const int E=200555;   //边数
const int INF= 0x3f3f3f3f;
const long long  LINF= 0x3F3F3F3F3F3F3F3FLL;

#define maxn 400005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int val[maxn];
void pushup(int rt)
{
    val[rt]=val[rt<<1]*val[rt<<1|1];
    return ;
}
void build(int l,int r,int rt)
{
    int t;
    if(l==r)
    {
        scanf("%d",&t);
        if(t<0)val[rt]=-1;
        else if(t>0)val[rt]=1;
        else val[rt]=0;
        return ;
    }
    int m=(l+r)>>1;
    build(lson),build(rson);
    pushup(rt);
}
void update(int p,int v,int l,int r,int rt)
{
    if(l==r)
    {
        val[rt]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(p,v,lson);
    else update(p,v,rson);
    pushup(rt);
}
int query(int l1,int r1,int l,int r,int rt)
{
    if(l1<=l&&r1>=r)
    {
        return val[rt];
    }
    int m=(l+r)>>1,tt=1;
    if(m>=l1)tt*=query(l1,r1,lson);
    if(m<r1)tt*=query(l1,r1,rson);
    return tt;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        char cc[5];
        int u,v;
        build(1,n,1);getchar();
        for(int i=0;i<m;i++)
        {
            scanf("%s%d%d",cc,&u,&v);
            if(cc[0]=='C')
            {
                if(v>0)v=1;
                else if(v<0)v=-1;
                update(u,v,1,n,1);
            }
            else
            {
                if(u>v)swap(u,v);
                int ans=query(u,v,1,n,1);
                if(ans>0)printf("+");
                else if(ans<0)printf("-");
                else printf("0");
            }

        }
        puts("");
    }

}
