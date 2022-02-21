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

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

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
long long POM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return (fac[n] * ( finv[n - k] % MOD)) % MOD;
}


vector<vector<int> > tree;

int main(){
    COMinit();
    int n, k; cin >> n >> k;
    tree = vector<vector<int> >(n);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    ll ans = 1;
    vector<int> flag(n, 0);
    flag[0] = 1;
    queue<int> que;
    int count = 0;
    REP(i, 0, tree[0].size()){
        que.push(tree[0][i]);
        flag[tree[0][i]] = 1;
    }
    ans *= POM(k, tree[0].size()+1);
    //cout << ans << endl;
    while(!que.empty()){
        int now = que.front();
        //cout << now << endl;
        que.pop();
        int count = 0;
        REP(i, 0, tree[now].size()){
            if(flag[tree[now][i]] == 0){
                count++;
                flag[tree[now][i]] = 1;
                que.push(tree[now][i]);
            }
        }
        ans *= POM(k-2, count);
        ans %= MOD;
    }
    cout << ans << endl;
}