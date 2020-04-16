#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


vector<vector<int> > tree;
vector<ll> used;
vector<ll> ans;
vector<ll> checklis;
vector<vector<ll>> depth;

void solve(int now, ll cost){
    REP(i, 0, tree[now].size()){
        int ne = tree[now][i];
        if(used[ne] == 0){
            used[ne] = 1;
            if(checklis[now] == 1){
                solve(ne, cost+1ll);
            }else{
                solve(ne, cost);
            }
        }else{
            continue;
        }
    }
    //cout << now << cost << endl;
    if(checklis[now] != 1)
        ans.pb(cost);
}

void de(int now, ll d){
    int f = 0;
    REP(i, 0, tree[now].size()){
        int ne = tree[now][i];
        if(used[ne] == 0){
            f = 1;
            used[ne] = 1;
            de(ne, d+1ll);
        }else{
            continue;
        }
    }
        depth[now][0] = d;
        depth[now][1] = now;
        depth[now][2] = f;
}

int main(){
    int n, k; cin >> n >> k;
    tree = vector<vector<int>>(n);
    depth = vector<vector<ll>>(n, vector<ll>(3, 0));
    used = vector<ll>(n, 0);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    queue<int> q;
    int check = 1;
    checklis = vector<ll>(n, 0);
    de(0, 0);
    q.push(0);
    used = vector<ll>(n, 0);
    sort(ALL(depth), [](auto &x, auto &y){return x[0] > y[0];})
    int k = 1;
    checklis[0] = 1;
    while(check != n-k && !q.empty()){
        int pre = 1;
        for(; k < n; k++){
            if(depth[])
        }
    }
    //REP(i, 0, n){cout << checklis[i];}
    //cout << endl;
    used[0] = 1;
    //REP(i, 0, 1e5){ans.pb(0ll);}
    solve(0, 0ll);
    sort(ALL(ans), greater<>());
    ll cc = 0;
    int i = 0;
    for(; i < k; i++){
        cc += ans[i];
    }
    //cout << cc << endl;
    //cout << check << endl;
    cout << cc << endl;
}