#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 10000000000

struct edge{int to; ll cost;};
vector<ll> dis(1000000, INF);

int solve(vector<vector<edge> > &tree, int num, ll cos){
    if(dis[num] != INF){
        if(cos != dis[num]){
            return -1;
        }
    }
    for(int i = 0; i < tree[num].size(); i++){
        int t = tree[num][i].to;
        ll c = cos + tree[num][i].cost;
        cout << t << endl;
        if(dis[t] == INF){
            dis[t] = c;
        }
        return solve(tree, t, c);
    }
    return 1;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<edge> > tree(n);
    for(int i = 0; i < m; i++){
        int from, to;
        ll d;
        cin >> from >> to >> d;
        tree[from-1].push_back({to-1, d});
        tree[to-1].push_back({from-1, d*-1});
    }
    for(int i =0 ; i < n; i++){
        if(!solve(tree, i, 0)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << dis[0] << dis[1] << dis[2] << endl;
    cout << "Yes" << endl;
}