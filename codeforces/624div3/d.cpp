#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

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


void solve(){
    int a, b, c; cin >> a >> b >> c;
    vector<int> anslis(3);
    int ans = 1e9;
    REP(i, 1, 10100){
        //cout << i << endl;
        vector<ll> r = divisor(i);
        int mid, prec;
        if(c-(c%i) - i < 0){
            mid = abs(c+(i-(c%i))-c);
            prec = c+(i-(c%i));
        }else if(abs(c-(c%i)-c) > abs(c+(i-(c%i))-c)){
            mid = abs(c+(i-(c%i))-c);
            prec = c+(i-(c%i));
        }else{
            mid = abs(c-(c%i)-c);
            prec = c-(c%i);
        }
        //cout << mid;
        int k = 1e9;
        int prea = 1;
        for(auto l: r){
            if(k > abs(l-a)){
                k = abs(l - a);
                prea = l;
            }
        }
        mid += k;
        //cout << mid;
        mid += abs(i - b);
        //cout << mid << endl;
        if(ans > mid){
            ans = mid;
            anslis[0] = prea;
            anslis[1] = i;
            anslis[2] = prec;
        }
    }
    cout << ans << endl;
    REP(i, 0, 3){cout << anslis[i] << " ";}
    cout << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){
        solve();
    }
}