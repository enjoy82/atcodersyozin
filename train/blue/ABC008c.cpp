#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    double ans = 0;
    REP(i, 0, n){cin >> lis[i];}
    REP(i, 0, n){
        vector<ll> r = divisor(lis[i]);
        int count = 0;
        REP(l, 0, n){
            REP(j, 0, r.size()){
                if(lis[l] == r[j]){
                    count ++;
                    break;
                }
            }
        }
        //cout << count << " ";
        if(count == 1){
            ans += 1.0;
        }
        else if(count % 2 == 0){
            ans += 0.5;
        }else{
            ans += ((count/2+1) / (count*1.0));
        }
        //cout << ans << endl;
    }
    cout << fixed << setprecision(20) << ans << endl;
}