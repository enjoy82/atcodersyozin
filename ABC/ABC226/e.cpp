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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
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

const long long LINF = 1LL << 60;

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

const ll MOD = 998244353;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


int main(){
    int n, m; cin >> n >> m;
    ll ans = 1;
    if(n != m){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int> > graph(n);
    vector<int> count(n, 0);
    REP(i,0,m){
        int u, v; cin >> u >> v;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
        count[u]++;
        count[v]++;
    }
    vector<int> idxs = arg_sort(count);
    stack<int> st;
    vector<int> used(n, 0);
    REP(i,0,idxs.size()){
        if(count[idxs[i]] == 1){
            st.push(idxs[i]);
        }
    }
    while(!st.empty()){
        int now = st.top();
        used[now] = 1;
        st.pop();
        int c = 0;
        int nn;
        REP(i,0,graph[now].size()){
            int next = graph[now][i];
            if(used[next]){
                continue;
            }else{
                nn = next;
                c++;
            }
        }
        if(c == 1){
            st.push(nn);
        }else{
            used[now] = 0;
        }
    }
    vector<int> from;
    REP(i,0,n){
        //cout << used[i] << " ";
        if(used[i] == 0){
            from.pb(i);
        }
    }
    //cout << endl;
    ll loop = 0;
    REP(fr,0,from.size()){
        if(used[from[fr]])
            continue;
        loop += 1;
        used[from[fr]] = 1;
        //cout << from[fr] << endl;
        st.push(from[fr]);
        int f = 1;
        while(!st.empty()){
            int now = st.top();
            //cout << "now" << now << endl;
            st.pop();
            int cc = 0;
            int nn;
            REP(i,0,graph[now].size()){
                int next = graph[now][i];
                if(used[next]){
                    continue;
                }else{
                    cc++;
                    nn = next;
                }
            }
            if( (f && cc == 2) || cc == 1){
                used[nn] = 1;
                st.push(nn);
            }else if(cc >= 2){
                ans = 0;
            }
            f = 0;
        }
    }
    cout << ans * Pow(2, loop) << endl;
}