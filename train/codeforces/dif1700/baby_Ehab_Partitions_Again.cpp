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

Pii makepii(int a, int b){
    int count = 0;
    while(a % 2 == 0){
        a /= 2;
        count++;
    }
    return Pii(count, b);
}

int main(){
    int n; cin >> n;
    vector<int> alis(n);
    REP(i,0,n){cin >> alis[i];}
    int sum = accumulate(ALL(alis), 0);
    if(sum % 2 == 1){
        cout << 0 << endl;
        return 0;
    }else{
        vector<int> anslis;
        map<int, int> mp;
        while(1){
            ll sum2 = 0;
            REP(i,0,n){
                if(mp[i] == 0){
                    sum2 += alis[i];
                }
            }
            if(sum2 % 2 == 1){
                break;
            }
            vector<vector<Pii>> dp(n+1, vector<Pii>(3e5, Pii(1e9, -1))); //1 -> num, 2->ind
            dp[0][0] = Pii(1e8, -1);
            REP(i,0,n){
                dp[i+1] = dp[i];
                if(mp[i] == 1) continue;
                REP(l,0,3e5){
                    if(dp[i][l].first != 1e9){
                        dp[i+1][l+alis[i]] = min(dp[i+1][l+alis[i]], min(makepii(alis[i], i), dp[i][l]));
                    }
                }
            }
            if(dp[n][sum2/2].first == 1e9){
                break;
            }else{
                mp[dp[n][sum2/2].second] = 1;
                anslis.pb(dp[n][sum2/2].second);
            }
        }
        cout << anslis.size() << endl;
        REP(i,0,anslis.size()){
            cout << anslis[i] + 1 << " ";
        }
        cout << endl;
    }
}