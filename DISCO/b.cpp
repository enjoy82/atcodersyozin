#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    ll total = 0;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        total += lis[i];
    }
    ll mid1 = 0;
    ll mid2 = 0;
    for(int i = 0; i < n; i++){
        mid1 += lis[i];
        if(mid1 >= (total / 2)){
            break;
        }
        mid2 += lis[i];
    }
    ll a1 = total - mid1;
    ll a2 = total - mid2;
    cout << min(abs(a1 - mid1), abs(a2 - mid2)) << endl;
    return 0;
}