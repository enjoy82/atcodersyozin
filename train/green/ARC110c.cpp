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

struct fenwick_tree {
    typedef int T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i,0,n){cin >> lis[i];}
    reverse(ALL(lis));
    fenwick_tree f_tree(n);
    vector<int> anslis(n, 0);
    REP(i,0,n){
        anslis[i] += f_tree.sum(lis[i]);
        f_tree.add(lis[i], 1);
    }
    reverse(ALL(anslis));
    reverse(ALL(lis));
    int count = 0;
    vector<int> ans;
    vector<int> flag(1e6, 0);
    for(int i = n-1; i >= 0; i--){
        REP(l,0,anslis[i]){
            ans.pb(i+1+l);
            flag[i+1+l]++;
            if(flag[i+1+l] >= 2){
                cout << -1 << endl;
                return 0;
            }
        }
        count += anslis[i];
        if(count > n-1){
            cout << -1 << endl;
            return 0;
        }
    }
    if(n-1-count != 0){
        cout << -1 << endl;
        return 0;
    }else{
        REP(i,0,ans.size()){
            cout << ans[i] << endl;
        }
        REP(i,0,n-1-count){
            cout << 1 << endl;
        }
        return 0;
    }
}