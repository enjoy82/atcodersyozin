// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace atcoder;

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

const ll MOD = 998244353;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示
using mint = modint998244353;

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<vector<mint> > dp(h, vector<mint>(w, 0));
    vector<vector<int> > grid(h, vector<int>(w, 0));
    mint start = Pow(3,  h*w-k);
    REP(i, 0, k){
        int x, y; cin >> x >> y;
        x--; y--;
        char a; cin >> a;
        if(a == 'R'){
            grid[x][y] = 1;
        }else if(a == 'D'){
            grid[x][y] = 2;
        }else if(a == 'X'){
            grid[x][y] = 3;
        }
    }
    dp[0][0] = start;
    //cout << start.val() << endl;
    REP(i, 0, h){
        REP(l, 0, w){
            //cout << i << l << endl;
            if(grid[i][l] == 0){
                mint c = dp[i][l] *2 / 3;
                //cout << c.val() << endl;
                if(i+1 < h)
                    dp[i+1][l] += c;
                if(l+1 < w)
                    dp[i][l+1] += c;
            }else if(grid[i][l] == 1){
                //cout << i << l << endl;
                if(l+1 < w)
                    dp[i][l+1] += dp[i][l];
            }else if(grid[i][l] == 2){
                if(i+1 < h)
                    dp[i+1][l] += dp[i][l];
            }else if(grid[i][l] == 3){
                if(i+1 < h)
                    dp[i+1][l] += dp[i][l];
                if(l+1 < w)
                    dp[i][l+1] += dp[i][l];
            }
            //cout << dp[i][l].val() << endl;
        }
    }
    /*REP(i, 0, h){
        REP(l, 0, w){
             cout << dp[i][l].val() << " ";
        }
        cout << endl;
    }*/
    cout << dp[h-1][w-1].val() << endl;
}