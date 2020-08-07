#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9+7;
const int mxN = 4e5;
const int mxM = 4*mxN;
long long sum[mxM], add[mxM], mul[mxM], lft[mxM], rht[mxM];
 
void build(int u, int l, int r) {
	sum[u] = 0, add[u] = 0;
	mul[u] = 1;
	lft[u] = l, rht[u] = r;
	if (l == r) return;
	int m = l + r >> 1;
	build(u + u, l, m);
	build(u + u + 1, m + 1, r);
}
 
void up(int u) {
	sum[u] = (sum[u+u] + sum[u+u+1]) % MOD;
}
 
void down(int u) {
	int l = lft[u], r = rht[u];
	int m = l+r >> 1;
	if (mul[u] != 1) {
		sum[u+u] *= mul[u]; sum[u+u] %= MOD;
		mul[u+u] *= mul[u]; mul[u+u] %= MOD;
		sum[u+u+1] *= mul[u]; sum[u+u+1] %= MOD;
		mul[u+u+1] *= mul[u]; mul[u+u+1] %= MOD;
		add[u+u] *= mul[u]; add[u+u] %= MOD;
		add[u+u+1] *= mul[u]; add[u+u+1] %= MOD;
		mul[u] = 1;
	}
	if (add[u]) {
		sum[u+u] += add[u]*(m-l+1); sum[u+u] %= MOD;
		add[u+u] += add[u]; add[u+u] %= MOD;
		sum[1+u+u] += add[u]*(r-m); sum[u+u+1] %= MOD;
		add[1+u+u] += add[u]; add[u+u+1] %= MOD;
		add[u] = 0;
	}
}
 
long long query(int u, int ll, int rr) {
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		return sum[u];
	}
	int m = l + r >> 1;
	down(u);
	long long ret = 0;
	if (ll <= m) ret += query(u + u, ll, rr);
	if (m < rr) ret += query(u + u + 1, ll, rr);
	up(u);
	return (ret%MOD+MOD)%MOD;
}
 
void update_add(int u, int ll, int rr, long long x) {
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		sum[u] += x*(r-l+1);
		sum[u] %= MOD;
		add[u] += x;
		add[u] %= MOD;
		return;
	}
	int m = l + r >> 1;
	down(u);
	if (ll <= m) update_add(u + u, ll, rr, x);
	if (m < rr) update_add(u + u + 1, ll, rr, x);
	up(u);
}
 
void update_mul(int u, int ll, int rr, long long x) {
	int l = lft[u], r = rht[u];
	if (ll <= l && r <= rr) {
		sum[u] *= x;
		sum[u] %= MOD;
		mul[u] *= x;
		mul[u] %= MOD;
		add[u] *= x;
		add[u] %= MOD;
		return;
	}
	int m = l + r >> 1;
	down(u);
	if (ll <= m) update_mul(u + u, ll, rr, x);
	if (m < rr) update_mul(u + u + 1, ll, rr, x);
	up(u);
}
 
int main() {
	int n, q;
	cin>>n>>q;
	build(1, 1, n);
	for (int i = 1; i <= n; i ++) {
		update_add(1, i, i, 0);
	}
	
	while (q --) {
		LL v,l,r;
		cin>>l>>r>>v;
		update_mul(1, l, r, 0);
		update_add(1, l, r, v);
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<query(1,i,i)<<'\n';
	}
	
}
