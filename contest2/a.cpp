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

const int maxn = 3005;

int n, a[maxn], b[maxn], ans1, ans2, winner;

int main()
{
	#ifdef MPS
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d",&n);
	fo(i,1,n) {int x; sf("%d",&x); a[x] ++; b[x] ++;}
	sf("%d",&n);
	fo(i,1,n) {int x; sf("%d",&x); a[x] -- ; b[x] ++;}
	winner = -1;
	fo(i,1,4*12*60)
	{
		a[i] += a[i-1];
		b[i] += b[i-1];
		if(i == 2*12*60) ans1 = b[i];
		if(a[i] > 0 && winner == 0) ++ ans2;
		if(a[i] < 0 && winner == 1) ++ ans2;
		if(a[i] != 0) winner = (a[i] > 0 ? 1 : 0);
		
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}