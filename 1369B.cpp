#include<iostream>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        for(int i=n-1; i>=1; i--){
            if(s[i] == '0' && s[i-1] == '1'){
                s.erase(i-1, 2);
                s.insert(i-1, 1, 'x');
                i--;
            }
        }
        
        int first_x = -1, last_x = -1;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'x'){
                first_x = i;
                for(int j=first_x-1; j>=0; j--){
                    if(s[j] == '1'){
                        s.erase(j, 1);
                    }
                }
                break;
            }
        }
        
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == 'x'){
                last_x = i;
                for(int j=s.size()-1; j>last_x; j--){
                    if(s[j] == '0'){
                        s.erase(j, 1);
                    }
                }
            }
        }
        
        if(first_x != -1){
            for(int i=0; i<s.size(); i++){
                if(s[i] == 'x'){
                    first_x = i;
                    break;
                }
            }
            
            for(int i=s.size()-1; i>=0; i--){
                if(s[i] == 'x'){
                    last_x = i;
                    break;
                }
            }
            s.erase(first_x, last_x - first_x + 1);
            s.insert(first_x, 1, '0');
        }
        
        cout << s << endl;
    }
}