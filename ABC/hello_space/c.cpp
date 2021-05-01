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

int main(){
    int n; cin >> n;
    vector<vector<ll> > lis(n, vector<ll>(5));
    REP(i,0,n){
        cin >> lis[i][0] >> lis[i][1] >> lis[i][2] >> lis[i][3] >> lis[i][4];
    }
    ll ans = 0;
    vector<vector<ll> > lis2;
    int size = lis.size() - 1;
    vector<ll> rank(5, 0);
    sort(ALL(lis), [](auto &x, auto &y){return x[0] > y[0];});
    rank[0] = lis[min(100, size)][0];
    sort(ALL(lis), [](auto &x, auto &y){return x[1] > y[1];});
    rank[1] = lis[min(100, size)][1];
    sort(ALL(lis), [](auto &x, auto &y){return x[2] > y[2];});
    rank[2] = lis[min(100, size)][2];
    sort(ALL(lis), [](auto &x, auto &y){return x[3] > y[3];});
    rank[3] = lis[min(100, size)][3];
    sort(ALL(lis), [](auto &x, auto &y){return x[4] > y[4];});
    rank[4] = lis[min(100, size)][4];
    REP(i,0,n){
        if(lis[i][0] >= rank[0] && lis[i][1] >= rank[1] && lis[i][2] >= rank[2] && lis[i][3] >= rank[3] && lis[i][4] >= rank[4]){
            lis2.pb(lis[i]);
        }
    }
    n = lis2.size();
    REP(i,0,n){
        REP(l,i+1,n){
            REP(k,l+1,n){
                vector<ll> mid(5, 0);
                ll cc = 1e9;
                REP(j,0,5){
                    mid[j] = max({lis2[i][j], lis2[l][j], lis2[k][j]});
                    chmin(cc, mid[j]);
                }
                chmax(ans, cc);
            }
        }
    }
    cout << ans << endl;
}