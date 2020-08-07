#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max=1e6+1;
ll phi[Max],ans[Max];
ll n;
 
void call_euler()
{
 
   for(int i=0;i<Max;i++){phi[i]=i;}    
    
   for(int i=2;i<Max;i++)
   {
   	if(i==phi[i])
   	{
   		for(int j=i;j<Max;j+=i)
   		{
   			phi[j]/=i;
   			phi[j]*=i-1;
   		}
   	}
   }
   
   for(int i=1;i<Max;i++)
    {
        for(int j=i;j<Max;j+=i)
        {
            ans[j]+=(ll)i*phi[i];
        }
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    call_euler();
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        ll finalans=0;
        
        finalans=((ans[n]+1)*n)/2;
        cout<<finalans<<'\n';
    }
    return 0;
} 
