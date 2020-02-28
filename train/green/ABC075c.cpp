#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int> > graph;
vector<int> a, b;
vector<int> flag;
int n, m;

void dfs(int v){
    flag[v] = 1;
    for(int i = 0; i < n; i++){
        if(graph[v][i] == 1 && flag[i] == 0){
            dfs(i);
        }else{
            continue;
        }
    }
}

int main(){
    cin >> n >> m;
    int ans = 0;
    a = vector<int>(51, 0);
    b = vector<int>(51, 0);
    graph = vector<vector<int> >(51, vector<int>(51, 0));
    flag = vector<int>(51, 0);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        graph[a[i]][b[i]] = 1;
        graph[b[i]][a[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        graph[a[i]][b[i]] = 0;
        graph[b[i]][a[i]] = 0;
        for(int l = 0; l < n; l++){flag[l] = 0;}
        dfs(0);
        int f = 0;
        for(int l = 0; l < n; l++){
            if(flag[l] == 0){
                f = 1;
                break;
            }
        }
        ans += f;
        graph[a[i]][b[i]] = 1;
        graph[b[i]][a[i]] = 1;
    }
    cout << ans  << endl;
}