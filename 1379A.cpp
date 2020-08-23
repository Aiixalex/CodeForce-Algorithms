#include<iostream>
#include<vector>
#include<cstdio>
 
using namespace std;
 
int count(int n, string s){
    int cnt = 0;
    for(int i=6; i<n; i++){
        if(s[i-6] == 'a' && s[i-5] == 'b' && s[i-4] == 'a' && s[i-3] == 'c' && s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'a'){
            cnt ++;
        }
    }
    return cnt;
}
 
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n=0;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        cnt = count(n, s);
        
        if(cnt > 1){
            printf("No\n");
        }else if(cnt == 1){
            for(int i=0; i<n; i++){
                if(s[i] == '?'){
                    s[i] = 'd';
                }
            }
            printf("Yes\n");
            cout << s << endl;
        }else if(cnt == 0){
            int flag = 0;
            for(int i=6; i<n; i++){
                if( (s[i-6] == 'a'||s[i-6] == '?') && 
                    (s[i-5] == 'b'||s[i-5] == '?') && 
                    (s[i-4] == 'a'||s[i-4] == '?') && 
                    (s[i-3] == 'c'||s[i-3] == '?') && 
                    (s[i-2] == 'a'||s[i-2] == '?') && 
                    (s[i-1] == 'b'||s[i-1] == '?') && 
                    (s[i-0] == 'a'||s[i-0] == '?') )
                {
                    vector<int> index;
                    if(s[i-6] == '?'){
                        s[i-6] = 'a';
                        index.push_back(6);
                    }
                    if(s[i-5] == '?'){
                        s[i-5] = 'b';
                        index.push_back(5);
                    }
                    if(s[i-4] == '?'){
                        s[i-4] = 'a';
                        index.push_back(4);
                    }
                    if(s[i-3] == '?'){
                        s[i-3] = 'c';
                        index.push_back(3);
                    }
                    if(s[i-2] == '?'){
                        s[i-2] = 'a';
                        index.push_back(2);
                    }
                    if(s[i-1] == '?'){
                        s[i-1] = 'b';
                        index.push_back(1);
                    }
                    if(s[i] == '?'){
                        s[i] = 'a';
                        index.push_back(0);
                    }
                    
                    int cnt_temp = count(n, s);
 
                    if(cnt_temp > 1){
                        for(int j = 0; j < index.size(); j++){
                            s[i-index[j]] = '?';
                        }
                    }else if(cnt_temp == 1){
                        for(int i=0; i<n; i++){
                            if(s[i] == '?'){
                                s[i] = 'd';
                            }
                        }
                        flag = 1;
                        printf("Yes\n");
                        cout << s << endl;
                        break;
                    }
                }
            }
            if(!flag){
                printf("No\n");
            }
        }
    }
}