#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, u, v; cin >> n >> u >> v;
    u--; v--;
    vector<vector<int> > graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> used1(n, -1), used2(n, -1);
    used1[u] = 0; used2[v] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int mid = q.front();
        q.pop();
        int k = used1[mid];
        for(int i = 0; i < graph[mid].size(); i++){
            if(used1[graph[mid][i]] != -1) continue;
            q.push(graph[mid][i]);
            used1[graph[mid][i]] = k + 1;
        }
    }
    q.push(v);
    while(!q.empty()){
        int mid = q.front();
        q.pop();
        int k = used2[mid];
        for(int i = 0; i < graph[mid].size(); i++){
            if(used2[graph[mid][i]] != -1) continue;
            q.push(graph[mid][i]);
            used2[graph[mid][i]] = k + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(used1[i] < used2[i]){
            ans = max(ans, used2[i]-1);
        }
    }
    cout << ans << endl;
}