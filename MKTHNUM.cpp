#include <bits/stdc++.h> 
using namespace std; 
#define N (int)5e5 
int arr[N];
vector<int> seg[N]; 
  
void build(int ci, int st, int end, 
           pair<int, int>* B) 
{ 
    if (st == end) { 
        seg[ci].push_back(B[st].second); 
        return; 
    } 
  
    int mid = (st + end) / 2; 
    build(2 * ci + 1, st, mid, B); 
    build(2 * ci + 2, mid + 1, end, B); 
  
    merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), 
          seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(), 
          back_inserter(seg[ci])); 
} 
  
int query(int ci, int st, int end, 
          int l, int r, int k) 
{ 
    if (st == end) 
        return seg[ci][0]; 
  
    int p = upper_bound(seg[2 * ci + 1].begin(), 
                        seg[2 * ci + 1].end(), r) 
            - lower_bound(seg[2 * ci + 1].begin(), 
                          seg[2 * ci + 1].end(), l); 
  
    int mid = (st + end) / 2; 
    if (p >= k) 
        return query(2 * ci + 1, st, mid, l, r, k); 
    else
        return query(2 * ci + 2, mid + 1, end, l, r, k - p); 
} 
  
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++){cin>>arr[i];}
    pair<int, int> B[n]; 
  
    for(int i=0;i<n;i++){B[i]={arr[i],i};}
    sort(B,B+n); 
    build(0,0,n-1,B); 
  
    while(q--)
    {
    	int l,r,k;
    	cin>>l>>r>>k;
    	
    	cout<<arr[query(0,0,n-1,l-1,r-1,k)]<<'\n';
    }
    return 0;
}   
