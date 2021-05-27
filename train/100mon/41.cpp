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
    int d, n; cin >> d >> n;
    vector<int> temp(d);
    REP(i,0,d){
        cin >> temp[i];
    }
    vector<vector<int> > lis(n, vector<int>(3));
    REP(i,0,n){
        REP(l,0,3){
            cin >> lis[i][l];
        }
    }

    vector<vector<int> > dp(d, vector<int>(n, -1));
    REP(i,0,n){
        if(lis[i][0] <= temp[0] && lis[i][1] >= temp[0]){
            dp[0][i] = 0;
        }
    }
    REP(i,0,d-1){
        REP(l,0,n){
            if(dp[i][l] != -1){
                REP(k,0,n){
                    if(lis[k][0] <= temp[i+1] && lis[k][1] >= temp[i+1]){
                        chmax(dp[i+1][k], dp[i][l] + abs(lis[k][2] - lis[l][2]));
                    }
                }
            }
        }
    }
    int ans = -1;
    REP(i,0,n){
        chmax(ans, dp[d-1][i]);
    }
    cout << ans << endl;
}