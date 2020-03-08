#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
    string s; cin >> s;
    ll q; cin >> q;
    map<ll, string> mp;
    mp[0] = s;
    ll st = -1, last = 1;
    int f = 1;
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 1){
            f *= -1;
        }else{
            int c; cin >> c;
            string ss; cin >> ss;
            if(c == 1){
                if(f == 1){
                    mp[st] = ss;
                    st--;
                }else{
                    mp[last] = ss;
                    last++;
                }
            }else{
                if(f == 1){
                    mp[last] = ss;
                    last++;
                }else{
                    mp[st] = ss;
                    st--;
                }
            }
        }
    }
    if(f == 1){
        for(ll i = st+1; i < last; i++){
            cout << mp[i];
        }
    }else{
        for(ll i = last-1; i > st; i--){
            if(i == 0){
                string t = mp[0];
                reverse(t.begin(), t.end());
                cout << t;
                continue;
            }
            cout << mp[i];
        }
    }
}