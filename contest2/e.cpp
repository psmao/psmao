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
 
const int maxn = 100001;
 
struct event{int p, y1, y2, v;}a[maxn<<1];
int n, tot, num = 1, disc[maxn*2], overall;
bool Ans[maxn];
struct node{int l, r; set<int> Set1, Set2;}t[maxn*8];
 
void upd(int l, int r, int L, int R, int x, int k)
{
	if(x < 0) // erase operation
	{
		if(t[k].Set2.find(-x) != t[k].Set2.end()) t[k].Set2.erase(-x);
	}
	else
	{
		t[k].Set2.insert(x);
		set<int>:: iterator it = t[k].Set1.lower_bound(x);
		if(!SZ(t[k].Set1) || it == t[k].Set1.begin()) ;
		else
		{
			int v = -1;
			while(1)
			{
				-- it;
				v = (*it); Ans[v] = false;
				if(it == t[k].Set1.begin()) break;
			}
		}
		it = t[k].Set1.upper_bound(x);
		if(it != t[k].Set1.end()) Ans[x] = false;
	}
	if(l <= L && R <= r)
	{
		if(x < 0)
		{
			if(t[k].Set1.find(-x) != t[k].Set1.end()) t[k].Set1.erase(-x);
		}
		else
		{
			t[k].Set1.insert(x);
			set<int>:: iterator it = t[k].Set2.lower_bound(x);
			if(!SZ(t[k].Set2) || it == t[k].Set2.begin()) ;
			else
			{
				int v = -1;
				while(1)
				{
					-- it;
					v = (*it); Ans[v] = false;
					if(it == t[k].Set2.begin()) break;
				}
			}
			it = t[k].Set2.upper_bound(x);
			if(it != t[k].Set2.end()) Ans[x] = false;
		}
		return;
	}
	int mid = (1ll*L + R) >> 1;
	if(r <= mid) {if(!t[k].l) t[k].l = ++num; upd(l, r, L, mid, x, t[k].l);}
	else if(l > mid) {if(!t[k].r) t[k].r = ++num; upd(l, r, mid+1, R, x, t[k].r);}
	else 
	{
		if(!t[k].l) t[k].l = ++ num; 
		upd(l, mid, L, mid, x, t[k].l);
		if(!t[k].r) t[k].r = ++ num; 
		upd(mid+1, r, mid+1, R, x, t[k].r);
	}
}
bool cmp(event a, event b){return a.p != b.p ? a.p < b.p : a.v < b.v;}
int main()
{
	#ifdef MPS
		fp("1.in","r",stdin);
		fp("1.out","w",stdout);
	#endif
	sf("%d",&n);
	fo(i,1,n)
	{
		int x, y, l1, l2;
		sf("%d%d%d%d",&x,&y,&l1,&l2);
		a[++tot] = (struct event){x, y, y+l2-1, i};
		a[++tot] = (struct event){x+l1, y, y+l2-1, -i};
		disc[++overall] = y;
		disc[++overall] = y+l2-1;
	}
	sort(disc+1,disc+overall+1);
	overall = unique(disc+1, disc+overall+1) - (disc+1);
	fo(i,1,tot) 
	{
		a[i].y1 = lower_bound(disc+1,disc+overall+1,a[i].y1)-disc;
		a[i].y2 = lower_bound(disc+1,disc+overall+1,a[i].y2)-disc;
	}
	sort(a+1, a+tot+1, cmp);
	memset(Ans, 1, sizeof(Ans));
	fo(i,1,tot) upd(a[i].y1, a[i].y2, 1, overall, a[i].v, 1);
	fo(i,1,n) if(Ans[i]) pf("DA\n"); else pf("NE\n");
	return 0;
}