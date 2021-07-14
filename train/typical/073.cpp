// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

//ordered_set 重複不可
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use set_function + find_by_order(select itr-num)

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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

vector<vector<int> > Tree;
vector<char> Node;
vector<int> Used;
vector<vector<ll> > dp(2e5, vector<ll>(3, 0));
const ll mod = 1e9 + 7;

void dfs(int num){
    ll mid0 = 1, mid1 = 1;
    REP(i,0,Tree[num].size()){
        int next = Tree[num][i];
        if(Used[next] == 0){
            Used[next] = 1;
            dfs(next);
            if(Node[num] == 'a'){
                mid0 *= (dp[next][0] + dp[next][2]);
                mid1 *= (dp[next][0] + dp[next][1] + 2LL * dp[i][2]);
            }else{
                mid0 *= (dp[next][1] + dp[next][2]);
                mid1 *= (dp[next][0] + dp[next][1] + 2LL * dp[i][2]);
            } 
            mid0 %= mod;
            mid1 %= mod;
        }
    }
    cout << num << endl;
    cout << mid0 << " " << mid1 - mid0 << endl;
    if(Node[num] == 'a'){
        dp[num][0] = mid0;
        dp[num][2] = (mid1 - mid0 + mod) % mod;
    }else{
        dp[num][1] = mid0;
        dp[num][2] = (mid1 - mid0 + mod) % mod;
    }
}

int main(){
    int n; cin >> n;
    Tree = vector<vector<int> >(n);
    Node = vector<char>(n);
    Used = vector<int>(n, 0);
    REP(i,0,n){
        cin >> Node[i];
    }
    REP(i,0,n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        Tree[a].pb(b);
        Tree[b].pb(a);
    }
    Used[0] = 1;
    dfs(0);
    cout << dp[0][2] << endl;
}