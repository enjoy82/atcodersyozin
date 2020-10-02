// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

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
    vector<vector<int> > lis(n, vector<int>(2));
    dsu d(n);
    map<int, int> mp;
    set<int> s;
    REP(i, 0, n){
        cin >> lis[i][0] >> lis[i][1]; 
        mp[lis[i][1]] = i;
    }
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    s.insert(lis[0][1]);
    REP(i, 1, n){
        int y = lis[i][1];
        auto it = s.lower_bound(y);
        int idx = distance(s.begin(), it);
        vector<int> si;
        for(auto itr = s.begin(); itr != it; itr++){
            d.merge(mp[*itr], mp[y]);
            si.pb(*itr);
        }
        si.pb(y);
        s.insert(y);
        if(si.size() >= 2){
            REP(l, 1, si.size()){
                s.erase(si[l]);
            }
        }
    }
    REP(i, 0, n){
        cout << d.size(i) << endl;
    }
}