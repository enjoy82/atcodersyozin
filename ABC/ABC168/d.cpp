#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back


int main(){
    int n, m; cin >> n >> m;
    vector<vector<int> >  tree(n);
    REP(i, 0, m){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    queue<int> q;
    vector<int> flag(n, 0);
    q.push(0);
    flag[0] = -1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        REP(i, 0, tree[now].size()){
            int next = tree[now][i];
            if(flag[next] == 0){
                flag[next] = now+1;
                q.push(next);
            }
        }
    }
    cout << "Yes" << endl;
    REP(i, 1, n){
        cout << flag[i] << endl;
    }
}