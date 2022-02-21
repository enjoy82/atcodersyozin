#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    ll ans = 0;
    priority_queue<int> q;
    vector<vector<int> > lis(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++){
        cin >> lis[i][0] >> lis[i][1];
    }
    sort(lis.begin(), lis.end(), [](auto& x, auto& y){return x[0] < y[0];});
    int l = 0;
    for(int i = 1; i <= m; i++){
        for(;l < n && i >= lis[l][0]; l++){
            q.push(lis[l][1]);
        }
        if(q.empty()){continue;}
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}