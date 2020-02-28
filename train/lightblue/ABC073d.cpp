#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_V 210
#define INF 1000000000

int d[MAX_V][MAX_V];
int V; //頂点数

void warshall_floyd(){
    for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int l = 1; l <= V; l++){
                d[i][l] = min(d[i][l], d[i][k] + d[k][l]);
            }
        }
    }
}

int ans = 1000000000;

void dfs(int idx, vector<int> flag, vector<int> &lis, int count, int c){
    int f = 0;
    flag[idx] = 1;
    for(int i = 0; i < lis.size(); i++){
        if(flag[i] == 0){
            count += d[lis[idx]][lis[i]];
            dfs(i, flag, lis, count, 1);
            count -= d[lis[idx]][lis[i]];
            f = 1;
        }
    }
    if(f == 0){
        ans = min(ans, count);
    }
}


int main(){
    int m, r; cin >> V >> m >> r;
    for(int i = 0; i < MAX_V; i++){
        for(int l = 0; l < MAX_V; l++){
            d[i][l] = INF;
        }
    }
    for(int i = 0; i < MAX_V; i++){
        d[i][i] = 0;
    }
    vector<int> lis(r);
    vector<int> flag(r);
    for(int i = 0; i < r; i++){
        cin >> lis[i];
    }
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }
    warshall_floyd();
    for(int i = 0; i < r; i++){
        dfs(i, flag, lis, 0, 0);
    }
    cout << ans << endl;
}