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

const int maxn = 100050;
const int P = 1e9+7;

int n, l, q, a[maxn], new_a[maxn];
int DP1[maxn], DP2[maxn], _DP1[maxn], _DP2[maxn]; 
int new_g[maxn];
VI adj[maxn];
map<int,int> tmp[maxn], new_tmp[maxn];

void add(int &x, int y)
{
	x += y;
	if(x >= P) x -= P;
}
void dec(int &x, int y)
{
	x -= y;
	if(x < 0) x += P;
}
void getup(int u)
{
	DP1[u] = (a[u] == 1 ? 1 : new_g[a[u]-1]);
	DP2[u] = (new_a[u] == 1 ? 1 : new_g[new_a[u]-1]);
	if(new_a[u] == 1) add(new_g[new_a[u]], 1);
	else add(new_g[new_a[u]], new_g[new_a[u]-1]);
	for(auto p : adj[u]) getup(p);
	if(new_a[u] == 1) dec(new_g[new_a[u]], 1);
	else dec(new_g[new_a[u]], new_g[new_a[u]-1]);
}
void getdown(int u)
{
	tmp[u].clear();
	for(auto p : adj[u]) 
	{
		getdown(p);
		if(SZ(tmp[p]) > SZ(tmp[u])) swap(tmp[u], tmp[p]);
	}
	for(auto p : adj[u])
	{
		for(auto q : tmp[p]) add(tmp[u][q.fi], q.se);
	}
	_DP1[u] = (a[u] == l ? 1 : tmp[u][a[u]+1]);
	_DP2[u] = (new_a[u] == l ? 1 : tmp[u][new_a[u]+1]);
	if(a[u] == l) add(tmp[u][a[u]], 1);
	else add(tmp[u][a[u]], tmp[u][a[u]+1]);
}
int main()
{
	#ifdef MPS	
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d%d%d",&n,&l,&q);
	fo(i,1,n-1) {int x; sf("%d",&x); adj[x].pb(i);}
	fo(i,0,n-1) sf("%d",&a[i]);
	int ans = 0, o = 0;
	getup(0); getdown(0);
	ans = tmp[0][1];
	// D("~~~~~~~~\n");
	// fo(i,0,n-1) D("%d %d %d %d %d\n",i,DP1[i],DP2[i],_DP1[i],_DP2[i]);
	// D("~~~~~~~~~~\n");
	D("%d\n",ans);
	for(int i = 0; i < q; i += n)
	{
		for(int j = 0; j < n; ++ j) new_a[j] = a[j];
		for(int j = 0; j < n && i + j + 1 <= q; ++ j) sf("%d",&new_a[j]);
		getup(0); getdown(0);
		for(int j = 0; j < n && i + j + 1 <= q; ++ j)
		{
			int delta = (1ll * DP1[j] * _DP1[j]) % P;
			dec(ans, delta);
			delta = (1ll * DP2[j] * _DP2[j]) % P;
			add(ans, delta);
			a[j] = new_a[j];
			delta = (1ll * (i+j+1) * ans) % P;
			add(o, delta);

	// D("~~~~~~~~\n");
	// fo(i,0,n-1) D("%d %d %d %d %d\n",i,DP1[i],DP2[i],_DP1[i],_DP2[i]);
	// D("~~~~~~~~~~\n");
			D("%d\n",ans);
		}
	}
	pf("%d\n",o);
	return 0;
}
