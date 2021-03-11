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


//cout << std::fixed << std::setprecision(15) << y << endl; //小数表示

int main(){
    ll n, m, d; cin >> n >> m >> d;
    vector<vector<ll> > dp(30, vector<ll>(n));
    REP(i, 0, n){
        dp[0][i] = i;
    }
    REP(i, 0, m){
        int a; cin >> a;
        a--;
        int x = dp[0][a];dp[0][a] = dp[0][a+1]; dp[0][a+1] = x;
    }
    //doubling
    REP(i, 0, 29){
        REP(l, 0, n){
            dp[i+1][l] = dp[i][dp[i][l]];
        }
    }
    map<int, int> mp;
    REP(i, 0, n){
        ll k = 1;
        ll sum = 0;
        int now = i;
        while(sum != d){
            int count = 0;
            while(sum + k*2 <= d){
                k *= 2;
                count++;
            }
            sum += k;
            now = dp[count][now];
            k = 1;
        }
        mp[now] = i+1;
    }
    REP(i, 0, n){
        cout << mp[i] << endl;
    }
}