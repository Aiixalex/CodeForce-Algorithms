#include<iostream>
 
using namespace std;
 
int main(){
    int n, m, a;
    while(cin >> n >> m >> a){
        int x = n/a;
        int y = m/a;
        if(n%a) x++;
        if(m%a) y++;
        cout << x*y << endl;
    }
    return 0;
}