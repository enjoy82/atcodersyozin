// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n; cin >> n;
    map<ll, ll> mp;
    REP(i, 0, n){
        ll a; cin >> a;
        mp[a]++;
    }
    vector<vector<ll> > ruiseki(n+1, vector<ll>(2, 0));
    int ii = 0;
    ll count = 0, c1 = 0;
    for(auto &x:mp){
        ruiseki[ii][0] = x.first;
        ruiseki[ii][1] = x.second;
        c1++;
        ii++;
    }
    ruiseki[ii][0] = 1;
    ruiseki[ii][1] = ruiseki[ii-1][1];
    c1++;
    vector<ll> lis(c1, 0);
    REP(i, 0, c1){
        count += ruiseki[i][1];
        lis[i] = count;
    }
    int q; cin >> q;
    /*REP(i, 0, c1){
        cout << lis[i] << " ";
    }
    cout << endl;*/
    REP(i, 0, q){
        int k; cin >> k;
        ll key = n-k;
        if(key == 0){
            cout << 0 << endl;
            continue;
        }
        auto it = lower_bound(ALL(lis), key);
        int cc = it - lis.begin();
        if(ruiseki[cc][0] + 1 == 1){
            cout << 0 << endl;
        }else{
            cout << ruiseki[cc][0] + 1 << endl;
        }
    }
}