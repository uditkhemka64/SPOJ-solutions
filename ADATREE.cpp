#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max=3e5+1;
vector<int> tree[Max<<2];
int arr[Max],n,h,l,r,q;
 
void merge(vector<int> &a, vector<int> &b, vector<int> &to) {
    int lengthA = (int)a.size();
    int lengthB = (int)b.size();
    int ptrA = 0, ptrB = 0;
    while (ptrA < lengthA && ptrB < lengthB) {
        if (a[ptrA] < b[ptrB]) {
            to.push_back(a[ptrA]);
            ptrA ++;
        }
        else {
            to.push_back(b[ptrB]);
            ptrB ++;
        }
    }
    while (ptrA < lengthA) {
        to.push_back(a[ptrA ++]);
    }
    while (ptrB < lengthB) {
        to.push_back(b[ptrB ++]);
    }
}
 
void buildTree(int index,int l,int r)
{
    if(l==r)
    {
        tree[index]=vector<int>(1,arr[l]);
        return;
    }
    
    int m=(l+r)>>1;
    buildTree(2*index,l,m);
    buildTree(2*index+1,m+1,r);
    merge(tree[2*index],tree[2*index+1],tree[index]);
}
 
int get(int index,int low,int high,int l,int r,int h)
{
    if(low>r || high<l){return 0;}
    if(low>=l && high<=r)
    {
        vector<int>::iterator it = --lower_bound(tree[index].begin(), tree[index].end(), h + 1);
        if(*it>h){return 0;}
        return *it;
    }
    
    int m=(low+high)/2;
    return max(get(index<<1,low,m,l,r,h),get(index<<1|1,m+1,high,l,r,h));
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>q;
    for(int i=1;i<=n;i++){cin>>arr[i];}
    buildTree(1,1,n);
    
    while(q--)
    {
        cin>>l>>r>>h;
        l++;r++;
        cout<<get(1,1,n,l,r,h)<<'\n';
    }
    
} 
