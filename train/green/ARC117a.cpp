// execute g++-11 main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
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

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

template <class T>
vector<int> arg_sort(vector<T> &lis){
    vector<int> idx(lis.size());
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](auto &l, auto &r){
        return lis[l] < lis[r];
    });
    return idx;
}

template <class T>
int compression(vector<T> &A){
    std::map<T,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const long long LINF = 1LL << 62;
const int INF = 1LL << 30;

const ll MOD = 1e9+7;

ll modpow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return modpow(x * x % MOD, n / 2);
  else
    return x * modpow(x, n - 1) % MOD;
}

//逆元でもっておいて復元する
ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

ll n;

ll calc_num(ll a, ll count_one){
    if(a > n){
        return 0;
    }
    if(to_string(a).size() == to_string(n).size()){
        //cout <<  "res1 " <<  a << " " << count_one << endl;
        return count_one;
    }
    ll sum = count_one;
    ll len = to_string(n).size() - to_string(a).size();
    ll key = 10;
    REP(i,0,len-1){
        sum += key * count_one;
        key *= 10;
    }
    bool f = true;
    vector<vector<ll> > dp(to_string(n).size(), vector<ll>(2, 0));
    REP(i,0,to_string(a).size()){
        if(f && to_string(n)[i] < to_string(a)[i]){ //超えてる
            //cout << "res2 " <<  a << " " << sum << endl;
            return sum;
        }else if(to_string(n)[i] == to_string(a)[i]){
            if(f == true){
                dp[i][0] = 1;
            }else{
                dp[i][1] = 1;
            }
        }else{
            dp[i][1] = 1;
            f = false;
        }
    }
    //確定していない数字を埋める
    REP(i,to_string(a).size(), to_string(n).size()){
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][0] * (to_string(n)[i] - '0') + dp[i-1][1] * 10;
    }
    sum += count_one * (dp[to_string(n).size()-1][0] + dp[to_string(n).size()-1][1]);
    //cout << "res3 " << a << " " << sum << endl;
    return sum;
}

int main(){
    cin >> n;
    ll key = 1;
    ll ans = 0;
    REP(i,0,16){
        REP(l,0,10){
            if(l == 1)
                continue;
            ans += calc_num(key * 10 + l, i+1);
        }
        if(key <= n){
            ans += i + 1;
        }
        key = key * 10 + 1;
    }
    cout << ans << endl;
}