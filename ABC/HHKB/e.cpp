// execute g++ main.cpp -std=c++14 -I C:\Users\naoya\Desktop\code\Atcoder
#include<bits/stdc++.h>
//#include<atcoder/all>
typedef long long ll;
typedef long double ld;
using namespace std;
//using namespace atcoder;

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

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

const ll MOD = 1e9+7;

ll Pow(ll  x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return Pow(x * x % MOD, n / 2);
  else
    return x * Pow(x, n - 1) % MOD;
}


int main(){
    int h, w; cin >> h >> w;
    vector<string> lis(h);
    ll k = 0;
    vector<vector<vector<ll> > > dp(h, vector<vector<ll>>(w, vector<ll>(4, 0)));
    REP(i, 0, h){cin >> lis[i];}
    REP(i, 0, h){
        ll count = 0;
        REP(l, 0, w){
            dp[i][l][0] = count;
            if(lis[i][l] == '.'){
                count++;
            }else{
                count = 0;
            }
        }
        count = 0;
        for(int l =  w-1; l >= 0; l--){
            dp[i][l][1] = count;
            if(lis[i][l] == '.'){
                count++;
            }else{
                count = 0;
            }
        }
    }
    REP(l, 0, w){
        ll count = 0;
        REP(i, 0, h){
            dp[i][l][2] = count;
            if(lis[i][l] == '.'){
                count++;
            }else{
                count = 0;
            }
        }
        count = 0;
        for(int i =  h-1; i >= 0; i--){
            dp[i][l][3] = count;
            if(lis[i][l] == '.'){
                count++;
            }else{
                count = 0;
            }
        }
    }
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '.'){
                k++;
            }
        }
    }
    ll ans = (Pow(2, k) * k) % MOD;
    REP(i, 0, h){
        REP(l, 0, w){
            if(lis[i][l] == '#'){
                continue;
            }
            ll mid = 1;
            REP(j, 0, 4){
                mid += dp[i][l][j];
            }
            //cout << mid << endl;
            ans = (ans - Pow(2, k-mid) + MOD) % MOD;
        }
    }
    cout << ans << endl;
}