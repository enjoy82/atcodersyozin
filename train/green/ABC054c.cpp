#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int ans = 0;
int n, m;


struct edge{
    int to;
    int cost;
};

int check(vector<int> list){
    for(int i = 0; i < n; i++){
        if(list[i] == -1){
            return 0;
        }
    }
    return 1;
}

int solve(vector<vector<edge> > tree, vector<int> list, int from, vector<vector<int> >flag){
    //cout << from << endl;
    list[from] = 1;
    if(check(list) == 1){
        ans++;
    }else{
        int c = tree[from].size();
        if(c == 0){
            return 0;
        }else{
            for(int i = 0; i < c; i++){ 
                int t = tree[from][i].to;
                //cout << "flag is" << flag[from][t] << endl;
                if(flag[from][t] == 1  && list[t] == -1){
                    //cout << from << t << endl;
                    flag[from][t] = 0;
                    flag[t][from] = 0;
                    solve(tree, list, t, flag);
                }else{
                    continue;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    vector<vector<edge> > tree(n);
    vector<vector<int> >flag(8, vector<int>(8, 0));
    vector<int> list(n, -1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edge e = {b-1, 0};
        edge e1 = {a-1, 0};
        tree[a-1].push_back(e);
        tree[b-1].push_back(e1);
        flag[a-1][b-1] = 1;
        flag[b-1][a-1] = 1;
    }
    solve(tree, list, 0, flag);
    cout << ans << endl;
}