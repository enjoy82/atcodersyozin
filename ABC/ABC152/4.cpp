#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    ll ans = 0;
    ll ans2 = 0;
    int count = 0;
    for(int i = n; i >= 1; i--){
        int c = i;
        int ch = c % 10;
        if(c >= 10){
            c = c / 10;
        }
        if(ch == 0){continue;}
        ll mid = 1;
        while(c >= 10){
            mid *= (c % 10);
            c = c / 10;
        }
        if(ch > c){continue;}
        if(mid != 1){
            ans += mid * 2;
        }else{
            if(ch == c && i >= 10){ans2++;}
            else if(i < 10){ans2++;}
            else{ans += 1;}
        }
        cout << i << endl;
        cout << c << ch << endl;
        string s = to_string(i);
        for(int l = s.size() - 1; l >= 1; l--){
            if(l == 2){
                if(ch == c){ans += 2;}
                else{ans += 1;}
            }
            if(l == 1 && i < 10){ans += 1;}
            else{ans += (int)pow(9, l-2) * 2;}
        }
        cout <<"#" <<ans << endl;
    }
    cout << ans*2 + ans2<< endl;
}