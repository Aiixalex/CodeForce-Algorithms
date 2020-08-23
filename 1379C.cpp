#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long n=0, m=0;
        cin >> n >> m;
        vector<long long> a(m);
        vector<long long> b(m);
        for(int i=0; i<m; i++){
            cin >> a[i] >> b[i];
        }
        
        vector<long long> a_sorted = a;
        sort(a_sorted.begin(), a_sorted.end());
        
        vector<long long> sum(m+1);
        sum[m] = 0;
        sum[m-1] = a_sorted[m-1];
        for(int i=m-2; i>=0; i--){
            sum[i] = sum[i+1] + a_sorted[i];
        }
        
        long long ans = sum[max<long long>(0, m-n)];
        
        for(int i=0; i<m; i++){
            long long cnt = min(n - 1, m - (upper_bound(a_sorted.begin(), a_sorted.end(), b[i]) - a_sorted.begin()));
            long long res = sum[m - cnt] + b[i] * (n - 1 - cnt);
            if(cnt == 0 || a[i] < a_sorted[m - cnt]){
                res += a[i];
            }else if(cnt != m){
                res += max(b[i], a_sorted[m - cnt - 1]);
            }else if(cnt == m){
                res += b[i];
            }
            
            ans = max(ans, res);
        }
        
        cout << ans << endl;
    }
}