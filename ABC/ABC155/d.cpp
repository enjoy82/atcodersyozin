#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int atoi(char a){
    return a - '0';
}

int main(){
    string s, k = ""; cin >> s;
    ll ans = 0;
    int f = 0;
    for(int i = s.size()-1; i >= 0; i--){
        int l = atoi(s[i]);
        if(l+f >= 6){
            k = "0" + k;
            f = 1;
        }else{
            ans += l + f;
            k = to_string(l+f) + k;
            f = 0;
        }
    }
    if(f == 1){
        ans++;
    }
    f = 0;
    for(int i = s.size()-1; i >= 0; i--){
        int l = atoi(s[i]), m = atoi(k[i]);
        if(m == 0 && l != 0){
            ans += 10 - l - f;
            f = 1;
        }else{
            ans += m - l - f;
            f = 0;
        }
    }
    cout << ans << endl;
}