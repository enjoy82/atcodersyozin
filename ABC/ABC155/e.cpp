#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int atoi(char a){
    return a - '0';
}

int main(){
    string s; cin >> s;
    ll ans = 0;
    int f = 0;
    /*for(int i = s.size()-1; i >= 0; i--){
        int k = atoi(s[i]);
        if(k > 5){
            ans += 10 - (k+f);
            f = 1;
        }else if(k == 5){
            ans += 5;
            f  = 1;
        }else{
            ans += k + f;
            f = 0;
        }
        cout << ans << endl;
    }
    if(f == 1){ans++;}
    cout << ans << endl;
}