#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n; cin >> n;
    ll sum = 0;
    vector<ll> lis(n);
    for(int i = 0; i < n; i++){
        cin >> lis[i];
        sum += lis[i];
    }
    ll mid = 0;
    for(int i = 1; i < n; i+=2){
        mid += (2*lis[i]);
    }
    vector<ll> ans(n);
    ans[0] = sum - mid;
    for(int i = 1; i < n; i++){
        ans[i] = 2 * (lis[i-1] - (ans[i-1]/2));
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}op=