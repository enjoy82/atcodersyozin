#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct edge{
    int a, b;
};

int main(){
    int n, m; cin >> n >> m;
    vector<edge> lis;
    for(int i = 0; i < m; i++){
        int c, d; cin >> c >> d;
        edge e = {c, d};
        lis.push_back(e);
    }
    sort(lis.begin(), lis.end(), [](auto const& x, auto const& y){return x.b < y.b;});
    int ans = 0;
    int bridge = 0;
    for(int i = 0; i < m; i++){
        if(bridge > lis[i].a && bridge <= lis[i].b){
            continue;
        }else{
            ans++;
            bridge = lis[i].b;
        }
    }
    cout << ans << endl;
}