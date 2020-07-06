#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


void solve(){
    ll n; cin >> n;
    vector<ll> lis(n), lis0, lis1;
    REP(i, 0, n){cin >> lis[i];}
    map<ll, ll> mp0, mp1;
    string s; cin >> s;
    REP(i, 0, n){
        if(s[i] == '1'){
            if(mp1[lis[i]] == 0){
                lis1.pb(lis[i]);
                mp1[lis[i]]++;
            }
        }else{
            if(mp0[lis[i]] == 0){
                lis0.pb(lis[i]);
                mp0[lis[i]]++;
            }
        }
    }
    if(lis1.size() > lis0.size()){
        cout << 1 << endl;
        return;
    }
    REP(i, 0, lis0.size()){
        int k = lis0.size();
        REP(l, 0, k){
            ll c = lis0[i] ^ lis0[l];
            if(mp0[c] == 0){
                mp0[c]++;
                lis0.pb(c);
            }
        }
    }
   REP(i, 0, lis1.size()){
        int k = lis1.size();
        REP(l, 0, k){
            ll c = lis1[i] ^ lis1[l];
            if(mp1[c] == 0){
                mp1[c]++;
                lis1.pb(c);
            }
        }
    }
   REP(i, 0, lis1.size()){
       if(mp0[lis1[i]] == 0){
           cout << 1 << endl;
           return;
       }
   }
   cout << 0 << endl;
}

int main(){
    int t; cin >> t;
    REP(i, 0, t){solve();}
}