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
    vector<ll> lis(n);
    REP(i,0,n){cin >> lis[i];}
    vector<vector<vector<ll>>> dp(200), pdp(200);
    REP(i,0,n){
        int key = lis[i] % 200;
        dp = pdp;
        REP(l,0,200){
            int count = 0;
            REP(j,0, pdp[l].size() ){
                count++;
                if(count >= 3) break;
                vector<ll> mid = pdp[l][j];
                mid.pb(i);
                if(dp[(l+key)%200].size() >= 2) continue;
                dp[(l+key)%200].pb(mid);
            }
        }
        if(!(dp[(key)%200].size() >= 2)){
            vector<ll> mid;
            mid.pb(i);
            dp[key].pb(mid);
        }
        pdp = dp;
    }
    /*
    REP(i,0,10){
        cout << "#" << i << endl;
        cout << dp[i].size() << endl;;
        REP(l,0,dp[i].size()){
            REP(j,0,dp[i][l].size()){
                cout << dp[i][l][j] << " ";
            }
            cout << endl;
        }
    }
    */
    REP(i,0,200){
        if(dp[i].size() >= 2){
            cout << "Yes" << endl;
            REP(k,0,2){
                cout << dp[i][k].size()<< " ";
                REP(l,0,dp[i][k].size()){
                    cout << dp[i][k][l] + 1 << " ";
                }
                cout << endl;
            }
            return 0;
        }
    }
    cout << "No" <<  endl;
}