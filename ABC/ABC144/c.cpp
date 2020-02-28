#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n; cin >> n;
    ll mid = 1;
    for(ll i = (ll)sqrt(n) + 1; i > 1; i--){
        if(n % i == 0){
            n = n / i;
            mid = i;
            break;
        }
    }
    cout << mid + n - 2 << endl;
}