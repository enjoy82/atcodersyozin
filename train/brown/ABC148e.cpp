#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n; cin >> n;
    if(n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    while(n >= 10){
        n = n / 5;
        ans += n/2;
    }
    cout << ans << endl;
    return 0;
}