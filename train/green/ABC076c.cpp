#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s, t; cin >> s >> t;
    int f = 0;
    for(int i = s.size() - 1;i >= 0; i--){
        if(f == 1){
            break;
        }
        int j;
        for(j = 0; j < t.size(); j++){
            if(s[i - j] == t[t.size() - 1 - j] || s[i - j] == '?'){
                continue;
            }else{
                break;
            }
        }
        if(j == t.size()){
            f = 1;
            for(j = 0; j < t.size(); j++){
                s[i-j] = t[t.size() - 1 - j];
            }
        }
    }
    if(f == 0){
        cout << "UNRESTORABLE" << endl; 
    }else{
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '?'){
                s[i] = 'a';
            }
        }
        cout << s << endl;
    }
}