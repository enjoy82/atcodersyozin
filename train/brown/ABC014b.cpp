#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

int main(){
    int n, x; cin >> n >> x;
    vector<int> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    int ans = 0;
    REP(i, 0, n){
        if(x & 1 == 1){
            ans += lis[i];
        }
        x /= 2;
    }
    cout << ans << endl;
}