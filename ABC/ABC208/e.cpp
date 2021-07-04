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

#define REP(i, l, n) for(ll i=(l), i##_len=(n); i<i##_len; ++i)
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

const ll INF = 1e12;

int main(){
    string n; cin >> n;
    ll kk; cin >> kk;
    int nsize = n.size();
    vector<vector<map<ll, ll>> > dp(22, vector<map<ll, ll>>(2));
    //cout << nsize << endl;
    REP(l,1,(n[0] - '0') + 1){
        if(l <= kk){
            if(l == (n[0] - '0')){
                dp[1][1][l] = 1;
            }else{
                dp[1][0][l] += 1;
            }
        }
    }
    REP(i,2,nsize+1){
        REP(l,1,10){
            if(l <= kk){
                dp[i][0][l] += 1;
            }else{
                dp[i][0][INF] += 1;
            }
        }
    }
    REP(i,1,nsize){
        //cout << "i : " << i << endl;
        REP(l,0, (n[i] - '0') ){ //何でもOK
            REP(k,0,2)
                for(auto x:dp[i][k]){
                    ll mul = x.first;
                    ll count = x.second;
                    if(mul * l > kk){
                        dp[i+1][0][INF] += count;
                    }else{
                        //cout << i << " " << mul *l << i << l <<  endl;
                        dp[i+1][0][mul * l] += count;
                    }
                }
        }
        for(auto x:dp[i][1]){
            ll mul = x.first;
            ll count = x.second;
            if( (mul * (ll)(n[i] - '0')) > kk){
                dp[i+1][1][INF] += count;
            }else{
                dp[i+1][1][mul * (ll)(n[i] - '0')] += count;
            }
        }
        REP(l, (n[i] - '0'), 10){ //0のみOK
            for(auto x:dp[i][0]){
                ll mul = x.first;
                ll count = x.second;
                if( (mul * l) > kk){
                    dp[i+1][0][INF] += count;
                }else{
                    dp[i+1][0][mul * l] += count;
                }
            }
        }
    }
    ll ans = 0;
    REP(l,0,2){
        for(auto x:dp[nsize][l]){
            if(x.first == INF) continue;
            ans += x.second;
            //cout << x.first << " " << x.second << endl;
        }
    }
    cout << ans << endl;
} 
