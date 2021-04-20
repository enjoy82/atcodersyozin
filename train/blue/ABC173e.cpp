// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

const ll mod = 1e9 + 7;

ll calc(vector<ll> plis, vector<ll> mlis){
    ll ans = 1;
    REP(i,0,plis.size()){
        ans *= plis[i];
        ans += mod;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    REP(i,0,mlis.size()){
        ans *= mlis[i];
        ans += mod;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }
    return ans;
}

int main(){
    int n, k; cin >> n >> k;
    vector<ll> alis(n);
    int count0 = 0;
    REP(i,0,n){
        cin >> alis[i];
        if(alis[i] == 0){
            count0++;
        }
    }
    if(n - k < count0){
        cout << 0 << endl;
        return 0;
    }
    n -= count0;
    ll ans = 1;
    if(n == k){
        REP(i,0,k){
            ans *= alis[i];
            ans += mod;
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }
    sort(ALL(alis), [](auto &x, auto &y){return abs(x) > abs(y);});
    vector<ll> anslis_p, anslis_m;
    REP(i,0,n){
        if(alis[i] < 0){
            anslis_m.pb(alis[i]);
        }else{
            anslis_p.pb(alis[i]);
        }
    }
    if(k % 2 == 1 && anslis_m.size() == n){
        if(count0 > 0){
            cout << 0 << endl;
            return 0;
        }
        sort(ALL(anslis_m), greater<>());
        REP(i,0,k){
            ans *= anslis_m[i];
            ans += mod;
            ans %= mod;
            ans += mod;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }
    //正で最大化
    int pidx = 0, midx = 0, mcount = 0;
    vector<ll> midp, midm;
    REP(i,0,k){
        if(pidx < anslis_p.size() && midx < anslis_m.size()){
            if(abs(anslis_p[pidx]) > abs(anslis_m[midx])){
                midp.pb(anslis_p[pidx]);
                pidx++;
            }else{
                midm.pb(anslis_m[midx]);
                midx++;
                mcount++;
            }
        }else if(pidx < anslis_p.size()){
            midp.pb(anslis_p[pidx]);
            pidx++;
        }else{
            midm.pb(anslis_m[midx]);
            midx++;
            mcount++;
        }
    }
    if(mcount % 2 == 0){
        cout << calc(midp, midm) << endl;
        return 0;
    }else{
        ll f1b = -1e12, f1a = -1e12, f2b = -1e12, f2a = -1e12;
        ll ans1 = 0, ans2 = 0;
        if(!midp.empty() && anslis_m.size() > midx){
            f1b = abs(midp.back());
            f1a = abs(anslis_m[midx]);
        }
        ll mmin = midm.back();
        if(anslis_p.size() > pidx){
            f2b = abs(midm.back());
            f2a = abs(anslis_p[pidx]);
        }
        if(f1b == -1e12){
            midm.back() = anslis_p[pidx];
            cout << calc(midm, midp) << endl;
            return 0;
        }
        if(f2a == -1e12){ //ちゃんと拾う
            midp.back() = anslis_m[midx];
            cout << calc(midm, midp) << endl;
            return 0;
        }
        //cout << f1a << " " << f1b << " " << f2a << " " << f2b << endl;
        if(f1a * f2b > f1b * f2a){
            midp.back() = anslis_m[midx];
            cout << calc(midm, midp) << endl;
        }else{
            midm.back() = anslis_p[pidx];
            cout << calc(midm, midp) << endl;
        }
    }
}