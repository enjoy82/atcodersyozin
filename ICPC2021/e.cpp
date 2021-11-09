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

template <class T>
inline vector<T> make_vec(size_t a, T val) {
    return vector<T>(a, val);
}
template <class... Ts>
inline auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec(ts...))>(a, make_vec(ts...));
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

const long long LINF = 1LL << 60;

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


void bfs(vector<vector<map<ll, ll>>> &dp, int now, int goal, vector<int> &used, Graph &hG, Graph &pG){
    queue<int> que;
    que.push(0);
    int pre = -1;
    int count = 0;
    while(!que.empty()){
        cout << now << endl;
        count++;
        if(count > goal * goal * 4){
            break;
        }
        now = que.front();
        que.pop();
        if(pre == now)
            continue;
        pre = now;
        set<int> nextlis;
        REP(i,0,hG[now].size()){ //歩道使う
            ll next = hG[now][i].to;
            ll cost = hG[now][i].cost;
            for(auto x:dp[now][0]){
                ll restnum = x.first;
                ll numcost = x.second;
                if(dp[next][0].count(restnum)){
                    if(chmin(dp[next][0][restnum], numcost + cost)){
                        que.push(next);
                    }
                }else{
                    dp[next][0][restnum] = numcost + cost;
                    que.push(next);
                }
            }
            for(auto x:dp[now][1]){
                ll restnum = x.first;
                ll numcost = x.second;
                if(dp[next][0].count(restnum)){
                    if(chmin(dp[next][0][restnum], numcost + cost)){
                        que.push(next);
                    }
                }else{
                    dp[next][0][restnum] = numcost + cost;
                    que.push(next);
                }
            }
        }
        REP(i,0,pG[now].size()){ //車道使う
            ll next = hG[now][i].to;
            ll cost = hG[now][i].cost;
            for(auto x:dp[now][0]){
                ll restnum = x.first + 1;
                ll numcost = x.second;
                ll carcost = cost + Pow(2, restnum-1);
                if(dp[next][1].count(restnum)){
                    if(chmin(dp[next][1][restnum], numcost + carcost)){
                        que.push(next);
                    }
                }else{
                    dp[next][1][restnum] = numcost + carcost;
                    que.push(next);
                }
            }
            for(auto x:dp[now][1]){
                ll restnum = x.first;
                ll numcost = x.second;
                if(dp[next][1].count(restnum)){
                    if(chmin(dp[next][1][restnum], numcost + cost)){
                        que.push(next);
                    }
                }else{
                    dp[next][1][restnum] = numcost + cost;
                    que.push(next);
                }
            }
        }
    } 
    ll ans = LINF;
    for(auto x:dp[goal][0]){
        chmin(ans, x.second);
    }
    for(auto x:dp[goal][1]){
        chmin(ans, x.second);
    }
    cout << ans << endl;
}

int main(){
    int n, p, q;
    while(cin >> n){
        cin >> p >> q;
        if(n == 0 && p == 0 && q == 0)
            break;
        Graph hG(n), pG(n);
        vector<vector<map<ll, ll>>> dp(n, vector<map<ll, ll>>(2));
        REP(i,0,p){
            int a, b, c; cin >> a >> b >> c;
            a--;
            b--;
            Edge e1 = {b, c};
            Edge e2 = {a, c};
            hG[a].pb(e1);
            hG[b].pb(e2);
        }
        REP(i,0,q){
            int a, b, c; cin >> a >> b >> c;
            a--;
            b--;
            Edge e1 = {b, c};
            Edge e2 = {a, c};
            pG[a].pb(e1);
            pG[b].pb(e2);
        }
        vector<int> used(n, 0);
        used[0] = 1;
        dp[0][0][0] = 0;
        bfs(dp, 0, n-1, used, hG, pG);
    }
}