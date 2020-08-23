#include<iostream>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        
        int is_RXCY = 0;
        
        int C_pos = 0;
        
        long long row=0, column=0;
        
        for(int j=0; j<s.size()-1 ; j++){
            if(s[j]>='0' && s[j]<='9' && s[j+1] == 'C'){
                is_RXCY = 1;
                C_pos = j+1;
                break;
            }
        }
        
        if(is_RXCY){
            for(int j=1; j<C_pos; j++){
                row = row * 10 + (s[j] - '0');
            }
            for(int j=C_pos+1; j<s.size(); j++){
                column = column * 10 + (s[j] - '0');
            }
            
            string column_str;
            while(column){
                if(column % 26){
                    column_str = char(column % 26 + 'A'-1) + column_str;
                }else{
                    column_str = 'Z' + column_str;
                    column -= 26;
                }
                column /= 26;
            }
            cout << column_str << row << endl;
        }
        else{
            for(int j=0; j<s.size(); j++){
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    column = column*26 + s[j] - 'A' + 1;
                }else{
                    row = row * 10 + s[j] - '0';
                }
            }
            cout << 'R' << row << 'C' << column << endl;
        }
    }
}