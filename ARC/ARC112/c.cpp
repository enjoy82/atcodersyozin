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

vector<vector<int> > tree; //双方向木
vector<vector<int> > rtree; //双方向木

vector<map<int, int> > baby;

Pii dfs(vector<vector<int> > &tree, int pos){
    Pii sum = Pii(1, 0);
    //cout << pos << endl;
    vector<Pii> mid;
    REP(i, 0, tree[pos].size()){
        int next = tree[pos][i];
        Pii k = dfs(tree, next);
        mid.pb(k);
        //cout << mid << endl;
    }
    sort(ALL(mid));
    REP(i, 0, mid.size()){
        if(i % 2 == 0){
            sum.first += mid[i].first;
            sum.second += mid[i].second;
        }else{
            sum.second += mid[i].first;
            sum.first += mid[i].second;
        }
    }
    //cout << sum+1 << endl;
    return sum;
}

int main(){
    int n; cin >> n;
    vector<vector<int> > tree(n), rtree(n);
    baby = vector<map<int, int> >(n);
    REP(i, 0, n-1){
        int p; cin >> p;
        tree[p-1].pb(i+1);
        rtree[i+1].pb(p-1);
    }
    //int tans = 0, aans = 0;
    vector<int> flag(n, 0);

    Pii ans = dfs(tree, 0);

    cout << ans.first << endl;
}