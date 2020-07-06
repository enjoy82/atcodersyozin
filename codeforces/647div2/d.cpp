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

vector<vector<int> > graph;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > topic(n, vector<int>(2, 0));
    graph = vector<vector<int> >(n);
    vector<vector<int> > topiclis(n);
    vector<vector<int> > rtopic(n, vector<int>(2, 0));
    REP(i, 0, n){
        rtopic[i][1] = i;
    }
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    REP(i, 0, n){
        int a; cin >> a;
        a--;
        topiclis[a].pb(i);
        topic[i][0] = a;
        topic[i][1] = i;
    }
    REP(i, 0, n){
        if(graph[i].size() > 0){
            int t = topic[i][0];
            rtopic[t][0]++;
        }
        REP(l, 0, graph[i].size()){
            int next = graph[i][l];
            if(topic[i][0] == topic[next][0]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    vector<int> ans;
    sort(ALL(rtopic), [](auto &x, auto &y){return x[0] < y[0];});
    REP(i, 0, n){
        int key = rtopic[i][1];
        REP(l, 0, topiclis[key].size()){
            ans.pb(topiclis[key][l]);
        }
    }
    REP(i, 0, n){
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}