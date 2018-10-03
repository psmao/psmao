#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
#ifdef MPS
#define D(x...) printf(x)
#else
#define D(x...)
#endif
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 505;

int n, m, f[maxn][maxn][maxn];
char a[maxn], b[maxn];

void add(int &a, int b) {a += b; if(a > 1024523) a -= 1024523;}
int main()
{
	sf("%d%d",&n,&m);
	sf("%s",a+1);
	sf("%s",b+1);
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	f[0][0][0] = 1;
	fo(i,0,n) fo(j,0,m) fo(k,0,n)
	{
		if(i+1 <= n && k+1 <= n && a[i+1] == a[k+1]) add(f[i+1][j][k+1], f[i][j][k]);
		if(i+1 <= n && a[i+1] == b[i+j-k+1] && i+j-k+1 <= m) add(f[i+1][j][k], f[i][j][k]);
		if(j+1 <= m && k+1 <= n && b[j+1] == a[k+1]) add(f[i][j+1][k+1], f[i][j][k]);
		if(j+1 <= m && i+j-k+1 <= m && b[j+1] == b[i+j-k+1]) add(f[i][j+1][k], f[i][j][k]);
	}
	pf("%d\n",f[n][m][n]);
	return 0;
}