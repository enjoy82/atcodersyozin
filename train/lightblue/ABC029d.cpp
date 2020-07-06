#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x, n / 2);
  else
    return x * Pow(x, n - 1);
}


int main(){
    ll n; cin >> n;
    n++;
    ll ans = 0;
    for(ll i = 0; i < to_string(n).size(); i++){
        ll kk = Pow(10, i+1);
        ll k = Pow(10, i);
        ans += (n / kk) * k; 
        if(n - ((n/kk) * kk) - k > 0){
            if(i == 0){
                ans++;
            }else{
                ans += min(n - ((n/kk) * kk) - k, k);
            }
        }
    }  
    cout << ans << endl;
}