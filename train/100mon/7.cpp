// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
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



//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

bool check(Pii &a, Pii &b){
    if(a.first < 0 || a.second < 0 || a.first > 5000 || a.second > 5000){
        return false;
    }
    if(b.first < 0 || b.second < 0 || b.first > 5000 || b.second > 5000){
        return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<Pii> lis(n);
    map<Pii, int> mp;
    REP(i,0,n){
        int a, b; cin >> a >> b;
        lis[i] = Pii(a, b);
        mp[lis[i]] = 1;
    }
    int ans = 0;
    REP(i,0,n){
        REP(l, i+1, n){
            if(i == l) continue;
            int dx = lis[l].first - lis[i].first, dy = lis[l].second - lis[i].second;
            Pii p1 = Pii(lis[i].first + dy * -1, lis[i].second + dx), p2 = Pii(dy * -1 + lis[l].first, dx + lis[l].second);         
            if(check(p1, p2) == false){
                continue;
            }   
            if(mp.count(p1) > 0 && mp.count(p2) > 0){ //map注意！どんどんふえてく！
                //cout << dx * dx + dy * dy << endl;
                chmax(ans, dx * dx + dy * dy);
            }
        }
    }
    cout << ans << endl;
}