#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> lis(200001, 0);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        lis[a] += b;
    }
    ll mid = 0;
    for(int i = 0; i < 200000; i++){
        mid += lis[i];
        if(mid >= k){cout << i << endl; return 0;}
    }
    return 0;
}