// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

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
char Alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
const ll mod = 1e9 + 7;
vector<vector<int> > tree;
vector<int> flag;

Pll solve(int v){
    int f = 0;
    vector<Pll> col;
    REP(i, 0, tree[v].size()){
        int next = tree[v][i];
        if(flag[next] == 0){
            flag[next] = 1;
            col.pb(solve(next));
            f = 1;
        }
    }
    if(f == 0){
        return Pll(1, 1);
    }
    ll white = 1, black = 1;
    REP(i, 0, col.size()){
        white *=  (col[i].first + col[i].second);
        black *= col[i].first;
        white %= mod;
        black %= mod;
    }
    return Pll(white, black);
}

int main(){
    cin >> n;
    tree = vector<vector<int> >(n);
    flag = vector<int>(n, 0);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    flag[0] = 1;
    Pll ans = solve(0);
    cout << (ans.first + ans.second)%mod << endl;
}