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

const ll mod = 998244353;


class BIT {
public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n):n(n),a(n+1,0){}

    //a[i]にxを加算する
    void add(ll i,ll x){
        i++;
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            a[k]+=x;
        }
    }

    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        return sum_sub(j)-sum_sub(i-1);
    }

    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=a[k];
        }
        return s;
    }

    //a[0]+a[1]+…+a[i]>=xとなる最小のiを求める(任意のkでa[k]>=0が必要)
    ll lower_bound(ll x){
        if(x<=0){
            //xが0以下の場合は該当するものなし→0を返す
            return 0;
        }else{
            ll i=0;ll r=1;
            //最大としてありうる区間の長さを取得する
            //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
            while(r<n) r=r<<1;
            //区間の長さは調べるごとに半分になる
            for(int len=r;len>0;len=len>>1) {
                //その区間を採用する場合
                if(i+len<n && a[i+len]<x){
                    x-=a[i+len];
                    i+=len;
                }
            }
            return i;
        }
    }
};

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % mod, n / 2);
  else
    return x * Pow(x, n - 1) % mod;
}

int main(){
    const ll div = Pow(2ll,mod-2);
    int n; cin >> n;
    vector<ll> alis(n);
    REP(i,0,n){
        cin >> alis[i];
    }
    int N = compression(alis);
    BIT Bit(n);
    ll ans = 0;
    REP(i,0,n){
        ans += Bit.sum_sub(alis[i]) * Pow(2, i);
        ans %= mod;
        Bit.add(alis[i], Pow(div, i+1));
    }
    cout << ans << endl;
}
