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

class SCC {
    public:
        int V;
        vector<vector<int> > graph, rgraph;
        vector<int> flag, rflag;
        SCC(int node_size) : V(node_size), graph(node_size), rgraph(node_size), flag(V, 0), rflag(V, 0){}

        void add_edge(int from, int to){
            graph[from].pb(to);
            rgraph[to].pb(from);
        }

        void dfs(vector<vector<int> > &G, int pos, vector<int> &dfslis){
            REP(i,0,G[pos].size()){
                int next = G[pos][i];
                if(flag[next] == 0){
                    flag[next] = 1;
                    dfs(G, next, dfslis);
                }
            }
            dfslis.pb(pos);
        }

        vector<int> solveSCC(){
            vector<int> dfslis;
            REP(i,0,V){
                if(flag[i] == 0){
                    flag[i] = 1;
                    dfs(graph, i, dfslis);
                }
            }

            vector<int> SCClis(V, -1);
            int count = 0;
            flag = vector<int>(V, 0);
            for(int i = V-1; i >= 0; i--){
                if(flag[dfslis[i]] != 0){
                    continue;
                }
                vector<int> rdfs;
                flag[dfslis[i]] = 1;
                dfs(rgraph, dfslis[i], rdfs);
                REP(l,0, rdfs.size()){
                    SCClis[rdfs[l]] = count;
                }
                count++;
            }
            return SCClis;
        }
};

int main(){
    int n, m; cin >> n >> m;
    SCC scc(n);
    REP(i,0,m){
        int a, b; cin >> a >> b;
        a--; b--;
        scc.add_edge(a, b);
    }
    vector<int> lis = scc.solveSCC();
    vector<ll> anslis(2e5, 0);
    REP(i,0,lis.size()){
        anslis[lis[i]]++;
    }
    ll ans = 0;
    REP(i,0,anslis.size()){
        ans += (anslis[i] * (anslis[i] - 1)) / 2;
    }
    cout << ans << endl;
}