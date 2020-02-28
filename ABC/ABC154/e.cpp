#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll atoi(char c){
    return c - '0';
}

int main(){
    string s; cin >> s;
    int k; cin >> k;
    if(k == 1){
        ll ans = 0;
        for(int i = 1; i < s.size(); i++){
            ans += 9;
        }
        ans += atoi(s[0]);
        cout << ans << endl;
        return 0;
    }else if(k == 2){
        ll ans = 0;
        for(int i = 2; i < s.size(); i++){
            ans += 9 * (i-1) * 9;
        }
         ans += (atoi(s[0])-1) * (s.size()-1) * 9;
         int f = 0;
         for(int i = 1; i < s.size(); i++){
             if(f == 1){
                 ans += 9;
             }else{
                if(atoi(s[i]) != 0){
                    f = 1;
                    ans += atoi(s[i]);
                }    
             }
         }
         cout << ans << endl;
        return 0;
    }else{
        ll ans = 0;
        ll siz = s.size();
        for(ll i = 3; i < siz; i++){
            ans += (i-1) * (i-2) / 2 * 729;
        }
        ans +=  (atoi(s[0])-1) * (siz-1) * (siz-2) / 2 * 81;
        int f = 0;
        for(ll i = 1; i < siz; i++){
            if(f == 1){
                ans += 9 * (siz-1-i) * 9;
            }else{
                if(atoi(s[i]) != 0){
                    f = 1;
                    int f2 = 0;
                    //ans += atoi(s[i]) * (siz-1-i) * 9;
                    for(ll l = i+1; l < siz; l++){
                        if(f2 == 1){
                            ans += atoi(s[i]) * 9;
                        }else{
                            if(atoi(s[l]) != 0){
                                //cout << "OK" << endl;
                                f2 = 1;
                                ans += atoi(s[l]);
                                ans += (atoi(s[i])-1) * 9;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
}