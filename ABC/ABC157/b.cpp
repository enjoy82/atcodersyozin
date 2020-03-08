#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> use;
vector<int> ans;
vector<vector<int> > graph;
vector<vector<int> > graph2;

int solve(int s, int k){
    int sum = 1;
    use[s] = k;
    for(int i = 0; i < graph[s].size(); i++){
        if(use[graph[s][i]] == k){
            continue;
        }
        sum += solve(graph[s][i], k);
    }
    return sum;
}

int main(){
    ll n, m, k; cin >> n >> m >> k;
    graph = vector<vector<int> >(n);
    graph2 = vector<vector<int> >(n);
    use = vector<int>(n, -1);
    ans = vector<int>(n, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        if(use[i] != -1){
            continue;
        }
        int size = solve(i, i);
        mp[i] = size;
    }
    for(int i = 0; i < n; i++){
        int k = use[i];
        int ans = mp[k] - 1;
        ans -= graph[i].size();
        for(int l = 0; l< graph2[i].size(); l++){
            if(use[graph2[i][l]] == k){
                ans--;
            }
        }
        cout << max(ans, 0) << " ";
    }
}