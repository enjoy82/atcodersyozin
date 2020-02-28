#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int ans = 0;
vector<int> used(100100, 0);

void solve(vector<vector<int> > &graph, int s){
    if(used[s] == 1){return;}
    else{
        used[s] = 1;
        for(int i = 0; i < graph[s].size(); i++){
            solve(graph, graph[s][i]);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> > graph(n);
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(used[i] == 0){
            ans++;
            solve(graph, i);
        }
    }
    cout << ans << endl;
}