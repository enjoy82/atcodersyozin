#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;

int d[1000000];
struct edge{
    int to;
    int cost;
};

void dfs(int node, const vector<vector<edge> >&v, int pcolor){
    d[node] = pcolor;
    for(int i = 0; i < v[node].size(); i++){
        int next_node = v[node][i].to;
        if(d[next_node] == -1){
            int color = pcolor;
            if(v[node][i].cost % 2 == 1) {color = 1 - color;}
            dfs(next_node, v, color);
        }
    }
}
int main(){
    cin >> n;
    vector<vector<edge> > tree(n);
    for(int i = 0; i < n; i++) {d[i] = -1;}
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge e = {v-1, w};
        edge re = {u-1, w};
        tree[u-1].emplace_back(e);
        tree[v-1].emplace_back(re);
    }

    dfs(0, tree, 0);

    for(int i = 0; i < n; i++){
        cout << d[i] << endl;
    }

    return 0;
}