#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    string s, t; cin >> s >> t;
    vector<int> al1(26, 0), al2(26, 0);
    REP(i, 0, s.size()){
        al1[s[i]-'a']++;
    }
    REP(i, 0, t.size()){
        al2[t[i]-'a']++;
    }
    REP(i, 0, 26){
        if(al2[i] > 0 && al1[i] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = -1, count = 0;
    vector<vector<ll> > slis(26);
    REP(i, 0, s.size()){
        int k = s[i] - 'a';
        slis[k].pb(i);
    }
    REP(i, 0, 26){
        sort(ALL(slis[i]));
    }
    REP(i, 0, t.size()){
        ll now = ans;
        ll key = t[i] - 'a';
        auto it = upper_bound(ALL(slis[key]), now);
        if((it - slis[key].begin()) >=  slis[key].size()){
            count++;
            ans = slis[key][0];
        }else{
            ans = *it;
        }
    }
    cout << count * s.size() + ans + 1 << endl;
}