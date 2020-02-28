#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    vector<int> lis(n+1, 0), lis2(n+1, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(a == 1){
            lis[b] = 1;
        }
        if(b == n){
            lis2[a] = 1;
        }
    }
    for(int i = 2; i < n; i++){
        if(lis[i] == 1 && lis2[i] == 1){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}