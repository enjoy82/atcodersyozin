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

const ll MOD  = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<ll> lis(n);
    REP(i,0,n){cin >> lis[i];}
    vector<ll> ruiseki(n+1, 0);

    REP(i,0,n){
        ruiseki[i+1] = ruiseki[i] + lis[i];
    }
    
    vector<vector<Pll> > arange(n+1);
    
    REP(i,2,n+1){
        map<int, vector<int>> mp;
        REP(l,0,n+1){
            mp[ruiseki[l]%i].pb(l);
        }
        for(auto x:mp){
            int key = x.first;
            vector<int> keyind = x.second;
            sort(ALL(keyind));
            REP(l,0,keyind.size()){
                REP(k,l+1,keyind.size()){
                    arange[i].pb(Pii(keyind[l],keyind[k]));
                }
            }
        }
    }
    
    /*
    REP(i,0,n){
        ll mid = 0;
        REP(l,i,n){
            mid += lis[l];
            REP(k,1,n+1){
                if (mid % k == 0){
                    arange[k].pb(Pii(i,l+1));
                }
            }
        }
    }
    */
    REP(i,0,n+1){
        sort(ALL(arange[i]));
    }
    vector<vector<ll> > dp(n, vector<ll>(n+1, 0));
    REP(i,0,n){
        dp[0][i+1] = 1;
    }
    /*
    REP(i,1,n+1){
        cout << "i : " << i << endl;
        REP(l,0,arange[i].size()){
            cout << arange[i][l].first << arange[i][l].second << " ";
        }
        cout << endl;
    }
    */
    REP(i,1,n){
        REP(l,0,arange[i+1].size()){
            dp[i][arange[i+1][l].second] += dp[i-1][arange[i+1][l].first];
            dp[i][arange[i+1][l].second] %= MOD;
        }
    }
    ll ans = 0;
    REP(i,0,n){
        ans += dp[i][n];
        ans %= MOD;
    }
    cout << ans << endl;
}