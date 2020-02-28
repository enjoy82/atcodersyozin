#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll a, b; cin >> a >> b;
    ll ans = 0;
    while(a <= b){
        a *= 2;
        ans++;
    }
    cout << ans << endl;
}