#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 10000000
#define INF 100000000

int dp[100000] = {0};

struct edge{
    int to;
    int cost;
};

int solve(vector<vector<edge> >& tree, int from, int count){
    if(dp[from] != 0){
        return dp[from];
    }else if(tree[from].size() == 0){
        return 0;
    }else{
    int res = 0;
    for(int i = 0; i < tree[from].size(); i++){
        res = max(res, solve(tree, tree[from][i].to, count)+1);
    }
    return dp[from] = res;
    }
}


int main(){
    int n, m; cin >> n >> m;
    vector<vector<edge> > tree(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        edge e = {y-1, 0};
        tree[x-1].push_back(e);
    }
    for(int i = 0; i < n; i++){
        solve(tree, i, 0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
    }
    /*for(int i = 0; i < n; i++){
        cout << dp[i] << endl;
    }*/
    cout << ans << endl;
}