#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll h; cin >> h;
    ll ans = 0;
    ll count = 1;
    while(h != 0){
        ans += count;
        h /= 2;
        count *= 2;
    }
    cout << ans << endl;
}