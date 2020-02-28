#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAX_N 1000000

int par[MAX_N];
int union_rank[MAX_N];

void init(int n){  //初期化
    for(int i = 0; i < n; i++){
        par[i] = i;
        union_rank[i] = 0;
    }
}

int find(int x){ //木の根を調べる
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y){ //要素をくっつける
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(union_rank[x] < union_rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(union_rank[x] == union_rank[y]) union_rank[x]++;
    }
}

bool same(int x, int y){ //同じ集団に属するかどうか
    return find(x) == find(y);
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    init(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        unite(x, y);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(same(a[i], i+1)){
            ans++;
        }
    }
    cout << ans << endl;
}