#include<iostream>
#include<vector>
#include<cstdio>
 
using namespace std;
 
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long l=0, r=0, m=0;
        cin >> l >> r >> m;
        long long biggest_remainder = r - l;
        for(int a=l; a<=r; a++){
            long long remainder = m % a;
            if(remainder <= biggest_remainder && m/a > 0){
                cout << a << ' ' << r << ' ' << r-remainder << endl;
                break;
            }else if(remainder >= a - biggest_remainder){
                cout << a << ' ' << r-(a-remainder) << ' ' << r << endl;
                break;
            }
        }
    }
}