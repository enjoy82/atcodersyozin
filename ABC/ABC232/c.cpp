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

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
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

bool same(Pii a, Pii b){
    if(min(a.first, a.second) == min(b.first, b.second) && max(a.first, a.second) == max(b.first, b.second)){
        return true;
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<Pii> tlis(m), alis(m);
    REP(i,0,m){
        int a,b; cin >> a >> b;
        tlis[i] = Pii(a-1,b-1);
    }
    REP(i,0,m){
        int a,b; cin >> a >> b;
        alis[i] = Pii(a-1,b-1);
    }
    vector<int> alisball(n);
    REP(i,0,n)
        alisball[i] = i;
    do {
        vector<Pii> swapped(m);
        REP(i,0,m){
            int val_first = alis[i].first;
            int val_second = alis[i].second;
            swapped[i] = Pii(alisball[val_first], alisball[val_second]);
        }
        bool flag = true;
        REP(i,0,m){
            bool f = false;
            REP(l,0,m){
                if(same(swapped[i], tlis[l])){
                    f = true;
                }else{
                    continue;
                }
            }
            if(f == false){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(alisball.begin(), alisball.end()));
    cout << "No" << endl;
    return 0;
}