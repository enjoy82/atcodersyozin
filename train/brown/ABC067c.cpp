#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    ll sum = 0, count = 0, ans = 1000000000000;
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        sum += lis[i];
    }
    for(int i = 0; i < n-1; i++){
        count += lis[i];
        ans = min(abs(sum - 2*count), ans);
    }
    cout << ans << endl;
}