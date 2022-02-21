#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

const ll MAX = 1000000; //テーブルの数
const ll MOD = 1e9+7; //mod宣言

long long fac[MAX], finv[MAX], inv[MAX];
// finv ->階乗割り算
// fac ->階乗掛け算

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;
}

int main(){
    COMinit();
    int n, k; cin >> n >> k;
    if(n == 2){
        if(k == 0){
            cout << 1 << endl << 1 << " " << 2 << endl;
            return 0;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(k > COM(n-1, 2)){
        cout << -1 << endl;
        return 0;
    }
    vector<Pii> graph;
    vector<Pii> edge;
    REP(i, 2, n+1){
        graph.pb({1, i});
    }
    int mid = COM(n-1, 2);
    vector<vector<int> > flag(n+1, vector<int>(n+1, 0)); 
    REP(i, 2, n){
        REP(l, i+1, n+1){
            if(flag[i][l] == 0 && flag[l][i] == 0){
                flag[i][l] = 1;
                flag[l][i] = 1;
                edge.pb({i, l});
            }
        }
    }
    int i = edge.size()-1;
    while(mid != k){
        graph.pb(edge[i]);
        i--;
        mid--;
    }
    cout << graph.size() << endl;
    REP(i, 0, graph.size()){
        cout << graph[i].first << " " << graph[i].second << endl;
    }
    return 0;
}