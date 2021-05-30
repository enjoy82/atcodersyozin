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

//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int dy[2] = {-1, 1};

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> lis(m, vector<ll>(2));
    map<ll, int> mp;
    REP(i,0,m){
        cin >> lis[i][0] >> lis[i][1];
    }
    int pre = -1;
    sort(ALL(lis), [](auto &x, auto &y){return x[0] < y[0];});
    vector<vector<vector<int> > > boucher(m);
    mp[n] = 0;
    REP(i,0,m){
        if(lis[i][0] == pre){

        }else{
            idx++;
        }
    }
    REP(i,0,m){
        map<ll, int> mp2;
        REP(l,0,2){
            if(mp.count(lis[i][1] + dy[l])){
                if(mp[lis[i][1] + dy[l]] < lis[i][0]){
                    mp[lis[i][1]] = lis[i][0];
                }
            }else{
                continue;
            }
        }
    }
    map<int, int> ans;
    for(auto x:mp){
        REP(i,0,2){
            ans[x.first + dy[i]] = 1;
        }
    }
    ll aans = 0;
    for(auto x:ans){
        aans++;
    }
    cout << aans << endl;
}