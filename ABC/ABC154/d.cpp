#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, k; cin >> n >> k;
    vector<double> lis(n);
    vector<double> plis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
    }
    double ans = 0;
    double a = 0;
    for(int i = 0; i < n; i++){
        double k = (lis[i] * (lis[i]+1)) / 2;
        plis[i] = k / lis[i];
    }
    for(int i = 0; i < k; i++){
        ans += plis[i];
    }
    double ch = ans;
    for(int i = k; i < n; i++){
        ch = ch - plis[i-k] + plis[i];
        ans = max(ch, ans);
    }
    cout << std::fixed << std::setprecision(15) << ans << endl;
}