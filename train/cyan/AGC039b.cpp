// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
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


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using Graph = vector<vector<ll>>;
Graph tree;
int colors[100005];
bool is_bipartite_graph(const Graph &graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}


void Searchdepth(vector<int> &depth, int now, int cost){
    depth[now] = cost;
    REP(i, 0, tree[now].size()){
        int next = tree[now][i];
        if(depth[next] == -1){
            Searchdepth(depth, next, cost+1);
        }else{
            continue;
        }
    }
}

vector<int> searchdepth(int pos, int num){ //第1引数として頂点与える、第2引数で頂点の数
    vector<int> depth(num, -1);
    Searchdepth(depth, pos, 0);
    return depth;
}

vector<vector<int> > d(1000, vector<int>(1000, 1e9));
int V; //頂点数

void warshall_floyd(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int l = 0; l < V; l++){
                d[i][l] = min(d[i][l], d[i][k] + d[k][l]);
            }
        }
    }
}


int main(){
    int n; cin >> n;
    vector<string> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
    }
    REP(i, 0, 100005){
        colors[i] = 0;
    }
    REP(i, 0, 1000){
        d[i][i] = 0;
    }
    tree = Graph(n);
    REP(i, 0, n){
        REP(l, 0, n){
            if(l > i) break;
            if(lis[i][l] - '0' == 1){
                tree[i].pb(l);
                tree[l].pb(i);
                d[i][l] = 1;
                d[l][i] = 1;
            }
        }
    }
    if(is_bipartite_graph(tree, 0, 1)){
        int ans = 0;
        V = n+1;
        warshall_floyd();
        REP(i, 0, 1000){
            REP(l, 0, 1000){
                if(d[i][l] != 1e9){
                    chmax(ans, d[i][l]);
                }
            }
        }
        cout << ans + 1 << endl;
    }else{
        cout << -1 << endl;
    }
}