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

int n, L[maxn], R[maxn], U[maxn], D[maxn];
set<int> r[maxn], l[maxn];

void gg(){pf("NE\n"); exit(0);}
int main()
{
	#ifdef MPS
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d",&n);
	fo(i,1,n) {int x; sf("%d",&x); L[i] = x; if(x != -1) r[i].insert(x+1);}	
	fo(i,1,n) {int x; sf("%d",&x); R[i] = x; if(x != -1) r[i].insert(n-x);}
	fo(i,1,n) {int x; sf("%d",&x); U[i] = x; if(x != -1) l[i].insert(x+1);}
	fo(i,1,n) {int x; sf("%d",&x); D[i] = x; if(x != -1) l[i].insert(n-x);}
	fo(i,1,n) 
	{
		if(L[i] == -1 && SZ(r[i])) gg();
		if(L[i] != -1 && (!SZ(r[i]) || (*r[i].begin())-1 != L[i])) gg();
		if(R[i] == -1 && SZ(r[i])) gg();
		set<int>:: iterator it = r[i].end();
		if(R[i] != -1 && (!SZ(r[i]) || n-(*(--it)) != R[i])) gg();
		if(U[i] == -1 && SZ(l[i])) gg();
		if(U[i] != -1 && (!SZ(l[i]) || (*l[i].begin())-1 != U[i])) gg();
		if(D[i] == -1 && SZ(l[i])) gg(); 
		it = l[i].end();
		if(D[i] != -1 && (!SZ(l[i]) || n-(*(--it)) != D[i])) gg();
	}
	pf("DA\n");
	return 0;
}