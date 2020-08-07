#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int Max=1e6+1;
const ll mod1=998244353;
int freq[Max],above[Max],ans[Max];
int finalans=0;
 
int block;
 
struct Query { 
    int L, R, index;
};
 
bool compare(Query x, Query y) 
{ 
    if (x.L / block != y.L / block) 
        return y.L / block < x.L / block; 
  
    return x.R < y.R; 
} 
 
 
ll power(ll a,ll b){ll res=1;while(b>0){if(b%2==1){res=(res*a)%mod;}a=(a*a)%mod;b>>=1;}return res;}
 
void mo(Query query[],int arr[],int n,int q)
{
	int ml=query[0].L,mr=query[0].L-1;
	int element,f;
	
	for(int i=0;i<q;i++)
	{
		int l=query[i].L,r=query[i].R;
		
		while(ml<l)
		{
			element=arr[ml];
			freq[element]--;
			if(freq[element]==0){finalans--;}
			ml++;
		}
		while(ml>l)
		{
			ml--;
			element=arr[ml];
			f=freq[element];
			freq[element]++;
			if(freq[element]==1){finalans++;}
		}
		while(mr<r)
		{
			mr++;
			element=arr[mr];
			f=freq[element];
			freq[element]++;
			if(freq[element]==1){finalans++;}
		}
		while(mr>r)
		{
			element=arr[mr];
			freq[element]--;
			if(freq[element]==0){finalans--;}
			mr--;
		}
		
		ans[query[i].index]=finalans;
 
	}
	
	for(int i=0;i<q;i++){cout<<ans[i]<<"\n";}
}
 
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;t=1;
	while(t--)
	{
		int n,q;
		cin>>n;
		int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
		int l,r;
		cin>>q;
		Query query[q];
        for(int i=0;i<q;i++)
        {
        cin>>l>>r;
        query[i]={l-1,r-1,i};
        }
        
        block=800;
		sort(query,query+q,compare);
		mo(query,arr,n,q);
	}
} 
