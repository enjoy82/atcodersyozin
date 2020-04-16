#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll x; cin >> x;
    ll k = x / 500;
    x -= 500 * k;
    ll m = x  / 5;
    cout << k * 1000 + 5 * m;
}