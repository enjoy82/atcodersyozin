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

Pii dfs(vector<vector<int> > &tree, vector<map<int, Pii> > &dp, vector<bool> &used, int pos, vector<vector<int> > &tree_d){
    // return number, value
    used[pos] = false;
    int sum = 0, number = 0;
    REP(i,0,tree[pos].size()){
        int next = tree[pos][i];
        if(used[next] == false){
            continue;
        }else{
            used[next] = false;
            tree_d[pos].pb(next);
            dp[pos][next] = dfs(tree, dp, used, next, tree_d);
            number += dp[pos][next].first;
            sum += dp[pos][next].second;
        }
    }
    return Pii(number+1, sum + number + 1);
}


int main(){
    int n; cin >> n;
    vector<vector<int> > tree(n), tree_d(n);
    REP(i,0,n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<map<int, Pii> > dp(n);
    vector<bool> used(n, true);
    dfs(tree, dp, used, 0, tree_d);
    vector<bool> flag(n, true);
    flag[0] = false;
    queue<int> que;
    que.push(0);
    vector<int> ans(n, 0);
    //bfs
    while(!que.empty()){
        int pos = que.front();
        int sum = 0;
        int count = 0;
        que.pop();
        for(auto &x:dp[pos]){
            int next = x.first;
            sum += x.second.second;
            count += x.second.first;
            if(flag[next]){
                flag[next] = false;
                que.push(next);
            }
        }
        /*
        cout << "node : " << pos << " ";
        REP(i,0,tree_d[pos].size()){
            cout << tree_d[pos][i] << " ";
        }
        cout << endl;
        */
        ans[pos] = sum;
        REP(i,0,tree_d[pos].size()){
            int next = tree_d[pos][i];
            int ncount = count - dp[pos][next].first + 1;
            int nvalue = sum - dp[pos][next].second + ncount;
            dp[next][pos] = Pii(ncount, nvalue);
        }
    }
    REP(i,0,n){
        cout << ans[i] << endl;
    }
    /*
    REP(i,0,6){
        REP(l,0,6){
            cout << dp[i][l].second << " ";
        }
        cout << endl;
    }
    */
}