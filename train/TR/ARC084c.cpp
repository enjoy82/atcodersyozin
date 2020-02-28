#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<int> lis(n), lis1(n);
    for(int i = 0; i < n; i++){
        auto idx = lower_bound(a.begin(), a.end(), b[i]);
        lis[i] = idx-a.begin();
    }
    for(int i = 0; i < n; i++){
        auto idx = lower_bound(b.begin(), b.end(), c[i]);
        lis1[i] = idx-b.begin();
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int l = 0; l < lis[i]; l++){
            ans += lis[i] * lis1[l];
        }
    }
    cout << ans << endl;
}