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

vector<int> arg_sort(vector<int> &lis){
    vector<int> idx(lis.size());
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](auto &l, auto &r){
        return lis[l] < lis[r];
    });
    return idx;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const long long LINF = 1LL << 62;
const int INF = 1LL << 30;

vector<vector<int> > graph(9);

void swap(int &x, int y){
    int a = x;
    x = y;
    y = a;
}

int main(){
    int m; cin >> m;
    REP(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    map<vector<int>, int> dp;
    queue<vector<int> > que;
    vector<int> init(8); //こまiがどのノードにいるか
    REP(i,0,8){cin >> init[i]; init[i]--;}
    que.push(init);
    dp[init] = 0;
    while(!que.empty()){
        vector<int> lis = que.front();
        vector<int> from_tree(9, -1); //のーどiにはどのこまがあるか
        que.pop();
        vector<int> used(9, false);
        REP(i,0,lis.size()){
            used[lis[i]] = true;
            from_tree[lis[i]] = i;
        }
        int idx;
        REP(i,0,used.size()){
            if(!used[i])
                idx = i;
        }
        REP(i,0,graph[idx].size()){
            int next = graph[idx][i];
            vector<int> cp = lis;
            swap(cp[from_tree[next]], idx);
            if(!dp.count(cp)){
                dp[cp] = dp[lis] + 1;
                que.push(cp);
            }
        }
    }
    if(!dp.count({0,1,2,3,4,5,6,7}))
        cout << -1 << endl;
    else
        cout << dp[{0,1,2,3,4,5,6,7}] << endl;
}