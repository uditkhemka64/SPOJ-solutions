#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int Max=3e5+1;
int n,q,maxx;
string s,s1;
int siz[Max],parent[Max];
vector<pair<int,int>> query;
int type,value;
vector<int> ans;
 
int find(int x)
{
	if(x==parent[x]){return parent[x];}
	return parent[x]=find(parent[x]);
}
 
void unionset(int a,int b)
{
	int para=find(a);
	int parb=find(b);
	
	if(para==parb)return;
	if(siz[para]<siz[parb])
	{
		parent[para]=parb;
		siz[parb]+=siz[para];
		maxx=max(maxx,siz[parb]);
	}
	else
	{
		parent[parb]=para;
		siz[para]+=siz[parb];
		maxx=max(maxx,siz[para]);
	}
}
 
ll power(ll a,ll b,ll m){ll res=1;while(b){if(b%2){res=(res*a)%m;}b>>=1;a=(a*a)%m;}return res;}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int cc=1;
	int t;cin>>t;
    while(t--)
    {
    	cin>>s>>q;
    	n=s.length();
    	s='#'+s+'#';
    	s1=s;
    	
    	query.clear();ans.clear();
    	
    	while(q--)
    	{
    		cin>>type>>value;
    		query.push_back({type,value});
    		if(type==2)
    		{
    			value++;
    			s1[value]='#';
    		}
    	}
    	
    	
    	for(int i=1;i<=n;i++)
    	{
    		if(s1[i]!='#')
    		{
    		parent[i]=i;
    		siz[i]=1;
    		}
    	}
    	
    	for(int i=1;i<=n;i++)
    	{
    		if(s1[i]!='#' && s1[i]==s1[i-1])
    		{
    			unionset(i-1,i);
    		}
    	}
    	
    	q=query.size();
    	
    	
    	for(int i=q-1;i>=0;i--)
    	{
    		if(query[i].first==2)
    		{
    			value=query[i].second;
    			value++;
    			s1[value]=s[value];
    			siz[value]=1;
    			parent[value]=value;
    			if(s1[value]==s1[value+1]){unionset(value,value+1);}
    			if(s1[value]==s1[value-1]){unionset(value-1,value);}
    		}
    		else
    		{
    			value=query[i].second;
    			value++;
    			int finalans=find(parent[value]);
    			finalans=siz[finalans];
    			ans.push_back(finalans);
    		}
    	}
    	
    	cout<<"Case "<<cc<<":"<<endl;
    	cc++;
    	for(int i=ans.size()-1;i>=0;i--)
    	{
    		cout<<ans[i]<<'\n';
    	}
    	
    }
return 0;
} 
