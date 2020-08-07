#include <bits/stdc++.h>
using namespace std;
#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>
const int me = 100025;
const int mod = 0x3b9aca07;
int t, n, c;
int a[me];
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t --){
        cin >> n >> c;
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        sort(a, a + n);
        int low = 0, high = 1.e9, mid, best = 0;
        while(low <= high){
            mid = (low + high + 1) / 2;
            int cnt = 1, last = 0;
            for(int i = 1; i < n && cnt < c; i ++){
                if(a[i] - a[last] >= mid)
                    last = i, cnt ++;
            }
            if(cnt >= c){
                best = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << best << '\n';
    }
    return 0;
} 
