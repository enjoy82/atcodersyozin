#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    ll ans = 10000000;
    for(int i = -100; i <= 100; i++){
        ll mid = 0;
        for(int l = 0; l < n; l++){
            mid += (lis[l] - i) * (lis[l] - i);
        }
        ans = min(ans, mid);
    }
    cout << ans << endl;
}