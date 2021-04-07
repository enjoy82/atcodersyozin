#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> color(n);
    vector<vector<int>> graph(n);
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    REP(i, 0, n){cin >> color[i];}
    REP(i, 0, q){
        int a; cin >> a;
        if(a == 1){
            int now; cin >> now;
            now--;
            cout << color[now] << endl;
            REP(i, 0, graph[now].size()){
                int next = graph[now][i];
                color[next] = color[now];
            }
        }else{
            int now; cin >> now;
            now--;
            cout << color[now] << endl;
            int c; cin >> c;
            color[now] = c;
        }
    }
}