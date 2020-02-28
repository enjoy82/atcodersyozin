#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = k+1; i <= n; i++){
        int p = n / i;
        ans += p*max(0, (i-k)) + max(0, (n % i +1 -k));
        if(k == 0){
            ans -= 1;
        }
        //cout << p*max(0, (i-k)) << " " << max(0, (n % i +1 -k)) << " " << ans << endl;
    }
    cout << ans << endl;
}