// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define REP(i, l, n) for(int i=(l), i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<class T>inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}


char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int op(int a, int b) { return max(a, b); }

int e() { return -1; }

int target;

int main(){
    int n, k; cin >> n >> k;
    int ma = 0;
    vector<int> lis(n);
    REP(i, 0, n){
        cin >> lis[i];
        chmax(ma, lis[i]);
    }
    vector<int> se(ma+100, -1);
    segtree<int, op, e> seg(se);
    vector<int> dp(n, 1);
    vector<vector<int> > tree(n);
    REP(i, 0, n){
        int a = lis[i] - k, b = lis[i] + k;
        int ind1 = seg.prod(max(0, a), lis[i] + 1), ind2 = seg.prod(lis[i], min(b+1, ma + 10));
        if(ind1 != -1){
            //g.add_edge(ind1, i, 1);
            tree[i].pb(ind1);
        }
        if(ind2 != -1){
            //g.add_edge(ind2, i, 1);
            tree[i].pb(ind2);
        } 
        //cout << i << lis[i] << " " << ind1 << " "  << ind2 << endl;
        seg.set(lis[i], i);
    }
    int ans = 1;
    for(int i = n-1; i >= 0; i--){
        REP(l, 0, tree[i].size()){
            int next = tree[i][l];
            chmax(dp[next], dp[i]+1);
        }
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
}