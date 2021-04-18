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

int n;
vector<int> color;
vector<int> anslis;
vector<int> flag;

void solve(int pos, unordered_map<int, int> &mp, vector<vector<int> > &tree){
    if(mp.count(color[pos])){
        if(mp[color[pos]] == 0){
            anslis[pos] = 1;
        }
    }else{
        anslis[pos] = 1;    
    }
    mp[color[pos]]++;
    REP(i,0,tree[pos].size()){
        int next = tree[pos][i];
        if(flag[next] == 0){
            flag[next] = 1;
            solve(next, mp, tree);
        }
    }
    mp[color[pos]]--;
}

int main(){
    int n; cin >> n;
    color = vector<int>(n);
    anslis = vector<int>(n, 0);
    flag = vector<int>(n, 0);
    REP(i,0,n){cin >> color[i];}
    vector<vector<int> > tree(n);
    REP(i,0,n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    unordered_map<int, int> mp;
    flag[0] = 1;
    solve(0, mp, tree);
    REP(i,0,n){
        if(anslis[i] == 1){
            cout << i + 1 << endl;
        }
    }
    return 0;
}