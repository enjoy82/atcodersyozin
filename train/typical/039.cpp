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



//木の深さ調べる
////////////////////////
void Searchdepth(vector<int> &depth, int now, int cost, vector<vector<int> > &tree){
    depth[now] = cost;
    REP(i, 0, tree[now].size()){
        int next = tree[now][i];
        if(depth[next] == -1){
            Searchdepth(depth, next, cost+1, tree);
        }else{
            continue;
        }
    }
}

vector<int> searchdepth(int pos, int num, vector<vector<int> > &tree){ //第1引数として頂点与える、第2引数で頂点の数
    vector<int> depth(num, -1);
    Searchdepth(depth, pos, 0, tree);
    return depth;
}
///////////////////////


//木の子孫の数数える
////////////////////////////
int Searchleaf(vector<int> &leaf, vector<int> &used,int now, vector<vector<int> > &tree){
    int count = 0;
    used[now] = 1;
    REP(i, 0, tree[now].size()){
        int next = tree[now][i];
        if(used[next] == -1){
            count += Searchleaf(leaf, used, next, tree);
        }else{
            continue;
        }
    }
    leaf[now] = count;
    return count+1;
}

vector<int> searchleaf(int pos, int num, vector<vector<int> > &tree){ //第1引数として頂点与える、第2引数で頂点の数
    vector<int> leaf(num, -1);
    vector<int> used(num, -1);
    Searchleaf(leaf, used, pos, tree);
    return leaf;
}
///////////////////////////

/////hoe to use
int main(){
    int n; cin >> n;
    vector<vector<int> > tree(n); //双方向木(n);
    REP(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    vector<int> leaf = searchleaf(0, n, tree);
    map<Pii, int> mp;
    ll ans = 0;
    REP(i,0,n){
        REP(l,0,tree[i].size()){
            if(mp.count(Pii(i, tree[i][l]))){
                continue;
            }
            mp[Pii(tree[i][l],i)] = 1;
            mp[Pii(i,tree[i][l])] = 1;
            ll lf = min(leaf[i], leaf[tree[i][l]]) + 1;
            //cout << lf << " " << n-lf << endl;
            ans += lf * (n-lf);
        }
    }
    cout << ans << endl;
}