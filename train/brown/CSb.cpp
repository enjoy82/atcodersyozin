#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define div 998244353

int main(){
    int n; cin >> n;
    vector<int> d(n, 0);
    ll ans = 1;
    int a; cin >> a;
    if(a != 0){cout << 0 << endl; return 0;}
    for(int i = 1; i < n; i++){
        int mid; cin >> mid;
        d[mid]++;
    }
    ll count = 1;
    ll pre = 1;
    for(int i = 1; i < n; i++){
        if(pre == 0 && count < n){
            cout << 0 << endl;
            return 0;
        }
        for(int l = 0; l < d[i]; l++){
            ans = (ans * pre) % div;
        }
        pre = d[i];
        count += d[i];
        if(count == n){
            break;
        }
    }
    cout << ans << endl;
}