#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define int long long
const int inf = 100100100100100;
const int mod = 1000000007;

const int maxn = 20;
int n;
int dist[maxn][maxn];
int dp[1<<maxn][maxn];

int dfs(int s, int v){

    if(dp[s][v] >= 0){
        return dp[s][v];
    }

    if(s == (1<<n)-1 && v == 0){
        return dp[s][v] = 0;
    }

    int ans = inf;
    rep(u,0,n){
        if(!(s >> u & 1)){
            ans = min(ans, dfs(s | 1 << u, u) + dist[v][u]);
        }
    }

    dp[s][v] = ans;
    return ans;


}

signed main(){
    cin >> n;

    memset(dp,-1,sizeof(dp));
    fill(dist[0],dist[0]+maxn*maxn,inf);

    

    vector<vector<int> > lis(n, vector<int>(3));
    rep(i, 0, n){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2];
    }
    rep(i, 0, n){
        rep(l, 0, n){
            if(i == l) continue;
            int k = abs(lis[l][0] - lis[i][0]) + abs(lis[l][1]-lis[i][1]) + max(0ll, lis[l][2] - lis[i][2]);
            dist[i][l] = k;
        }
    }
    int ans = dfs(0,0);
    cout << (ans == inf ? -1 : ans) << endl;
}