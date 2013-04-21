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

struct node{
    int son, onlyson;
    node *next[30], *fail;
    node(){
        onlyson= 0;
        son= 0;
        rep(i,0,26)
            next[i]= NULL;
        fail= NULL;
    }
};

void insert(char *pat, node *root){
    node *p= root;
    int t= 0;
    while(pat[t]){
        int idx= pat[t]-'a';
        if (p->next[idx]==NULL){
            p->next[idx]= new node();
            p->son++;
            if(p->son==1)   p->onlyson= idx;
        }
        p= p->next[idx];
        t++;
    }
    p->next[26]= new node();
    p->son++;
    if(p->son==1)   p->onlyson= 26;
}

int ans, n;
char ch[1000005];
node *root;

void dfs(node *p, int c)
{
    //printf(" son= %d c= %d \n", p->son, c);
    if(p->son==0)
    {
        ans+= c+1;
        //printf("ans= %d\n", ans);
        return;
    }else if(p->son==1)
    {
        dfs(p->next[p->onlyson], c);
    }else
    {
        rep(i,0,25)
        {
            if(p->next[i]==NULL)    continue;
            dfs(p->next[i], c+1);
        }
        if(p->next[26]!=NULL)
            ans+= c+1;
        //printf("ans= %d\n", ans);
    }

}

int main(){

    while(~scanf("%d", &n))
    {
        ans= 0;
        root= new node();
        rep(i,1,n)
        {
            scanf("%s", ch);
            insert(ch, root);
        }
        rep(i,0,25)
        {
            if(root->next[i]==NULL) continue;
            dfs(root->next[i], 0);
        }
        printf("%.2lf\n", (double)ans/n);
    }

}
